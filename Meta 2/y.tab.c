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
#line 1 "jucompiler.y" /* yacc.c:339  */

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include "structures.h"
    #define NSYMS 100

    symtab tab[NSYMS];

    node *head = NULL;

    symtab *symlook(char *varname);
    void print_tabelita();
    float powerzito(float a, float b);
    int yylex(void);
    void yyerror (const char *s);

#line 85 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    AND = 258,
    ASSIGN = 259,
    STAR = 260,
    COMMA = 261,
    DIV = 262,
    EQ = 263,
    GE = 264,
    GT = 265,
    IF = 266,
    LBRACE = 267,
    LE = 268,
    LPAR = 269,
    LSQ = 270,
    LT = 271,
    MINUS = 272,
    MOD = 273,
    NE = 274,
    NOT = 275,
    OR = 276,
    PLUS = 277,
    RBRACE = 278,
    RPAR = 279,
    RSQ = 280,
    SEMICOLON = 281,
    ARROW = 282,
    LSHIFT = 283,
    RSHIFT = 284,
    XOR = 285,
    BOOL = 286,
    CLASS = 287,
    DOTLENGTH = 288,
    DOUBLE = 289,
    ELSE = 290,
    INT = 291,
    PRINT = 292,
    PARSEINT = 293,
    PUBLIC = 294,
    RETURN = 295,
    STATIC = 296,
    STRING = 297,
    VOID = 298,
    WHILE = 299,
    INTLIT = 300,
    REALLIT = 301,
    BOOLLIT = 302,
    RESERVED = 303,
    ID = 304,
    STRLIT = 305
  };
#endif
/* Tokens.  */
#define AND 258
#define ASSIGN 259
#define STAR 260
#define COMMA 261
#define DIV 262
#define EQ 263
#define GE 264
#define GT 265
#define IF 266
#define LBRACE 267
#define LE 268
#define LPAR 269
#define LSQ 270
#define LT 271
#define MINUS 272
#define MOD 273
#define NE 274
#define NOT 275
#define OR 276
#define PLUS 277
#define RBRACE 278
#define RPAR 279
#define RSQ 280
#define SEMICOLON 281
#define ARROW 282
#define LSHIFT 283
#define RSHIFT 284
#define XOR 285
#define BOOL 286
#define CLASS 287
#define DOTLENGTH 288
#define DOUBLE 289
#define ELSE 290
#define INT 291
#define PRINT 292
#define PARSEINT 293
#define PUBLIC 294
#define RETURN 295
#define STATIC 296
#define STRING 297
#define VOID 298
#define WHILE 299
#define INTLIT 300
#define REALLIT 301
#define BOOLLIT 302
#define RESERVED 303
#define ID 304
#define STRLIT 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "jucompiler.y" /* yacc.c:355  */

    char *str;
    struct node *node;

#line 230 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 247 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   375

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

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
       0,    38,    38,    47,    54,    61,    63,    66,    75,    89,
      98,   101,   102,   103,   106,   115,   126,   134,   137,   151,
     164,   177,   180,   189,   197,   206,   209,   220,   228,   231,
     242,   257,   269,   277,   283,   292,   301,   304,   311,   314,
     319,   322,   328,   334,   340,   343,   349,   356,   361,   370,
     385,   397,   410,   414,   420,   426,   432,   438,   444,   450,
     456,   462,   468,   474,   480,   486,   492,   498,   504,   510,
     516,   522,   528,   534,   540,   546,   550,   554,   558,   563,
     564
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "ASSIGN", "STAR", "COMMA", "DIV",
  "EQ", "GE", "GT", "IF", "LBRACE", "LE", "LPAR", "LSQ", "LT", "MINUS",
  "MOD", "NE", "NOT", "OR", "PLUS", "RBRACE", "RPAR", "RSQ", "SEMICOLON",
  "ARROW", "LSHIFT", "RSHIFT", "XOR", "BOOL", "CLASS", "DOTLENGTH",
  "DOUBLE", "ELSE", "INT", "PRINT", "PARSEINT", "PUBLIC", "RETURN",
  "STATIC", "STRING", "VOID", "WHILE", "INTLIT", "REALLIT", "BOOLLIT",
  "RESERVED", "ID", "STRLIT", "$accept", "Program", "ProgramOpt",
  "MethodDecl", "FieldDecl", "FieldDeclOpt", "Type", "MethodHeader",
  "MethodHeaderOpt2", "FormalParams", "FormalParamsOpt", "MethodBody",
  "MethodBody2", "VarDecl", "VarDeclOpt", "Statement", "StatementOpt",
  "StatementOpt2", "StatementOpt3", "StatementOpt4", "StatementOpt5",
  "MethodInvocation", "MethodInvocationOpt", "Assignment", "ParseArgs",
  "Expr", "DotLengthOpt", YY_NULLPTR
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
     305
};
# endif

