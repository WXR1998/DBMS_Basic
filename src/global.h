//
// Created by MaYe on 2015/10/23.
//

#ifndef DATABASE_GLOBAL_H
#define DATABASE_GLOBAL_H
#include <iostream>
#include <cstdio>
#include <cassert>
#include <sstream>
#include <vector>
#include <regex>

#define MAX_PAGE_NUMBER 4096
#define PAGE_HEADER_SIZE 48
#define MAX_NAME 42
#define MAX_RECORD_SIZE 4096
#define MAX_CHECK_SIZE 10

enum CmpOP {
    T_EQ, T_LT, T_GT, T_LE, T_GE, T_NE, T_NO, T_ISNOTNULL, T_ISNULL, T_IN
};

enum AttrType {
    T_INT, T_FLOAT, T_STRING, T_DATE
};


template<typename T>
bool compare(const T &a, const T &b, CmpOP op) {
    switch (op) {
        case CmpOP::T_EQ:
            return a == b;
        case CmpOP::T_LT:
            return a < b;
        case CmpOP::T_GT:
            return a > b;
        case CmpOP::T_LE:
            return a <= b;
        case CmpOP::T_GE:
            return a >= b;
        case CmpOP::T_NE:
            return a != b;
        default:
            return false;
    }
}

template<typename T>
static bool compareIn(const T &a, const std::vector<T>& b) {
    for(const auto v : b) {
        if(a == v)
            return true;
    }
    return false;
}

struct AttrValue {
    AttrType type;
    int i;
    float f;
    std::string s;
    bool isNull;

    // Definitions are in Tree.cpp
    bool operator ==(const AttrValue &val) const;
    bool operator !=(const AttrValue &val) const;
    bool operator >=(const AttrValue &val) const;
    bool operator <=(const AttrValue &val) const;
    bool operator > (const AttrValue &val) const;
    bool operator < (const AttrValue &val) const;
};

struct AttrInfo {
    char attrName[MAX_NAME + 1];
    int attrLength;
    AttrType attrType;
    int isPrimaryKey;
    int notNull;
};

struct DataAttrInfo {
    char relName[MAX_NAME + 1];     // 这个Attr在哪个Relation里
    char attrName[MAX_NAME + 1];    // 这个Attr的名称
    int offset;                     // 这个Attr在Record中的偏移量
    AttrType attrType;              // Attr的类型
    int attrLength;                 // Attr占用字节长度
    int indexNo;                    // Attr在Relation中的编号
    int isPrimaryKey;               // 是否为主键
    int notNull;                    // 是否为非空
};

struct DataRelInfo {
    char relName[MAX_NAME + 1];
    int recordSize;
    int attrCount;
    int indexCount;
};

typedef int RETVAL;

#define RETVAL_OK               0
#define RETVAL_ERR              1
#define RETVAL_EOF              2
#define RETVAL_NOREC            3
#define RETVAL_NOIDX            4

// Exit immediately if error occurs
#define RETURNIF(rc) do { RETVAL _x_ = (rc); if ((_x_) != RETVAL_OK) { PrintError(__LINE__, __FILE__, __func__); return _x_; }} while(0)


inline void PrintError(int line, const char* file, const char* func) {
    printf("Error occured, in line %d of file \"%s\", in function<%s>\n",
          line,
          file,
          func);
}

#define kDefaultDBPosition "./"
#define kDefaultRelCatName "relcat"
#define kDefaultAttrCatName "attrcat"
#define kDefaultCheckCatName "checkcat"

template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}


#endif //DATABASE_GLOBAL_H
