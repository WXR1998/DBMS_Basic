#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <cstddef>
#include <cstdio>
#include "SystemManager.h"
#include "../record/FileScan.h"
#include "DBHandle.h"
#include "Printer.h"
#include "../index/IndexHandler.h"

#ifdef __APPLE__
#include <sys/stat.h>
#endif

using namespace std;

SystemManager* SystemManager::systemManager = nullptr;

SystemManager::SystemManager()
{
    recordManager = FileHandler::instance();
    hasOpenDB = false;
#ifdef __MINGW32__
    mkdir(kDefaultDBPosition);
    chdir(kDefaultDBPosition);
#else
    mkdir(kDefaultDBPosition, S_IRWXU | S_IRWXG | S_IXOTH);
    chdir(kDefaultDBPosition);
#endif
}


SystemManager::~SystemManager() {

}

RETVAL SystemManager::createDB(const char *dbName) {
    if(hasOpenDB) {
        closeDB();
    }
    // Create Folder First
#ifdef __MINGW32__
    mkdir(dbName);
    RETURNIF(chdir(dbName));
#else
    mkdir(dbName, S_IRWXU | S_IRWXG | S_IXOTH);
    chdir(dbName);
#endif

    // 当前database中各个table的的相关信息
    /*

    - RelCat:
        table名, table一条记录的长度, table的attr数量, table有多少行, table是否有主键
    - AttrCat:
        table名, attr名, attr在记录中的偏移, attr类型, attr长度, attr索引编号, 在主键中的排序编号, 是否非空, attr是否存在默认值, 默认值
    - FkCat:
        fk名, 从table, 主table, attr数, 从attr1, 从attr2，从attr3, 主attr1, 主attr2, 主attr3
    - IdxCat:
        idxName, table名, attr名

    */


    // RelCat
    RETURNIF(recordManager->createFile(kDefaultRelCatName, sizeof(DataRelInfo)));
    SingleFileHandler* fileHandle = recordManager->openFile(kDefaultRelCatName);
    DataRelInfo dataRelInfo;
    memset(&dataRelInfo, 0, sizeof(DataRelInfo));
    dataRelInfo.recordSize = sizeof(DataRelInfo);
    dataRelInfo.indexCount = 0;
    dataRelInfo.attrCount = 5;
    dataRelInfo.primaryCount = 0;
    strcpy(dataRelInfo.relName, kDefaultRelCatName);
    RecordID recordID;
    RETURNIF(fileHandle->insertRecord((const char*)&dataRelInfo, recordID));

    memset(&dataRelInfo, 0, sizeof(DataRelInfo));
    dataRelInfo.recordSize = sizeof(DataAttrInfo);
    dataRelInfo.indexCount = 0;
    dataRelInfo.attrCount = 10;
    dataRelInfo.primaryCount = 0;
    strcpy(dataRelInfo.relName, kDefaultAttrCatName);
    RETURNIF(fileHandle->insertRecord((const char*)&dataRelInfo, recordID));

    memset(&dataRelInfo, 0, sizeof(DataRelInfo));
    dataRelInfo.recordSize = sizeof(DataFkInfo);
    dataRelInfo.indexCount = 0;
    dataRelInfo.attrCount = 10;
    dataRelInfo.primaryCount = 0;
    strcpy(dataRelInfo.relName, kDefaultFkCatName);
    RETURNIF(fileHandle->insertRecord((const char*)&dataRelInfo, recordID));

    memset(&dataRelInfo, 0, sizeof(DataRelInfo));
    dataRelInfo.recordSize = sizeof(DataIdxInfo);
    dataRelInfo.indexCount = 0;
    dataRelInfo.attrCount = 3;
    dataRelInfo.primaryCount = 0;
    strcpy(dataRelInfo.relName, kDefaultIdxCatName);
    RETURNIF(fileHandle->insertRecord((const char*)&dataRelInfo, recordID));

    // FkCat
    RETURNIF(recordManager->createFile(kDefaultFkCatName, sizeof(DataFkInfo)));
    fileHandle = recordManager->openFile(kDefaultFkCatName);

    // IdxCat
    RETURNIF(recordManager->createFile(kDefaultIdxCatName, sizeof(DataIdxInfo)));
    fileHandle = recordManager->openFile(kDefaultIdxCatName);

    // AttrCat
    // attr in relCat
    RETURNIF(recordManager->createFile(kDefaultAttrCatName, sizeof(DataAttrInfo)));
    fileHandle = recordManager->openFile(kDefaultAttrCatName);

    DataAttrInfo dataAttrInfo;
    memset(&dataAttrInfo, 0, sizeof(DataAttrInfo));
    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultRelCatName);
    strcpy(dataAttrInfo.attrName, "relName");
    dataAttrInfo.offset = offsetof(DataRelInfo, relName);
    dataAttrInfo.attrLength = MAX_NAME + 1;
    dataAttrInfo.attrType = AttrType::T_STRING;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultRelCatName);
    strcpy(dataAttrInfo.attrName, "recordSize");
    dataAttrInfo.offset = offsetof(DataRelInfo, recordSize);
    dataAttrInfo.attrLength = sizeof(int);
    dataAttrInfo.attrType = AttrType::T_INT;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultRelCatName);
    strcpy(dataAttrInfo.attrName, "attrCount");
    dataAttrInfo.offset = offsetof(DataRelInfo, attrCount);
    dataAttrInfo.attrLength = sizeof(int);
    dataAttrInfo.attrType = AttrType::T_INT;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultRelCatName);
    strcpy(dataAttrInfo.attrName, "indexCount");
    dataAttrInfo.offset = offsetof(DataRelInfo, indexCount);
    dataAttrInfo.attrLength = sizeof(int);
    dataAttrInfo.attrType = AttrType::T_INT;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultRelCatName);
    strcpy(dataAttrInfo.attrName, "primaryCount");
    dataAttrInfo.offset = offsetof(DataRelInfo, primaryCount);
    dataAttrInfo.attrLength = sizeof(int);
    dataAttrInfo.attrType = AttrType::T_INT;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    // attr in attrCat
    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultAttrCatName);
    strcpy(dataAttrInfo.attrName, "relName");
    dataAttrInfo.offset = offsetof(DataAttrInfo, relName);
    dataAttrInfo.attrLength = MAX_NAME + 1;
    dataAttrInfo.attrType = AttrType::T_STRING;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = false;
    dataAttrInfo.notNull = false;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultAttrCatName);
    strcpy(dataAttrInfo.attrName, "attrName");
    dataAttrInfo.offset = offsetof(DataAttrInfo, attrName);
    dataAttrInfo.attrLength = MAX_NAME + 1;
    dataAttrInfo.attrType = AttrType::T_STRING;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultAttrCatName);
    strcpy(dataAttrInfo.attrName, "offset");
    dataAttrInfo.offset = offsetof(DataAttrInfo, offset);
    dataAttrInfo.attrLength = sizeof(int);
    dataAttrInfo.attrType = AttrType::T_INT;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultAttrCatName);
    strcpy(dataAttrInfo.attrName, "attrType");
    dataAttrInfo.offset = offsetof(DataAttrInfo, attrType);
    dataAttrInfo.attrLength = sizeof(AttrType);
    dataAttrInfo.attrType = AttrType::T_INT;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultAttrCatName);
    strcpy(dataAttrInfo.attrName, "attrLength");
    dataAttrInfo.offset = offsetof(DataAttrInfo, attrLength);
    dataAttrInfo.attrLength = sizeof(int);
    dataAttrInfo.attrType = AttrType::T_INT;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultAttrCatName);
    strcpy(dataAttrInfo.attrName, "indexNo");
    dataAttrInfo.offset = offsetof(DataAttrInfo, indexNo);
    dataAttrInfo.attrLength = sizeof(int);
    dataAttrInfo.attrType = AttrType::T_INT;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultAttrCatName);
    strcpy(dataAttrInfo.attrName, "isPrimaryKey");
    dataAttrInfo.offset = offsetof(DataAttrInfo, isPrimaryKey);
    dataAttrInfo.attrLength = sizeof(int);
    dataAttrInfo.attrType = AttrType::T_INT;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultAttrCatName);
    strcpy(dataAttrInfo.attrName, "notNull");
    dataAttrInfo.offset = offsetof(DataAttrInfo, notNull);
    dataAttrInfo.attrLength = sizeof(int);
    dataAttrInfo.attrType = AttrType::T_INT;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultAttrCatName);
    strcpy(dataAttrInfo.attrName, "isDefault");
    dataAttrInfo.offset = offsetof(DataAttrInfo, isDefault);
    dataAttrInfo.attrLength = sizeof(int);
    dataAttrInfo.attrType = AttrType::T_INT;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultAttrCatName);
    strcpy(dataAttrInfo.attrName, "defaultVal");
    dataAttrInfo.offset = offsetof(DataAttrInfo, defaultVal);
    dataAttrInfo.attrLength = MAX_DEF + 1;
    dataAttrInfo.attrType = AttrType::T_NONE;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    // attr in FkCat
    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultFkCatName);
    strcpy(dataAttrInfo.attrName, "fkName");
    dataAttrInfo.offset = offsetof(DataFkInfo, fkName);
    dataAttrInfo.attrLength = MAX_NAME + 1;
    dataAttrInfo.attrType = AttrType::T_STRING;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultFkCatName);
    strcpy(dataAttrInfo.attrName, "serRelName");
    dataAttrInfo.offset = offsetof(DataFkInfo, serRelName);
    dataAttrInfo.attrLength = MAX_NAME + 1;
    dataAttrInfo.attrType = AttrType::T_STRING;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultFkCatName);
    strcpy(dataAttrInfo.attrName, "masRelName");
    dataAttrInfo.offset = offsetof(DataFkInfo, masRelName);
    dataAttrInfo.attrLength = MAX_NAME + 1;
    dataAttrInfo.attrType = AttrType::T_STRING;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultFkCatName);
    strcpy(dataAttrInfo.attrName, "attrCount");
    dataAttrInfo.offset = offsetof(DataFkInfo, attrCount);
    dataAttrInfo.attrLength = sizeof(int);
    dataAttrInfo.attrType = AttrType::T_INT;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultFkCatName);
    strcpy(dataAttrInfo.attrName, "serAttr1Name");
    dataAttrInfo.offset = offsetof(DataFkInfo, serAttr1Name);
    dataAttrInfo.attrLength = MAX_NAME + 1;
    dataAttrInfo.attrType = AttrType::T_STRING;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultFkCatName);
    strcpy(dataAttrInfo.attrName, "serAttr2Name");
    dataAttrInfo.offset = offsetof(DataFkInfo, serAttr2Name);
    dataAttrInfo.attrLength = MAX_NAME + 1;
    dataAttrInfo.attrType = AttrType::T_STRING;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultFkCatName);
    strcpy(dataAttrInfo.attrName, "serAttr3Name");
    dataAttrInfo.offset = offsetof(DataFkInfo, serAttr3Name);
    dataAttrInfo.attrLength = MAX_NAME + 1;
    dataAttrInfo.attrType = AttrType::T_STRING;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultFkCatName);
    strcpy(dataAttrInfo.attrName, "masAttr1Name");
    dataAttrInfo.offset = offsetof(DataFkInfo, masAttr1Name);
    dataAttrInfo.attrLength = MAX_NAME + 1;
    dataAttrInfo.attrType = AttrType::T_STRING;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultFkCatName);
    strcpy(dataAttrInfo.attrName, "masAttr2Name");
    dataAttrInfo.offset = offsetof(DataFkInfo, masAttr2Name);
    dataAttrInfo.attrLength = MAX_NAME + 1;
    dataAttrInfo.attrType = AttrType::T_STRING;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultFkCatName);
    strcpy(dataAttrInfo.attrName, "masAttr3Name");
    dataAttrInfo.offset = offsetof(DataFkInfo, masAttr3Name);
    dataAttrInfo.attrLength = MAX_NAME + 1;
    dataAttrInfo.attrType = AttrType::T_STRING;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    // attr in idxCat
    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultIdxCatName);
    strcpy(dataAttrInfo.attrName, "idxName");
    dataAttrInfo.offset = offsetof(DataIdxInfo, idxName);
    dataAttrInfo.attrLength = MAX_NAME + 1;
    dataAttrInfo.attrType = AttrType::T_STRING;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultIdxCatName);
    strcpy(dataAttrInfo.attrName, "relName");
    dataAttrInfo.offset = offsetof(DataIdxInfo, relName);
    dataAttrInfo.attrLength = MAX_NAME + 1;
    dataAttrInfo.attrType = AttrType::T_STRING;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

    memset(dataAttrInfo.relName, 0, MAX_NAME + 1);
    memset(dataAttrInfo.attrName, 0, MAX_NAME + 1);
    strcpy(dataAttrInfo.relName, kDefaultIdxCatName);
    strcpy(dataAttrInfo.attrName, "attrName");
    dataAttrInfo.offset = offsetof(DataIdxInfo, attrName);
    dataAttrInfo.attrLength = MAX_NAME + 1;
    dataAttrInfo.attrType = AttrType::T_STRING;
    dataAttrInfo.indexNo = 0;
    dataAttrInfo.isPrimaryKey = 0;
    dataAttrInfo.notNull = 0;
    RETURNIF(fileHandle->insertRecord((const char*)&dataAttrInfo, recordID));

