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
    DATE = 284,
    FOREIGN = 285,
    KINT = 286,
    KFLOAT = 287,
    KVARCHAR = 288,
    INTEGER = 289,
    FLOAT = 290,
    STRING = 291,
    IDENTIFIER = 292,
    EQ = 293,
    GT = 294,
    LT = 295,
    GE = 296,
    LE = 297,
    NE = 298,
    NOTNULL = 299,
    PRIMARY = 300,
    DESC = 301,
    INDEX = 302,
    T_NULL = 303,
    IS = 304,
    AND = 305
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
#define DATE 284
#define FOREIGN 285
#define KINT 286
#define KFLOAT 287
#define KVARCHAR 288
#define INTEGER 289
#define FLOAT 290
#define STRING 291
#define IDENTIFIER 292
#define EQ 293
#define GT 294
#define LT 295
#define GE 296
#define LE 297
#define NE 298
#define NOTNULL 299
#define PRIMARY 300
#define DESC 301
#define INDEX 302
#define T_NULL 303
#define IS 304
#define AND 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "parser.y" /* yacc.c:1909  */

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

#line 175 "y.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
