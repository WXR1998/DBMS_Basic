#include "tree.h"
#include "../system/SystemManager.h"

#include <cstdlib>
#include <cstring>

using std::string;
using std::vector;

void Error(const char *msg) {
    printf("> Error: %s\n", msg);
    exit(0);
}

Tree* Tree::tree = nullptr;

/* TypeTree */
TypeTree::TypeTree(AttrType t){
    this->type = t;
    this->len = 4;
}

TypeTree::TypeTree(AttrType t, int l){
    this->type = t;
    this->len = l;
}

AttrType TypeTree::getType(){
    return this->type;
}

int TypeTree::getLen(){
    return this->len;
}


/* SelectTree */
SelectTree::SelectTree(RelationsTree *relations, WhereClauseTree *whereClause) {
    this->attributes = nullptr;
    this->relations = relations;
    this->whereClause = whereClause;
    this->groupAttrName = string();
}

SelectTree::SelectTree(AttributesTree *attributes,
                       RelationsTree *relations,
                       WhereClauseTree *whereClause) {
    this->attributes = attributes;
    this->relations = relations;
    this->whereClause = whereClause;
}

SelectTree::~SelectTree() {
    delete attributes;
    delete relations;
    delete whereClause;
}

void SelectTree::visit() {
    vector<AttributeTree::AttributeDescriptor> attrs;
    if (attributes) {
        attrs = attributes->getDescriptors();
    } else {
        attrs = vector<AttributeTree::AttributeDescriptor>();
    }
    vector<string> rels = relations->getRelations();
    vector<ComparisonTree::ComparisonDescriptor> coms;
    if (whereClause != nullptr) {
        coms = whereClause->getComparision();
        SystemManager::instance()->Select(attrs, rels, coms);
    } else {
        SystemManager::instance()->Select(attrs, rels, coms);
    }
}


/* InsertTree */
InsertTree::InsertTree(const char *relationName, InsertValueTree* insertValueTree) {
    this->relationName = string(relationName);
    this->insertValueTree = insertValueTree;
}

InsertTree::~InsertTree() {
    delete insertValueTree;
}

void InsertTree::visit() {
    for(const auto& constValues : insertValueTree->values) {
        SystemManager::instance()->Insert(relationName, constValues->getConstValues());
    }
}

/* UpdateTree */
UpdateTree::UpdateTree(string relationName,
                       AttributeTree *attribute,
                       ConstValueTree *constValue,
                       WhereClauseTree *whereClause) {
    this->relationName = relationName;
    this->attribute = attribute;
    this->constValue = constValue;
    this->whereClause = whereClause;
}

UpdateTree::~UpdateTree() {
    delete attribute;
    delete constValue;
    delete whereClause;
}

void UpdateTree::visit() {
    AttributeTree::AttributeDescriptor attr = attribute->getDescriptor();
    AttrValue val = constValue->getDescriptor();
    vector<ComparisonTree::ComparisonDescriptor> coms = whereClause->getComparision();
    SystemManager::instance()->Update(relationName, attr, val, coms);
}

/* DeleteTree */
DeleteTree::DeleteTree(const char *relationName, WhereClauseTree *whereClause) {
    this->relationName = string(relationName);
    this->whereClause = whereClause;
}

DeleteTree::~DeleteTree() {
    delete whereClause;
}

void DeleteTree::visit() {
    vector<ComparisonTree::ComparisonDescriptor> coms;
    if (whereClause != nullptr)
        coms = whereClause->getComparision();
    SystemManager::instance()->Delete(relationName, coms);
}

/* CreateDatabaseTree */
CreateDatabaseTree::CreateDatabaseTree(const char *dbName) {
    this->dbName = string(dbName);
}

CreateDatabaseTree::~CreateDatabaseTree() {
}

void CreateDatabaseTree::visit() {
    SystemManager::instance()->createDB(dbName.c_str());
}

/* CreateTableTree */
CreateTableTree::CreateTableTree(const char *tableName, ColumnsTree *columns) {
    this->tableName = string(tableName);
    this->columns = columns;
}

CreateTableTree::~CreateTableTree() {
    delete columns;
}

void CreateTableTree::visit() {
    int attrCount = columns->getColumnCount();
    AttrInfo *attrInfos = columns->getAttrInfos();
    SystemManager::instance()->createTable(tableName.c_str(), attrCount, attrInfos);
    columns->deleteAttrInfos();
}