#ifdef __MINGW32__
    RETURNIF(chdir(kDefaultDBPosition));
#else
    chdir("..");
#endif

    return RETVAL_OK;
}

RETVAL SystemManager::dropDB(const char *dbName) {
    if(hasOpenDB && strcmp(currentDBName, dbName) == 0)
        RETURNIF(recordManager->closeFile());

#ifdef __MINGW32__
    char cmd[256] = "rmdir /s /q ";
    strcat(cmd, kDefaultDBPosition);
    strcat(cmd, dbName);
    system(cmd);
#else
    char cmd[256] = "rm -rf ";
    if (hasOpenDB) {
        chdir("..");
        hasOpenDB = false;
    }
    strcat(cmd, dbName);
    system(cmd);
    printf("[INFO] Drop database %s success.\n", dbName);
#endif
    return 0;
}

RETVAL SystemManager::openDB(const char *dbName) {
    if(hasOpenDB)
        closeDB();
    MSGIF(chdir(dbName), "[ERROR] Database does not exist.");
    printf("[INFO] Open database %s success.\n", dbName);
    hasOpenDB = true;
    strcpy(currentDBName, dbName);
    RETURNIF(dbHandle.refreshHandle());
    return 0;
}

RETVAL SystemManager::closeDB() {
    RETURNIF(recordManager->closeFile());
    hasOpenDB = false;
    memset(currentDBName, 0, MAX_NAME);
#ifdef __MINGW32__
    RETURNIF(chdir(".."));
#else
    chdir("..");
#endif
    return 0;
}

