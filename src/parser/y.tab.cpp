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
#include "../global.h"
#include "tree.h"

int yylex();
void yyerror(const char *);

class Tree;

#line 85 "y.tab.cpp" /* yacc.c:339  */

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
#line 20 "parser.y" /* yacc.c:355  */

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

#line 246 "y.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 263 "y.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   143

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      52,    53,     2,     2,    54,     2,    55,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    87,    94,    97,   101,   107,   113,   120,
     128,   135,   142,   149,   156,   163,   170,   177,   184,   191,
     197,   206,   210,   217,   221,   228,   235,   240,   247,   251,
     255,   259,   263,   270,   276,   282,   288,   345,   352,   357,
     364,   369,   378,   384,   392,   397,   403,   408,   415,   419,
     423,   427,   431,   435,   439,   443,   447,   451,   455,   459,
     463,   467,   474,   479,   486,   487,   488,   489
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
  "REFERENCES", "DATE", "FOREIGN", "KINT", "KFLOAT", "KVARCHAR", "INTEGER",
  "FLOAT", "STRING", "IDENTIFIER", "EQ", "GT", "LT", "GE", "LE", "NE",
  "NOTNULL", "PRIMARY", "DESC", "INDEX", "T_NULL", "IS", "AND", "';'",
  "'('", "')'", "','", "'.'", "$accept", "sql", "command", "insertData",
  "columns", "columnsTmp", "type", "column", "attributes", "attrList",
  "attribute", "relations", "whereclause", "conditions", "comparison",
  "constvalues", "constvalue", YY_NULLPTR
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
     305,    59,    40,    41,    44,    46
};
# endif

#define YYPACT_NINF -64

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-64)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      14,    -8,    10,    -2,    26,    -5,    -3,    21,    17,    22,
       3,   -64,    32,     6,    56,    18,   -64,    42,    61,    44,
      52,    53,    54,    55,    58,    59,   -64,   -64,   -64,   -64,
     -64,    14,    60,    62,    60,    63,    77,    63,    80,   -64,
      49,    50,   -64,   -64,    51,   -64,   -64,   -11,   -64,   -11,
     -64,    63,   -64,    66,    57,    68,    63,    63,    69,   -64,
     -64,    45,    64,   -64,    34,    34,    65,    33,    67,    70,
     -64,    72,    73,   -64,    15,    15,    15,    15,    15,    15,
     -17,    63,   -64,   -64,   -64,   -64,    77,   -21,   -64,    71,
     -64,    75,   -64,    76,     4,   -64,     0,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,    34,    34,    74,    78,
      34,    85,    79,    81,   -64,   -64,   -14,    82,    83,   -64,
      34,    84,    92,   -64,   -64,   -64,   -64,    86,    87,    88,
     -64,    93,    89,    95,    90,   -64
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,     0,     0,     0,     0,    19,
       0,     2,     0,    40,     0,    37,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    20,     5,    16,
       1,     4,     0,     0,     0,     0,    45,     0,     0,    11,
       0,     0,    13,    14,     0,     3,    42,    45,    41,    45,
      39,     0,    10,     0,     0,     0,     0,     0,     0,     6,
       7,     0,    44,    46,     0,     0,     8,     0,     0,    23,
      26,     0,     0,    43,     0,     0,     0,     0,     0,     0,
       0,     0,    64,    65,    66,    67,    45,     0,    62,     0,
      32,    28,    30,     0,    33,    12,     0,    17,    18,    56,
      48,    57,    49,    58,    50,    59,    51,    60,    52,    61,
      53,    55,    54,    47,     9,    21,     0,     0,     0,     0,
       0,    34,     0,     0,    27,    63,     0,     0,     0,    35,
       0,     0,     0,    22,    29,    31,    36,     0,     0,     0,
      24,     0,     0,     0,     0,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,   -64,    91,   -64,   -64,   -64,   -64,    19,   -64,   -64,
      -1,   100,   -45,   -64,    29,    -6,   -63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    10,    11,    66,    68,    69,    94,    70,    14,    15,
      61,    47,    52,    62,    63,    87,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      16,    86,    59,    30,    60,    51,    12,    20,    21,    23,
      24,   100,   102,   104,   106,   108,   110,     1,     2,     3,
       4,     5,     6,     7,     8,    17,   120,   111,    27,    13,
     122,   112,   115,   116,    50,    18,    53,    67,    28,   133,
     116,   114,    22,    58,    25,   123,    19,    32,   121,    82,
      83,    84,    13,   125,    31,    71,    72,   129,    26,    29,
       9,    33,    90,    85,    91,    92,    93,   136,    82,    83,
      84,    34,    35,    99,   101,   103,   105,   107,   109,    36,
      37,    38,    85,    74,    75,    76,    77,    78,    79,    39,
      40,    41,    42,    51,    80,    43,    44,    46,    54,    48,
      13,    55,    56,    57,    64,    67,    73,   130,   127,    65,
     113,   126,   128,     0,    81,   124,   141,     0,     0,    89,
      95,   137,    45,   117,    96,    97,    98,   118,   119,   138,
     142,   131,   144,   132,    49,   134,   135,     0,     0,   139,
     140,   143,     0,   145
};