/* CreateIndexTree */
CreateIndexTree::CreateIndexTree(const char *relName, AttributeTree *attr) {
    this->relName = string(relName);
    this->attribute = attr;
}

CreateIndexTree::~CreateIndexTree() {
    delete attribute;
}

void CreateIndexTree::visit() {
    auto attr = attribute->getDescriptor();
    SystemManager::instance()->createIndex(relName, attr);
}


DropIndexTree::DropIndexTree(const char *relName, AttributeTree *attr) {
    this->relName = string(relName);
    this->attribute = attr;
}

DropIndexTree::~DropIndexTree() {
    delete attribute;
}

void DropIndexTree::visit() {
    auto attr = attribute->getDescriptor();
    SystemManager::instance()->dropIndex(relName, attr);
}


/* DropDatabaseTree */
DropDatabaseTree::DropDatabaseTree(const char *dbName) {
    this->dbName = string(dbName);
}

DropDatabaseTree::~DropDatabaseTree() {
}

void DropDatabaseTree::visit() {
    SystemManager::instance()->dropDB(dbName.c_str());
}

/* DropTableTree */
DropTableTree::DropTableTree(const char *tableName) {
    this->tableName = string(tableName);
}

DropTableTree::~DropTableTree() {
}

void DropTableTree::visit() {
    SystemManager::instance()->dropTable(tableName.c_str());
}

/* ColumnsTree */
ColumnsTree::ColumnsTree() {
}

ColumnsTree::~ColumnsTree() {
    for (const auto &column : columns)
        delete column;
}

void ColumnsTree::addColumn(ColumnTree *column) {
    for (const auto &col : columns)
        if (col->columnName == column->columnName)
            Error("duplicated column name");
    columns.push_back(column);
}

bool ColumnsTree::setPrimaryKey(const char *attr) {
    bool found = false;
    for(auto& tree : columns) {
        if(tree->columnName == string(attr)) {
            tree->isPrimaryKey = 1;
            tree->notNull = 1;
            found = true;
            break;
        }
    }
    return found;
}


int ColumnsTree::getColumnCount() {
    return (int) columns.size();
}

AttrInfo *ColumnsTree::getAttrInfos() {
    attrInfos = new AttrInfo[columns.size()];
    for (int i = 0; i < columns.size(); ++i)
        attrInfos[i] = columns[i]->getAttrInfo();
    return attrInfos;
}

void ColumnsTree::deleteAttrInfos() {
    delete attrInfos;
    attrInfos = nullptr;
}

/* ColumnTree */
ColumnTree::ColumnTree(const char *columnName, AttrType type, int size,
                       int notNull, ConstValueTree *defaultValue) {
    this->columnName = string(columnName);
    this->type = type;
    this->size = size;
    this->isPrimaryKey = 0;
    this->notNull = notNull;
    if (defaultValue != NULL){
        this->isDefault = true;
        this->constDescriptor = defaultValue->getDescriptor();
        if (this->constDescriptor.type != this->type)
            Error("Default value is not of the same type.");
    }
    if(type == T_STRING)
        this->size++;
}

void ColumnTree::setNotNull(int notNull) {
    this->notNull = notNull;
}

ColumnTree::~ColumnTree() {
}

AttrInfo ColumnTree::getAttrInfo() {
    AttrInfo attrInfo;
    strcpy(attrInfo.attrName, columnName.c_str());
    attrInfo.attrType = (AttrType) type;
    attrInfo.attrLength = size;
    attrInfo.isPrimaryKey = isPrimaryKey;
    attrInfo.notNull = notNull;
    return attrInfo;
}


/* AttributesTree */
AttributesTree::AttributesTree() {
}

AttributesTree::~AttributesTree() {
    for (const auto &attribute : attributes)
        delete attribute;
}

void AttributesTree::addAttribute(AttributeTree *attribute) {
    attributes.push_back(attribute);
}

vector<AttributeTree::AttributeDescriptor> AttributesTree::getDescriptors() const {
    vector<AttributeTree::AttributeDescriptor> attrs;
    for (int i = 0; i < attributes.size(); ++i)
        attrs.push_back(attributes[i]->getDescriptor());
    return attrs;
}

/* AttributeTree */
AttributeTree::AttributeTree(const char *relationName, const char *attributeName) {
    this->relation = string(relationName);
    this->attribute = string(attributeName);
}

AttributeTree::AttributeTree(const char *attributeName) {
    this->attribute = string(attributeName);
}

AttributeTree::AttributeDescriptor AttributeTree::getDescriptor() const {
    return AttributeDescriptor(relation, attribute);
}

