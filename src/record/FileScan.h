#ifndef DATABASE_FILESCAN_H
#define DATABASE_FILESCAN_H


#include "SingleFileHandler.h"

class FileScan {
public:


    FileScan();

    ~FileScan();

    RETVAL openScan(const SingleFileHandler &fileHandle,
                AttrType attrType,
                int attrLength,
                int attrOffset,
                CmpOP compOP,
                void *value);
    RETVAL openScan(const SingleFileHandler &fileHandle);

    RETVAL getNextRec(Record &record);
    RETVAL getNextRec(Record &record, RecordID &recordID);

    RETVAL closeScan();

private:
    bool isOpened;
    int attrLength;
    int attrOffset;
    void *value;
    const SingleFileHandler *fileHandle;
    AttrType attrType;
    CmpOP op;

    int nextPageID;
    int nextSlotID;


    bool isValid(Record &record);

};


#endif //DATABASE_FILESCAN_H