static const yytype_int16 yycheck[] =
{
       1,    64,    47,     0,    49,    16,    14,    12,    13,    12,
      13,    74,    75,    76,    77,    78,    79,     3,     4,     5,
       6,     7,     8,     9,    10,    15,    22,    44,    11,    37,
      30,    48,    53,    54,    35,    37,    37,    37,    21,    53,
      54,    86,    47,    54,    47,    45,    20,    15,    44,    34,
      35,    36,    37,   116,    51,    56,    57,   120,    37,    37,
      46,    55,    29,    48,    31,    32,    33,   130,    34,    35,
      36,    15,    54,    74,    75,    76,    77,    78,    79,    37,
      19,    37,    48,    38,    39,    40,    41,    42,    43,    37,
      37,    37,    37,    16,    49,    37,    37,    37,    18,    37,
      37,    52,    52,    52,    38,    37,    37,    22,    34,    52,
      81,   117,    34,    -1,    50,    96,    28,    -1,    -1,    54,
      53,    37,    31,    52,    54,    53,    53,    52,    52,    37,
      37,    52,    37,    52,    34,    53,    53,    -1,    -1,    53,
      53,    52,    -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    46,
      57,    58,    14,    37,    64,    65,    66,    15,    37,    20,
      12,    13,    47,    12,    13,    47,    37,    11,    21,    37,
       0,    51,    15,    55,    15,    54,    37,    19,    37,    37,
      37,    37,    37,    37,    37,    58,    37,    67,    37,    67,
      66,    16,    68,    66,    18,    52,    52,    52,    54,    68,
      68,    66,    69,    70,    38,    52,    59,    37,    60,    61,
      63,    66,    66,    37,    38,    39,    40,    41,    42,    43,
      49,    50,    34,    35,    36,    48,    72,    71,    72,    54,
      29,    31,    32,    33,    62,    53,    54,    53,    53,    66,
      72,    66,    72,    66,    72,    66,    72,    66,    72,    66,
      72,    44,    48,    70,    68,    53,    54,    52,    52,    52,
      22,    44,    30,    45,    63,    72,    71,    34,    34,    72,
      22,    52,    52,    53,    53,    53,    72,    37,    37,    53,
      53,    28,    37,    52,    37,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    59,    59,    60,    60,    60,    61,    61,    62,    62,
      62,    62,    62,    63,    63,    63,    63,    64,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    72,    72,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     0,     2,     5,     5,     5,     7,
       4,     3,     6,     3,     3,     2,     2,     6,     6,     1,
       2,     3,     5,     1,     6,    11,     1,     3,     1,     4,
       1,     4,     1,     2,     3,     4,     5,     1,     1,     3,
       1,     3,     1,     3,     2,     0,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     1,     1,     1,     1
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
#line 84 "parser.y" /* yacc.c:1646  */
    {

            }
#line 1439 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 88 "parser.y" /* yacc.c:1646  */
    {

            }
#line 1447 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 94 "parser.y" /* yacc.c:1646  */
    {

            }
#line 1455 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 98 "parser.y" /* yacc.c:1646  */
    {
                // TODO
            }
#line 1463 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 102 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = new SelectTree((yyvsp[-1].relationsTree), (yyvsp[0].whereClauseTree));
                Tree::setInstance((yyval.tree));
                Tree::run();
            }
#line 1473 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 108 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = new SelectTree((yyvsp[-3].attributesTree), (yyvsp[-1].relationsTree), (yyvsp[0].whereClauseTree));
                Tree::setInstance((yyval.tree));
                Tree::run();
            }
#line 1483 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 114 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = new InsertTree((yyvsp[-2].string), (yyvsp[0].insertValueTree));
                Tree::setInstance((yyval.tree));
                delete (yyvsp[-2].string);
                Tree::run();
            }