bool AttributeTree::operator==(const AttributeTree &attribute) const {
    return this->relation == attribute.relation &&
           this->attribute == attribute.attribute;
}

AttributeTree::~AttributeTree() {
}


/* RelationsTree */
RelationsTree::RelationsTree() {
}

RelationsTree::~RelationsTree() {
}

void RelationsTree::addRelation(const char *relation) {
    auto r = string(relation);
    for (const auto &rel : relations)
        if (rel == r)
            return;
    relations.push_back(r);
}

vector<string> RelationsTree::getRelations() {
    return relations;
}


/* WhereClauseTree */
WhereClauseTree::WhereClauseTree(ConditionsTree *conditions) {
    this->conditions = conditions;
}

WhereClauseTree::WhereClauseTree() {
    conditions = nullptr;
}

WhereClauseTree::~WhereClauseTree() {
    delete conditions;
}

vector<ComparisonTree::ComparisonDescriptor> WhereClauseTree::getComparision() {
    return conditions->getComparisions();
}

/* ConditionsTree */
ConditionsTree::ConditionsTree() {
}

ConditionsTree::~ConditionsTree() {
    for (const auto &comparision : comparisons)
        delete comparision;
}

void ConditionsTree::addComparison(ComparisonTree *comparison) {
    comparisons.push_back(comparison);
}

vector<ComparisonTree::ComparisonDescriptor> ConditionsTree::getComparisions() {
    vector<ComparisonTree::ComparisonDescriptor> coms;
    for (int i = 0; i < comparisons.size(); ++i)
        coms.push_back(comparisons[i]->getDescriptor());
    return coms;
}

/* ComparisonTree */
ComparisonTree::ComparisonTree(AttributeTree *attribute, CmpOP op) {
    this->op = op;
    this->attribute = attribute;
    this->constValue = nullptr;
    this->isAttrCmp = false;
}

ComparisonTree::ComparisonTree(AttributeTree *attribute, CmpOP op, ConstValueTree *constValue) {
    this->op = op;
    this->attribute = attribute;
    this->constValue = constValue;
    this->isAttrCmp = false;
}

ComparisonTree::ComparisonTree(AttributeTree *attribute, CmpOP op, AttributeTree *attribute2) {
    this->op = op;
    this->attribute = attribute;
    this->attribute2 = attribute2;
    this->isAttrCmp = true;
}

ComparisonTree::~ComparisonTree() {
    delete attribute;
    if(isAttrCmp)
        delete attribute2;
    else
        delete constValue;
}

ComparisonTree::ComparisonDescriptor ComparisonTree::getDescriptor() {
    ComparisonDescriptor com;
    com.attr = this->attribute->getDescriptor();
    if(!isAttrCmp && this->constValue != nullptr)
        com.val = this->constValue->getDescriptor();
    else if(isAttrCmp)
        com.attr2 = this->attribute2->getDescriptor();
    com.isAttrCmp = isAttrCmp;
    com.op = this->op;
    return com;
}


/* ConstValuesTree */
ConstValuesTree::ConstValuesTree() {
}

ConstValuesTree::~ConstValuesTree() {
    for (const auto &constValue: constValues)
        delete constValue;
}

void ConstValuesTree::addConstValue(ConstValueTree *constValue) {
    constValues.push_back(constValue);
}

vector<AttrValue> ConstValuesTree::getConstValues() {
    vector<AttrValue> vals;
    for (int i = 0; i < constValues.size(); ++i)
        vals.push_back(constValues[i]->getDescriptor());
    return vals;
}


/* ConstValueTree */
ConstValueTree::ConstValueTree(int i) {
    this->i = i;
    this->type = AttrType::T_INT;
    this->isNull = false;
}

ConstValueTree::ConstValueTree(float f) {
    this->f = f;
    this->type = AttrType::T_FLOAT;
    this->isNull = false;
}

ConstValueTree::ConstValueTree(const char *s) {
    this->s = string(s, 1, strlen(s) - 2);
    this->type = AttrType::T_STRING;
    this->isNull = false;
}

ConstValueTree::~ConstValueTree() {
}

AttrValue ConstValueTree::getDescriptor() {
    return AttrValue{type, i, f, s, isNull};
}

