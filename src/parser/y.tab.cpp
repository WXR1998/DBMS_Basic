/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#include <cstdio>
#define __STRICT_ANSI__
#else
#include <cstdio>
#endif

#include <stdlib.h>
#include <string>
#include "../global.h"
#include "tree.h"

int yylex();
void yyerror(const char *);

class Tree;

#line 86 "y.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.hpp".  */
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
#line 21 "parser.y" /* yacc.c:355  */

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

#line 255 "y.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 272 "y.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  208

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      55,    56,     2,     2,    57,     2,    58,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    54,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    88,    88,    90,    95,    97,    99,   101,   103,   105,
     110,   118,   125,   132,   139,   148,   155,   162,   169,   176,
     183,   190,   196,   205,   213,   221,   226,   234,   240,   246,
     252,   258,   264,   270,   276,   282,   288,   297,   302,   309,
     315,   321,   327,   333,   338,   346,   350,   354,   358,   362,
     369,   373,   380,   385,   396,   400,   405,   409,   414,   422,
     426,   430,   434,   442,   447,   453,   458,   465,   471,   479,
     483,   487,   491,   495,   499,   506,   511,   518,   523,   530,
     536,   548,   553,   560,   565,   570,   575,   580,   585
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SELECT", "DELETE", "UPDATE", "INSERT",
  "CREATE", "DROP", "USE", "SHOW", "TABLES", "DATABASE", "TABLE", "STAR",
  "FROM", "WHERE", "OPERATOR", "VALUES", "SET", "INTO", "DATABASES",
  "DEFAULT", "CONSTRAINT", "CHANGE", "ALTER", "ADD", "RENAME",
  "REFERENCES", "FOREIGN", "ON", "TO", "KINT", "KFLOAT", "KVARCHAR",
  "KDATE", "INTEGER", "FLOAT", "STRING", "IDENTIFIER", "DATE", "EQ", "GT",
  "LT", "GE", "LE", "NE", "NOTNULL", "PRIMARY", "DESC", "INDEX", "T_NULL",
  "IS", "AND", "';'", "'('", "')'", "','", "'.'", "$accept", "program",
  "stmt", "sysStmt", "dbStmt", "tbStmt", "idxStmt", "alterStmt",
  "fieldList", "field", "type", "valueLists", "valueList", "value",
  "comparisonClause", "whereClause", "conditions", "col", "op",
  "setClause", "colList", "tableList", "columnList", "dbName", "tbName",
  "fkName", "pkName", "idxName", "colName", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    59,    40,    41,    44,    46
};
# endif

#define YYPACT_NINF -102

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-102)))

