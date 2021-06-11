/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "PARSER/parse.y"

/*
 * parser.y: yacc specification for RQL
 *
 * Authors: Dallan Quass
 *          Jan Jannink
 *          Jason McHugh
 *
 * originally by: Mark McAuliffe, University of Wisconsin - Madison, 1991
 *
 * 1997: Added "print buffer", "print io", "reset io" and the "*" in
 * SFW Query.
 * 1998: Added "reset buffer", "resize buffer [int]", "queryplans on",
 * and "queryplans off".
 * 2000: Added "const" to yyerror-header
 *
 */

#include <cstdio>
#include <iostream>
#include <sys/types.h>
#include <cstdlib>
#include <unistd.h>
#include "../redbase.h"
#include "parser_internal.h"
#include "../PF/pf.h"     // for PF_PrintError
#include "../RM/rm.h"     // for RM_PrintError
#include "../IX/ix.h"     // for IX_PrintError
#include "../SM/sm.h"
#include "../QL/ql.h"

using namespace std;

  // Added by Wendy Tobagus
#ifndef yyrestart
void yyrestart(FILE*);
#endif

// The PF_STATS indicates that we will be tracking statistics for the PF
// Layer.  The Manager is defined within pf_buffermgr.cc.  
// We include it within the parser so that a system command can display
// statistics about the DB.
#ifdef PF_STATS
#include "statistics.h"

// This is defined within the pf_buffermgr.cc
extern StatisticsMgr *pStatisticsMgr;

#endif    // PF_STATS

/*
 * string representation of tokens; provided by scanner
 */
extern char *yytext;

/*
 * points to root of parse tree
 */
static NODE *parse_tree;

int bExit;                 // when to return from RBparse

int bQueryPlans;           // When to print the query plans

PF_Manager *pPfm;          // PF component manager
SM_Manager *pSmm;          // SM component manager
QL_Manager *pQlm;          // QL component manager


#line 140 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_HOME_QUANJUNYUAN_CLIONPROJECTS_DATABASE4_CMAKE_BUILD_DEBUG_Y_TAB_H_INCLUDED
# define YY_YY_HOME_QUANJUNYUAN_CLIONPROJECTS_DATABASE4_CMAKE_BUILD_DEBUG_Y_TAB_H_INCLUDED
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
    RW_CREATE = 258,
    RW_DROP = 259,
    RW_TABLE = 260,
    RW_INDEX = 261,
    RW_LOAD = 262,
    RW_SET = 263,
    RW_HELP = 264,
    RW_PRINT = 265,
    RW_EXIT = 266,
    RW_SELECT = 267,
    RW_FROM = 268,
    RW_WHERE = 269,
    RW_INSERT = 270,
    RW_DELETE = 271,
    RW_UPDATE = 272,
    RW_AND = 273,
    RW_INTO = 274,
    RW_VALUES = 275,
    RW_DATABASE = 276,
    RW_DATABASES = 277,
    RW_TABLES = 278,
    RW_SHOW = 279,
    RW_USE = 280,
    RW_PRIMARY = 281,
    RW_KEY = 282,
    RW_NOT = 283,
    RW_NULL = 284,
    RW_IS = 285,
    RW_DESC = 286,
    T_EQ = 287,
    T_LT = 288,
    T_LE = 289,
    T_GT = 290,
    T_GE = 291,
    T_NE = 292,
    T_EOF = 293,
    NOTOKEN = 294,
    RW_RESET = 295,
    RW_IO = 296,
    RW_BUFFER = 297,
    RW_RESIZE = 298,
    RW_QUERY_PLAN = 299,
    RW_ON = 300,
    RW_OFF = 301,
    T_INT = 302,
    T_REAL = 303,
    T_STRING = 304,
    T_QSTRING = 305,
    T_SHELL_CMD = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 71 "PARSER/parse.y"

    int ival;
    enum CompOp cval;
    float rval;
    char *sval;
    NODE *n;

#line 252 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_QUANJUNYUAN_CLIONPROJECTS_DATABASE4_CMAKE_BUILD_DEBUG_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  77
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   139

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

