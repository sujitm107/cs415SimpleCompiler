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
#line 1 "parse.y" /* yacc.c:339  */

#include <stdio.h>
#include "attr.h"
#include "instrutil.h"
int yylex();
void yyerror(char * s);
#include "symtab.h"

FILE *outfile;
char *CommentBuffer;
 

#line 79 "parse.tab.c" /* yacc.c:339  */

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
   by #include "parse.tab.h".  */
#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
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
    PROG = 258,
    PERIOD = 259,
    VAR = 260,
    INT = 261,
    BOOL = 262,
    PRT = 263,
    THEN = 264,
    IF = 265,
    DO = 266,
    FI = 267,
    ENDFOR = 268,
    ARRAY = 269,
    OF = 270,
    BEG = 271,
    END = 272,
    ASG = 273,
    EQ = 274,
    NEQ = 275,
    LT = 276,
    LEQ = 277,
    GT = 278,
    GEQ = 279,
    AND = 280,
    OR = 281,
    TRUE = 282,
    FALSE = 283,
    ELSE = 284,
    FOR = 285,
    ID = 286,
    ICONST = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "parse.y" /* yacc.c:355  */
tokentype token;
        regInfo targetReg;

        // My declarations
        varList *vList;
        Type_Expression tex;
        type type;

        fstmt forstmt;
        cntrlExp controlStmt;
        condExp conditionStmt;
        ifStmtType ifStmt;
        ifHeadType ifHead;
       

#line 168 "parse.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 185 "parse.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   120

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

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
      41,    42,    35,    33,    38,    34,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    36,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    60,    60,    60,    65,    68,    69,    72,    73,    74,
      77,    92,    96,   104,   109,   112,   115,   120,   121,   122,
     125,   126,   127,   128,   129,   132,   135,   136,   140,   145,
     135,   153,   153,   173,   190,   203,   219,   220,   190,   236,
     255,   279,   328,   343,   358,   373,   389,   405,   426,   472,
     477,   482,   487,   491,   527,   540,   553,   564,   574,   585,
     598
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROG", "PERIOD", "VAR", "INT", "BOOL",
  "PRT", "THEN", "IF", "DO", "FI", "ENDFOR", "ARRAY", "OF", "BEG", "END",
  "ASG", "EQ", "NEQ", "LT", "LEQ", "GT", "GEQ", "AND", "OR", "TRUE",
  "FALSE", "ELSE", "FOR", "ID", "ICONST", "'+'", "'-'", "'*'", "';'",
  "':'", "','", "'['", "']'", "'('", "')'", "$accept", "program", "$@1",
  "block", "variables", "vardcls", "vardcl", "idlist", "type", "stype",
  "stmtlist", "stmt", "cmpdstmt", "ifstmt", "$@2", "$@3", "$@4", "$@5",
  "ifhead", "$@6", "writestmt", "fstmt", "$@7", "$@8", "$@9", "$@10",
  "astmt", "lhs", "exp", "ctrlexp", "condexp", YY_NULLPTR
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
     285,   286,   287,    43,    45,    42,    59,    58,    44,    91,
      93,    40,    41
};
# endif

#define YYPACT_NINF -50

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-50)))

