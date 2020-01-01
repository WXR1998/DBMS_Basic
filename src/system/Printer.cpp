#include <string.h>
#include <cstdio>
#include "Printer.h"
#include "RecordDescriptor.h"
using namespace std;

string getHex(string str){
    char buf[100] = {};
    string res;
    for (int i = 0; i < 6 && i < str.size(); ++i){
        sprintf(buf, "%x ", (unsigned char)str.c_str()[i]);
        res = res + string(buf);
    }
    return res;
}

void Printer::printHeader(std::vector<AttributeTree::AttributeDescriptor> attrs, ostream &c) {
    for(int i = 0; i < attrs.size(); ++i)
    {
        if(attrs[i].relName.empty()) {
            c << attrs[i].attrName << " | ";
        }
        else {
            c << attrs[i].relName << "." << attrs[i].attrName << " | ";
        }
    }
    c << endl;
    for (int i = 0; i < 80; ++i)
        c << "=";
    c << endl;
}

void Printer::printFooter(ostream &c) {
    for (int i = 0; i < 80; ++i)
        c << "=";
    c << endl;
}

void Printer::printAll(vector<RecordDescriptor> recordDescriptors, ostream& c) {
    if(recordDescriptors.empty())
        return;
    // First Print Header
    for(int i = 0; i < recordDescriptors[0].attrNames.size(); ++i)
        c << recordDescriptors[0].attrNames[i] << " | ";
    c << endl;
    for (int i = 0; i < 80; ++i)
        c << "=";
    c << endl;
    for(const auto& recordDescriptor : recordDescriptors) {
        for(int i = 0; i < recordDescriptor.attrVals.size(); ++i) {
            const auto& val = recordDescriptor.attrVals[i];
            if(val.isNull)
                c << "NULL" << " | ";
            else {
                switch(val.type) {
                    case T_INT :
                        c << val.i << " | ";
                        break;
                    case T_FLOAT :
                        c << val.f << " | ";
                        break;
                    case T_STRING :
                        c << val.s << " | ";
                        break;
                    case T_DATE :
                        c << val.s << " | ";
                        break;
                    case T_NONE :
                        c << getHex(val.s) << " | ";
                        break;
                }
            }
        }
        c << endl;
    }
}

void Printer::printBody(std::vector<RecordDescriptor> recordDescriptors, ostream &c) {
    for(const auto& recordDescriptor : recordDescriptors) {
        for(int i = 0; i < recordDescriptor.attrVals.size(); ++i) {
            const auto& val = recordDescriptor.attrVals[i];
            if(val.isNull)
                c << "NULL" << " | ";
            else {
                switch(val.type) {
                    case T_INT :
                        c << val.i << " | ";
                        break;
                    case T_FLOAT :
                        c << val.f << " | ";
                        break;
                    case T_STRING :
                        c << val.s << " | ";
                        break;
                    case T_DATE :
                        c << val.s << " | ";
                        break;
                    case T_NONE :
                        c << getHex(val.s) << " | ";
                        break;
                }
            }
        }
        c << endl;
    }
}

void Printer::printBody(RecordDescriptor recordDescriptor, ostream &c) {
    for(int i = 0; i < recordDescriptor.attrVals.size(); ++i) {
        const auto& val = recordDescriptor.attrVals[i];
        if(val.isNull)
            c << "NULL" << " | ";
        else {
            switch(val.type) {
                case T_INT :
                    c << val.i << " | ";
                    break;
                case T_FLOAT :
                    c << val.f << " | ";
                    break;
                case T_STRING :
                    c << val.s << " | ";
                    break;
                case T_DATE :
                    c << val.s << " | ";
                    break;
                case T_NONE :
                    c << getHex(val.s) << " | ";
                    break;
            }
        }
    }
    c << endl;
}

void Printer::printBody(std::vector<double> vals, ostream &c) {
    for(int i = 0; i < vals.size(); ++i)
        c << vals[i] << " | ";
    c << endl;
}

void Printer::printBody(AttrValue val, std::vector<double> vals, ostream &c) {
    switch(val.type) {
        case T_INT :
            c << val.i << " | ";
            break;
        case T_FLOAT :
            c << val.f << " | ";
            break;
        case T_STRING :
            c << val.s << " | ";
            break;
        case T_DATE :
            c << val.s << " | ";
            break;
        case T_NONE :
            c << getHex(val.s) << " | ";
            break;
    }
    for(int i = 0; i < vals.size(); ++i)
        c << vals[i] << " | ";
    c << endl;
}