#define YYTABLE_NINF -87

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      85,    -6,    20,   -33,    21,    -2,    17,     5,    87,    49,
     -33,  -102,    15,  -102,    11,    31,    46,    51,    61,   108,
      60,  -102,   -14,    68,  -102,   -33,  -102,   129,   -33,     5,
     -33,   115,     5,   -33,   115,  -102,  -102,  -102,  -102,   -33,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,   -33,   -33,
     130,   131,   155,   131,   156,  -102,   118,  -102,   145,  -102,
    -102,   146,    34,   -11,  -102,   -11,  -102,  -102,  -102,   130,
    -102,    -4,   137,   124,    27,   -33,   -33,    77,   131,    74,
     149,   -33,  -102,  -102,  -102,   128,   120,   131,  -102,   109,
     109,   125,   132,   133,   -30,  -102,   103,   134,  -102,   144,
     147,   115,  -102,    27,   151,   136,   115,  -102,   -33,  -102,
     130,  -102,  -102,  -102,  -102,  -102,  -102,    12,   104,   143,
    -102,  -102,  -102,  -102,  -102,  -102,    55,  -102,   138,   131,
     131,  -102,    27,   139,  -102,   141,  -102,    -9,   131,  -102,
    -102,  -102,  -102,  -102,  -102,   150,   163,   152,   131,   142,
    -102,  -102,  -102,  -102,  -102,  -102,   109,  -102,   109,   109,
     148,    64,  -102,  -102,   165,   166,   109,   181,    73,   153,
     154,    76,   131,  -102,  -102,    94,   157,  -102,   131,   158,
     159,  -102,   109,  -102,   131,   131,  -102,    96,  -102,   -33,
    -102,  -102,  -102,  -102,   100,   102,  -102,   161,   177,  -102,
     131,   -33,   162,   164,  -102,   131,   111,  -102
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,     0,     2,     0,     0,     0,     0,     0,     0,
      88,    77,     0,     0,    68,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,    83,    13,    14,    10,     0,
      17,     1,     3,     4,     5,     6,     7,     8,     0,     0,
       0,     0,    64,     0,     0,    11,     0,    87,     0,    12,
      16,     0,     0,    64,    79,    64,    78,    88,    67,     0,
      19,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,    22,    65,    63,     0,     0,    20,     0,
       0,    18,     0,     0,     0,    37,     0,     0,    24,     0,
      32,     0,    28,     0,     0,     0,     0,    27,     0,    80,
       0,    69,    71,    72,    73,    74,    70,     0,     0,     0,
      54,    56,    55,    57,    58,    75,     0,    52,     0,     0,
       0,    15,     0,    45,    49,     0,    48,    39,     0,    85,
      36,    86,    34,    26,    29,    85,     0,     0,     0,     0,
      30,    66,    62,    61,    60,    59,     0,    50,     0,     0,
       0,     0,    81,    38,     0,     0,     0,    40,     0,     0,
       0,     0,     0,    76,    53,     0,     0,    43,     0,     0,
       0,    41,     0,    23,     0,     0,    31,     0,    51,     0,
      82,    46,    47,    42,     0,     0,    25,     0,     0,    33,
       0,     0,     0,     0,    44,     0,     0,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,   194,  -102,  -102,  -102,  -102,  -102,  -102,   -75,
    -102,  -102,    52,   -86,   107,    36,  -102,     1,  -102,  -102,
    -102,   171,  -101,   -15,     6,   106,   117,   -27,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    16,    17,    18,    94,    95,
     137,    91,   126,   127,    84,    70,    85,    86,   118,    71,
      22,    63,   161,    36,    23,   140,   142,    58,   162
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,    49,    21,   125,   107,    69,    26,    61,    19,    27,
      29,    30,    69,   166,    55,    41,    40,    59,     1,     2,
       3,     4,     5,     6,     7,     8,   131,   132,   144,    32,
      33,    52,   154,    20,    54,    25,    56,   168,   167,    60,
       9,    28,    77,    50,    35,    62,    81,   171,    31,    24,
      68,    66,    72,    87,    64,    64,    92,   163,    78,   152,
      79,    80,    39,   153,    10,    43,    67,    34,    24,    11,
     173,   187,   174,    96,   143,    93,   102,   103,    96,   149,
     181,    97,    98,   194,   195,    44,   119,   109,     1,     2,
       3,     4,     5,     6,     7,     8,   193,   104,    37,    82,
      45,    83,    96,    92,   206,    46,    99,    88,    38,    24,
       9,   157,   158,    67,   150,    47,    67,    24,   -84,   155,
     177,   178,   105,    48,   106,   100,    51,   101,   160,   183,
     178,    96,   186,   178,    10,   133,   134,   135,   136,    11,
     120,   121,   122,    20,   123,   120,   121,   122,    53,   123,
     188,   158,   196,   178,    57,   124,   198,   178,   199,   178,
     124,   111,   112,   113,   114,   115,   116,   207,   178,    20,
      67,    69,   117,    74,    73,    75,    76,   190,    89,    90,
     108,   110,   128,   139,   156,   189,   141,   129,   130,   138,
     145,   148,   169,   159,   164,   197,   165,   172,   -86,   202,
     170,   179,   180,   182,   176,   201,    42,   203,   184,   185,
     146,   175,     0,     0,   191,   192,   200,   151,   204,   205,
      65,   147
};