#define YYTABLE_NINF -61

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -50,     5,    13,   -50,   -24,   -16,    22,    21,    24,    37,
      23,   -50,    -2,    54,   -23,   -50,    50,   -50,   -50,    57,
     -50,     4,    26,   -50,    14,   -50,   -50,    15,   -15,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,    76,   -50,   -50,   -50,
      56,   -50,   -50,   -50,    16,    18,    71,    16,   -50,    -7,
      94,    16,    72,   -50,   -50,   -50,    68,   -50,    36,    96,
      63,   -50,    90,   -50,    39,   -50,   -50,    42,    69,    16,
      16,    16,    16,    16,    16,   -50,    16,    16,    16,    16,
      16,    16,    78,   100,   -50,    -7,    97,    66,   -22,   -50,
     -22,   -22,   -50,    42,    42,    42,    42,    42,    42,    75,
     -50,   -50,    19,   -50,    82,    -7,    86,   -50,   -50,   -50,
     -50,   103,    -7,   -50,   105,   -50
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     5,     0,     0,     0,
       0,    12,     6,     0,     0,     3,     0,     4,     9,     0,
       8,     0,     0,    19,     0,    31,    34,    40,     0,    18,
      24,    20,    26,    23,    21,    22,     0,     7,    15,    16,
       0,    10,    14,    11,     0,     0,     0,     0,    25,     0,
       0,     0,     0,    52,    50,    51,    47,    49,     0,    52,
       0,    32,     0,    35,     0,    17,    27,    39,     0,     0,
       0,     0,     0,     0,     0,    33,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,    45,    46,
      42,    43,    44,    55,    54,    56,    57,    58,    59,     0,
      36,    28,     0,    48,     0,     0,     0,    13,    53,    37,
      29,     0,     0,    38,     0,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -50,   -50,   -50,   -50,   -50,   -50,   106,   -50,   -50,    17,
     -50,   -49,   111,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -39,   -50,
     -50
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     8,     9,    12,    13,    14,    41,    42,
      28,    29,    30,    31,    50,    85,   106,   112,    32,    45,
      33,    34,    46,    83,   105,   111,    35,    36,    58,    63,
      61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      65,    24,    48,    25,    71,     3,    60,     5,    64,    16,
      38,    39,    67,    74,    21,    22,     4,    53,    40,    59,
       6,    49,    10,    26,    27,    38,    39,     7,    15,    11,
      87,    88,    89,    90,    91,    92,   101,    93,    94,    95,
      96,    97,    98,    54,    55,    54,    55,    56,    57,    56,
      57,    23,    11,    16,    47,    44,   109,    43,    24,    18,
      25,    70,    71,   114,    70,    71,    16,    70,    71,    72,
      73,    74,    72,    73,    74,    72,    73,    74,    75,    84,
      26,    27,    76,    77,    78,    79,    80,    81,    70,    71,
      20,    70,    71,    37,    51,    52,    72,    73,    74,    72,
      73,    74,    62,    66,    68,   -60,   103,    69,    82,    86,
      99,   100,   102,   104,   108,   110,   113,   115,    19,   107,
      17
};