#define YYUNDEFTOK  2
#define YYMAXUTOK   306


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      53,    54,    56,     2,    55,     2,    57,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    52,
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   179,   179,   184,   194,   200,   209,   210,   211,   212,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   231,
     232,   233,   234,   238,   239,   240,   241,   242,   243,   244,
     245,   249,   255,   266,   274,   279,   287,   298,   311,   318,
     325,   332,   339,   346,   353,   360,   367,   374,   382,   389,
     396,   403,   411,   418,   425,   432,   439,   443,   450,   454,
     458,   465,   466,   473,   477,   484,   488,   495,   499,   506,
     513,   517,   524,   528,   535,   539,   543,   550,   554,   561,
     565,   572,   576,   583,   587,   591,   595,   602,   606,   613,
     617,   621,   625,   629,   633,   640
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RW_CREATE", "RW_DROP", "RW_TABLE",
  "RW_INDEX", "RW_LOAD", "RW_SET", "RW_HELP", "RW_PRINT", "RW_EXIT",
  "RW_SELECT", "RW_FROM", "RW_WHERE", "RW_INSERT", "RW_DELETE",
  "RW_UPDATE", "RW_AND", "RW_INTO", "RW_VALUES", "RW_DATABASE",
  "RW_DATABASES", "RW_TABLES", "RW_SHOW", "RW_USE", "RW_PRIMARY", "RW_KEY",
  "RW_NOT", "RW_NULL", "RW_IS", "RW_DESC", "T_EQ", "T_LT", "T_LE", "T_GT",
  "T_GE", "T_NE", "T_EOF", "NOTOKEN", "RW_RESET", "RW_IO", "RW_BUFFER",
  "RW_RESIZE", "RW_QUERY_PLAN", "RW_ON", "RW_OFF", "T_INT", "T_REAL",
  "T_STRING", "T_QSTRING", "T_SHELL_CMD", "';'", "'('", "')'", "','",
  "'*'", "'.'", "$accept", "start", "command", "ddl", "dml", "utility",
  "queryplans", "buffer", "statistics", "showdbs", "createdb", "dropdb",
  "usedb", "showtables", "createtable", "createindex", "droptable",
  "dropindex", "load", "set", "help", "print", "exit", "query", "insert",
  "delete", "update", "non_mt_attrtype_list", "attrtype",
  "non_mt_select_clause", "non_mt_relattr_list", "relattr",
  "non_mt_relation_list", "relation", "opt_where_clause",
  "non_mt_cond_list", "condition", "relattr_or_value",
  "non_mt_quoted_values_list", "non_mt_value_list", "value", "opt_relname",
  "op", "nothing", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    59,    40,    41,    44,    42,    46
};
# endif