static const yytype_int16 yycheck[] =
{
       1,    15,     1,    89,    79,    16,    39,    34,    14,     3,
      12,    13,    16,    22,    29,     0,    10,    32,     3,     4,
       5,     6,     7,     8,     9,    10,    56,    57,   103,    12,
      13,    25,   118,    39,    28,    15,    30,   138,    47,    33,
      25,    20,     8,    57,    39,    39,    57,   148,    50,    50,
      51,    50,    53,    57,    48,    49,    29,   132,    24,    47,
      26,    27,    13,    51,    49,    54,    39,    50,    69,    54,
     156,   172,   158,    74,   101,    48,    77,    78,    79,   106,
     166,    75,    76,   184,   185,    54,    87,    81,     3,     4,
       5,     6,     7,     8,     9,    10,   182,    23,    11,    63,
      54,    65,   103,    29,   205,    54,    29,    71,    21,   110,
      25,    56,    57,    39,   108,    54,    39,   118,    58,   118,
      56,    57,    48,    15,    50,    48,    58,    50,   129,    56,
      57,   132,    56,    57,    49,    32,    33,    34,    35,    54,
      36,    37,    38,    39,    40,    36,    37,    38,    19,    40,
      56,    57,    56,    57,    39,    51,    56,    57,    56,    57,
      51,    41,    42,    43,    44,    45,    46,    56,    57,    39,
      39,    16,    52,    55,    18,    30,    30,   178,    41,    55,
      31,    53,    57,    39,    41,    28,    39,    55,    55,    55,
      39,    55,    29,    55,    55,   189,    55,    55,    48,   200,
      48,    36,    36,    22,    56,    28,    12,   201,    55,    55,
     104,   159,    -1,    -1,    56,    56,    55,   110,    56,    55,
      49,   104
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    25,
      49,    54,    60,    61,    62,    63,    64,    65,    66,    14,
      39,    76,    79,    83,    87,    15,    39,    83,    20,    12,
      13,    50,    12,    13,    50,    39,    82,    11,    21,    13,
      83,     0,    61,    54,    54,    54,    54,    54,    15,    15,
      57,    58,    83,    19,    83,    82,    83,    39,    86,    82,
      83,    86,    83,    80,    83,    80,    76,    39,    87,    16,
      74,    78,    87,    18,    55,    30,    30,     8,    24,    26,
      27,    57,    74,    74,    73,    75,    76,    57,    74,    41,
      55,    70,    29,    48,    67,    68,    87,    83,    83,    29,
      48,    50,    87,    87,    23,    48,    50,    68,    31,    83,
      53,    41,    42,    43,    44,    45,    46,    52,    77,    87,
      36,    37,    38,    40,    51,    72,    71,    72,    57,    55,
      55,    56,    57,    32,    33,    34,    35,    69,    55,    39,
      84,    39,    85,    86,    68,    39,    84,    85,    55,    86,
      83,    73,    47,    51,    72,    76,    41,    56,    57,    55,
      87,    81,    87,    68,    55,    55,    22,    47,    81,    29,
      48,    81,    55,    72,    72,    71,    56,    56,    57,    36,
      36,    72,    22,    56,    55,    55,    56,    81,    56,    28,
      87,    56,    56,    72,    81,    81,    56,    83,    56,    56,
      55,    28,    87,    83,    56,    55,    81,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    61,    61,    61,    61,
      62,    63,    63,    63,    63,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    67,    67,    68,
      68,    68,    68,    68,    68,    69,    69,    69,    69,    69,
      70,    70,    71,    71,    72,    72,    72,    72,    72,    73,
      73,    73,    73,    74,    74,    75,    75,    76,    76,    77,
      77,    77,    77,    77,    77,    78,    78,    79,    79,    80,
      80,    81,    81,    82,    83,    84,    85,    86,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     2,     2,     2,     1,
       2,     3,     3,     2,     2,     6,     3,     2,     5,     4,
       5,     5,     5,     8,     5,     9,     6,     5,     5,     6,
       6,     8,     5,    10,     6,    15,     6,     1,     3,     2,
       3,     4,     5,     4,     9,     1,     4,     4,     1,     1,
       3,     5,     1,     3,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     2,     0,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     5,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 89 "parser.y" /* yacc.c:1646  */
    { }
#line 1490 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 91 "parser.y" /* yacc.c:1646  */
    { }
#line 1496 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 96 "parser.y" /* yacc.c:1646  */
    { }
#line 1502 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 98 "parser.y" /* yacc.c:1646  */
    { }
#line 1508 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 100 "parser.y" /* yacc.c:1646  */
    { }
#line 1514 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 102 "parser.y" /* yacc.c:1646  */
    { }
#line 1520 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 104 "parser.y" /* yacc.c:1646  */
    { }
#line 1526 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 106 "parser.y" /* yacc.c:1646  */
    { }
#line 1532 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 111 "parser.y" /* yacc.c:1646  */
    {
            // TODO
            printf("TODO\n");
        }
#line 1541 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 119 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = new CreateDatabaseTree((yyvsp[0].string));
            Tree::setInstance((yyval.tree));
            delete (yyvsp[0].string);
            Tree::run();
        }