#define YYPACT_NINF -40

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-40)))

#define YYTABLE_NINF -45

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -26,   -39,    12,     2,   -40,   -18,   -18,    -9,    21,   -18,
     -18,   -40,    63,   -40,   -40,   -40,   -40,   -40,   -40,    -3,
       3,    31,    45,    -1,    44,   -40,    73,     9,    73,    38,
      51,   184,    53,    55,   129,    57,    20,    23,    50,    44,
      44,    59,   -40,   -40,   -40,    62,    30,    65,   -40,    84,
      71,   -40,   129,   184,    78,   185,    47,   129,   129,   129,
     129,   -40,   -40,   -40,    43,    79,   -40,   -40,   -40,   345,
     129,   129,   129,    97,   -40,   -40,   -40,   -40,    83,   104,
     -40,   -40,   -40,   233,   -40,   -40,   -40,    87,   345,    98,
     261,   345,   345,   345,   -40,   -40,   -40,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   289,   345,    90,    32,    67,    91,    70,
      -6,   -40,   160,    95,   129,   -40,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   160,   -40,   -40,    97,   -40,   -40,    74,    89,
     -40,   317,   -40,   -40,   104,   160,   -40,   113,   -40,   -40,
     -40
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     6,     6,     0,     0,     6,
       6,     5,     0,     2,     3,     4,    11,    13,    12,     0,
       0,     0,     0,    10,    25,     7,    17,     0,    17,     0,
       0,    36,     0,     0,    40,     0,     0,     0,     0,    25,
      25,     0,    41,    42,    43,     0,     0,     0,    16,    10,
       0,     8,     0,    36,     0,     0,     0,     0,     0,     0,
       0,    76,    77,    78,    80,     0,    72,    73,    74,    39,
       0,     0,    49,    28,    22,    24,    23,    33,     0,    21,
      15,     9,    14,     0,    35,    29,    46,     0,    45,     0,
       0,    69,    70,    71,    79,    75,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,    17,     0,     0,     0,
       0,    18,    44,     0,     0,    52,    58,    55,    56,    63,
      64,    65,    66,    67,    54,    57,    68,    59,    53,    61,
      62,    60,    44,    47,    48,    28,    26,    19,     0,    38,
      34,     0,    31,    27,    21,    44,    30,     0,    20,    37,
      51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -40,   -40,    77,   -40,   -40,    80,    10,   -40,   -25,   -40,
     -16,   -40,   -13,   -40,   -17,   -30,    92,   -40,   -40,   -40,
     -40,   -24,   -40,   -22,   -20,    82,   -40
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    10,    29,    37,    21,    47,    48,
     121,    25,    38,    39,   118,    40,    54,   156,    65,    41,
      87,    66,   115,    67,    68,    69,    95
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    53,    43,    50,    44,    27,     1,    42,     6,    43,
       3,    44,     4,    28,     5,    42,    42,    43,    43,    44,
      44,     7,    20,    53,    71,    16,    75,    76,    17,    42,
      18,    43,    12,    44,    72,    97,    46,    98,    46,    99,
     100,   101,   102,    24,    13,   103,    22,    71,   104,   105,
     106,   107,    23,   108,   109,    30,    31,    72,    49,    26,
     110,   111,   112,    16,    51,    52,    17,    55,    18,    56,
     -44,    70,    73,    74,    45,    16,    94,    78,    17,    79,
      18,    32,    33,    11,    34,    77,    14,    15,    35,    80,
      27,   144,   149,    36,    16,    82,    89,    17,    42,    18,
      43,    85,    44,   117,    16,    96,    19,    17,   119,    18,
     120,   123,   152,   124,   143,    45,   145,   146,    42,   147,
      43,   150,    44,   154,   155,   159,    46,   160,   153,    81,
     148,    42,     0,    43,    83,    44,     0,    88,   158,    90,
      91,    92,    93,    57,     0,    84,    58,     0,     0,    59,
       0,    60,   113,   114,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     0,
       0,    30,    31,     0,    61,    62,    63,     0,    64,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,    30,    31,    32,    33,    57,
      34,     0,    58,     0,    35,    59,   151,    60,     0,    36,
     -44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,    33,    34,     0,     0,     0,    35,     0,
      61,    62,    63,    36,    64,    86,    97,     0,    98,     0,
      99,   100,   101,   102,     0,     0,   103,     0,     0,   104,
     105,   106,   107,     0,   108,   109,     0,   122,     0,     0,
       0,   110,   111,   112,    97,     0,    98,     0,    99,   100,
     101,   102,     0,     0,   103,     0,     0,   104,   105,   106,
     107,     0,   108,   109,     0,   125,     0,     0,     0,   110,
     111,   112,    97,     0,    98,     0,    99,   100,   101,   102,
       0,     0,   103,     0,     0,   104,   105,   106,   107,     0,
     108,   109,     0,   142,     0,     0,     0,   110,   111,   112,
      97,     0,    98,     0,    99,   100,   101,   102,     0,     0,
     103,     0,     0,   104,   105,   106,   107,     0,   108,   109,
       0,     0,   157,     0,     0,   110,   111,   112,    97,     0,
      98,     0,    99,   100,   101,   102,     0,     0,   103,     0,
       0,   104,   105,   106,   107,     0,   108,   109,     0,     0,
       0,     0,     0,   110,   111,   112
};