#line 1494 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 121 "parser.y" /* yacc.c:1646  */
    {
                // TODO
                (yyval.tree) = new UpdateTree((yyvsp[-5].string), (yyvsp[-3].attributeTree), (yyvsp[-1].constValueTree), (yyvsp[0].whereClauseTree));
                Tree::setInstance((yyval.tree));
                delete (yyvsp[-5].string);
                Tree::run();
            }
#line 1506 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 129 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = new DeleteTree((yyvsp[-1].string), (yyvsp[0].whereClauseTree));
                Tree::setInstance((yyval.tree));
                delete (yyvsp[-1].string);
                Tree::run();
            }
#line 1517 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 136 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = new CreateDatabaseTree((yyvsp[0].string));
                Tree::setInstance((yyval.tree));
                delete (yyvsp[0].string);
                Tree::run();
            }
#line 1528 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 143 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = new CreateTableTree((yyvsp[-3].string), (yyvsp[-1].columnsTree));
                Tree::setInstance((yyval.tree));
                delete (yyvsp[-3].string);
                Tree::run();
            }
#line 1539 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 150 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = new DropDatabaseTree((yyvsp[0].string));
                Tree::setInstance((yyval.tree));
                delete (yyvsp[0].string);
                Tree::run();
            }
#line 1550 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 157 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = new DropTableTree((yyvsp[0].string));
                Tree::setInstance((yyval.tree));
                delete (yyvsp[0].string);
                Tree::run();
            }
#line 1561 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 164 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = new UseDatabaseTree((yyvsp[0].string));
                Tree::setInstance((yyval.tree));
                delete (yyvsp[0].string);
                Tree::run();
            }
#line 1572 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 171 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = new DescTableTree((yyvsp[0].string));
                Tree::setInstance((yyval.tree));
                delete (yyvsp[0].string);
                Tree::run();
            }
#line 1583 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 178 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = new CreateIndexTree((yyvsp[-3].string), (yyvsp[-1].attributeTree));
                Tree::setInstance((yyval.tree));
                delete (yyvsp[-3].string);
                Tree::run();
            }
#line 1594 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 185 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = new DropIndexTree((yyvsp[-3].string), (yyvsp[-1].attributeTree));
                Tree::setInstance((yyval.tree));
                delete (yyvsp[-3].string);
                Tree::run();
            }
#line 1605 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 192 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = new DescTableTree("");
                Tree::setInstance((yyval.tree));
                Tree::run();
            }
#line 1615 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 198 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = new DescTableTree("");
                Tree::setInstance((yyval.tree));
                Tree::run();
            }
#line 1625 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 207 "parser.y" /* yacc.c:1646  */
    {
                (yyval.insertValueTree) = new InsertValueTree((yyvsp[-1].constValuesTree));
            }
#line 1633 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 211 "parser.y" /* yacc.c:1646  */
    {
                (yyval.insertValueTree)->addConstValues((yyvsp[-1].constValuesTree));
            }
#line 1641 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 218 "parser.y" /* yacc.c:1646  */
    {

            }
#line 1649 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 222 "parser.y" /* yacc.c:1646  */
    {
                bool found = (yyval.columnsTree)->setPrimaryKey((yyvsp[-1].string));
                if(!found) {yyerror("Primary Key Set Failed!");}
                delete (yyvsp[-1].string);
            }
#line 1659 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 229 "parser.y" /* yacc.c:1646  */
    {
                // TODO
            }
#line 1667 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 236 "parser.y" /* yacc.c:1646  */
    {
                (yyval.columnsTree) = new ColumnsTree();
                (yyval.columnsTree)->addColumn((yyvsp[0].columnTree));
            }
#line 1676 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 241 "parser.y" /* yacc.c:1646  */
    {
                (yyval.columnsTree)->addColumn((yyvsp[0].columnTree));
            }
#line 1684 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 248 "parser.y" /* yacc.c:1646  */
    {
                (yyval.typeTree) = new TypeTree(AttrType::T_INT);
            }
#line 1692 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 252 "parser.y" /* yacc.c:1646  */
    {
                (yyval.typeTree) = new TypeTree(AttrType::T_INT, (yyvsp[-1].ivalue));
            }
#line 1700 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 256 "parser.y" /* yacc.c:1646  */
    {
                (yyval.typeTree) = new TypeTree(AttrType::T_FLOAT);
            }