#line 1552 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 126 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = new DropDatabaseTree((yyvsp[0].string));
            Tree::setInstance((yyval.tree));
            delete (yyvsp[0].string);
            Tree::run();
        }
#line 1563 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 133 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = new UseDatabaseTree((yyvsp[0].string));
            Tree::setInstance((yyval.tree));
            delete (yyvsp[0].string);
            Tree::run();
        }
#line 1574 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 140 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = new DescTableTree("");
            Tree::setInstance((yyval.tree));
            Tree::run();
        }
#line 1584 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 149 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = new CreateTableTree((yyvsp[-3].string), (yyvsp[-1].columnsTree));
            Tree::setInstance((yyval.tree));
            delete (yyvsp[-3].string);
            Tree::run();
        }
#line 1595 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 156 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = new DropTableTree((yyvsp[0].string));
            Tree::setInstance((yyval.tree));
            delete (yyvsp[0].string);
            Tree::run();
        }
#line 1606 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 163 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = new DescTableTree((yyvsp[0].string));
            Tree::setInstance((yyval.tree));
            delete (yyvsp[0].string);
            Tree::run();
        }
#line 1617 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 170 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = new InsertTree((yyvsp[-2].string), (yyvsp[0].insertValueTree));
            Tree::setInstance((yyval.tree));
            delete (yyvsp[-2].string);
            Tree::run();
        }
#line 1628 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 177 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = new DeleteTree((yyvsp[-1].string), (yyvsp[0].whereClauseTree));
            Tree::setInstance((yyval.tree));
            delete (yyvsp[-1].string);
            Tree::run();
        }
#line 1639 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 184 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = new UpdateTree(std::string((yyvsp[-3].string)), (yyvsp[-1].setClauseTree), (yyvsp[0].whereClauseTree)); 
            Tree::setInstance((yyval.tree));
            delete (yyvsp[-3].string);
            Tree::run();
        }
#line 1650 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 191 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = new SelectTree((yyvsp[-1].relationsTree), (yyvsp[0].whereClauseTree));
            Tree::setInstance((yyval.tree));
            Tree::run();
        }
#line 1660 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 197 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = new SelectTree((yyvsp[-3].attributesTree), (yyvsp[-1].relationsTree), (yyvsp[0].whereClauseTree));
            Tree::setInstance((yyval.tree));
            Tree::run();
        }
#line 1670 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 206 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = new CreateIndexTree((yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].attributesTree));
            Tree::setInstance((yyval.tree));
            delete (yyvsp[-5].string);
            delete (yyvsp[-3].string);
            Tree::run();
        }
#line 1682 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 214 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = new DropIndexTree((yyvsp[-2].string), (yyvsp[0].string));
            Tree::setInstance((yyval.tree));
            delete (yyvsp[-2].string);
            delete (yyvsp[0].string);
            Tree::run();
        }
#line 1694 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 222 "parser.y" /* yacc.c:1646  */
    {
            // TODO
            printf("TODO\n");
        }