RETVAL SystemManager::createTable(const char *relName, int attrCount, AttrInfo *attributes) {
    if(!hasOpenDB)
    {
        cerr << "[ERROR] Please Open DB first!" << endl;
        return RETVAL_ERR;
    }
    if (hasRelation(relName)){
        cerr << "[ERROR] There is a table named <" << relName << ">." << endl;
        return RETVAL_ERR;
    }
    RETURNIF(dbHandle.createTable(relName, attrCount, attributes));
    return RETVAL_OK;
}

RETVAL SystemManager::dropTable(const char *relName) {
    if(strcmp(relName, kDefaultRelCatName) == 0 ||
            strcmp(relName, kDefaultAttrCatName) == 0)
        return RETVAL_ERR;
    RETURNIF(dbHandle.dropTable(relName));
    return RETVAL_OK;
}

RETVAL SystemManager::createIndex(string relName, Attribute attrName, string idxName) {
    if (!hasRelation(relName.c_str())){
        cerr << "[ERROR] No such relation." << endl;
        return RETVAL_ERR;
    }

    // check whether the relName has already owned a index;
    DataAttrInfo attrData;
    int attrCount;
    bool found = false;
    bool foundIndex = false;
    RecordID attrRecordID;
    for(int i = 0; i < dbHandle.attributes.size(); ++i) {
        if(dbHandle.attributes[i].attrName == attrName.attrName && dbHandle.attributes[i].relName == relName) {
            found = true;
            attrRecordID = dbHandle.attributeRecordIDs[i];
            attrData = dbHandle.attributes[i];
            if(dbHandle.attributes[i].indexNo != 0)
                foundIndex = true;
            break;
        }
    }
    if(!found) {
        cerr << "[ERROR] No such attribute to create index." << endl;
        return RETVAL_ERR;
    }
    if(foundIndex) {
        cerr << "[ERROR] Already have index for this attribute." << endl;
        return RETVAL_ERR;
    }
    if (hasIndex(relName.c_str(), idxName.c_str())){
        cerr << "[ERROR] Already have an index which has the same idxName on <" << relName << ">." << endl;
        return RETVAL_ERR;
    }

    // Create a new index
    int indexCount = 0;
    RecordID relRecordID;
    DataRelInfo relInfo;
    for(int i = 0; i < dbHandle.relations.size(); ++i) {
        const auto& dataRelInfo = dbHandle.relations[i];
        if(relName == string(dataRelInfo.relName)) {
            indexCount = dataRelInfo.indexCount;
            relRecordID = dbHandle.relationRecordIDs[i];
            relInfo = dataRelInfo;
        }
    }
    indexCount++;
    attrData.indexNo = indexCount;
    relInfo.indexCount = indexCount;
    // 索引编号是每个表的属性，每次增大1

    // Update IndexNo in attrcat
    SingleFileHandler* fileHandle = recordManager->openFile(kDefaultAttrCatName);
    Record record(attrRecordID, (char*)(&attrData), sizeof(DataAttrInfo));
    fileHandle->updateRecord(record);
    // Update IndexCount in relcat
    fileHandle = recordManager->openFile(kDefaultRelCatName);
    Record record1(relRecordID, (char*)(&relInfo), sizeof(DataRelInfo));
    fileHandle->updateRecord(record1);
    recordManager->closeFile();
    // Update index info in idxcat
    fileHandle = recordManager->openFile(kDefaultIdxCatName);
    RecordID rid;
    DataIdxInfo dataIdxInfo;
    strcpy(dataIdxInfo.idxName, idxName.c_str());
    strcpy(dataIdxInfo.attrName, attrName.attrName.c_str());
    strcpy(dataIdxInfo.relName, relName.c_str());
    fileHandle->insertRecord((const char*)&dataIdxInfo, rid);

    dbHandle.refreshHandle();

    // Build Up Index
    RETURNIF(IndexHandler::instance()->CreateIndex(relName.c_str(),
                                                   indexCount,
                                                   attrData.attrType,
                                                   attrData.attrLength));
    SingleIndexHandler indexHandle;
    // 把当前所有行的对应列的值放进B+树
    RETVAL rc;
    auto records = retrieveRecords(relName, rc);
    RETURNIF(IndexHandler::instance()->OpenIndex(relName.c_str(), indexCount, indexHandle));
    for (auto it = records.begin(); it != records.end(); ++it) {
        RecordID rid = it->first;
        RecordDescriptor r = it->second;
        AttrValue v = r[attrName.attrName];
        char* data;
        if(v.isNull)
            continue;
        switch(v.type) {
            case T_INT: data = (char*)&(v.i); break;
            case T_FLOAT: data = (char*)&(v.f); break;
            case T_STRING: data = (char*)(v.s.c_str()); break;
            case T_DATE: data = (char*)(v.s.c_str()); break;
        }
        indexHandle.InsertEntry(data, rid);
    }
    return RETVAL_OK;
}