static const yytype_uint8 yycheck[] =
{
      49,     8,    17,    10,    26,     0,    45,    31,    47,    16,
       6,     7,    51,    35,    37,    38,     3,     1,    14,     1,
      36,    36,     1,    30,    31,     6,     7,     5,     4,    31,
      69,    70,    71,    72,    73,    74,    85,    76,    77,    78,
      79,    80,    81,    27,    28,    27,    28,    31,    32,    31,
      32,     1,    31,    16,    39,    41,   105,    31,     8,    36,
      10,    25,    26,   112,    25,    26,    16,    25,    26,    33,
      34,    35,    33,    34,    35,    33,    34,    35,    42,    40,
      30,    31,    19,    20,    21,    22,    23,    24,    25,    26,
      36,    25,    26,    36,    18,    39,    33,    34,    35,    33,
      34,    35,    31,     9,    32,     9,    40,    39,    18,    40,
      32,    11,    15,    38,    32,    29,    13,    12,    12,   102,
       9
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    45,     0,     3,    31,    36,     5,    46,    47,
       1,    31,    48,    49,    50,     4,    16,    55,    36,    49,
      36,    37,    38,     1,     8,    10,    30,    31,    53,    54,
      55,    56,    61,    63,    64,    69,    70,    36,     6,     7,
      14,    51,    52,    31,    41,    62,    65,    39,    17,    36,
      57,    18,    39,     1,    27,    28,    31,    32,    71,     1,
      71,    73,    31,    72,    71,    54,     9,    71,    32,    39,
      25,    26,    33,    34,    35,    42,    19,    20,    21,    22,
      23,    24,    18,    66,    40,    58,    40,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    32,
      11,    54,    15,    40,    38,    67,    59,    52,    32,    54,
      29,    68,    60,    13,    54,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    45,    44,    46,    47,    47,    48,    48,    48,
      49,    50,    50,    51,    51,    52,    52,    53,    53,    53,
      54,    54,    54,    54,    54,    55,    57,    58,    59,    60,
      56,    62,    61,    63,    65,    66,    67,    68,    64,    69,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    72,    73,    73,    73,    73,    73,    73,
      73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     2,     0,     2,     3,     2,     2,
       3,     3,     1,     6,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     0,     0,     0,
      10,     0,     3,     4,     0,     0,     0,     0,     9,     3,
       1,     4,     3,     3,     3,     3,     3,     1,     4,     1,
       1,     1,     1,     5,     3,     3,     3,     3,     3,     3,
       1
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
#line 60 "parse.y" /* yacc.c:1646  */
    {emitComment("Assign STATIC_AREA_ADDRESS to register \"r0\"");
           emit(NOLABEL, LOADI, STATIC_AREA_ADDRESS, 0, EMPTY);}
#line 1346 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 62 "parse.y" /* yacc.c:1646  */
    { printf("\n\n Done with compiling program \"%s\"\n ", (yyvsp[-3].token).str); }
#line 1352 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 65 "parse.y" /* yacc.c:1646  */
    { }
#line 1358 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 69 "parse.y" /* yacc.c:1646  */
    { }
#line 1364 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 72 "parse.y" /* yacc.c:1646  */
    { }
#line 1370 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 73 "parse.y" /* yacc.c:1646  */
    { }
#line 1376 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 74 "parse.y" /* yacc.c:1646  */
    { yyerror("***Error: illegal variable declaration\n");}
#line 1382 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 77 "parse.y" /* yacc.c:1646  */
    { 
                varNode* ptr = (yyvsp[-2].vList)->head;
                while(ptr != NULL){
                        if(lookup(ptr->name) != NULL){
                                printf("\n***ERROR: duplicate declaration of %s\n", ptr->name);
                        } else {
                                insert(ptr->name, (yyvsp[0].type).baseType, NextOffset((yyvsp[0].type).varSize), (yyvsp[0].type).varType);
                        }
                        // NextOffset($3.varSize - 1); //allocate space for entire array if necessary, if it is scalar, the line is negated by the -1 as the scalar's varSize is 1
                        ptr = ptr->next;
                }

        }
#line 1400 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 92 "parse.y" /* yacc.c:1646  */
    {     varList_insert((yyvsp[-2].vList), (yyvsp[0].token).str);
                                // varList_printList($1);
                                (yyval.vList) = (yyvsp[-2].vList);
                        }
#line 1409 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 96 "parse.y" /* yacc.c:1646  */
    {varList* list = malloc(sizeof(varList));
                                list->head = NULL;
                                varList_insert(list, (yyvsp[0].token).str);
                                (yyval.vList) = list;
                         }
#line 1419 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 104 "parse.y" /* yacc.c:1646  */
    { 
        
                (yyval.type).varType = TYPE_ARRAY; (yyval.type).baseType = (yyvsp[0].tex); (yyval.type).varSize = (yyvsp[-3].token).num;
        }
#line 1428 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 109 "parse.y" /* yacc.c:1646  */
    { (yyval.type).varType = TYPE_SCALAR; (yyval.type).baseType = (yyvsp[0].tex); (yyval.type).varSize = 1;}
#line 1434 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 112 "parse.y" /* yacc.c:1646  */
    { 
                (yyval.tex) = TYPE_INT;
        }
#line 1442 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 115 "parse.y" /* yacc.c:1646  */
    { 
                (yyval.tex) = TYPE_BOOL; 
        }
#line 1450 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 120 "parse.y" /* yacc.c:1646  */
    { }
#line 1456 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 121 "parse.y" /* yacc.c:1646  */
    { }
#line 1462 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 122 "parse.y" /* yacc.c:1646  */
    { yyerror("***Error: ';' expected or illegal statement \n");}
#line 1468 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 125 "parse.y" /* yacc.c:1646  */
    { }
#line 1474 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 126 "parse.y" /* yacc.c:1646  */
    { }
#line 1480 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 127 "parse.y" /* yacc.c:1646  */
    { }
#line 1486 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 128 "parse.y" /* yacc.c:1646  */
    { }
#line 1492 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 129 "parse.y" /* yacc.c:1646  */
    { }
#line 1498 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 132 "parse.y" /* yacc.c:1646  */
    { }
#line 1504 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 135 "parse.y" /* yacc.c:1646  */
    { (yyvsp[0].ifHead).followLabel = NextLabel(); }
#line 1510 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 136 "parse.y" /* yacc.c:1646  */
    {/* NEXTLABEL() L0 */ emit((yyvsp[-2].ifHead).trueLabel, NOP, EMPTY, EMPTY, EMPTY);
                sprintf(CommentBuffer, "This is the \"true\" Branch");
                emitComment(CommentBuffer);
          }
#line 1519 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 140 "parse.y" /* yacc.c:1646  */
    {/* GO TO BRANCH AFTER ELSE STMT */ 
                sprintf(CommentBuffer, "Branch to statement following the \"else\" statement list");
                emitComment(CommentBuffer);
                emit(NOLABEL, BR, (yyvsp[-4].ifHead).followLabel, EMPTY, EMPTY);
          }
#line 1529 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 145 "parse.y" /* yacc.c:1646  */
    {/* NEXTLABEL() L1 */ emit((yyvsp[-6].ifHead).falseLabel, NOP, EMPTY, EMPTY, EMPTY); 
                sprintf(CommentBuffer, "This is the \"false\" Branch");
                emitComment(CommentBuffer);
            }
#line 1538 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 150 "parse.y" /* yacc.c:1646  */
    {/*NEXTLABEL() L2 */ emit((yyvsp[-9].ifHead).followLabel, NOP, EMPTY, EMPTY, EMPTY);}
#line 1544 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 153 "parse.y" /* yacc.c:1646  */
    {
                //Declare Labels
                int trueLabel = NextLabel();
                int falseLabel = NextLabel();

                (yyvsp[0].ifStmt).trueLabel = trueLabel;
                (yyvsp[0].ifStmt).falseLabel = falseLabel;

        }
#line 1558 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 162 "parse.y" /* yacc.c:1646  */
    { /*DEPENING ON TARGETREG INFO CBR TO TRUE LABEL OR FALSE LABEL */
                        // if($$.type != TYPE_BOOL){
                        //         printf("\n***ERROR: exp in if stmt must be boolean\n");
                        // }

                        emit(NOLABEL, CBR, (yyvsp[0].conditionStmt).targetReg, (yyvsp[-2].ifStmt).trueLabel, (yyvsp[-2].ifStmt).falseLabel);
                        (yyval.ifHead).trueLabel = (yyvsp[-2].ifStmt).trueLabel;
                        (yyval.ifHead).falseLabel = (yyvsp[-2].ifStmt).falseLabel;
                }
#line 1572 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 173 "parse.y" /* yacc.c:1646  */
    { 
                        if((yyvsp[-1].targetReg).type != TYPE_INT){
                                printf("\n***Error: illegal type for write\n");
                        }
                        
                        int printOffset = -4; /* default location for printing */
  	                         sprintf(CommentBuffer, "Code for \"PRINT\" from offset %d", printOffset);
	                         emitComment(CommentBuffer);
                                 emit(NOLABEL, STOREAI, (yyvsp[-1].targetReg).targetRegister, 0, printOffset);
                                 emit(NOLABEL, 
                                      OUTPUTAI, 
                                      0,
                                      printOffset, 
                                      EMPTY);
                               }
#line 1592 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 190 "parse.y" /* yacc.c:1646  */
    {
                sprintf(CommentBuffer, "Control For \"FOR\" Statement"); emitComment(CommentBuffer); 

                // Regiseters 7 8 should be declared here?

                int decLabel = NextLabel();
                int trueLabel = NextLabel();
                int falseLabel = NextLabel();

                (yyvsp[0].forstmt).decLabel = decLabel;
                (yyvsp[0].forstmt).trueLabel = trueLabel;
                (yyvsp[0].forstmt).falseLabel = falseLabel;

        }
#line 1611 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 203 "parse.y" /* yacc.c:1646  */
    { 
                
                int offset = lookup((yyvsp[0].controlStmt).indexStr)->offset; //Swap with offset of i which is saved in ctrlexp
                int newReg = NextRegister(); 
                int upperBoundReg = (yyvsp[0].controlStmt).upperBoundReg; // NextRegister(); //Swap with Ctrl Upper
                int decLabel = (yyvsp[-2].forstmt).decLabel; //Swap with For Dec Label
                emit(decLabel, LOADAI, 0, offset, newReg);

                int newReg2 = NextRegister();
                emit(NOLABEL, CMPLE, newReg, upperBoundReg, newReg2);

                int trueLabel = (yyvsp[-2].forstmt).trueLabel; // Swap with For True Label
                int falseLabel = (yyvsp[-2].forstmt).falseLabel; // Swap with For False Label

                emit(NOLABEL, CBR, newReg2, trueLabel, falseLabel);
        }
#line 1632 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 219 "parse.y" /* yacc.c:1646  */
    {emit((yyvsp[-4].forstmt).trueLabel, NOP, EMPTY, EMPTY, EMPTY);}
#line 1638 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 220 "parse.y" /* yacc.c:1646  */
    { 
                int currIndexReg = NextRegister();
                int newIndexReg = NextRegister();

                //Incrementing I
                int offset = lookup((yyvsp[-4].controlStmt).indexStr)->offset; // offset of i
                emit(NOLABEL, LOADAI, 0, offset, currIndexReg);
                emit(NOLABEL, ADDI, currIndexReg, 1, newIndexReg);
                emit(NOLABEL, STOREAI, newIndexReg, 0, offset);
                emit(NOLABEL, BR, (yyvsp[-6].forstmt).decLabel, EMPTY, EMPTY);
         }
#line 1654 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 231 "parse.y" /* yacc.c:1646  */
    {emit((yyvsp[-8].forstmt).falseLabel, NOP, EMPTY, EMPTY, EMPTY);}
#line 1660 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 236 "parse.y" /* yacc.c:1646  */
    { 
 				  if (! ((((yyvsp[-2].targetReg).type == TYPE_INT) && ((yyvsp[0].targetReg).type == TYPE_INT)) || 
				         (((yyvsp[-2].targetReg).type == TYPE_BOOL) && ((yyvsp[0].targetReg).type == TYPE_BOOL)))) {
				    printf("\n***ERROR: assignment types do not match.\n");
				  }
                                
                                // ***ERROR: assignment to whole array
                                  if ((yyvsp[-2].targetReg).varType == TYPE_ARRAY) {
				    printf("\n***ERROR: assignment to whole array.\n");
				  }

				  emit(NOLABEL,
                                       STORE, 
                                       (yyvsp[0].targetReg).targetRegister,
                                       (yyvsp[-2].targetReg).targetRegister,
                                       EMPTY);
                                }
#line 1682 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 255 "parse.y" /* yacc.c:1646  */
    { /* BOGUS  - needs to be fixed */
                                  int newReg1 = NextRegister();
                                  int newReg2 = NextRegister();
                                  
                                  if(lookup((yyvsp[0].token).str) == NULL){
                                          printf("\n***ERROR: undeclared identifier %s\n", (yyvsp[0].token).str);
                                          
                                  }

                                  int offset = lookup((yyvsp[0].token).str) != NULL ? lookup((yyvsp[0].token).str)->offset : NextOffset(1);
                                  
                                  sprintf(CommentBuffer, "Compute address of variable \"%s\" with base address %d", (yyvsp[0].token).str, offset);
	                         emitComment(CommentBuffer);

                                  (yyval.targetReg).targetRegister = newReg2;
                                  (yyval.targetReg).type = lookup((yyvsp[0].token).str) != NULL ? lookup((yyvsp[0].token).str)->type : TYPE_ERROR;
                                  (yyval.targetReg).varType = lookup((yyvsp[0].token).str) != NULL ? lookup((yyvsp[0].token).str)->varType : TYPE_UNDEFINED; 
				   
				  emit(NOLABEL, LOADI, offset, newReg1, EMPTY);
				  emit(NOLABEL, ADD, 0, newReg1, newReg2);
				  
                         	  }
#line 1709 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 279 "parse.y" /* yacc.c:1646  */
    { 
                                        
                                        int base_address = lookup((yyvsp[-3].token).str)->offset;
                                        sprintf(CommentBuffer, "Compute address of array \"%s\" with base address %d", (yyvsp[-3].token).str, base_address);

                                        emitComment(CommentBuffer);

                                        if((yyvsp[-1].targetReg).type != TYPE_INT){
                                                printf("\n***ERROR: subscript exp not type integer\n");
                                        }

                                        if(lookup((yyvsp[-3].token).str)->varType != TYPE_ARRAY){
                                                printf("\n***ERROR: id %s is not an array\n", (yyvsp[-3].token).str);
                                        }

                                        //Store final value in here
                                        int final_reg = NextRegister();

                                        // Load Constant 4 into a register
                                        int four_reg = NextRegister();
                                        emit(NOLABEL, LOADI, 4, four_reg, EMPTY);

                                        // Get register the index is stored in [exp]
                                        int constant_reg = (yyvsp[-1].targetReg).targetRegister;

                                        // Compute the total offset by multilying the index * 4
                                        int mult_offset_reg = NextRegister();
                                        emit(NOLABEL, MULT, constant_reg, four_reg, mult_offset_reg);
                                        
                                        //Load Base address
                                        int base_addr_reg = NextRegister();
                                        emit(NOLABEL, LOADI, base_address, base_addr_reg, EMPTY);

                                        //Compute Total Offset by adding mult_offset and base address
                                        int total_addr_reg = NextRegister();
                                        emit(NOLABEL, ADD, base_addr_reg, mult_offset_reg, total_addr_reg);

                                        //add total offset to base addr r0(1024) to get actual value
                                        emit(NOLABEL, ADD, 0, total_addr_reg, final_reg);

                                        (yyval.targetReg).targetRegister = final_reg;
                                        (yyval.targetReg).type = lookup((yyvsp[-3].token).str) != NULL ? lookup((yyvsp[-3].token).str)->type : TYPE_ERROR;
                                        (yyval.targetReg).varType = lookup((yyvsp[-3].token).str) != NULL ? lookup((yyvsp[-3].token).str)->varType : TYPE_UNDEFINED; 
         

                                  }
#line 1760 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 328 "parse.y" /* yacc.c:1646  */
    { int newReg = NextRegister();

                                  if (! (((yyvsp[-2].targetReg).type == TYPE_INT) && ((yyvsp[0].targetReg).type == TYPE_INT))) {
    				    printf("\n***ERROR: types of operands for operation + do not match\n");
                                  }
                                  (yyval.targetReg).type = (yyvsp[-2].targetReg).type;

                                  (yyval.targetReg).targetRegister = newReg;
                                  emit(NOLABEL, 
                                       ADD, 
                                       (yyvsp[-2].targetReg).targetRegister, 
                                       (yyvsp[0].targetReg).targetRegister, 
                                       newReg);
                                }
#line 1779 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 343 "parse.y" /* yacc.c:1646  */
    { int newReg = NextRegister();
                                        if(! (((yyvsp[-2].targetReg).type == TYPE_INT) && ((yyvsp[0].targetReg).type == TYPE_INT))) {
                                          printf("\n***ERROR: types of operands for operation - do not match\n");
                                        }

                                        (yyval.targetReg).type = (yyvsp[-2].targetReg).type;

                                        (yyval.targetReg).targetRegister = newReg;
                                        emit(NOLABEL, 
                                                SUB, 
                                                (yyvsp[-2].targetReg).targetRegister, 
                                                (yyvsp[0].targetReg).targetRegister, 
                                                newReg);
                                 }
#line 1798 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 358 "parse.y" /* yacc.c:1646  */
    { int newReg = NextRegister();
                                        if(! (((yyvsp[-2].targetReg).type == TYPE_INT) && ((yyvsp[0].targetReg).type == TYPE_INT))) {
                                          printf("\n***ERROR: types of operands for operation * do match\n");
                                        }

                                        (yyval.targetReg).type = (yyvsp[-2].targetReg).type;

                                        (yyval.targetReg).targetRegister = newReg;
                                        emit(NOLABEL, 
                                                MULT, 
                                                (yyvsp[-2].targetReg).targetRegister, 
                                                (yyvsp[0].targetReg).targetRegister, 
                                                newReg); 
                                }
#line 1817 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 373 "parse.y" /* yacc.c:1646  */
    { int newReg = NextRegister();

                                  if (! (((yyvsp[-2].targetReg).type == TYPE_BOOL) && ((yyvsp[0].targetReg).type == TYPE_BOOL))){
    				    printf("***ERROR: types of operands for operation AND do not match\n");
                                  }
                                  (yyval.targetReg).type = (yyvsp[-2].targetReg).type;

                                  (yyval.targetReg).targetRegister = newReg;
                                  emit(NOLABEL, 
                                       AND_INSTR, 
                                       (yyvsp[-2].targetReg).targetRegister, 
                                       (yyvsp[0].targetReg).targetRegister, 
                                       newReg); 
                                }
#line 1836 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 389 "parse.y" /* yacc.c:1646  */
    { int newReg = NextRegister();

                                  if (! (((yyvsp[-2].targetReg).type == TYPE_BOOL) && ((yyvsp[0].targetReg).type == TYPE_BOOL))) {
    				    printf("\n***ERROR: types of operands for operation OR do not match\n");
                                  }
                                  (yyval.targetReg).type = (yyvsp[-2].targetReg).type;

                                  (yyval.targetReg).targetRegister = newReg;
                                  emit(NOLABEL, 
                                       OR_INSTR, 
                                       (yyvsp[-2].targetReg).targetRegister, 
                                       (yyvsp[0].targetReg).targetRegister, 
                                       newReg); 
                                }
#line 1855 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 405 "parse.y" /* yacc.c:1646  */
    { /* BOGUS  - needs to be fixed */
	                          int newReg = NextRegister();
                                  
                                  if( lookup((yyvsp[0].token).str) == NULL){
                                        printf("\n***ERROR: undeclared identifier \"%s\"\n", (yyvsp[0].token).str);
                                        
                                  } 

                                  int offset = lookup((yyvsp[0].token).str) != NULL ? lookup((yyvsp[0].token).str)->offset : NextOffset(1);
                                  
                                  sprintf(CommentBuffer, "Load RHS value of variable \"%s\" at offset %d", (yyvsp[0].token).str, offset);
	                         emitComment(CommentBuffer);

	                          (yyval.targetReg).targetRegister = newReg;
                                  (yyval.targetReg).type = lookup((yyvsp[0].token).str) != NULL ? lookup((yyvsp[0].token).str)->type : TYPE_ERROR;
				//   $$.type = TYPE_INT;

				  emit(NOLABEL, LOADAI, 0, offset, newReg);
                                  
	                        }
#line 1880 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 426 "parse.y" /* yacc.c:1646  */
    {  
                                        int base_address = lookup((yyvsp[-3].token).str)->offset;
                                        sprintf(CommentBuffer, "Load RHS value of array variable \"%s\" with base address %d", (yyvsp[-3].token).str, base_address);

                                        emitComment(CommentBuffer);

                                        if((yyvsp[-1].targetReg).type != TYPE_INT){
                                                printf("\n***ERROR: subscript exp not type integer\n");
                                        }

                                        if(lookup((yyvsp[-3].token).str)->varType != TYPE_ARRAY){
                                                printf("\n***ERROR: id %s is not an array\n", (yyvsp[-3].token).str);
                                        }

                                        //Store final value in here
                                        int final_reg = NextRegister();

                                        // Load Constant 4 into a register
                                        int four_reg = NextRegister();
                                        emit(NOLABEL, LOADI, 4, four_reg, EMPTY);

                                        // Get register the index is stored in [exp]
                                        int constant_reg = (yyvsp[-1].targetReg).targetRegister;

                                        // Compute the total offset by multilying the index * 4
                                        int mult_offset_reg = NextRegister();
                                        emit(NOLABEL, MULT, constant_reg, four_reg, mult_offset_reg);
                                        
                                        //Load Base address
                                        int base_addr_reg = NextRegister();
                                        emit(NOLABEL, LOADI, base_address, base_addr_reg, EMPTY);

                                        //Compute Total Offset by adding mult_offset and base address
                                        int total_addr_reg = NextRegister();
                                        emit(NOLABEL, ADD, base_addr_reg, mult_offset_reg, total_addr_reg);

                                        //add total offset to base addr r0(1024) to get actual value
                                        emit(NOLABEL, LOADAO, 0, total_addr_reg, final_reg);

                                        (yyval.targetReg).targetRegister = final_reg;
                                        (yyval.targetReg).type = lookup((yyvsp[-3].token).str)->type;

                                }
#line 1928 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 472 "parse.y" /* yacc.c:1646  */
    { int newReg = NextRegister();
	                           (yyval.targetReg).targetRegister = newReg;
				   (yyval.targetReg).type = TYPE_INT;
				   emit(NOLABEL, LOADI, (yyvsp[0].token).num, newReg, EMPTY); }
#line 1937 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 477 "parse.y" /* yacc.c:1646  */
    { int newReg = NextRegister(); /* TRUE is encoded as value '1' */
	                           (yyval.targetReg).targetRegister = newReg;
				   (yyval.targetReg).type = TYPE_BOOL;
				   emit(NOLABEL, LOADI, 1, newReg, EMPTY); }
#line 1946 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 482 "parse.y" /* yacc.c:1646  */
    { int newReg = NextRegister(); /* FALSE is encoded as value '0' */
	                           (yyval.targetReg).targetRegister = newReg;
				   (yyval.targetReg).type = TYPE_BOOL;
				   emit(NOLABEL, LOADI, 0, newReg, EMPTY); }
#line 1955 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 487 "parse.y" /* yacc.c:1646  */
    { yyerror("***Error: illegal expression\n");}
#line 1961 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 491 "parse.y" /* yacc.c:1646  */
    { 
                                sprintf(CommentBuffer, "Initialize ind. variable \"%s\" at offset X with lower bound value %d", (yyvsp[-4].token).str, (yyvsp[-2].token));
                                emitComment(CommentBuffer); 

                                int offset = lookup((yyvsp[-4].token).str) != NULL ? lookup((yyvsp[-4].token).str)->offset : NextOffset(1);
                                int newReg = NextRegister(); //offset of i
                                emit(NOLABEL, LOADI, offset, newReg, EMPTY);

                                int memReg = NextRegister(); //mem addr for i
                                emit(NOLABEL, ADD, 0, newReg, memReg);

                                // Load In start and end bound
                                int start = (yyvsp[-2].token).num;
                                int end = (yyvsp[0].token).num;

                                if( start > end){
                                        printf("\n***ERROR: lower bound exceeds upper bound\n");
                                }
                                if( lookup((yyvsp[-4].token).str)->varType != TYPE_SCALAR ) {
                                        printf("\n***ERROR: induction variable %s not scalar integer variable\n", (yyvsp[-4].token).str);
                                }
                                
                                int startReg = NextRegister();
                                int endReg = NextRegister();

                                emit(NOLABEL, LOADI, start, startReg, EMPTY);
                                emit(NOLABEL, LOADI, end, endReg, EMPTY);

                                emit(NOLABEL, STORE, startReg, memReg, EMPTY);

                                (yyval.controlStmt).indexStr = (yyvsp[-4].token).str;
                                (yyval.controlStmt).upperBoundReg = endReg;
        
                        }
#line 2000 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 527 "parse.y" /* yacc.c:1646  */
    { 
                                        if (! ((((yyvsp[-2].targetReg).type == TYPE_INT) && ((yyvsp[0].targetReg).type == TYPE_INT)) ||
                                        (((yyvsp[-2].targetReg).type == TYPE_BOOL) && ((yyvsp[0].targetReg).type == TYPE_BOOL)))) {
                                                printf("\n***ERROR: types of operrands for operation != do not match\n");
                                        }

                                        int newReg = NextRegister();
                                        emit(NOLABEL, CMPNE, (yyvsp[-2].targetReg).targetRegister, (yyvsp[0].targetReg).targetRegister, newReg);

                                        (yyval.conditionStmt).targetReg = newReg; 

                                }
#line 2017 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 540 "parse.y" /* yacc.c:1646  */
    {  
                                        if (! ((((yyvsp[-2].targetReg).type == TYPE_INT) && ((yyvsp[0].targetReg).type == TYPE_INT)) ||
                                        (((yyvsp[-2].targetReg).type == TYPE_BOOL) && ((yyvsp[0].targetReg).type == TYPE_BOOL)))) {
                                                printf("\n***ERROR: types of operrands for operation == do not match\n");
                                        }

                                        int newReg = NextRegister();
                                        emit(NOLABEL, CMPEQ, (yyvsp[-2].targetReg).targetRegister, (yyvsp[0].targetReg).targetRegister, newReg);

                                        (yyval.conditionStmt).targetReg = newReg; 

                                }
#line 2034 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 553 "parse.y" /* yacc.c:1646  */
    {//MUST BE INTEGERS

                                        if (! (((yyvsp[-2].targetReg).type == TYPE_INT) && ((yyvsp[0].targetReg).type == TYPE_INT))) {
                                                printf("\n***ERROR: types of operrands for operation < do not match\n");
                                        }
                                        int newReg = NextRegister();
                                        emit(NOLABEL, CMPLT, (yyvsp[-2].targetReg).targetRegister, (yyvsp[0].targetReg).targetRegister, newReg);

                                        (yyval.conditionStmt).targetReg = newReg;
                                 }
#line 2049 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 564 "parse.y" /* yacc.c:1646  */
    { //MUST BE INTEGERS
                                        if (! (((yyvsp[-2].targetReg).type == TYPE_INT) && ((yyvsp[0].targetReg).type == TYPE_INT))) {
                                                printf("\n***ERROR: types of operrands for operation <= do not match\n");
                                        }
                                        int newReg = NextRegister();
                                        emit(NOLABEL, CMPLE, (yyvsp[-2].targetReg).targetRegister, (yyvsp[0].targetReg).targetRegister, newReg);

                                        (yyval.conditionStmt).targetReg = newReg; 
                                }
#line 2063 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 574 "parse.y" /* yacc.c:1646  */
    { 
                                        if (! (((yyvsp[-2].targetReg).type == TYPE_INT) && ((yyvsp[0].targetReg).type == TYPE_INT))) {
                                                printf("\n***ERROR: types of operrands for operation <= do not match\n");
                                        }

                                        int newReg = NextRegister();
                                        emit(NOLABEL, CMPGT, (yyvsp[-2].targetReg).targetRegister, (yyvsp[0].targetReg).targetRegister, newReg);

                                        (yyval.conditionStmt).targetReg = newReg; 
                                }
#line 2078 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 585 "parse.y" /* yacc.c:1646  */
    { 
                                        if (! (((yyvsp[-2].targetReg).type == TYPE_INT) && ((yyvsp[0].targetReg).type == TYPE_INT))) {
                                                printf("\n***ERROR: types of operrands for operation <= do not match\n");
                                        }

                                        int newReg = NextRegister();
                                        emit(NOLABEL, CMPGE, (yyvsp[-2].targetReg).targetRegister, (yyvsp[0].targetReg).targetRegister, newReg);

                                        (yyval.conditionStmt).targetReg = newReg; 


                                }
#line 2095 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 598 "parse.y" /* yacc.c:1646  */
    { yyerror("***Error: illegal conditional expression\n");}
#line 2101 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 2105 "parse.tab.c" /* yacc.c:1646  */
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
#line 601 "parse.y" /* yacc.c:1906  */


void yyerror(char* s) {
        fprintf(stderr,"%s\n",s);
        }


int
main(int argc, char* argv[]) {

  printf("\n     CS415 Spring 2021 Compiler\n\n");

  outfile = fopen("iloc.out", "w");
  if (outfile == NULL) { 
    printf("ERROR: Cannot open output file \"iloc.out\".\n");
    return -1;
  }

  CommentBuffer = (char *) malloc(1832);  
  InitSymbolTable();

  printf("1\t");
  yyparse();
  printf("\n");

  PrintSymbolTable();
  
  fclose(outfile);
  
  return 1;
}