#line 1703 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 227 "parser.y" /* yacc.c:1646  */
    {
            // TODO
            printf("TODO\n");
        }
#line 1712 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 235 "parser.y" /* yacc.c:1646  */
    {
            // TODO
            printf("TODO\n");

        }
#line 1722 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 241 "parser.y" /* yacc.c:1646  */
    {
            // TODO
            printf("TODO\n");

        }
#line 1732 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 247 "parser.y" /* yacc.c:1646  */
    {
            // TODO

            printf("TODO\n");
        }
#line 1742 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 253 "parser.y" /* yacc.c:1646  */
    {
            // TODO
            printf("TODO\n");

        }
#line 1752 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 259 "parser.y" /* yacc.c:1646  */
    {
            // TODO
            printf("TODO\n");

        }
#line 1762 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 265 "parser.y" /* yacc.c:1646  */
    {
            // TODO
            printf("TODO\n");

        }
#line 1772 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 271 "parser.y" /* yacc.c:1646  */
    {
            // TODO
            printf("TODO\n");

        }
#line 1782 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 277 "parser.y" /* yacc.c:1646  */
    {
            // TODO
            printf("TODO\n");

        }
#line 1792 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 283 "parser.y" /* yacc.c:1646  */
    {
            // TODO
            printf("TODO\n");

        }
#line 1802 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 289 "parser.y" /* yacc.c:1646  */
    {
            // TODO
            printf("TODO\n");

        }
#line 1812 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 298 "parser.y" /* yacc.c:1646  */
    {
            (yyval.columnsTree) = new ColumnsTree();
            (yyval.columnsTree)->addColumn((yyvsp[0].columnTree));
        }
#line 1821 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 303 "parser.y" /* yacc.c:1646  */
    {
            (yyval.columnsTree)->addColumn((yyvsp[0].columnTree));
        }
#line 1829 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 310 "parser.y" /* yacc.c:1646  */
    {
            (yyval.columnTree) = new ColumnTree((yyvsp[-1].string), (yyvsp[0].typeTree)->getType(), (yyvsp[0].typeTree)->getLen());
            delete (yyvsp[-1].string);
            delete (yyvsp[0].typeTree);
        }
#line 1839 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 316 "parser.y" /* yacc.c:1646  */
    {
            (yyval.columnTree) = new ColumnTree((yyvsp[-2].string), (yyvsp[-1].typeTree)->getType(), (yyvsp[-1].typeTree)->getLen(), 1);
            delete (yyvsp[-2].string);
            delete (yyvsp[-1].typeTree);
        }
#line 1849 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 322 "parser.y" /* yacc.c:1646  */
    {
            (yyval.columnTree) = new ColumnTree((yyvsp[-3].string), (yyvsp[-2].typeTree)->getType(), (yyvsp[-2].typeTree)->getLen(), 0, (yyvsp[0].constValueTree));
            delete (yyvsp[-3].string);
            delete (yyvsp[-2].typeTree);
        }
#line 1859 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 328 "parser.y" /* yacc.c:1646  */
    {
            (yyval.columnTree) = new ColumnTree((yyvsp[-4].string), (yyvsp[-3].typeTree)->getType(), (yyvsp[-3].typeTree)->getLen(), 1, (yyvsp[0].constValueTree));
            delete (yyvsp[-4].string);
            delete (yyvsp[-3].typeTree);
        }
#line 1869 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 334 "parser.y" /* yacc.c:1646  */
    {
            // TODO
            printf("TODO\n");
        }
#line 1878 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 339 "parser.y" /* yacc.c:1646  */
    {
            // TODO
            printf("TODO\n");
        }
#line 1887 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 347 "parser.y" /* yacc.c:1646  */
    {
            (yyval.typeTree) = new TypeTree(AttrType::T_INT);
        }
#line 1895 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 351 "parser.y" /* yacc.c:1646  */
    {
            (yyval.typeTree) = new TypeTree(AttrType::T_INT, (yyvsp[-1].ivalue));
        }