#line 1708 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 260 "parser.y" /* yacc.c:1646  */
    {
                (yyval.typeTree) = new TypeTree(AttrType::T_STRING, (yyvsp[-1].ivalue));
            }
#line 1716 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 264 "parser.y" /* yacc.c:1646  */
    {
                (yyval.typeTree) = new TypeTree(AttrType::T_STRING, 10);
            }
#line 1724 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 271 "parser.y" /* yacc.c:1646  */
    {
                (yyval.columnTree) = new ColumnTree((yyvsp[-1].string), (yyvsp[0].typeTree)->getType(), (yyvsp[0].typeTree)->getLen());
                delete (yyvsp[-1].string);
                delete (yyvsp[0].typeTree);
            }
#line 1734 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 277 "parser.y" /* yacc.c:1646  */
    {
                (yyval.columnTree) = new ColumnTree((yyvsp[-2].string), (yyvsp[-1].typeTree)->getType(), (yyvsp[-1].typeTree)->getLen(), 1);
                delete (yyvsp[-2].string);
                delete (yyvsp[-1].typeTree);
            }
#line 1744 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 283 "parser.y" /* yacc.c:1646  */
    {
                (yyval.columnTree) = new ColumnTree((yyvsp[-3].string), (yyvsp[-2].typeTree)->getType(), (yyvsp[-2].typeTree)->getLen(), 0, (yyvsp[0].constValueTree));
                delete (yyvsp[-3].string);
                delete (yyvsp[-2].typeTree);
            }
#line 1754 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 289 "parser.y" /* yacc.c:1646  */
    {
                (yyval.columnTree) = new ColumnTree((yyvsp[-4].string), (yyvsp[-3].typeTree)->getType(), (yyvsp[-3].typeTree)->getLen(), 1, (yyvsp[0].constValueTree));
                delete (yyvsp[-4].string);
                delete (yyvsp[-3].typeTree);
            }
#line 1764 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 346 "parser.y" /* yacc.c:1646  */
    {
                (yyval.attributesTree) = (yyvsp[0].attributesTree);
            }
#line 1772 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 353 "parser.y" /* yacc.c:1646  */
    {
                (yyval.attributesTree) = new AttributesTree();
                (yyval.attributesTree)->addAttribute((yyvsp[0].attributeTree));
            }
#line 1781 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 358 "parser.y" /* yacc.c:1646  */
    {
                (yyval.attributesTree)->addAttribute((yyvsp[0].attributeTree));
            }
#line 1789 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 365 "parser.y" /* yacc.c:1646  */
    {
                (yyval.attributeTree) = new AttributeTree((yyvsp[0].string));
                delete (yyvsp[0].string);
            }
#line 1798 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 370 "parser.y" /* yacc.c:1646  */
    {
                (yyval.attributeTree) = new AttributeTree((yyvsp[-2].string), (yyvsp[0].string));
                delete (yyvsp[-2].string);
                delete (yyvsp[0].string);
            }
#line 1808 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 379 "parser.y" /* yacc.c:1646  */
    {
                (yyval.relationsTree) = new RelationsTree();
                (yyval.relationsTree)->addRelation((yyvsp[0].string));
                delete (yyvsp[0].string);
            }
#line 1818 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 385 "parser.y" /* yacc.c:1646  */
    {
                (yyval.relationsTree)->addRelation((yyvsp[0].string));
                delete (yyvsp[0].string);
            }
#line 1827 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 393 "parser.y" /* yacc.c:1646  */
    {
                (yyval.whereClauseTree) = new WhereClauseTree((yyvsp[0].conditionsTree));
            }
#line 1835 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 397 "parser.y" /* yacc.c:1646  */
    {
                (yyval.whereClauseTree) = nullptr;
            }
#line 1843 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 404 "parser.y" /* yacc.c:1646  */
    {
                (yyval.conditionsTree) = new ConditionsTree();
                (yyval.conditionsTree)->addComparison((yyvsp[0].comparisonTree));
            }
#line 1852 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 409 "parser.y" /* yacc.c:1646  */
    {
                (yyval.conditionsTree)->addComparison((yyvsp[0].comparisonTree));
            }
#line 1860 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 416 "parser.y" /* yacc.c:1646  */
    {
                (yyval.comparisonTree) = new ComparisonTree((yyvsp[-2].attributeTree), CmpOP::T_EQ, (yyvsp[0].constValueTree));
            }
#line 1868 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 420 "parser.y" /* yacc.c:1646  */
    {
                (yyval.comparisonTree) = new ComparisonTree((yyvsp[-2].attributeTree), CmpOP::T_GT, (yyvsp[0].constValueTree));
            }
