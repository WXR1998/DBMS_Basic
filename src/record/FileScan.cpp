#include <string.h>
#include "FileScan.h"

using std::string;

FileScan::FileScan() {
    isOpened = false;
    fileHandle = nullptr;
}

FileScan::~FileScan() {

}

RETVAL FileScan::openScan(const SingleFileHandler &fileHandle,
                      AttrType attrType,
                      int attrLength,
                      int attrOffset,
                      CmpOP compOP,
                      void *value) {
    if (isOpened)
        return RETVAL_ERR;
    this->isOpened = true;
    this->fileHandle = &fileHandle;
    this->attrType = attrType;
    this->attrLength = attrLength;
    this->attrOffset = attrOffset;
    this->op = compOP;
    this->value = value;
    nextPageID = 1;
    nextSlotID = 0;
    return RETVAL_OK;
}

RETVAL FileScan::openScan(const SingleFileHandler &fileHandle) {
    return openScan(fileHandle, AttrType::T_INT , 0, 0, CmpOP::T_NO , nullptr);
}

RETVAL FileScan::getNextRec(Record &record) {
    if (!isOpened)
        return RETVAL_ERR;
    while (nextPageID < fileHandle->getPageNumber()) {
        RecordID rid = RecordID(nextPageID, nextSlotID);
        RETVAL rc = fileHandle->getRecord(rid, record);
        nextSlotID += 1;
        if (nextSlotID == fileHandle->getSlotNumber()) {
            nextPageID += 1;
            nextSlotID = 0;
        }
        if (rc == RETVAL_OK) {
            if (op == CmpOP::T_NO || isValid(record)) {
                return RETVAL_OK;
            } else {
                continue;
            }
        } else if (rc == RETVAL_NOREC) {
            continue;
        } else {
            return RETVAL_ERR;
        }
    };
    isOpened = false;
    return RETVAL_EOF;
}

RETVAL FileScan::closeScan() {
    isOpened = false;
    return RETVAL_OK;
}

bool FileScan::isValid(Record &record) {
    if (op == CmpOP::T_NO)
        return true;
    char *pData = record.getData();
    pData += attrOffset;
    if (attrType == AttrType::T_INT) {
        return compare<int>(((int *) pData)[0], ((int *) value)[0], op);
    } else if (attrType == AttrType::T_FLOAT) {
        return compare<float>(((float *) pData)[0], ((float *) value)[0], op);
    } else if (attrType == AttrType::T_STRING) {
        string a = string(pData);
        string b = string((char *) value);
        return compare<string>(a, b, op);
    }

    return false;
}