#define YYPACT_NINF (-122)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-96)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       4,  -122,    40,    45,   -45,   -43,   -32,  -122,   -24,    43,
      17,    14,    11,    15,    16,  -122,   -15,    33,    12,  -122,
      76,    25,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,    29,    30,    32,
      34,    35,    36,    27,    50,  -122,  -122,  -122,    38,  -122,
      73,  -122,    39,    41,    42,    79,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,    46,  -122,  -122,  -122,  -122,    44,
      47,  -122,  -122,    48,  -122,    49,    52,    55,    56,    57,
      68,    75,    57,  -122,   -25,    58,    59,    60,  -122,  -122,
    -122,    75,    61,  -122,    62,    57,  -122,  -122,    64,    65,
      63,    66,    67,    69,    70,  -122,  -122,    56,    -7,  -122,
      37,  -122,    80,   -11,    72,    74,  -122,   -25,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,    77,    71,    31,  -122,  -122,
    -122,  -122,  -122,  -122,   -11,    57,  -122,    75,  -122,    81,
      82,  -122,    78,    -7,    84,  -122,  -122,  -122,  -122,    83,
      85,    62,  -122,  -122,  -122,    89,  -122,    90,  -122
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     0,     0,     0,     0,     0,    51,     0,     0,
       0,     0,     0,     0,    95,     5,     0,     0,     0,     3,
       0,     0,     6,     7,     8,    30,    28,    29,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    23,    25,    26,
      27,    24,    19,    20,    21,    22,     9,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    34,    50,    66,    62,
       0,    61,    64,     0,     0,     0,    38,    42,    41,    87,
      49,    88,    37,    33,     0,    31,    32,     1,     2,     0,
       0,    39,    45,     0,    40,     0,     0,     0,     0,     0,
       0,    95,     0,    35,     0,     0,     0,     0,    48,    65,
      69,    95,    68,    63,     0,     0,    54,    71,     0,     0,
       0,     0,    57,     0,     0,    47,    52,     0,     0,    53,
       0,    70,    73,     0,     0,     0,    43,     0,    44,    46,
      67,    86,    84,    85,    83,     0,    82,     0,    93,    89,
      90,    91,    92,    94,     0,     0,    77,    95,    78,     0,
       0,    56,    79,     0,     0,    75,    74,    72,    55,     0,
       0,     0,    81,    76,    60,    58,    80,     0,    59
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,   -18,  -122,  -122,
      21,   -92,   -14,  -122,   -98,   -34,  -122,   -26,   -40,   -21,
    -121,  -122,  -122,    54
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,   111,   112,    60,
      61,    62,   101,   102,   106,   121,   122,   147,   119,   135,
     136,    70,   144,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     108,   109,   148,   116,    53,     1,    54,     2,     3,    55,
      56,     4,     5,   120,     6,     7,     8,    57,   131,     9,
      10,    11,   131,   148,   110,    58,    72,    73,    12,    13,
      64,   146,    59,    66,    67,    14,   132,   133,    58,   134,
     132,   133,    15,   134,    16,    47,    48,    17,    18,   158,
      50,    51,   146,   120,    46,    19,   -95,    75,    76,   154,
     155,    49,    63,    65,    68,    69,    52,   137,    71,   138,
     139,   140,   141,   142,   143,    74,    77,    78,    79,    80,
      85,    81,    86,    82,    83,    84,    88,    92,   104,   105,
      90,    91,   124,    93,    89,    87,   123,    94,   145,    97,
      95,    96,    98,   130,    99,   100,    58,   113,   114,   151,
     103,   157,   125,   163,   115,   118,   117,   167,   156,   168,
     126,   166,   127,   128,   129,   149,   153,   150,     0,   160,
     159,   152,   162,   161,     0,     0,     0,   164,     0,   165
};