RETVAL SystemManager::dropIndex(string relName, string idxName) {
    /*
        删除一个索引分为3个部分
        1、 在attrcat中把indexNo部分清零
        2、 由于在relcat中，indexCount列表示的是“当前列一共创建过的索引个数”，并且创建新的索引需要使用该值以避免问题，所以不应该修改relcat中的值
        3、 删掉索引文件
        4、 在idxcat中删去对应行
    */
    if (!hasRelation(relName.c_str())){
        cerr << "[ERROR] No such relation." << endl;
        return RETVAL_ERR;
    }
    if (!hasIndex(relName.c_str(), idxName.c_str())){
        cerr << "[ERROR] No such index name." << endl;
        return RETVAL_ERR;
    }

    RecordID indexRID;
    char attrName[MAX_NAME + 1] = {};
    for (int i = 0, lim = dbHandle.indexes.size(); i < lim; ++i)
        if (strcmp(dbHandle.indexes[i].idxName, idxName.c_str()) == 0 && strcmp(dbHandle.indexes[i].relName, relName.c_str()) == 0){
            strcpy(attrName, dbHandle.indexes[i].attrName);
            indexRID = dbHandle.indexRecordIDs[i];
            break;
        }

    DataAttrInfo attrData;
    RecordID attrRID;
    for (int i = 0, lim = dbHandle.attributes.size(); i < lim; ++i)
        if (strcmp(dbHandle.attributes[i].attrName, attrName) == 0 && strcmp(dbHandle.attributes[i].relName, relName.c_str()) == 0){
            attrRID = dbHandle.attributeRecordIDs[i];
            attrData = dbHandle.attributes[i];
            break;
        }

    int indexNo = attrData.indexNo;
    // 在attrcat中清零indexNo部分
    attrData.indexNo = 0;
    SingleFileHandler *fileHandler = recordManager->openFile(kDefaultAttrCatName);
    Record record(attrRID, (char*)(&attrData), sizeof (DataAttrInfo));
    fileHandler->updateRecord(record);
    recordManager->closeFile();
    // 删除索引文件
    RETURNIF(IndexHandler::instance()->DestroyIndex(relName.c_str(), indexNo));
    // 在idxcat中删去对应行
    fileHandler = recordManager->openFile(kDefaultIdxCatName);
    int pag, slt;
    indexRID.getPageID(pag);
    indexRID.getSlotID(slt);
    RETURNIF(fileHandler->deleteRecord(indexRID));
    recordManager->closeFile();

    dbHandle.refreshHandle();
    return RETVAL_OK;
}

RETVAL SystemManager::load(const char *relName, const char *fileName) {
    return 0;
}

RETVAL SystemManager::help() {
    if(!hasOpenDB) {
        cerr << "[ERROR] Please Open DB first." << endl;
        return RETVAL_ERR;
    }
    RETURNIF(dbHandle.help());
    return RETVAL_OK;
}

std::vector<std::vector<string>> SystemManager::qHelp()
{
    return dbHandle.qHelp();
}

RETVAL SystemManager::help(const char *relName) {
    if(!hasOpenDB) {
        cerr << "[ERROR] Please Open DB first." << endl;
        return RETVAL_ERR;
    }
    RETURNIF(dbHandle.help(relName));
    return RETVAL_OK;
}

std::vector<std::vector<string> > SystemManager::qHelp(const char *relName)
{
    return dbHandle.qHelp(relName);
}

RETVAL SystemManager::set(const char *paramName, const char *value) {
    return 0;
}

SystemManager *SystemManager::instance() {
    if(systemManager != nullptr)
        return systemManager;
    systemManager = new SystemManager();
    return systemManager;
}

void SystemManager::resetInstance() {
    FileHandler::resetInstance();
}


RETVAL SystemManager::Select(vector<AttributeTree::AttributeDescriptor> attrs,
                         vector<std::string> rels,
                         vector<ComparisonTree::ComparisonDescriptor> coms) {
    RETVAL rc = RETVAL_OK;
    vector<RecordDescriptor> records = select(attrs, rels, coms, rc);
    RETURNIF(rc);
    if (attrs.empty()){
        int attrCount;
        DataAttrInfo* dataAttrInfo;
        for (auto rel : rels){
            RETURNIF(dbHandle.fillAttributesFromTable(rel.c_str(), attrCount, dataAttrInfo));
            for (int i = 0; i < attrCount; ++i)
                attrs.push_back((AttributeTree::AttributeDescriptor){string(rels.size()>1? rel : ""), string(dataAttrInfo[i].attrName)});
            delete[] dataAttrInfo;
        }
    }
    if(records.empty()) {
        Printer::printHeader(attrs);
        return RETVAL_OK;
    }
    Printer::printHeader(attrs);
    Printer::printBody(records);
    return RETVAL_OK;
}


/*
    SELECT <selector> FROM <tablelist> (WHERE <whereClause>)
    selector:   attrs
    tablelist:  rels
    whereClause:    coms
*/
vector<RecordDescriptor> SystemManager::select(std::vector<AttributeTree::AttributeDescriptor> attrs,
                         std::vector<std::string> rels,
                         std::vector<ComparisonTree::ComparisonDescriptor> coms, RETVAL& rc) {
    if (!checkRelations(rels)) {    // 确认存在rels表
        rc = RETVAL_ERR;
        return vector<RecordDescriptor>();
    }
    if (!checkAttributes(attrs, rels)) {    // 确认attrs都在rels表里
        rc = RETVAL_ERR;
        return vector<RecordDescriptor>();
    }
    if (!checkComparisons(coms, rels)) {    // 确认coms都在rels表里
        rc = RETVAL_ERR;
        return vector<RecordDescriptor>();
    }

    // Divide comparisons into 2 parts
    vector<Comparison> inrel_coms;
    vector<Comparison> crossrel_coms;
    for (const auto &com : coms)
        if (com.isAttrCmp == true && com.attr.relName != com.attr2.relName)
            crossrel_coms.push_back(com);   // 跨表比较
        else
            inrel_coms.push_back(com);      // 同表比较

    // Comparisons in the same relation
    // 对于每个
    vector<vector<RecordDescriptor>> validRecords;
    for (auto & rel : rels) {
        auto out = retrieveRecordsByIndex(rel, inrel_coms, rc);
        validRecords.push_back(out);
    }
    vector<RecordDescriptor> output;
    iterateCrossProduct(validRecords, attrs, rels, crossrel_coms, 0, output);
    return output;
}

