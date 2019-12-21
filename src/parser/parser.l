%option caseless

%{
#include "tree.h"
#include "y.tab.hpp"
#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#include <cstdio>
#define __STRICT_ANSI__
#else
#include <cstdio>
#endif
#include <cstring>

char *get_text(const char *text) {
    int length = strlen(text);
    char *buffer = new char[length + 1];
    memcpy(buffer, text, (length + 1) * sizeof(char));
    return buffer;
}

void yyerror(const char *);

%}


DIGIT           [0-9]
INTEGER         {DIGIT}+
FLOAT           {DIGIT}+\.{DIGIT}*
IDENTIFIER      [a-z][a-z0-9_]*
WHITESPACE      [ \t\n]
STRING          (\"[^\"]*\")|(\'[^\']*\')

%%

","             { /*printf(", "); */ return yytext[0]; }
"("             { /*printf("( "); */ return yytext[0]; }
")"             { /*printf(") "); */ return yytext[0]; }
"."             { /*printf(". "); */ return yytext[0]; }
";"             { /*printf("; "); */ return yytext[0]; }
"*"             { /*printf("* "); */ return STAR; }
DATABASES       { /*printf("DATABASES "); */ return DATABASES; }
DEFAULT         { /*printf("DEFAULT "); */ return DEFAULT; }
CONSTRAINT      { /*printf("CONSTRAINT "); */ return CONSTRAINT; }
CHANGE          { /*printf("CHANGE "); */ return CHANGE; }
ALTER           { /*printf("ALTER "); */ return ALTER; }
ADD             { /*printf("ADD "); */ return ADD; }
RENAME          { /*printf("RENAME "); */ return RENAME; }
REFERENCES      { /*printf("REFERENCES "); */ return REFERENCES; }
DATE            { /*printf("DATE "); */ return DATE; }
"FOREIGN KEY"   { /*printf("FOREIGN_KEY "); */ return FOREIGN; }
CREATE          { /*printf("CREATE "); */ return CREATE; }
DROP            { /*printf("DROP "); */ return DROP; }
USE             { /*printf("USE "); */ return USE; }
SHOW            { /*printf("SHOW "); */ return SHOW; }
DATABASE        { /*printf("DATABASE "); */ return DATABASE; }
TABLE           { /*printf("TABLE "); */ return TABLE; }
TABLES          { /*printf("TABLES "); */ return TABLES; }
SELECT          { /*printf("SELECT "); */ return SELECT; }
DELETE          { /*printf("DELETE "); */ return DELETE; }
INSERT          { /*printf("INSERT "); */ return INSERT; }
UPDATE          { /*printf("UPDATE "); */ return UPDATE; }
VALUES          { /*printf("VALUES "); */ return VALUES; }
SET             { /*printf("SET "); */ return SET; }
FROM            { /*printf("FROM "); */ return FROM; }
INTO            { /*printf("INTO "); */ return INTO; }
WHERE           { /*printf("WHERE "); */ return WHERE; }
AND             { /*printf("AND "); */ return AND; }
"NOT NULL"      { /*printf("NOT_NULL "); */ return NOTNULL; }
"PRIMARY KEY"   { /*printf("PRIMARY_KEY "); */ return PRIMARY; }
DESC            { /*printf("DESC "); */ return DESC; }
INDEX           { /*printf("INDEX "); */ return INDEX; }
IS              { /*printf("IS "); */ return IS; }
NULL            { /*printf("NULL "); */ return T_NULL; }
int             { /*printf("int "); */ return KINT; }
float           { /*printf("float "); */ return KFLOAT; }
varchar         { /*printf("varchar "); */ return KVARCHAR; }
{FLOAT}         { /*printf("FLOAT "); */ sscanf(yytext, "%f", &yylval.fvalue); return FLOAT; }
{INTEGER}       { /*printf("INTEGER "); */ sscanf(yytext, "%d", &yylval.ivalue); return INTEGER; }
{IDENTIFIER}    { yylval.string = get_text(yytext); /*printf("IDENTIFIER(%s) ", yylval.string);*/ return IDENTIFIER; }
"="             { /*printf("= ");*/ return EQ; }
">"             { /*printf("> ");*/ return GT; }
"<"             { /*printf("< ");*/ return LT; }
">="            { /*printf(">= ");*/ return GE; }
"<="            { /*printf("<= ");*/ return LE; }
"<>"            { /*printf("<> ");*/ return NE; }

{STRING}        { yylval.string = get_text(yytext); /*printf("STRING(%s) ", yylval.string);*/ return STRING; }
{WHITESPACE}    {}
.               { yyerror((std::string("invalid char ") + yytext).c_str()); }

%%

int yywrap() {
    return 1;
}