#line 1903 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 355 "parser.y" /* yacc.c:1646  */
    {
            (yyval.typeTree) = new TypeTree(AttrType::T_STRING, (yyvsp[-1].ivalue));
        }
#line 1911 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 359 "parser.y" /* yacc.c:1646  */
    {
            (yyval.typeTree) = new TypeTree(AttrType::T_DATE, 15);
        }
#line 1919 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 363 "parser.y" /* yacc.c:1646  */
    {
            (yyval.typeTree) = new TypeTree(AttrType::T_FLOAT);
        }
#line 1927 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 370 "parser.y" /* yacc.c:1646  */
    {
            (yyval.insertValueTree) = new InsertValueTree((yyvsp[-1].constValuesTree));
        }
#line 1935 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 374 "parser.y" /* yacc.c:1646  */
    {
            (yyval.insertValueTree)->addConstValues((yyvsp[-1].constValuesTree));
        }
#line 1943 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 381 "parser.y" /* yacc.c:1646  */
    {
            (yyval.constValuesTree) = new ConstValuesTree();
            (yyval.constValuesTree)->addConstValue((yyvsp[0].constValueTree));
        }
#line 1952 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 386 "parser.y" /* yacc.c:1646  */
    {
            (yyval.constValuesTree)->addConstValue((yyvsp[0].constValueTree));
        }
#line 1960 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 397 "parser.y" /* yacc.c:1646  */
    {
            (yyval.constValueTree) = new ConstValueTree((yyvsp[0].ivalue));
        }
#line 1968 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 401 "parser.y" /* yacc.c:1646  */
    {
            (yyval.constValueTree) = new ConstValueTree((yyvsp[0].string));
            delete (yyvsp[0].string);
        }
#line 1977 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 406 "parser.y" /* yacc.c:1646  */
    {
            (yyval.constValueTree) = new ConstValueTree((yyvsp[0].fvalue));
        }
#line 1985 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 410 "parser.y" /* yacc.c:1646  */
    {
            (yyval.constValueTree) = new ConstValueTree((yyvsp[0].string));
            delete (yyvsp[0].string);
        }
#line 1994 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 415 "parser.y" /* yacc.c:1646  */
    {
            (yyval.constValueTree) = new ConstValueTree(0);
            (yyval.constValueTree)->setNull();
        }
#line 2003 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 423 "parser.y" /* yacc.c:1646  */
    {
            (yyval.comparisonTree) = new ComparisonTree((yyvsp[-2].attributeTree), (yyvsp[-1].operatorTree)->op, (yyvsp[0].attributeTree));
        }
#line 2011 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 427 "parser.y" /* yacc.c:1646  */
    {
            (yyval.comparisonTree) = new ComparisonTree((yyvsp[-2].attributeTree), (yyvsp[-1].operatorTree)->op, (yyvsp[0].constValueTree));
        }
#line 2019 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 431 "parser.y" /* yacc.c:1646  */
    {
            (yyval.comparisonTree) = new ComparisonTree((yyvsp[-2].attributeTree), CmpOP::T_ISNULL);
        }
#line 2027 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 435 "parser.y" /* yacc.c:1646  */
    {
            (yyval.comparisonTree) = new ComparisonTree((yyvsp[-2].attributeTree), CmpOP::T_ISNOTNULL);
        }
#line 2035 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 443 "parser.y" /* yacc.c:1646  */
    {
            (yyval.whereClauseTree) = new WhereClauseTree((yyvsp[0].conditionsTree));
        }
#line 2043 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 447 "parser.y" /* yacc.c:1646  */
    {
            (yyval.whereClauseTree) = nullptr;
        }
#line 2051 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 454 "parser.y" /* yacc.c:1646  */
    {
            (yyval.conditionsTree) = new ConditionsTree();
            (yyval.conditionsTree)->addComparison((yyvsp[0].comparisonTree));
        }
#line 2060 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 459 "parser.y" /* yacc.c:1646  */
    {
            (yyval.conditionsTree)->addComparison((yyvsp[0].comparisonTree));
        }