#line 1876 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 424 "parser.y" /* yacc.c:1646  */
    {
                (yyval.comparisonTree) = new ComparisonTree((yyvsp[-2].attributeTree), CmpOP::T_LT, (yyvsp[0].constValueTree));
            }
#line 1884 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 428 "parser.y" /* yacc.c:1646  */
    {
                (yyval.comparisonTree) = new ComparisonTree((yyvsp[-2].attributeTree), CmpOP::T_GE, (yyvsp[0].constValueTree));
            }
#line 1892 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 432 "parser.y" /* yacc.c:1646  */
    {
                (yyval.comparisonTree) = new ComparisonTree((yyvsp[-2].attributeTree), CmpOP::T_LE, (yyvsp[0].constValueTree));
            }
#line 1900 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 436 "parser.y" /* yacc.c:1646  */
    {
                (yyval.comparisonTree) = new ComparisonTree((yyvsp[-2].attributeTree), CmpOP::T_NE, (yyvsp[0].constValueTree));
            }
#line 1908 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 440 "parser.y" /* yacc.c:1646  */
    {
                (yyval.comparisonTree) = new ComparisonTree((yyvsp[-2].attributeTree), CmpOP::T_ISNULL);
            }
#line 1916 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 444 "parser.y" /* yacc.c:1646  */
    {
                (yyval.comparisonTree) = new ComparisonTree((yyvsp[-2].attributeTree), CmpOP::T_ISNOTNULL);
            }
#line 1924 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 448 "parser.y" /* yacc.c:1646  */
    {
                (yyval.comparisonTree) = new ComparisonTree((yyvsp[-2].attributeTree), CmpOP::T_EQ, (yyvsp[0].attributeTree));
            }
#line 1932 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 452 "parser.y" /* yacc.c:1646  */
    {
                (yyval.comparisonTree) = new ComparisonTree((yyvsp[-2].attributeTree), CmpOP::T_GT, (yyvsp[0].attributeTree));
            }
#line 1940 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 456 "parser.y" /* yacc.c:1646  */
    {
                (yyval.comparisonTree) = new ComparisonTree((yyvsp[-2].attributeTree), CmpOP::T_LT, (yyvsp[0].attributeTree));
            }
#line 1948 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 460 "parser.y" /* yacc.c:1646  */
    {
                (yyval.comparisonTree) = new ComparisonTree((yyvsp[-2].attributeTree), CmpOP::T_GE, (yyvsp[0].attributeTree));
            }
#line 1956 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 464 "parser.y" /* yacc.c:1646  */
    {
                (yyval.comparisonTree) = new ComparisonTree((yyvsp[-2].attributeTree), CmpOP::T_LE, (yyvsp[0].attributeTree));
            }
#line 1964 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 468 "parser.y" /* yacc.c:1646  */
    {
                (yyval.comparisonTree) = new ComparisonTree((yyvsp[-2].attributeTree), CmpOP::T_NE, (yyvsp[0].attributeTree));
            }
#line 1972 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 475 "parser.y" /* yacc.c:1646  */
    {
                (yyval.constValuesTree) = new ConstValuesTree();
                (yyval.constValuesTree)->addConstValue((yyvsp[0].constValueTree));
            }
#line 1981 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 480 "parser.y" /* yacc.c:1646  */
    {
                (yyval.constValuesTree)->addConstValue((yyvsp[0].constValueTree));
            }
#line 1989 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 486 "parser.y" /* yacc.c:1646  */
    { (yyval.constValueTree) = new ConstValueTree((yyvsp[0].ivalue)); }
#line 1995 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 487 "parser.y" /* yacc.c:1646  */
    { (yyval.constValueTree) = new ConstValueTree((yyvsp[0].fvalue)); }
#line 2001 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 488 "parser.y" /* yacc.c:1646  */
    { (yyval.constValueTree) = new ConstValueTree((yyvsp[0].string)); delete (yyvsp[0].string); }
#line 2007 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 489 "parser.y" /* yacc.c:1646  */
    { (yyval.constValueTree) = new ConstValueTree(0); (yyval.constValueTree)->setNull(); }
#line 2013 "y.tab.cpp" /* yacc.c:1646  */
    break;


#line 2017 "y.tab.cpp" /* yacc.c:1646  */
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
#line 492 "parser.y" /* yacc.c:1906  */


void yyerror(const char *msg) {
    printf("YACC error: %s\n", msg);
}