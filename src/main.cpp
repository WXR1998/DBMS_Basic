
#include "system/SystemManager.h"

using namespace std;

struct yy_buffer_state;
extern int yyparse();
extern void yy_switch_to_buffer(yy_buffer_state *);
extern yy_buffer_state *yy_scan_string(const char *);

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<std::string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}


void runSQL(const char *sql) {
    delete Tree::tree;
    Tree::tree = nullptr;
    yy_switch_to_buffer(yy_scan_string(sql));
    yyparse();
}

int main() {
    string buffer;
    string message;
    printf("\n>> ");
    while(getline(cin, message)) {
        if(!message.empty()) {
            if(message[message.size()-1] == ';') {
                buffer += message;
                runSQL(buffer.c_str());
                buffer.clear();
                printf("\n>> ");
            }
            else
                buffer += message;
        }
    }
    SystemManager::resetInstance();
    return 0;
}