/*
    得到表连接的笛卡尔积
*/
void SystemManager::iterateCrossProduct(vector<vector<RecordDescriptor>> &records,
                                        vector<AttributeTree::AttributeDescriptor> attrs,
                                        vector<string> &rels,
                                        vector<SystemManager::Comparison> &coms,
                                        int depth,
                                        vector<RecordDescriptor>& output) {
    static vector<RecordDescriptor> crossproduct;
    static vector<int> com_rels1;       // 约束条件i的第一个attr属于哪个表
    static vector<int> com_rels2;

    // Check a cross-product
    if (depth == records.size()) {
        bool flag = true;
        for (int i = 0; i < coms.size(); ++i) {
            Comparison &com = coms[i];
            RecordDescriptor &attr1 = crossproduct[com_rels1[i]];
            RecordDescriptor &attr2 = crossproduct[com_rels2[i]];
            if (!compare(attr1[com.attr.attrName], attr2[com.attr2.attrName], com.op)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            // Print
            RecordDescriptor recordDescriptor;
            if (!attrs.empty()) {
                for (const auto& record : crossproduct) {
                    RecordDescriptor rr = record.filteredByAttributeName(attrs);
                    recordDescriptor = recordDescriptor.concatenate(rr);
                }
            } else {
                for (const auto &record : crossproduct)
                    recordDescriptor = recordDescriptor.concatenate(record);
            }
            output.push_back(recordDescriptor);
        }
    } else {
        // Init
        if (depth == 0) {
            crossproduct = vector<RecordDescriptor>(records.size());
            com_rels1 = vector<int>();
            com_rels2 = vector<int>();
            for (const auto &com : coms) {
                for (int i = 0; i < rels.size(); ++i) {
                    if (rels[i] == com.attr.relName)
                        com_rels1.push_back(i);
                    if (rels[i] == com.attr2.relName)
                        com_rels2.push_back(i);
                }
            }
        }
        for (const auto &record : records[depth]) {
            crossproduct[depth] = record;
            iterateCrossProduct(records, attrs, rels, coms, depth + 1, output);
        }
    }
}

/*
    向relName里插入一条Record，它的值列表为vals
    如果attrs == NULL，说明是直接插入全部数值
    否则只插入限定的attrs，其他的做非空判断，填入默认值

    TODO
    如果主键存在索引，就在索引里找重复
    否则扫描文件，寻找是否有重复。如果没有才可插入
*/
RETVAL SystemManager::Insert(std::string relName, std::vector<std::string>* attrs, std::vector<AttrValue> vals) {
    if (!hasRelation(relName.c_str())) {
        cerr << "[ERROR] No such relation." << endl;
        return RETVAL_ERR;
    }
    RETVAL rc;
    RecordDescriptor descriptor;
    if (attrs == NULL)
        descriptor = RecordDescriptor::createRecordDescriptor(relName, vals, rc);
    else
        descriptor = RecordDescriptor::createRecordDescriptor(relName, *attrs, vals, rc);
    
    if(rc != RETVAL_OK) {
        return rc;
    }
    SingleFileHandler *fileHandle = FileHandler::instance()->openFile(relName.c_str());
    Record record;
    rc = descriptor.toRecord(RecordID(), record);
    if(rc != RETVAL_OK) {
        return RETVAL_ERR;
    }
    RecordID rid;
    fileHandle->insertRecord(record.getData(), rid);

    // Check Index
    int attrCount;
    DataAttrInfo* dataAttrInfo;
    RETURNIF(dbHandle.fillAttributesFromTable(relName.c_str(), attrCount, dataAttrInfo));
    for(int i = 0; i < attrCount; ++i) {
        if(dataAttrInfo[i].indexNo != 0) {
            // Insert Index
            AttrValue v = descriptor[dataAttrInfo[i].attrName];
            char* data;
            if(v.isNull)
                continue;
            switch(v.type) {
                case T_INT: data = (char*)&(v.i); break;
                case T_FLOAT: data = (char*)&(v.f); break;
                case T_STRING: data = (char*)(v.s.c_str()); break;
                case T_DATE: data = (char*)(v.s.c_str()); break;
            }
            SingleIndexHandler indexHandle;
            RETURNIF(IndexHandler::instance()->OpenIndex(relName.c_str(), dataAttrInfo[i].indexNo, indexHandle));
            indexHandle.InsertEntry(data, rid);
        }
    }

        // void* data;
        // if(primaryValue.type == T_INT)
        //     data = (void*)&(primaryValue.i);
        // else if(primaryValue.type == T_FLOAT)
        //     data = (void*)&(primaryValue.f);
        // else
        //     data = (void*)(primaryValue.s.c_str());
        // SingleFileHandler *fileHandle = FileHandler::instance()->openFile(relName.c_str());
        // FileScan fileScan;
        // fileScan.openScan(*fileHandle,
        //                   primaryAttrInfo.attrType,
        //                   primaryAttrInfo.attrLength,
        //                   primaryAttrInfo.offset,
        //                   CmpOP::T_EQ, data);
        // Record record;
        // rc = fileScan.getNextRec(record);
        // if(rc != RETVAL_EOF) {
        //     cerr << "[ERROR] Primary Key Duplicate!" << endl;
        //     rc = RETVAL_ERR;
        // }
        // else
        //     rc = RETVAL_OK;

    delete []dataAttrInfo;
    return RETVAL_OK;
}

RETVAL SystemManager::Update(std::string relName,
                         AttributeTree::AttributeDescriptor attr,
                         AttrValue val,
                         std::vector<ComparisonTree::ComparisonDescriptor> coms) {
    vector<AttributeTree::AttributeDescriptor> attrs;
    vector<string> rels;
    attrs.push_back(attr);
    rels.push_back(relName);
    if (!checkRelations(rels)) {
        return RETVAL_ERR;
    }
    if (!checkAttributes(attrs, rels)) {
        return RETVAL_ERR;
    }
    if (!checkComparison(coms, relName)) {
        return RETVAL_ERR;
    }

    RETVAL rc;
    auto records = retrieveRecords(relName, rc);
    if(rc != RETVAL_OK) {
        printf("Inner Error!");
        return RETVAL_ERR;
    }

    // Check Out Key
    vector<string> aaa = split(attr.attrName, '_');

    if(aaa.size() == 2 && !aaa[0].empty() && !aaa[1].empty()) {
        vector<string> rel_tmp;
        rel_tmp.push_back(aaa[0]);
        vector<AttributeTree::AttributeDescriptor> a_tmp;
        if(!checkRelations(rel_tmp)) {
            printf("Invalid Relation Name for Update\n");
            return RETVAL_OK;
        }
        AttributeTree::AttributeDescriptor ad(aaa[0], aaa[1]);
        a_tmp.push_back(ad);
        if(!checkAttributes(a_tmp, rel_tmp)) {
            printf("Invalid Attribute Name for Update\n");
            return RETVAL_OK;
        }
        vector<ComparisonTree::ComparisonDescriptor> coms_tmp;
        ComparisonTree::ComparisonDescriptor c_tmp;
        c_tmp.isAttrCmp = false;
        c_tmp.op = T_EQ;
        c_tmp.attr = ad;
        c_tmp.val = val;
        coms_tmp.push_back(c_tmp);
        auto records_tmp = select(a_tmp, rel_tmp, coms_tmp, rc);
        if(records_tmp.empty()) {
            cerr << "No Such Value!" << endl;
            return RETVAL_ERR;
        }
    }


    // Check Primary Key
    int attrCount = 0;
    DataAttrInfo* dataAttrInfo = nullptr;
    DataAttrInfo primaryAttrInfo;
    bool isPrimaryKey = false;
    RETURNIF(dbHandle.fillAttributesFromTable(relName.c_str(), attrCount, dataAttrInfo));
    for(int i = 0; i < attrCount; ++i) {
        if(attr.attrName == string(dataAttrInfo[i].attrName)) {
            if(dataAttrInfo[i].isPrimaryKey) {
                isPrimaryKey = true;
                primaryAttrInfo = dataAttrInfo[i];
            }
            break;
        }
    }

    for(int i = 0; i < attrCount; ++i) {
        if(dataAttrInfo[i].attrName == attr.attrName) {
            AttrType t = dataAttrInfo[i].attrType;
            if(t != val.type) {
                cerr << "Incompatable Type!" << endl;
                return RETVAL_ERR;
            }
        }
    }

    vector<RecordDescriptor *> validRecords;
    RecordID recordID;
    SingleFileHandler *fileHandle;
    fileHandle = FileHandler::instance()->openFile(relName.c_str());
    for (auto it = begin(records); it != end(records); ++it) {
        if (isValid(coms, it->second, relName)) {
            if(!isPrimaryKey) {
                // Update Index
                for(int i = 0; i < attrCount; ++i) {
                    if(dataAttrInfo[i].indexNo != 0 && dataAttrInfo[i].attrName == attr.attrName) {
                        AttrValue v = it->second[dataAttrInfo[i].attrName];
                        char* data;
                        if(v.isNull)
                            continue;
                        switch(v.type) {
                            case T_INT: data = (char*)&(v.i); break;
                            case T_FLOAT: data = (char*)&(v.f); break;
                            case T_STRING: data = (char*)(v.s.c_str()); break;
                        }
                        SingleIndexHandler indexHandle;
                        RETURNIF(IndexHandler::instance()->OpenIndex(relName.c_str(),
                                                                     dataAttrInfo[i].indexNo,
                                                                     indexHandle));
                        indexHandle.DeleteEntry(data, it->first);
                    }
                }
                // Actually Update record
                it->second.assign(attr.attrName, val);
                Record record;
                rc = it->second.toRecord(it->first, record);
                if(rc != RETVAL_OK) {
                    printf("Inner Error!");
                    delete[] dataAttrInfo;
                    return RETVAL_ERR;
                }
                fileHandle->updateRecord(record);

                // Insert New Index
                for(int i = 0; i < attrCount; ++i) {
                    if(dataAttrInfo[i].indexNo != 0 && dataAttrInfo[i].attrName == attr.attrName) {
                        AttrValue v = it->second[attr.attrName];
                        char* data;
                        if(v.isNull)
                            continue;
                        switch(v.type) {
                            case T_INT: data = (char*)&(v.i); break;
                            case T_FLOAT: data = (char*)&(v.f); break;
                            case T_STRING: data = (char*)(v.s.c_str()); break;
                        }
                        SingleIndexHandler indexHandle;
                        RETURNIF(IndexHandler::instance()->OpenIndex(relName.c_str(),
                                                                     dataAttrInfo[i].indexNo,
                                                                     indexHandle));
                        indexHandle.InsertEntry(data, it->first);
                    }
                }
            }
            else {
                recordID = it->first;
                validRecords.push_back(&(it->second));
            }
        }
    }
    if(validRecords.empty())
        return 0;
    if(isPrimaryKey) {
        if(validRecords.size() > 1) {
            cerr << "Primary Key Duplicate!" << endl;
            delete[] dataAttrInfo;
            return RETVAL_ERR;
        }
        // Size = 1
        void* data;
        if(val.type == T_INT)
            data = (void*)&(val.i);
        else if(val.type == T_FLOAT)
            data = (void*)&(val.f);
        else
            data = (void*)(val.s.c_str());

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
            delete[] dataAttrInfo;
            return RETVAL_ERR;
        }
        // Delete Index
        for(int i = 0; i < attrCount; ++i) {
            if(dataAttrInfo[i].indexNo != 0 && dataAttrInfo[i].attrName == attr.attrName) {
                AttrValue v = (*(validRecords[0]))[attr.attrName];
                char* data;
                if(v.isNull)
                    continue;
                switch(v.type) {
                    case T_INT: data = (char*)&(v.i); break;
                    case T_FLOAT: data = (char*)&(v.f); break;
                    case T_STRING: data = (char*)(v.s.c_str()); break;
                }
                SingleIndexHandler indexHandle;
                RETURNIF(IndexHandler::instance()->OpenIndex(relName.c_str(),
                                                             dataAttrInfo[i].indexNo,
                                                             indexHandle));
                indexHandle.DeleteEntry(data, recordID);
            }
        }

        // Assign
        validRecords[0]->assign(attr.attrName, val);
        rc = validRecords[0]->toRecord(recordID, record);
        if(rc != RETVAL_OK) {
            printf("Inner Error!");
            delete[] dataAttrInfo;
            return RETVAL_ERR;
        }
        fileHandle->updateRecord(record);

        // Update Index
        for(int i = 0; i < attrCount; ++i) {
            if(dataAttrInfo[i].indexNo != 0 && dataAttrInfo[i].attrName == attr.attrName) {
                AttrValue v = (*(validRecords[0]))[attr.attrName];
                char* data;
                if(v.isNull)
                    continue;
                switch(v.type) {
                    case T_INT: data = (char*)&(v.i); break;
                    case T_FLOAT: data = (char*)&(v.f); break;
                    case T_STRING: data = (char*)(v.s.c_str()); break;
                }
                SingleIndexHandler indexHandle;
                RETURNIF(IndexHandler::instance()->OpenIndex(relName.c_str(),
                                                             dataAttrInfo[i].indexNo,
                                                             indexHandle));
                indexHandle.DeleteEntry(data, recordID);
            }
        }

    }
    delete[] dataAttrInfo;
    return 0;
}