static const yytype_int16 yycheck[] =
{
      24,    31,    24,    28,    24,     6,    32,    31,    26,    31,
      49,    31,     0,    14,    12,    39,    40,    39,    40,    39,
      40,    39,    12,    53,     4,    31,    39,    40,    34,    53,
      36,    53,    41,    53,    14,     3,    26,     5,    28,     7,
       8,     9,    10,    12,    23,    13,    49,     4,    16,    17,
      18,    19,    49,    21,    22,    11,    12,    14,    49,    14,
      28,    29,    30,    31,    26,    14,    34,    14,    36,    14,
      26,    14,    49,    23,    42,    31,    33,    15,    34,    49,
      36,    37,    38,     6,    40,    26,     9,    10,    44,    24,
       6,   116,   122,    49,    31,    24,    49,    34,   122,    36,
     122,    23,   122,     6,    31,    26,    43,    34,    25,    36,
       6,    24,   142,    15,    24,    42,    49,    26,   142,    49,
     142,    26,   142,    49,    35,   155,   116,    14,   145,    49,
     120,   155,    -1,   155,    52,   155,    -1,    55,   154,    57,
      58,    59,    60,    14,    -1,    53,    17,    -1,    -1,    20,
      -1,    22,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    11,    12,    -1,    45,    46,    47,    -1,    49,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    11,    12,    37,    38,    14,
      40,    -1,    17,    -1,    44,    20,   124,    22,    -1,    49,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    38,    40,    -1,    -1,    -1,    44,    -1,
      45,    46,    47,    49,    49,    50,     3,    -1,     5,    -1,
       7,     8,     9,    10,    -1,    -1,    13,    -1,    -1,    16,
      17,    18,    19,    -1,    21,    22,    -1,    24,    -1,    -1,
      -1,    28,    29,    30,     3,    -1,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    13,    -1,    -1,    16,    17,    18,
      19,    -1,    21,    22,    -1,    24,    -1,    -1,    -1,    28,
      29,    30,     3,    -1,     5,    -1,     7,     8,     9,    10,
      -1,    -1,    13,    -1,    -1,    16,    17,    18,    19,    -1,
      21,    22,    -1,    24,    -1,    -1,    -1,    28,    29,    30,
       3,    -1,     5,    -1,     7,     8,     9,    10,    -1,    -1,
      13,    -1,    -1,    16,    17,    18,    19,    -1,    21,    22,
      -1,    -1,    25,    -1,    -1,    28,    29,    30,     3,    -1,
       5,    -1,     7,     8,     9,    10,    -1,    -1,    13,    -1,
      -1,    16,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    52,    49,     0,    12,    26,    39,    53,    54,
      55,    53,    41,    23,    53,    53,    31,    34,    36,    43,
      57,    58,    49,    49,    12,    62,    14,     6,    14,    56,
      11,    12,    37,    38,    40,    44,    49,    57,    63,    64,
      66,    70,    72,    74,    75,    42,    57,    59,    60,    49,
      59,    26,    14,    66,    67,    14,    14,    14,    17,    20,
      22,    45,    46,    47,    49,    69,    72,    74,    75,    76,
      14,     4,    14,    49,    23,    63,    63,    26,    15,    49,
      24,    56,    24,    76,    67,    23,    50,    71,    76,    49,
      76,    76,    76,    76,    33,    77,    26,     3,     5,     7,
       8,     9,    10,    13,    16,    17,    18,    19,    21,    22,
      28,    29,    30,    76,    76,    73,    76,     6,    65,    25,
       6,    61,    24,    24,    15,    24,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    24,    24,    59,    49,    26,    49,    57,    66,
      26,    76,    66,    65,    49,    35,    68,    25,    61,    66,
      14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    55,    56,
      56,    57,    57,    57,    58,    58,    59,    59,    60,    60,
      61,    61,    62,    63,    63,    63,    64,    65,    65,    66,
      66,    66,    66,    66,    66,    67,    67,    68,    68,    69,
      69,    70,    70,    70,    70,    71,    71,    72,    73,    73,
      74,    75,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    77,
      77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     2,     2,     0,     4,     6,     3,
       0,     1,     1,     1,     5,     5,     1,     0,     3,     4,
       4,     0,     3,     2,     2,     0,     4,     3,     0,     3,
       6,     5,     3,     2,     5,     2,     0,     2,     0,     1,
       0,     1,     1,     1,     0,     1,     1,     4,     2,     0,
       3,     7,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     1,     1,     1,     2,     1,     1,     1,     1,
       0
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
#line 38 "jucompiler.y" /* yacc.c:1646  */
    {
                                                    head = create_node("Program", "");
                                                    if ((yyvsp[-1].node) != NULL){
                                                        add_child(head, (yyvsp[-1].node));
                                                    }
                                                    (yyval.node) = head;
                                                }
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 47 "jucompiler.y" /* yacc.c:1646  */
    {
                                        if ((yyvsp[0].node) != NULL){
                                            add_bro((yyvsp[-1].node), (yyvsp[0].node));
                                        }
                                        (yyval.node) = (yyvsp[-1].node);
                                    }
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 54 "jucompiler.y" /* yacc.c:1646  */
    {
                                        if ((yyvsp[0].node) != NULL){
                                            add_bro((yyvsp[-1].node), (yyvsp[0].node));
                                        }
                                        (yyval.node) = (yyvsp[-1].node);
                                    }
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 61 "jucompiler.y" /* yacc.c:1646  */
    {}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 63 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 66 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        node *methoddecl = create_node("MethodDecl", "");
                                                        add_child(methoddecl, (yyvsp[-1].node));
                                                        add_child(methoddecl, (yyvsp[0].node));
                                                        add_bro((yyvsp[-1].node), (yyvsp[0].node));
                                                        (yyval.node) = methoddecl;
                                                    }
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 75 "jucompiler.y" /* yacc.c:1646  */
    {
                                                                    node *fielddecl = create_node("FieldDecl", "");
                                                                    add_child(fielddecl, (yyvsp[-3].node));
                                                                    add_child(fielddecl, (yyvsp[-2].str));
                                                                    add_bro((yyvsp[-3].node), (yyvsp[-2].str));
                                                                    if((yyvsp[-1].node) != NULL){
                                                                        add_child(fielddecl, (yyvsp[-1].node));
                                                                        add_bro((yyvsp[-3].node), (yyvsp[-1].node));
                                                                        add_bro((yyvsp[-2].str), (yyvsp[-1].node));
                                                                    }
                                                                    (yyval.node) = fielddecl;
                                                            }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 89 "jucompiler.y" /* yacc.c:1646  */
    {
                                                node *id = create_node("Id", (yyvsp[-1].str));
                                                if((yyvsp[0].node) != NULL){
                                                    (yyval.node) = add_bro(id, (yyvsp[0].node));
                                                }
                                                else{
                                                    (yyval.node) = id;
                                                }
                                            }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 98 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 101 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("Bool", "");}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 102 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("Int", "");}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 103 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("Double", "");}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 106 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            node *methodheader = create_node("MethodHeader","");
                                                            node *id = create_node("Id",(yyvsp[-3].str));
                                                            add_child(methodheader,id);
                                                            if((yyvsp[-1].node) != NULL){
                                                                add_child(methodheader,(yyvsp[-1].node));
                                                            }
                                                            (yyval.node) = methodheader;
                                                        }
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 115 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            node *methodheader = create_node("MethodHeader","");
                                                            node *id = create_node("Id",(yyvsp[-3].str));
                                                            add_child(methodheader,id);
                                                            if((yyvsp[-1].node) != NULL){
                                                                add_child(methodheader,(yyvsp[-1].node));
                                                            }
                                                            (yyval.node) = methodheader;
                                                        }
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 126 "jucompiler.y" /* yacc.c:1646  */
    {
                                            if((yyvsp[0].node) != NULL){
                                                (yyval.node) = (yyvsp[0].node);
                                            }
                                            else{
                                                (yyval.node) = NULL;
                                            }
                                        }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 134 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 137 "jucompiler.y" /* yacc.c:1646  */
    {
                                                node *parametros = create_node("MethodParams","");
                                                node *paramsDecl = create_node("ParamDecl","");
                                                node *id = create_node("Id",(yyvsp[-1].str));
                                                add_child(parametros,paramsDecl);
                                                add_child(paramsDecl,(yyvsp[-2].node));
                                                add_child(paramsDecl,id);
                                                add_bro((yyvsp[-2].node),(yyvsp[-1].str));
                                                if((yyvsp[0].node) != NULL){
                                                    add_child(parametros,(yyvsp[0].node));
                                                    add_bro(paramsDecl,(yyvsp[0].node));
                                                } 
                                                (yyval.node) = parametros;
                                            }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 151 "jucompiler.y" /* yacc.c:1646  */
    {
                                                node *parametros = create_node("MethodParams","");
                                                node *paramsDecl = create_node("ParamDecl","");
                                                node *string = create_node("String","");
                                                node *id = create_node("id",(yyvsp[0].str));
                                                add_child(parametros,paramsDecl);
                                                add_child(paramsDecl,string);
                                                add_child(paramsDecl,id);
                                                add_bro(string,id);
                                                (yyval.node) = parametros;
                                            }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 164 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            node *paramsDecl = create_node("ParamDecl","");
                                                            node *id = create_node("Id",(yyvsp[-1].str));
                                                            add_child(paramsDecl,(yyvsp[-2].node));
                                                            add_child(paramsDecl, id);
                                                            add_bro((yyvsp[-2].node),id);
                                                            if((yyvsp[0].node) != NULL){
                                                                (yyval.node) = add_bro(paramsDecl, (yyvsp[0].node));               
                                                            }
                                                            else{
                                                                (yyval.node) = paramsDecl;
                                                            }               
                                                        }
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 177 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 180 "jucompiler.y" /* yacc.c:1646  */
    {
                                                    node *methodbody = create_node("MethodBody","");
                                                    if((yyvsp[-1].node) != NULL){
                                                        add_child(methodbody,(yyvsp[-1].node));
                                                    }
                                                    (yyval.node) = methodbody;
                                            }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 189 "jucompiler.y" /* yacc.c:1646  */
    {
                                                if((yyvsp[0].node) != NULL){
                                                    (yyval.node) = add_bro((yyvsp[-1].node), (yyvsp[0].node));
                                                }
                                                else{
                                                    (yyval.node) = (yyvsp[-1].node);
                                                }
                                            }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 197 "jucompiler.y" /* yacc.c:1646  */
    {
                                                if((yyvsp[0].node) != NULL){
                                                    (yyval.node) = add_bro((yyvsp[-1].node), (yyvsp[0].node));
                                                }
                                                else{
                                                    (yyval.node) = (yyvsp[-1].node);
                                                }
                                                
                                            }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 206 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 209 "jucompiler.y" /* yacc.c:1646  */
    {
                                                node *vardecl = create_node("VarDecl", "");
                                                if ((yyvsp[-2].str) != NULL && (yyvsp[-1].node) != NULL){
                                                    add_child(vardecl, (yyvsp[-2].str));
                                                    add_child(vardecl, (yyvsp[-1].node));
                                                    add_bro((yyvsp[-2].str), (yyvsp[-1].node));
                                                }
                                                (yyval.node) = vardecl;
                                            }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 220 "jucompiler.y" /* yacc.c:1646  */
    {
                                        if ((yyvsp[0].node) != NULL){
                                            (yyval.node) = add_bro((yyvsp[-1].str), (yyvsp[0].node));
                                        }
                                        else{
                                            (yyval.node) = NULL;
                                        }
                                    }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 228 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 231 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            if ((yyvsp[-1].node) != NULL && (yyvsp[-1].node)->bro != NULL){
                                                                node *block = create_node("Block", "");
                                                                add_child(block, (yyvsp[-1].node));
                                                                (yyval.node) = block;
                                                            }
                                                            else{
                                                                (yyval.node) = (yyvsp[-1].node);
                                                            }
                                                        }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 242 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            node *iff = create_node("If", "");
                                                            if ((yyvsp[-3].node) != NULL){
                                                                add_child(iff, (yyvsp[-3].node));
                                                            }
                                                            node *block = create_node("Block", "");
                                                            if ((yyvsp[-1].node) != NULL){
                                                                add_child(block, (yyvsp[-1].node));
                                                            }
                                                            if ((yyvsp[0].node) != NULL){
                                                                add_bro(if, (yyvsp[0].node));
                                                            }
                                                            (yyval.node) = iff;
                                                        }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 257 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            node *whilee = create_node("While", "");
                                                            if ((yyvsp[-2].node) != NULL){
                                                                add_child(whilee, (yyvsp[-2].node));
                                                            }
                                                            node *block = create_node("Block", "");
                                                            if ((yyvsp[0].node) != NULL){
                                                                add_child(block, (yyvsp[0].node));
                                                            }
                                                            (yyval.node) = whilee;
                                                        }
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 269 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            node *return = create_node("Return", "");
                                                            if ((yyvsp[-1].node) != NULL){
                                                                add_child(return, (yyvsp[-1].node));
                                                            }
                                                            (yyval.node) = return;
                                                        }
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 277 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            if ((yyvsp[-1].node) != NULL){
                                                                (yyval.node) = (yyvsp[-1].node);
                                                            }
                                                        }
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 283 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            node *print = create_node("Print", "");
                                                            if ((yyvsp[-2].node) != NULL){
                                                                add_child(print, (yyvsp[-2].node));
                                                            }
                                                            (yyval.node) = print;
                                                        }
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 292 "jucompiler.y" /* yacc.c:1646  */
    {
                                                if ((yyvsp[0].node) != NULL){
                                                    (yyval.node) = (yyvsp[-1].node);
                                                }
                                                else{
                                                    (yyval.node) = NULL;
                                                }
                                            }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 301 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 304 "jucompiler.y" /* yacc.c:1646  */
    {
                                                node *elsee = create_node("Else", "");
                                                if ((yyvsp[0].node) != NULL){
                                                    add_child(elsee, (yyvsp[0].node));
                                                }
                                                (yyval.node) = elsee;
                                            }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 311 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 314 "jucompiler.y" /* yacc.c:1646  */
    {
                                if ((yyvsp[0].node) != NULL){
                                    (yyval.node) = (yyvsp[0].node);
                                }
                            }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 319 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 322 "jucompiler.y" /* yacc.c:1646  */
    {
                                            if ((yyvsp[0].node) != NULL){
                                                (yyval.node) = (yyvsp[0].node);
                                            }
                                        }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 328 "jucompiler.y" /* yacc.c:1646  */
    {
                                            if ((yyvsp[0].node) != NULL){
                                                (yyval.node) = (yyvsp[0].node);
                                            }
                                        }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 334 "jucompiler.y" /* yacc.c:1646  */
    {
                                            if ((yyvsp[0].node) != NULL){
                                                (yyval.node) = (yyvsp[0].node);
                                            }
                                        }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 340 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 343 "jucompiler.y" /* yacc.c:1646  */
    {
                                            if ((yyvsp[0].node) != NULL){
                                                (yyval.node) = (yyvsp[0].node);
                                            }
                                        }
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 349 "jucompiler.y" /* yacc.c:1646  */
    {
                                            if ((yyvsp[0].str) != NULL){
                                                (yyval.node) = (yyvsp[0].str);
                                            }
                                        }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 356 "jucompiler.y" /* yacc.c:1646  */
    {
                                                                /* ns o que fazer aqui */
                                                            }
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 361 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        /* ns o que fazer aqui */
                                                        if ((yyvsp[0].node) != NULL){
                                                            (yyval.node) = (yyvsp[0].node);
                                                        }
                                                        else{
                                                            (yyval.node) = NULL;
                                                        }
                                                    }
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 370 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 385 "jucompiler.y" /* yacc.c:1646  */
    {
                                    node *assign = create_node("Assign", "");
                                    add_child(assign, create_node("Id", (yyvsp[-2].str)));
                                    if ((yyvsp[0].node) != NULL){
                                        (yyval.node) = add_child(assign, (yyvsp[0].node));
                                    }
                                    else{
                                        (yyval.node) = NULL;
                                    }
                                }
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 397 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        node *parseargs = create_node("ParseArgs", "");
                                                        if ((yyvsp[-4].str) != NULL){
                                                            add_child(parseargs, (yyvsp[-4].str));
                                                        }
                                                        if ((yyvsp[-2].node) != NULL){
                                                            add_child(parseargs, (yyvsp[-2].node));
                                                            add_bro((yyvsp[-4].str), (yyvsp[-2].node));
                                                        }
                                                        (yyval.node) = parseargs;
                                                    }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 410 "jucompiler.y" /* yacc.c:1646  */
    {
                                    (yyval.node) = (yyvsp[-1].node);
                                }
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 414 "jucompiler.y" /* yacc.c:1646  */
    {
                                    node *plus = create_node("Add", "");
                                    add_child(plus,(yyvsp[-2].node));
                                    (yyval.node) = add_child(plus, (yyvsp[0].node));
                                }
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 420 "jucompiler.y" /* yacc.c:1646  */
    {
                                    node *minus = create_node("Sub", "");
                                    add_child(minus,(yyvsp[-2].node));
                                    (yyval.node) = add_child(minus, (yyvsp[0].node));
                                }
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 426 "jucompiler.y" /* yacc.c:1646  */
    {   
                                    node *star = create_node("Mul", "");
                                    add_child(star,(yyvsp[-2].node));
                                    (yyval.node) = add_child(star, (yyvsp[0].node));
                                }
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 432 "jucompiler.y" /* yacc.c:1646  */
    {
                                    node *div = create_node("Div", "");
                                    add_child(div,(yyvsp[-2].node));
                                    (yyval.node) = add_child(div, (yyvsp[0].node));
                                }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 438 "jucompiler.y" /* yacc.c:1646  */
    {
                                    node *mod = create_node("Mod", "");
                                    add_child(mod,(yyvsp[-2].node));
                                    (yyval.node) = add_child(mod, (yyvsp[0].node));
                                }
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 444 "jucompiler.y" /* yacc.c:1646  */
    {
                                    node *and = create_node("And", "");
                                    add_child(and,(yyvsp[-2].node));
                                    (yyval.node) = add_child(and, (yyvsp[0].node));
                                }
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 450 "jucompiler.y" /* yacc.c:1646  */
    {
                                    node *or = create_node("OR","");
                                    add_child(or,(yyvsp[-2].node));
                                    (yyval.node) = add_child(or, (yyvsp[0].node));
                                }
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 456 "jucompiler.y" /* yacc.c:1646  */
    {
                                    node *xor = create_node("Xor", "");
                                    add_child(xor, (yyvsp[-2].node));
                                    (yyval.node) = add_child(xor, (yyvsp[0].node));
                                }
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 462 "jucompiler.y" /* yacc.c:1646  */
    {
                                    node *lshift = create_node("Lshift", "");
                                    add_child(lshift, (yyvsp[-2].node));
                                    (yyval.node) = add_child(lshift, (yyvsp[0].node));
                                }
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 468 "jucompiler.y" /* yacc.c:1646  */
    {
                                    node *rshift = create_node("Rshift", "");
                                    add_child(rshift, (yyvsp[-2].node));
                                    (yyval.node) = add_child(rshift, (yyvsp[0].node));
                                }
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 474 "jucompiler.y" /* yacc.c:1646  */
    {
                                    node *eq = create_node("Eq", "");
                                    add_child(eq, (yyvsp[-2].node));
                                    (yyval.node) = add_child(eq, (yyvsp[0].node));
                                }
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 480 "jucompiler.y" /* yacc.c:1646  */
    {                                    
                                    node *ge = create_node("Ge", "");
                                    add_child(ge, (yyvsp[-2].node));
                                    (yyval.node) = add_child(ge, (yyvsp[0].node));
                                }
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 486 "jucompiler.y" /* yacc.c:1646  */
    {
                                    node *gt = create_node("Gt", "");
                                    add_child(gt, (yyvsp[-2].node));
                                    (yyval.node) = add_child(gt, (yyvsp[0].node));
                                }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 492 "jucompiler.y" /* yacc.c:1646  */
    {
                                    node *le = create_node("Le", "");
                                    add_child(le, (yyvsp[-2].node));
                                    (yyval.node) = add_child(le, (yyvsp[0].node));
                                }
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 498 "jucompiler.y" /* yacc.c:1646  */
    {
                                    node *lt = create_node("Lt", "");
                                    add_child(lt, (yyvsp[-2].node));
                                    (yyval.node) = add_child(lt, (yyvsp[0].node));
                                }
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 504 "jucompiler.y" /* yacc.c:1646  */
    {
                                    node *ne = create_node("Ne", "");
                                    add_child(ne, (yyvsp[-2].node));
                                    (yyval.node) = add_child(ne, (yyvsp[0].node));
                                }
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 510 "jucompiler.y" /* yacc.c:1646  */
    {
                                    node *minus = create_node("Minus", "");
                                    add_child(minus, minus);
                                    (yyval.node) = add_child(minus, (yyvsp[0].node));
                                }
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 516 "jucompiler.y" /* yacc.c:1646  */
    {
                                    node *not = create_node("Not", "");
                                    add_child(div, not);
                                    (yyval.node) = add_child(not, (yyvsp[0].node));
                                }
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 522 "jucompiler.y" /* yacc.c:1646  */
    {
                                node *plus = create_node("Plus", "");
                                add_child(plus, plus);
                                (yyval.node) = add_child(plus, (yyvsp[0].node));
                            }
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 528 "jucompiler.y" /* yacc.c:1646  */
    {
                                    if ((yyvsp[0].node) != NULL){
                                        (yyval.node) = (yyvsp[0].node);
                                    }
                                }
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 534 "jucompiler.y" /* yacc.c:1646  */
    {
                                    if ((yyvsp[0].node) != NULL){
                                        (yyval.node) = (yyvsp[0].node);
                                    }
                                }
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 540 "jucompiler.y" /* yacc.c:1646  */
    {
                                    if ((yyvsp[0].node) != NULL){
                                        (yyval.node) = (yyvsp[0].node);
                                    }
                                }
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 546 "jucompiler.y" /* yacc.c:1646  */
    {
                                    (yyval.node) = create_node("Id",(yyvsp[-1].str));
                                }
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 550 "jucompiler.y" /* yacc.c:1646  */
    {
                                    (yyval.node) = create_node("Int",(yyvsp[0].str));
                                }
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 554 "jucompiler.y" /* yacc.c:1646  */
    {
                                    (yyval.node) = create_node("RealLit",(yyvsp[0].str));
                                }
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 558 "jucompiler.y" /* yacc.c:1646  */
    {
                                    (yyval.node) = create_node("BoolLit",(yyvsp[0].str));
                                }
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 563 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = create_node("DotLength", "");}
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 564 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2302 "y.tab.c" /* yacc.c:1646  */
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
#line 566 "jucompiler.y" /* yacc.c:1906  */


int main(int argc, char **argv){
    if (argc > 1){
        if (strcmp(argv[1], "-l") == 0){
            yylex();
        }

        if (strcmp(argv[1], "-t") == 0){
            yyparse();
            print_tree(head, 0);
        }

        if (strcmp(argv[1], "-debug") == 0){
            yyparse();    
        }
    }
    else{
        yyparse();
    }
    yylex_destroy();
    return 0;
}