bool AttrValue::operator == (const AttrValue &val) const {
    if(this->isNull || val.isNull)
        return false;
    if ((type == AttrType::T_INT || type == AttrType::T_FLOAT) &&
        (val.type == AttrType::T_INT || val.type == AttrType::T_FLOAT)) {
        float f1 = this->type == AttrType::T_INT ? this->i : this->f;
        float f2 = val.type == AttrType::T_INT ? val.i : val.f;
        return f1 == f2;
    } else if (type == AttrType::T_STRING && val.type == AttrType::T_STRING) {
        return this->s == val.s;
    } else {
        // TODO cannot compare
    }
    return false;
}

bool AttrValue::operator != (const AttrValue &val) const {
    if(this->isNull || val.isNull)
        return false;
    if ((type == AttrType::T_INT || type == AttrType::T_FLOAT) &&
        (val.type == AttrType::T_INT || val.type == AttrType::T_FLOAT)) {
        float f1 = this->type == AttrType::T_INT ? this->i : this->f;
        float f2 = val.type == AttrType::T_INT ? val.i : val.f;
        return f1 != f2;
    } else if (type == AttrType::T_STRING && val.type == AttrType::T_STRING) {
        return this->s != val.s;
    } else {
        // TODO cannot compare
    }
    return false;
}

bool AttrValue::operator >= (const AttrValue &val) const {
    if(this->isNull || val.isNull)
        return false;
    if ((type == AttrType::T_INT || type == AttrType::T_FLOAT) &&
        (val.type == AttrType::T_INT || val.type == AttrType::T_FLOAT)) {
        float f1 = this->type == AttrType::T_INT ? this->i : this->f;
        float f2 = val.type == AttrType::T_INT ? val.i : val.f;
        return f1 >= f2;
    } else if (type == AttrType::T_STRING && val.type == AttrType::T_STRING) {
        return this->s >= val.s;
    } else {
        // TODO cannot compare
    }
    return false;
}

bool AttrValue::operator <= (const AttrValue &val) const {
    if(this->isNull || val.isNull)
        return false;
    if ((type == AttrType::T_INT || type == AttrType::T_FLOAT) &&
        (val.type == AttrType::T_INT || val.type == AttrType::T_FLOAT)) {
        float f1 = this->type == AttrType::T_INT ? this->i : this->f;
        float f2 = val.type == AttrType::T_INT ? val.i : val.f;
        return f1 <= f2;
    } else if (type == AttrType::T_STRING && val.type == AttrType::T_STRING) {
        return this->s <= val.s;
    } else {
        // TODO cannot compare
    }
    return false;
}

bool AttrValue::operator > (const AttrValue &val) const {
    if(this->isNull || val.isNull)
        return false;
    if ((type == AttrType::T_INT || type == AttrType::T_FLOAT) &&
        (val.type == AttrType::T_INT || val.type == AttrType::T_FLOAT)) {
        float f1 = this->type == AttrType::T_INT ? this->i : this->f;
        float f2 = val.type == AttrType::T_INT ? val.i : val.f;
        return f1 > f2;
    } else if (type == AttrType::T_STRING && val.type == AttrType::T_STRING) {
        return this->s > val.s;
    } else {
        // TODO cannot compare
    }
    return false;
}

bool AttrValue::operator < (const AttrValue &val) const {
    if(this->isNull || val.isNull)
        return false;
    if ((type == AttrType::T_INT || type == AttrType::T_FLOAT) &&
        (val.type == AttrType::T_INT || val.type == AttrType::T_FLOAT)) {
        float f1 = this->type == AttrType::T_INT ? this->i : this->f;
        float f2 = val.type == AttrType::T_INT ? val.i : val.f;
        return f1 < f2;
    } else if (type == AttrType::T_STRING && val.type == AttrType::T_STRING) {
        return this->s < val.s;
    } else {
        // TODO cannot compare
    }
    return false;
}

UseDatabaseTree::UseDatabaseTree(const char *dbName) {
    this->dbName = dbName;
}

void UseDatabaseTree::visit() {
    SystemManager::instance()->openDB(dbName.c_str());
}

DescTableTree::DescTableTree(const char *relName) {
    this->relName = string(relName);
}

DescTableTree::~DescTableTree() {

}

void DescTableTree::visit() {
    if(relName.empty())
        SystemManager::instance()->help();
    else
        SystemManager::instance()->help(relName.c_str());
}

InsertValueTree::InsertValueTree(ConstValuesTree *constValues) {
    values.push_back(constValues);
}

InsertValueTree::~InsertValueTree() {
    for(auto v : values) {
        delete v;
    }
}

void InsertValueTree::addConstValues(ConstValuesTree *constValuesTree) {
    values.push_back(constValuesTree);
}