RETVAL SystemManager::Delete(std::string relName, std::vector<ComparisonTree::ComparisonDescriptor> coms) {
    // Check relation
    if (!hasRelation(relName.c_str())) {
        printf("No such relation\n");
        return RETVAL_ERR;
    }
    checkComparison(coms, relName);

    RETVAL rc;
    auto records = retrieveRecords(relName, rc);
    if(rc != RETVAL_OK) {
        printf("Error!");
        return RETVAL_ERR;
    }

    int attrCount;
    DataAttrInfo* dataAttrInfo;
    RETURNIF(dbHandle.fillAttributesFromTable(relName.c_str(), attrCount, dataAttrInfo));
    SingleFileHandler *fileHandle = FileHandler::instance()->openFile(relName.c_str());
    for (auto it = begin(records); it != end(records); ++it) {
        if (isValid(coms, it->second, relName)) {
            RecordID recordID = it->first;
            fileHandle->deleteRecord(recordID);
            // Delete Index
            for(int i = 0; i < attrCount; ++i) {
                if(dataAttrInfo[i].indexNo != 0) {
                    AttrValue v = it->second[dataAttrInfo[i].attrName];
                    char* data;
                    if(v.isNull)
                        continue;
                    switch(v.type) {
                        case T_INT: data = (char*)&(v.i); break;
                        case T_FLOAT: data = (char*)&(v.f); break;
                        case T_STRING: data = (char*)(v.s.c_str()); break;
                    }
                    SingleIndexHandler indexHandle;
                    RETURNIF(IndexHandler::instance()->OpenIndex(relName.c_str(),
                                                                 dataAttrInfo[i].indexNo,
                                                                 indexHandle));
                    indexHandle.DeleteEntry(data, recordID);
                }
            }

        }
    }

    delete []dataAttrInfo;
    return 0;
}


