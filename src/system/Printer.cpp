#include <string.h>
#include "Printer.h"
#include "RecordDescriptor.h"
using namespace std;

void Printer::printHeader(std::vector<AttributeTree::AttributeDescriptor> attrs, ostream &c) {
    for(int i = 0; i < attrs.size(); ++i)
    {
        if(attrs[i].relName.empty()) {
            c << attrs[i].attrName << "\t\t";
        }
        else {
            c << attrs[i].relName << "." << attrs[i].attrName << "\t\t";
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
        c << recordDescriptors[0].attrNames[i] << "\t\t";
    c << endl;
    for(const auto& recordDescriptor : recordDescriptors) {
        for(int i = 0; i < recordDescriptor.attrVals.size(); ++i) {
            const auto& val = recordDescriptor.attrVals[i];
            if(val.isNull)
                c << "NULL" << "\t\t";
            else {
                switch(val.type) {
                    case T_INT :
                        c << val.i << "\t\t";
                        break;
                    case T_FLOAT :
                        c << val.f << "\t\t";
                        break;
                    case T_STRING :
                        c << val.s << "\t\t";
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
                c << "NULL" << "\t\t";
            else {
                switch(val.type) {
                    case T_INT :
                        c << val.i << "\t\t";
                        break;
                    case T_FLOAT :
                        c << val.f << "\t\t";
                        break;
                    case T_STRING :
                        c << val.s << "\t\t";
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
            c << "NULL" << "\t\t";
        else {
            switch(val.type) {
                case T_INT :
                    c << val.i << "\t\t";
                    break;
                case T_FLOAT :
                    c << val.f << "\t\t";
                    break;
                case T_STRING :
                    c << val.s << "\t\t";
                    break;
            }
        }
    }
    c << endl;
}

void Printer::printBody(std::vector<double> vals, ostream &c) {
    for(int i = 0; i < vals.size(); ++i)
        c << vals[i] << "\t\t";
    c << endl;
}

void Printer::printBody(AttrValue val, std::vector<double> vals, ostream &c) {
    switch(val.type) {
        case T_INT :
            c << val.i << "\t\t";
            break;
        case T_FLOAT :
            c << val.f << "\t\t";
            break;
        case T_STRING :
            c << val.s << "\t\t";
            break;
    }
    for(int i = 0; i < vals.size(); ++i)
        c << vals[i] << "\t\t";
    c << endl;
}