#line 2068 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 466 "parser.y" /* yacc.c:1646  */
    {
            (yyval.attributeTree) = new AttributeTree((yyvsp[-2].string), (yyvsp[0].string));
            delete (yyvsp[-2].string);
            delete (yyvsp[0].string);
        }
#line 2078 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 472 "parser.y" /* yacc.c:1646  */
    {
            (yyval.attributeTree) = new AttributeTree((yyvsp[0].string));
            delete (yyvsp[0].string);
        }
#line 2087 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 480 "parser.y" /* yacc.c:1646  */
    {
            (yyval.operatorTree) = new OperatorTree(CmpOP::T_EQ);
        }
#line 2095 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 484 "parser.y" /* yacc.c:1646  */
    {
            (yyval.operatorTree) = new OperatorTree(CmpOP::T_NE);
        }
#line 2103 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 488 "parser.y" /* yacc.c:1646  */
    {
            (yyval.operatorTree) = new OperatorTree(CmpOP::T_GT);
        }
#line 2111 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 492 "parser.y" /* yacc.c:1646  */
    {
            (yyval.operatorTree) = new OperatorTree(CmpOP::T_LT);
        }
#line 2119 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 496 "parser.y" /* yacc.c:1646  */
    {
            (yyval.operatorTree) = new OperatorTree(CmpOP::T_GE);
        }
#line 2127 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 500 "parser.y" /* yacc.c:1646  */
    {
            (yyval.operatorTree) = new OperatorTree(CmpOP::T_LE);
        }
#line 2135 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 507 "parser.y" /* yacc.c:1646  */
    {
            (yyval.setClauseTree) = new SetClauseTree();
            (yyval.setClauseTree)->addClause((yyvsp[-2].string), (yyvsp[0].constValueTree));
        }
#line 2144 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 512 "parser.y" /* yacc.c:1646  */
    {
            (yyval.setClauseTree)->addClause((yyvsp[-2].string), (yyvsp[0].constValueTree));
        }
#line 2152 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 519 "parser.y" /* yacc.c:1646  */
    {
            (yyval.attributesTree) = new AttributesTree();
            (yyval.attributesTree)->addAttribute((yyvsp[0].attributeTree));
        }
#line 2161 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 524 "parser.y" /* yacc.c:1646  */
    {
            (yyval.attributesTree)->addAttribute((yyvsp[0].attributeTree));
        }
#line 2169 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 531 "parser.y" /* yacc.c:1646  */
    {
            (yyval.relationsTree) = new RelationsTree();
            (yyval.relationsTree)->addRelation((yyvsp[0].string));
            delete (yyvsp[0].string);
        }
#line 2179 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 537 "parser.y" /* yacc.c:1646  */
    {
            (yyval.relationsTree)->addRelation((yyvsp[0].string));
            delete (yyvsp[0].string);
        }
#line 2188 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 549 "parser.y" /* yacc.c:1646  */
    {
            (yyval.attributesTree) = new AttributesTree();
            (yyval.attributesTree)->addAttribute(new AttributeTree((yyvsp[0].string)));
        }
#line 2197 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 554 "parser.y" /* yacc.c:1646  */
    {
            (yyval.attributesTree)->addAttribute(new AttributeTree((yyvsp[0].string)));
        }
#line 2205 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 561 "parser.y" /* yacc.c:1646  */
    { }
#line 2211 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 566 "parser.y" /* yacc.c:1646  */
    { }
#line 2217 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 571 "parser.y" /* yacc.c:1646  */
    { }
#line 2223 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 576 "parser.y" /* yacc.c:1646  */
    { }
#line 2229 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 581 "parser.y" /* yacc.c:1646  */
    { }
#line 2235 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 586 "parser.y" /* yacc.c:1646  */
    { }
#line 2241 "y.tab.cpp" /* yacc.c:1646  */
    break;


#line 2245 "y.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 589 "parser.y" /* yacc.c:1906  */


void yyerror(const char *msg) {
    printf("YACC error: %s\n", msg);
}