bool SystemManager::checkRelations(const vector<string> &relations) {
    for (const auto &rel : relations)
        if (!hasRelation(rel.c_str())) {
            printf("No relation '%s'\n", rel.c_str());
            return false;
        }
    return true;
}

bool SystemManager::checkAttributes(vector<SystemManager::Attribute> &attributes, vector<string> &relations) {
    for (auto &attr : attributes)
        if (attr.relName.empty()) {
            int count = 0;
            for (const auto &rel : relations)
                if (hasAttribute(rel.c_str(), attr.attrName.c_str())) {
                    count += 1;
                    attr.relName = rel;
                }
            if (count == 0) {
                printf("Not found attribute '%s'\n", attr.attrName.c_str());
                return false;
            } else if (count > 1) {
                printf("Too many attribute named '%s'\n", attr.attrName.c_str());
                return false;
            }
        } else {
            if (!hasRelation(attr.relName.c_str())) {
                printf("No relation '%s'\n", attr.relName.c_str());
                return false;
            }
            if (!hasAttribute(attr.relName.c_str(), attr.attrName.c_str())) {
                printf("No attribute '%s', in relation '%s'\n", attr.attrName.c_str(), attr.relName.c_str());
                return false;
            }
        }
    return true;
}


bool SystemManager::checkComparison(std::vector<Comparison> &coms, std::string &relation) {
    for (auto &com : coms) {
        if (com.attr.relName.empty() || com.attr.relName == relation) {
            if (!hasAttribute(relation.c_str(), com.attr.attrName.c_str())) {
                printf("Not found attribute '%s'\n", com.attr.attrName.c_str());
                return false;
            }
            if (com.attr.relName.empty())
                com.attr.relName = relation;
        } else {
            printf("Attributes should be in the same relation\n");
            return false;
        }
    }
    return true;
}

bool SystemManager::checkComparisons(vector<SystemManager::Comparison> &coms, vector<string> &relations) {
    for (auto &com : coms) {
        if (com.attr.relName.empty()) {
            int count = 0;
            for (const auto &rel : relations) {
                if (hasAttribute(rel.c_str(), com.attr.attrName.c_str())) {
                    count += 1;
                    com.attr.relName = rel;
                }
            }
            if (count == 0) {
                printf("Not found attribute '%s'\n", com.attr.attrName.c_str());
                return false;
            } else if (count > 1) {
                printf("Too many attribute named '%s'\n", com.attr.attrName.c_str());
                return false;
            }
        } else {
            bool exist = false;
            for (const auto &rel : relations)
                if (rel == com.attr.relName)
                    exist = true;
            if (!exist) {
                printf("In where clause, '%s' is not in relation list", com.attr.relName.c_str());
                return false;
            }
            if (!hasAttribute(com.attr.relName.c_str(), com.attr.attrName.c_str())) {
                printf("No attribute '%s', in relation '%s'\n", com.attr.attrName.c_str(), com.attr.relName.c_str());
                return false;
            }
        }

        if (com.isAttrCmp) {
            if (com.attr2.relName.empty()) {
                int count = 0;
                for (const auto &rel : relations) {
                    if (hasAttribute(rel.c_str(), com.attr2.attrName.c_str())) {
                        count += 1;
                        com.attr2.relName = rel;
                    }
                }
                if (count == 0) {
                    printf("Not found attribute '%s'\n", com.attr2.attrName.c_str());
                    return false;
                } else if (count > 1) {
                    printf("Too many attribute named '%s'\n", com.attr2.attrName.c_str());
                    return false;
                }
            } else {
                bool exist = false;
                for (const auto &rel : relations)
                    if (rel == com.attr2.relName)
                        exist = true;
                if (!exist) {
                    printf("In where clause, '%s' is not in relation list", com.attr2.relName.c_str());
                    return false;
                }
                if (!hasAttribute(com.attr2.relName.c_str(), com.attr2.attrName.c_str())) {
                    printf("No attribute '%s', in relation '%s'\n", com.attr2.attrName.c_str(), com.attr2.relName.c_str());
                    return false;
                }
            }
        }
    }
    return true;
}

