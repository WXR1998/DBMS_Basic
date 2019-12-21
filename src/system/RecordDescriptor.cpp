#include <string.h>
#include "RecordDescriptor.h"
#include "SystemManager.h"
#include "../record/FileScan.h"

using namespace std;

RecordDescriptor::RecordDescriptor() {

}


AttrValue &RecordDescriptor::operator[](const string &attrName) {
    int i = getIndex(attrName);
    return attrVals[i];
}

void RecordDescriptor::assign(const string &attrName, AttrValue &val) {
    int i = getIndex(attrName);
    attrVals[i] = val;
}

bool RecordDescriptor::checkAssignType(const string &attrName, AttrValue &val) {
    const AttrValue& constValue = attrVals[getIndex(attrName)];
    if(constValue.type == val.type)
        return true;
    if(constValue.type == T_FLOAT && val.type == T_INT)
        return true;
    return false;
}

bool RecordDescriptor::checkCompareType(const string &attrName, AttrValue &val) {
    const AttrValue& constValue = attrVals[getIndex(attrName)];
    if(constValue.type == val.type)
        return true;
    if((constValue.type == T_INT && val.type == T_FLOAT) ||
            (constValue.type == T_FLOAT && val.type == T_INT))
        return true;
    return false;
}

RETVAL RecordDescriptor::toRecord(const RecordID rid, Record& record) {
    int recordSize = 0;
    int attrCount = 0;
    DataAttrInfo* dataAttrInfo = nullptr;
    SystemManager::instance()->fillAttributesFromTable(relName.c_str(), attrCount, dataAttrInfo);
    int nullVectorBase = dataAttrInfo[attrCount-1].offset + dataAttrInfo[attrCount-1].attrLength;
    recordSize = nullVectorBase + attrCount;
    if(attrNames.size() != attrCount) {
        cerr << "InValid RecordDescriptor!" << endl;
        return RETVAL_ERR;
    }
    char* buffer = new char[recordSize];
    for(int i = 0; i < attrCount; ++i) {
        int offset = dataAttrInfo[i].offset;
        if(attrVals[i].type == T_INT) {
            memcpy(buffer + offset, (void*)&(attrVals[i].i), sizeof(int));
        }
        else if(attrVals[i].type == T_FLOAT) {
            memcpy(buffer + offset, (void*)&(attrVals[i].f), 4);
        }
        else
        {
            if(attrVals[i].s.size() < dataAttrInfo[i].attrLength) {
                strncpy(buffer + offset, attrVals[i].s.c_str(), dataAttrInfo[i].attrLength);
            }
            else {
                memcpy(buffer + offset, attrVals[i].s.c_str(), dataAttrInfo[i].attrLength);
            }
        }
    }
    for(int i = 0; i < attrCount; ++i) {
        if(attrVals[i].isNull) {
            memset(buffer + nullVectorBase + i, 1, 1);
        }
        else {
            memset(buffer + nullVectorBase + i, 0, 1);
        }
    }
    record =  Record(rid, buffer, recordSize);
    delete [] dataAttrInfo;
    delete [] buffer;
    return RETVAL_OK ;
}


int RecordDescriptor::getIndex(string attrName) {
    int i = 0;
    for(; i < attrNames.size(); ++i) {
        if(attrNames[i] == attrName)
            break;
    }
    return i;
}

RecordDescriptor RecordDescriptor::createRecordDescriptor(const std::string &relName,
                                                          vector<AttrValue> vals, RETVAL &rc) {
    RecordDescriptor recordDescriptor;
    recordDescriptor.relName = relName;
    int attrCount = 0;
    DataAttrInfo* dataAttrInfo = nullptr;
    SystemManager::instance()->fillAttributesFromTable(relName.c_str(), attrCount, dataAttrInfo);
    if(attrCount != vals.size()) {
        cerr << "Invalid Input!" << endl;
        rc = RETVAL_ERR;
        return recordDescriptor;
    }
    AttrValue primaryValue;
    DataAttrInfo primaryAttrInfo;
    bool hasPrimaryKey = false;
    for(int i = 0; i < attrCount; ++i) {
        if(vals[i].isNull) {
            if(dataAttrInfo[i].notNull) {
                // Check NULL
                cerr << "Insert NULL into NOT NULL Attribute!" << endl;
                rc = RETVAL_ERR;
                return recordDescriptor;
            }
            else {
                recordDescriptor.attrNames.push_back(dataAttrInfo[i].attrName);
                vals[i].type = dataAttrInfo[i].attrType;
                recordDescriptor.attrVals.push_back(vals[i]);
            }
        }
        else if((dataAttrInfo[i].attrType == vals[i].type)
           || (dataAttrInfo[i].attrType == T_FLOAT && vals[i].type == T_INT)) {
            if(dataAttrInfo[i].isPrimaryKey) {
                // Check Primary Key
                hasPrimaryKey = true;
                primaryValue = vals[i];
                primaryAttrInfo = dataAttrInfo[i];
            }

            recordDescriptor.attrNames.push_back(dataAttrInfo[i].attrName);
            recordDescriptor.attrVals.push_back(vals[i]);
        }
        else {
            cerr << "Input Type InValid" << endl;
            rc = RETVAL_ERR;
            return recordDescriptor;
        }
    }
    // Check Primary Key
    if(hasPrimaryKey) {
        void* data;
        if(primaryValue.type == T_INT)
            data = (void*)&(primaryValue.i);
        else if(primaryValue.type == T_FLOAT)
            data = (void*)&(primaryValue.f);
        else
            data = (void*)(primaryValue.s.c_str());
        SingleFileHandler *fileHandle = FileHandler::instance()->openFile(relName.c_str());
        FileScan fileScan;
        fileScan.openScan(*fileHandle,
                          primaryAttrInfo.attrType,
                          primaryAttrInfo.attrLength,
                          primaryAttrInfo.offset,
                          CmpOP::T_EQ, data);
        Record record;
        rc = fileScan.getNextRec(record);
        if(rc != RETVAL_EOF) {
            cerr << "Primary Key Duplicate!" << endl;
            rc = RETVAL_ERR;
        }
        else
            rc = RETVAL_OK;
    }
    else
        rc = RETVAL_OK;
    delete[] dataAttrInfo;
    return recordDescriptor;
}

// Filter Attributes to create a new RecordDescriptor
RecordDescriptor RecordDescriptor::filteredByAttributeName(std::vector<AttributeTree::AttributeDescriptor> attrs) const{
    RecordDescriptor recordDescriptor;
    recordDescriptor.relName = relName;
    // TODO: Check this Seqence
    for (const auto &attr : attrs) {
        for (int i = 0; i < attrNames.size(); ++i) {
            if (attr.relName != relName)
                continue;
            if(attrNames[i] == attr.attrName) {
                recordDescriptor.attrNames.push_back(attr.attrName);
                recordDescriptor.attrVals.push_back(attrVals[i]);
            }
        }
    }
    return recordDescriptor;
}

// Use this function ONLY to Print something. AttrNames and Relname are not filled by this function
RecordDescriptor RecordDescriptor::concatenate(const RecordDescriptor &next) const{
    RecordDescriptor recordDescriptor;
    for(const auto& attr : attrVals)
        recordDescriptor.attrVals.push_back(attr);
    for(const auto& attr : next.attrVals)
        recordDescriptor.attrVals.push_back(attr);
    return recordDescriptor;
}
