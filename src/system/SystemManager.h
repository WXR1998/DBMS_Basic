#ifndef DATABASE_SYSTEMMANAGER_H
#define DATABASE_SYSTEMMANAGER_H


#include <map>
#include "../global.h"
#include "../record/FileHandler.h"
#include "../parser/Tree.h"
#include "RecordDescriptor.h"
#include "DBHandle.h"


class SystemManager {
public:

    static SystemManager* instance();
    static void resetInstance();

    // DB Operations
    RETVAL createDB(const char* dbName);
    RETVAL dropDB(const char* dbName);
    RETVAL openDB(const char *dbName);
    RETVAL closeDB();

    // Relation Operations
    RETVAL createTable(const char *relName, int attrCount, AttrInfo *attributes);
    RETVAL dropTable(const char *relName);
    RETVAL createIndex(std::string relName, AttributeTree::AttributeDescriptor attr);
    RETVAL dropIndex(std::string relName, AttributeTree::AttributeDescriptor attr);
    RETVAL load(const char *relName, const char *fileName);
    RETVAL help();
    std::vector<std::vector<string> > qHelp();
    RETVAL help(const char *relName);
    std::vector<std::vector<std::string>> qHelp(const char* relName);
    RETVAL print(const char *relName) {return dbHandle.print(relName);}
    std::map<RecordID, RecordDescriptor> qPrint(const char* relName) {return dbHandle.qPrint(relName);}
    RETVAL qUpdate(const std::string& relName, const RecordID& recordID,
               int attrNo, const AttrValue& newVal);
    RETVAL set(const char *paramName, const char *value);

    // SQL Instruction API
    RETVAL Select(std::vector<AttributeTree::AttributeDescriptor> attrs,
              std::vector<std::string> rels,
              std::vector<ComparisonTree::ComparisonDescriptor> coms);

    RETVAL Insert(std::string relName,
              std::vector<AttrValue> vals);

    RETVAL Update(std::string relName,
              AttributeTree::AttributeDescriptor attr,
              AttrValue val,
              std::vector<ComparisonTree::ComparisonDescriptor> coms);

    RETVAL Delete(std::string relName,
              std::vector<ComparisonTree::ComparisonDescriptor> coms);

    // Public Utility Functions
    // Given a Relation name in this DB, Fill the AttrInfo of this relation
    RETVAL fillAttributesFromTable(const char* relName, int& attrCount, DataAttrInfo*& dataAttrInfo)
    {RETURNIF(dbHandle.fillAttributesFromTable(relName, attrCount, dataAttrInfo)); return RETVAL_OK;}

    std::vector<RecordDescriptor> select(std::vector<AttributeTree::AttributeDescriptor> attrs,
                                         std::vector<std::string> rels,
                                         std::vector<ComparisonTree::ComparisonDescriptor> coms,
                                         RETVAL& rc);

    ~SystemManager();
private:
    SystemManager();

    static SystemManager* systemManager;
    FileHandler* recordManager;
    DBHandle dbHandle;
    bool hasOpenDB;
    char currentDBName[MAX_NAME];

    // Return true if there is a relation named relName
    bool hasRelation(const char *relName) {return dbHandle.hasRelation(relName);}

    // Return true if there is a attribute name attrName in the relation
    // Assuming that we've got a relation named relName
    bool hasAttribute(const char *relName, const char *attrName) {return dbHandle.hasAttribute(relName, attrName);}

    typedef ComparisonTree::ComparisonDescriptor Comparison;
    typedef AttributeTree::AttributeDescriptor Attribute;

    std::map<RecordID, RecordDescriptor> retrieveRecords(std::string relName, RETVAL& rc)
    { return dbHandle.retrieveRecords(relName, rc);}

    bool checkRelations(const std::vector<std::string> &relations);
    bool checkAttributes(std::vector<Attribute> &attributes, std::vector<std::string> &relations);
    bool checkComparison(std::vector<Comparison> &coms, std::string &relation);
    bool checkComparisons(std::vector<Comparison> &coms, std::vector<std::string> &relations);

    bool isValid(std::vector<Comparison> &coms, RecordDescriptor &record, const std::string &relation);

    void iterateCrossProduct(std::vector<std::vector<RecordDescriptor>> &records,
                             std::vector<AttributeTree::AttributeDescriptor> attrs,
                             std::vector<std::string> &rels,
                             std::vector<Comparison> &coms,
                             int depth,
                             std::vector<RecordDescriptor>& output);

    std::vector<RecordDescriptor> retrieveRecordsByIndex(std::string relName, const std::vector<Comparison>& coms, RETVAL& rc);

    static vector<string> &split(const string &s, char delim, vector<string> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }


    static vector<std::string> split(const string &s, char delim) {
        vector<string> elems;
        split(s, delim, elems);
        return elems;
    }};

#endif //DATABASE_SYSTEMMANAGER_H