static const yytype_int16 yycheck[] =
{
      92,    26,   123,   101,    49,     1,    49,     3,     4,    41,
      42,     7,     8,   105,    10,    11,    12,    49,    29,    15,
      16,    17,    29,   144,    49,    49,    41,    42,    24,    25,
      13,   123,    56,    22,    23,    31,    47,    48,    49,    50,
      47,    48,    38,    50,    40,     5,     6,    43,    44,   147,
       5,     6,   144,   145,     0,    51,    52,    45,    46,    28,
      29,    21,    19,    49,    49,    49,    21,    30,    14,    32,
      33,    34,    35,    36,    37,    42,     0,    52,    49,    49,
      53,    49,    32,    49,    49,    49,    13,     8,    20,    14,
      49,    49,    27,    47,    55,    57,    32,    53,    18,    50,
      53,    53,    50,   117,    49,    49,    49,    49,    49,   127,
      89,   145,    49,    29,    54,    53,    55,    28,   144,    29,
      54,   161,    55,    54,    54,    53,    55,    53,    -1,    47,
      49,    54,   153,    55,    -1,    -1,    -1,    54,    -1,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     7,     8,    10,    11,    12,    15,
      16,    17,    24,    25,    31,    38,    40,    43,    44,    51,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,   101,     5,     6,    21,
       5,     6,    21,    49,    49,    41,    42,    49,    49,    56,
      87,    88,    89,    19,    13,    49,    22,    23,    49,    49,
      99,   101,    41,    42,    42,    45,    46,     0,    52,    49,
      49,    49,    49,    49,    49,    53,    32,    57,    13,    55,
      49,    49,     8,    47,    53,    53,    53,    50,    50,    49,
      49,    90,    91,    88,    20,    14,    92,   101,    89,    26,
      49,    85,    86,    49,    49,    54,    92,    55,    53,    96,
      89,    93,    94,    32,    27,    49,    54,    55,    54,    54,
      90,    29,    47,    48,    50,    97,    98,    30,    32,    33,
      34,    35,    36,    37,   100,    18,    89,    95,    98,    53,
      53,    85,    54,    55,    28,    29,    95,    93,    92,    49,
      47,    55,    97,    29,    54,    54,    96,    28,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    59,    59,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    62,
      62,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    64,    65,    65,    65,    66,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    85,    86,    86,
      86,    87,    87,    88,    88,    89,    89,    90,    90,    91,
      92,    92,    93,    93,    94,    94,    94,    95,    95,    96,
      96,    97,    97,    98,    98,    98,    98,    99,    99,   100,
     100,   100,   100,   100,   100,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     3,     2,     2,     2,     3,
       3,     2,     2,     6,     6,     3,     6,     5,     4,     2,
       2,     1,     5,     5,     4,     7,     3,     1,     5,     7,
       5,     1,     1,     3,     1,     3,     1,     3,     1,     1,
       2,     1,     3,     1,     3,     3,     4,     1,     1,     3,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 180 "PARSER/parse.y"
   {
      parse_tree = (yyvsp[-1].n);
      YYACCEPT;
   }
#line 1553 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 3:
#line 185 "PARSER/parse.y"
   {
      if (!isatty(0)) {
        cout << ((yyvsp[0].sval)) << "\n";
        cout.flush();
      }
      system((yyvsp[0].sval));
      parse_tree = NULL;
      YYACCEPT;
   }
#line 1567 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 4:
#line 195 "PARSER/parse.y"
   {
      reset_scanner();
      parse_tree = NULL;
      YYACCEPT;
   }
#line 1577 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 5:
#line 201 "PARSER/parse.y"
   {
      parse_tree = NULL;
      bExit = 1;
      YYACCEPT;
   }
#line 1587 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 9:
#line 213 "PARSER/parse.y"
   {
      (yyval.n) = NULL;
   }
#line 1595 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 31:
#line 250 "PARSER/parse.y"
   {
      bQueryPlans = 1;
      cout << "Query plan display turned on.\n";
      (yyval.n) = NULL;
   }
#line 1605 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 32:
#line 256 "PARSER/parse.y"
   { 
      bQueryPlans = 0;
      cout << "Query plan display turned off.\n";
      (yyval.n) = NULL;
   }
#line 1615 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 33:
#line 267 "PARSER/parse.y"
   {
      if (pPfm->ClearBuffer())
         cout << "Trouble clearing buffer!  Things may be pinned.\n";
      else 
         cout << "Everything kicked out of Buffer!\n";
      (yyval.n) = NULL;
   }
#line 1627 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 34:
#line 275 "PARSER/parse.y"
   {
      pPfm->PrintBuffer();
      (yyval.n) = NULL;
   }
#line 1636 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 35:
#line 280 "PARSER/parse.y"
   {
      pPfm->ResizeBuffer((yyvsp[0].ival));
      (yyval.n) = NULL;
   }
#line 1645 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 36:
#line 288 "PARSER/parse.y"
   {
      #ifdef PF_STATS
         cout << "Statistics\n";
         cout << "----------\n";
         pStatisticsMgr->Print();
      #else
         cout << "Statitisics not compiled.\n";
      #endif
      (yyval.n) = NULL;
   }
#line 1660 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 37:
#line 299 "PARSER/parse.y"
   {
      #ifdef PF_STATS
         cout << "Statistics reset.\n";
         pStatisticsMgr->Reset();
      #else
         cout << "Statitisics not compiled.\n";
      #endif
      (yyval.n) = NULL;
   }
#line 1674 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 38:
#line 312 "PARSER/parse.y"
   {
      (yyval.n) = show_dbs_node();
   }
#line 1682 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 39:
#line 319 "PARSER/parse.y"
   {
      (yyval.n) = create_db_node((yyvsp[0].sval));
   }
#line 1690 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 40:
#line 326 "PARSER/parse.y"
   {
      (yyval.n) = drop_db_node((yyvsp[0].sval));
   }
#line 1698 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 41:
#line 333 "PARSER/parse.y"
   {
      (yyval.n) = use_db_node((yyvsp[0].sval));
   }
#line 1706 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 42:
#line 340 "PARSER/parse.y"
   {
      (yyval.n) = show_tables_node();
   }
#line 1714 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 43:
#line 347 "PARSER/parse.y"
   {
      (yyval.n) = create_table_node((yyvsp[-3].sval), (yyvsp[-1].n));
   }
#line 1722 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 44:
#line 354 "PARSER/parse.y"
   {
      (yyval.n) = create_index_node((yyvsp[-3].sval), (yyvsp[-1].sval));
   }
#line 1730 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 45:
#line 361 "PARSER/parse.y"
   {
      (yyval.n) = drop_table_node((yyvsp[0].sval));
   }
#line 1738 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 46:
#line 368 "PARSER/parse.y"
   {
      (yyval.n) = drop_index_node((yyvsp[-3].sval), (yyvsp[-1].sval));
   }
#line 1746 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 47:
#line 375 "PARSER/parse.y"
   {
      (yyval.n) = load_node((yyvsp[-3].sval), (yyvsp[-1].sval));
   }
#line 1754 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 48:
#line 383 "PARSER/parse.y"
   {
      (yyval.n) = set_node((yyvsp[-2].sval), (yyvsp[0].sval));
   }
#line 1762 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 49:
#line 390 "PARSER/parse.y"
   {
      (yyval.n) = help_node((yyvsp[0].sval));
   }
#line 1770 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 50:
#line 397 "PARSER/parse.y"
   {
      (yyval.n) = print_node((yyvsp[0].sval));
   }
#line 1778 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 51:
#line 404 "PARSER/parse.y"
   {
      (yyval.n) = NULL;
      bExit = 1;
   }
#line 1787 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 52:
#line 412 "PARSER/parse.y"
   {
      (yyval.n) = query_node((yyvsp[-3].n), (yyvsp[-1].n), (yyvsp[0].n));
   }
#line 1795 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 53:
#line 419 "PARSER/parse.y"
   {
      (yyval.n) = insert_node((yyvsp[-2].sval), (yyvsp[0].n));
   }
#line 1803 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 54:
#line 426 "PARSER/parse.y"
   {
      (yyval.n) = delete_node((yyvsp[-1].sval), (yyvsp[0].n));
   }
#line 1811 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 55:
#line 433 "PARSER/parse.y"
   {
      (yyval.n) = update_node((yyvsp[-5].sval), (yyvsp[-3].n), (yyvsp[-1].n), (yyvsp[0].n));
   }
#line 1819 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 56:
#line 440 "PARSER/parse.y"
   {
      (yyval.n) = prepend((yyvsp[-2].n), (yyvsp[0].n));
   }
#line 1827 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 57:
#line 444 "PARSER/parse.y"
   {
      (yyval.n) = list_node((yyvsp[0].n));
   }
#line 1835 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 58:
#line 451 "PARSER/parse.y"
   {
      (yyval.n) = attrtype_node((yyvsp[-4].sval), (yyvsp[-3].sval), (yyvsp[-1].ival), ATTR_SPEC_NONE);
   }
#line 1843 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 59:
#line 455 "PARSER/parse.y"
   {
      (yyval.n) = attrtype_node((yyvsp[-6].sval), (yyvsp[-5].sval), (yyvsp[-3].ival), ATTR_SPEC_NOTNULL);
   }
#line 1851 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 60:
#line 459 "PARSER/parse.y"
   {
      (yyval.n) = attrtype_node((yyvsp[-1].sval), NULL, 0, ATTR_SPEC_PRIMARYKEY);
   }
#line 1859 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 62:
#line 467 "PARSER/parse.y"
   {
       (yyval.n) = list_node(relattr_node(NULL, (char*)"*"));
   }
#line 1867 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 63:
#line 474 "PARSER/parse.y"
   {
      (yyval.n) = prepend((yyvsp[-2].n), (yyvsp[0].n));
   }
#line 1875 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 64:
#line 478 "PARSER/parse.y"
   {
      (yyval.n) = list_node((yyvsp[0].n));
   }
#line 1883 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 65:
#line 485 "PARSER/parse.y"
   {
      (yyval.n) = relattr_node((yyvsp[-2].sval), (yyvsp[0].sval));
   }
#line 1891 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 66:
#line 489 "PARSER/parse.y"
   {
      (yyval.n) = relattr_node(NULL, (yyvsp[0].sval));
   }
#line 1899 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 67:
#line 496 "PARSER/parse.y"
   {
      (yyval.n) = prepend((yyvsp[-2].n), (yyvsp[0].n));
   }
#line 1907 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 68:
#line 500 "PARSER/parse.y"
   {
      (yyval.n) = list_node((yyvsp[0].n));
   }
#line 1915 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 69:
#line 507 "PARSER/parse.y"
   {
      (yyval.n) = relation_node((yyvsp[0].sval));
   }
#line 1923 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 70:
#line 514 "PARSER/parse.y"
   {
      (yyval.n) = (yyvsp[0].n);
   }
#line 1931 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 71:
#line 518 "PARSER/parse.y"
   {
      (yyval.n) = NULL;
   }
#line 1939 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 72:
#line 525 "PARSER/parse.y"
   {
      (yyval.n) = prepend((yyvsp[-2].n), (yyvsp[0].n));
   }
#line 1947 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 73:
#line 529 "PARSER/parse.y"
   {
      (yyval.n) = list_node((yyvsp[0].n));
   }
#line 1955 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 74:
#line 536 "PARSER/parse.y"
   {
      (yyval.n) = condition_node((yyvsp[-2].n), (yyvsp[-1].cval), (yyvsp[0].n));
   }
#line 1963 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 75:
#line 540 "PARSER/parse.y"
   {
      (yyval.n) = condition_node((yyvsp[-2].n), ISNULL_OP, NULL);
   }
#line 1971 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 76:
#line 544 "PARSER/parse.y"
   {
      (yyval.n) = condition_node((yyvsp[-3].n), NOTNULL_OP, NULL);
   }
#line 1979 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 77:
#line 551 "PARSER/parse.y"
   {
      (yyval.n) = relattr_or_value_node((yyvsp[0].n), NULL);
   }
#line 1987 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 78:
#line 555 "PARSER/parse.y"
   {
      (yyval.n) = relattr_or_value_node(NULL, (yyvsp[0].n));
   }
#line 1995 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 79:
#line 562 "PARSER/parse.y"
   {
      (yyval.n) = (yyvsp[-1].n);
   }
#line 2003 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 80:
#line 566 "PARSER/parse.y"
   {
      (yyval.n) = prepend_list((yyvsp[-3].n), (yyvsp[0].n));
   }
#line 2011 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 81:
#line 573 "PARSER/parse.y"
   {
      (yyval.n) = prepend((yyvsp[-2].n), (yyvsp[0].n));
   }
#line 2019 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 82:
#line 577 "PARSER/parse.y"
   {
      (yyval.n) = list_node((yyvsp[0].n));
   }
#line 2027 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 83:
#line 584 "PARSER/parse.y"
   {
      (yyval.n) = value_node(STRING, (void *) (yyvsp[0].sval));
   }
#line 2035 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 84:
#line 588 "PARSER/parse.y"
   {
      (yyval.n) = value_node(INT, (void *)& (yyvsp[0].ival));
   }
#line 2043 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 85:
#line 592 "PARSER/parse.y"
   {
      (yyval.n) = value_node(FLOAT, (void *)& (yyvsp[0].rval));
   }
#line 2051 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 86:
#line 596 "PARSER/parse.y"
   {
      (yyval.n) = NULL;
   }
#line 2059 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 87:
#line 603 "PARSER/parse.y"
   {
      (yyval.sval) = (yyvsp[0].sval);
   }
#line 2067 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 88:
#line 607 "PARSER/parse.y"
   {
      (yyval.sval) = NULL;
   }
#line 2075 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 89:
#line 614 "PARSER/parse.y"
   {
      (yyval.cval) = LT_OP;
   }
#line 2083 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 90:
#line 618 "PARSER/parse.y"
   {
      (yyval.cval) = LE_OP;
   }
#line 2091 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 91:
#line 622 "PARSER/parse.y"
   {
      (yyval.cval) = GT_OP;
   }
#line 2099 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 92:
#line 626 "PARSER/parse.y"
   {
      (yyval.cval) = GE_OP;
   }
#line 2107 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 93:
#line 630 "PARSER/parse.y"
   {
      (yyval.cval) = EQ_OP;
   }
#line 2115 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;

  case 94:
#line 634 "PARSER/parse.y"
   {
      (yyval.cval) = NE_OP;
   }
#line 2123 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"
    break;


#line 2127 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.cc"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 643 "PARSER/parse.y"


//
// PrintError
//
// Desc: Print an error message by calling the proper component-specific
//       print-error function
//
void PrintError(RC rc)
{
   if (abs(rc) <= END_PF_WARN)
      PF_PrintError(rc);
   else if (abs(rc) <= END_RM_WARN)
      RM_PrintError(rc);
   else if (abs(rc) <= END_IX_WARN)
      IX_PrintError(rc);
   else if (abs(rc) <= END_SM_WARN)
      SM_PrintError(rc);
   else if (abs(rc) <= END_QL_WARN)
      QL_PrintError(rc);
   else
      cerr << "Error code out of range: " << rc << "\n";
}

bool output_prompt;

//
// RBparse
//
// Desc: Parse redbase commands
//
void RBparse(PF_Manager &pfm, SM_Manager &smm, QL_Manager &qlm)
{
   RC rc;

   // Set up global variables to their defaults
   pPfm  = &pfm;
   pSmm  = &smm;
   pQlm  = &qlm;
   bExit = 0;
   bQueryPlans = 0;

   /* Do forever */
   while (!bExit) {
      /* Reset parser and scanner for a new query */
      new_query();

      if (output_prompt) {
         /* Print a prompt */
         cout << PROMPT;

         /* Get the prompt to actually show up on the screen */
         cout.flush();
      }

      /* If a query was successfully read, interpret it */
      if(yyparse() == 0 && parse_tree != NULL)
         if ((rc = interp(parse_tree))) {
            PrintError(rc);
            if (rc < 0){
               bExit = TRUE;
	    }
         }
   }
   
   pSmm->CloseDb();
}

//
// Functions for printing the various structures to an output stream
//
ostream &operator<<(ostream &s, const DataAttrInfo &ai)
{
   return
      s << " attrName=" << ai.attrName
      << " attrType=" << 
      (ai.attrType == INT ? "INT" :
       ai.attrType == FLOAT ? "FLOAT" : "STRING")
      << " attrDisplayLength=" << ai.attrDisplayLength;
}

ostream &operator<<(ostream &s, const RelAttr &qa)
{
   return
      s << (qa.relName ? qa.relName : "NULL")
      << "." << qa.attrName;
}

ostream &operator<<(ostream &s, const Condition &c)
{
   s << "\n      lhsAttr:" << c.lhsAttr << "\n"
      << "      op=" << c.op << "\n";
   if (c.bRhsIsAttr)
      s << "      bRhsIsAttr=TRUE \n      rhsAttr:" << c.rhsAttr;
   else
      s << "      bRshIsAttr=FALSE\n      rhsValue:" << c.rhsValue;
   return s;
}

ostream &operator<<(ostream &s, const Value &v)
{
   s << "AttrType: " << v.type;
   switch (v.type) {
      case INT:
         s << " *(int *)data=" << *(int *)v.data;
         break;
      case FLOAT:
         s << " *(float *)data=" << *(float *)v.data;
         break;
      case STRING:
         s << " (char *)data=" << (char *)v.data;
         break;
      default:
         break;
   }
   return s;
}

ostream &operator<<(ostream &s, const CompOp &op)
{
   switch(op){
      case EQ_OP:
         s << " =";
         break;
      case NE_OP:
         s << " <>";
         break;
      case LT_OP:
         s << " <";
         break;
      case LE_OP:
         s << " <=";
         break;
      case GT_OP:
         s << " >";
         break;
      case GE_OP:
         s << " >=";
         break;
      case NO_OP:
         s << " NO_OP";
         break;
      default:
         break;
   }
   return s;
}

ostream &operator<<(ostream &s, const AttrType &at)
{
   switch(at){
      case INT:
         s << "INT";
         break;
      case FLOAT:
         s << "FLOAT";
         break;
      case STRING:
         s << "STRING";
         break;
   }
   return s;
}

/*
 * Required by yacc
 */
void yyerror(char const *s) // New in 2000
{
   puts(s);
}

#if 0
/*
 * Sometimes required
 */
int yywrap(void)
{
   return 1;
}
#endif
