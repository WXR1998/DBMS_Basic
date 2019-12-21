#ifndef DATABASE_PRINTER_H
#define DATABASE_PRINTER_H

#include <vector>
#include "../global.h"
#include "../parser/Tree.h"
#include "RecordDescriptor.h"


class Printer {
public:
    Printer() {}
    ~Printer(){}
    static void printHeader(std::vector<AttributeTree::AttributeDescriptor> attrs, std::ostream& c = std::cout);
    static void printBody(std::vector<RecordDescriptor> recordDescriptors, std::ostream &c = std::cout);
    static void printBody(RecordDescriptor recordDescriptor, std::ostream &c = std::cout);
    static void printBody(std::vector<double> vals, std::ostream &c = std::cout);
    static void printBody(AttrValue val, std::vector<double> vals, std::ostream &c = std::cout);
    static void printAll(std::vector<RecordDescriptor> recordDescriptors, std::ostream& c = std::cout);
    static void printFooter(std::ostream& c = std::cout);
private:

};


#endif //DATABASE_PRINTER_H
