/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SELECT = 258,
    DELETE = 259,
    UPDATE = 260,
    INSERT = 261,
    CREATE = 262,
    DROP = 263,
    USE = 264,
    SHOW = 265,
    TABLES = 266,
    DATABASE = 267,
    TABLE = 268,
    STAR = 269,
    FROM = 270,
    WHERE = 271,
    OPERATOR = 272,
    VALUES = 273,
    SET = 274,
    INTO = 275,
    DATABASES = 276,
    DEFAULT = 277,
    CONSTRAINT = 278,
    CHANGE = 279,
    ALTER = 280,
    ADD = 281,
    RENAME = 282,
    REFERENCES = 283,
    FOREIGN = 284,
    ON = 285,
    TO = 286,
    KINT = 287,
    KFLOAT = 288,
    KVARCHAR = 289,
    KDATE = 290,
    INTEGER = 291,
    FLOAT = 292,
    STRING = 293,
    IDENTIFIER = 294,
    DATE = 295,
    EQ = 296,
    GT = 297,
    LT = 298,
    GE = 299,
    LE = 300,
    NE = 301,
    NOTNULL = 302,
    PRIMARY = 303,
    DESC = 304,
    INDEX = 305,
    T_NULL = 306,
    IS = 307,
    AND = 308
  };
#endif
/* Tokens.  */
#define SELECT 258
#define DELETE 259
#define UPDATE 260
#define INSERT 261
#define CREATE 262
#define DROP 263
#define USE 264
#define SHOW 265
#define TABLES 266
#define DATABASE 267
#define TABLE 268
#define STAR 269
#define FROM 270
#define WHERE 271
#define OPERATOR 272
#define VALUES 273
#define SET 274
#define INTO 275
#define DATABASES 276
#define DEFAULT 277
#define CONSTRAINT 278
#define CHANGE 279
#define ALTER 280
#define ADD 281
#define RENAME 282
#define REFERENCES 283
#define FOREIGN 284
#define ON 285
#define TO 286
#define KINT 287
#define KFLOAT 288
#define KVARCHAR 289
#define KDATE 290
#define INTEGER 291
#define FLOAT 292
#define STRING 293
#define IDENTIFIER 294
#define DATE 295
#define EQ 296
#define GT 297
#define LT 298
#define GE 299
#define LE 300
#define NE 301
#define NOTNULL 302
#define PRIMARY 303
#define DESC 304
#define INDEX 305
#define T_NULL 306
#define IS 307
#define AND 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "parser.y" /* yacc.c:1909  */

    int ivalue;
    float fvalue;
    char *string;
    Tree *tree;
    SelectTree *selectTree;
    DeleteTree *deleteTree;
    AttributesTree *attributesTree;
    AttributeTree *attributeTree;
    RelationsTree *relationsTree;
    WhereClauseTree *whereClauseTree;
    ConditionsTree *conditionsTree;
    ComparisonTree *comparisonTree;
    ConstValuesTree *constValuesTree;
    ConstValueTree *constValueTree;
    ColumnsTree *columnsTree;
    ColumnTree *columnTree;
    InsertValueTree *insertValueTree;
    TypeTree *typeTree;
    SetClauseTree *setClauseTree;
    OperatorTree *operatorTree;
    PrimarySetTree *primarySetTree;
    AddPrimaryTree *addPrimaryTree;
    DropPrimaryTree *dropPrimaryTree;
    ForeignSetTree *foreignSetTree;
    AddForeignTree *addForeignTree;

#line 188 "y.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