// Only check one relation's validation
// Only check type including NULL excluding Primary Key
bool SystemManager::isValid(vector<SystemManager::Comparison> &coms, RecordDescriptor &record, const string &relation) {
    for (auto const &com : coms)
        if (!com.isAttrCmp && com.attr.relName == relation) {
            auto value = record[com.attr.attrName];
            if(com.op == T_ISNULL) {
                if(value.isNull)
                    return true;
                else
                    return false;
            }
            else if (com.op == T_ISNOTNULL){
                if(value.isNull)
                    return false;
                else
                    return true;
            }
            else if ((value.type == AttrType::T_INT || value.type == AttrType::T_FLOAT)
                && (com.val.type == AttrType::T_INT || com.val.type == AttrType::T_FLOAT)) {
                float f1 = value.type == AttrType::T_INT ? value.i : value.f;
                float f2 = com.val.type == AttrType::T_INT ? com.val.i : com.val.f;
                if (!compare(f1, f2, com.op))
                    return false;
            } else if (value.type == AttrType::T_STRING && com.val.type == AttrType::T_STRING) {
                if (!compare(value.s, com.val.s, com.op))
                    return false;
            } else {
                printf("Incompatible type!\n");
                exit(0);
            }
        }
    // TODO: isAttrCmp = true
    return true;
}

RETVAL SystemManager::qUpdate(const std::string& relName, const RecordID &recordID,
                          int attrNo, const AttrValue &newVal) {
    // TODO: Check Here!
    RETVAL rc = RETVAL_OK;
    RecordDescriptor recordDescriptor = dbHandle.retrieveOneRecord(relName, recordID, rc);
    RETURNIF(rc);
    recordDescriptor.attrVals[attrNo] = newVal;
    Record record;
    rc = recordDescriptor.toRecord(recordID, record);
    RETURNIF(rc);
    SingleFileHandler* fileHandle = recordManager->openFile(relName.c_str());
    RETURNIF(fileHandle->updateRecord(record));
    return 0;
}

/*
    根据表名、约束名获得查找表项
    coms: 如 tablea.attr1 op constant
    首先找到其中的一列，这一列是和常量的比较，所以可以通过索引进行初筛
    如果没有这种列，就先把所有的行都取出
    接着进行暴力筛选
*/
vector<RecordDescriptor> SystemManager::retrieveRecordsByIndex(string relName,
                                                               const vector<SystemManager::Comparison> &coms,
                                                               RETVAL &rc) {
    // First get Indices Map
    int attrCount;
    DataAttrInfo* dataAttrInfo;
    dbHandle.fillAttributesFromTable(relName.c_str(), attrCount, dataAttrInfo);     // dataAttrInfo保存了这个relation表中，每一列的label信息
    map<string, int> indexNoMap;
    for(int i = 0; i < attrCount; ++i) {
        // indexNoMap保存了<attrName, id>的二元对，方便读取列label信息
        indexNoMap[string(dataAttrInfo[i].attrName)] = dataAttrInfo[i].indexNo;
    }

    vector<RecordDescriptor> validRecords;
    vector<RecordDescriptor> output;
    int i = 0;
    for(i = 0; i < coms.size(); ++i) {
        const auto& com = coms[i];
        if (com.attr.relName != relName)
            continue;
        if(!com.isAttrCmp && com.op != T_ISNULL && com.op != T_ISNOTNULL &&
                indexNoMap[com.attr.attrName] != 0) {   // 不是Attr-Attr比较，不是空-判别   ->   是和常量的比较
            // Use Index
            AttrValue v = com.val;
            char* data;
            if(v.isNull)
                continue;
            switch(v.type) {
                case T_INT: data = (char*)&(v.i); break;
                case T_FLOAT: data = (char*)&(v.f); break;
                case T_STRING: data = (char*)(v.s.c_str()); break;
                case T_DATE: data = (char*)(v.s.c_str()); break;
            }


            SingleIndexHandler indexHandle;
            IndexHandler::instance()->OpenIndex(relName.c_str(), indexNoMap[com.attr.attrName], indexHandle);
            auto ret = indexHandle.ScanIndex(data, com.op);
            SingleFileHandler *f = FileHandler::instance()->openFile(relName.c_str());
            for(const auto& rid : ret) {
                Record rrr;
                f->getRecord(rid, rrr);
                char* pData = rrr.getData();
                RecordDescriptor recordDescriptor;
                // Iterate throughout all the attributes
                for(int i = 0; i < attrCount; ++i) {
                    AttrValue descriptor;
                    int offset = dataAttrInfo[i].offset;

                    AttrType attrType = dataAttrInfo[i].attrType;
                    if(attrType == T_INT) {
                        int data = ((int*)(pData+offset))[0];
                        descriptor.i = data;
                    } else if(attrType == T_FLOAT) {
                        float data = ((float*)(pData+offset))[0];
                        descriptor.f = data;
                    } else {
                        int attrLength = dataAttrInfo[i].attrLength;
                        char data[attrLength];
                        memset(data, 0, attrLength);
                        memcpy(data, pData + offset, attrLength);
                        descriptor.s = string(data);
                    }
                    descriptor.type = attrType;
                    recordDescriptor.attrNames.push_back(dataAttrInfo[i].attrName);
                    recordDescriptor.attrVals.push_back(descriptor);
                }
                int nullVectorBase = dataAttrInfo[attrCount-1].offset + dataAttrInfo[attrCount-1].attrLength;
                for(int i = 0; i < attrCount; ++i) {
                    char t;
                    memcpy((void*)&t, pData + nullVectorBase + i, 1);
                    if(t == 1 && relName != string(kDefaultAttrCatName) && relName != string(kDefaultRelCatName))
                        recordDescriptor.attrVals[i].isNull = true;
                    else
                        recordDescriptor.attrVals[i].isNull = false;
                }
                recordDescriptor.relName = relName;
                validRecords.push_back(recordDescriptor);
            }

            break;
        }
    }
    if(i == coms.size()) {
        // Index Not Used, valid records equal to all records
        auto records = retrieveRecords(relName, rc);
        for (auto it = begin(records); it != end(records); ++it) {
            validRecords.push_back(it->second);
        }
    }
    for(int j = 0; j < validRecords.size(); ++j) {
        bool flag = true;
        auto record = validRecords[j];
        for(int k = 0; k < coms.size(); ++k) {
            if(k == i)
                continue;   // Index
            const auto& com = coms[k];
            if (com.attr.relName != relName)
                continue;
            if (!com.isAttrCmp) {
                if(record[com.attr.attrName].isNull && com.op == T_ISNULL) {
                    flag &= true;
                }
                else if(record[com.attr.attrName].isNull) {
                    flag = false;
                }
                else 
                    flag &= compare(record[com.attr.attrName], com.val, com.op);
            } else {
                flag &= compare(record[com.attr.attrName], record[com.attr2.attrName], com.op);
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            output.push_back(record);
        }
    }
    delete []dataAttrInfo;
    return output;
}
