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

    // yacc -d jucompiler.y ---> Gerar o "y.tab.c" e o respetivo header
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include <unistd.h>
    #include "semantics_ast.h"

    struct node *head = NULL;

    extern table_element * global_table;
    int error_tag = 0, imprime = 0, erros = 0, return_flag = 0, recursao = 0;
    char *tipo;
    int contador = 0;
    int yylex();
    void yyerror(const char *s);

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
# define YYDEBUG 1
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

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 261 "y.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   372

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

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
       0,    55,    55,    67,    73,    79,    87,    90,    99,   110,
     113,   126,   129,   134,   139,   146,   158,   173,   176,   179,
     190,   201,   213,   216,   225,   240,   246,   249,   262,   274,
     277,   287,   308,   340,   355,   360,   363,   368,   371,   385,
     388,   389,   392,   393,   394,   395,   398,   399,   405,   413,
     416,   422,   425,   431,   434,   444,   451,   454,   455,   458,
     461,   462,   469,   476,   483,   490,   497,   504,   511,   518,
     525,   532,   539,   546,   553,   560,   567,   574,   578,   582,
     586,   589,   592,   595,   600,   603,   606
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
  "StatementOpt3", "StatementOpt4", "StatementOpt5", "MethodInvocation",
  "MethodInvocationOpt", "MethodInvocationOpt2", "Assignment", "ParseArgs",
  "Expr", "Expr1", YY_NULLPTR
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

#define YYPACT_NINF -37

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-37)))

#define YYTABLE_NINF -52

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -10,    37,    13,    27,   -37,     6,    18,     6,    49,    78,
       6,     6,   -37,   -37,    53,   -37,   -37,   -37,   -37,   -37,
     -37,    43,    58,    82,    96,     0,   126,   -37,    69,    63,
      69,    76,    87,   101,   160,   108,   110,   206,   111,    51,
      80,   116,   126,   126,   105,   -37,   -37,   -37,   118,    85,
     117,   -37,   134,   119,   -37,   -37,   206,   160,   124,    71,
       2,   167,   218,   218,   218,   -37,   -37,   -37,     1,   128,
     -37,   -37,   -37,   -37,   263,   206,   206,   131,   144,   -37,
     -37,   -37,   -37,   133,   150,   -37,   -37,   -37,   135,   -37,
     -37,   -37,   141,   -37,   143,   158,   155,   161,    -3,   -37,
     -37,   -37,   -37,   -37,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     164,   -37,   166,   170,   168,   142,   169,   147,    30,   -37,
     181,   173,   -37,   206,   -37,   -37,   317,   -37,   -37,   232,
      31,    31,    31,    31,    36,   -37,   232,   291,    36,    45,
      45,   343,   181,   -37,   -37,   206,   -37,   144,   -37,   -37,
     152,   171,   -37,   177,   -37,   168,   -37,   150,   181,   179,
     -37,   -37,   -37,   -37
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     9,     5,     0,     2,     3,     4,    12,    14,
      13,     0,     0,     0,     0,    11,     0,     7,    18,     0,
      18,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,     0,    42,    43,    44,     0,     0,
       0,    17,    11,     0,     8,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    86,    82,     0,
      80,    58,    81,    40,    57,     0,     0,     0,    29,    23,
      25,    24,    35,     0,    22,    16,    10,    15,     0,    38,
      30,    47,     0,    46,     0,     0,     0,     0,    82,    78,
      77,    79,    83,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,    53,     0,     0,     0,     0,    19,
       0,     0,    56,     0,    60,    59,    66,    63,    64,    71,
      72,    73,    74,    75,    62,    65,    76,    67,    61,    69,
      70,    68,     0,    49,    48,     0,    50,    29,    27,    20,
       0,    31,    36,     0,    33,    53,    28,    22,     0,     0,
      52,    21,    32,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -37,   -37,    88,   -37,   -37,   156,    -5,   -37,   180,   -37,
      44,   -37,     4,   -37,    60,   -33,   165,   -37,   -37,   -37,
     -26,   -37,    50,   -24,   -22,   -19,   -36
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    10,    11,    31,    40,    23,    50,    51,
     129,    27,    41,    42,   126,    43,    58,    69,    44,    92,
      70,   123,   156,    71,    72,    73,    74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    57,    46,    94,    47,    76,    29,     6,    45,    22,
      46,    77,    47,     4,    30,    77,    45,    45,    46,    46,
      47,    47,     1,    49,    57,    49,    99,   100,   101,    -6,
     102,    45,     7,    46,   102,    47,   105,    88,   106,     5,
      93,   105,    97,   106,    12,     8,    80,    81,   112,   113,
     105,    95,   106,   116,   113,    76,   120,   121,   124,   117,
     118,    18,   112,   113,    19,    77,    20,   116,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,    18,    61,     3,    19,    62,    20,
      14,    63,    24,    64,    26,    13,    21,   161,    16,    17,
      18,    15,    54,    19,    45,    20,    46,    25,    47,    36,
      28,    48,    52,    55,   163,    56,    65,    66,    67,   164,
      68,    91,    59,   160,    60,    75,    45,    32,    46,    78,
      47,    82,   122,    83,    84,   172,   165,    33,    34,    79,
      29,    85,    45,    87,    46,    61,    47,    90,    62,   -26,
     125,    63,   -45,    64,   103,   -51,   128,    18,   127,   130,
      19,    32,    20,    35,    36,   131,    37,   132,    96,    36,
      38,    33,    34,   133,   155,    39,    65,    66,    67,   134,
      68,    61,    32,   -39,    62,   135,   -45,    63,   152,    64,
     153,   157,    33,    34,   154,   158,   159,    35,    36,   162,
      37,   167,   169,   173,    38,    36,   168,   -45,    86,    39,
      53,   171,    65,    66,    67,   170,    68,   166,    35,    36,
      61,    37,    89,    62,     0,    38,    63,     0,    64,     0,
      39,     0,    61,     0,     0,    62,     0,   105,    63,   106,
      64,   108,   109,     0,    36,   110,     0,     0,   111,   112,
     113,    65,    66,    67,   116,    68,    36,     0,     0,     0,
     117,   118,     0,    65,    66,    67,   104,    98,   105,     0,
     106,   107,   108,   109,     0,     0,   110,     0,     0,   111,
     112,   113,   114,     0,   115,   116,     0,     0,     0,     0,
       0,   117,   118,   119,   104,     0,   105,     0,   106,   107,
     108,   109,     0,     0,   110,     0,     0,   111,   112,   113,
     114,     0,     0,   116,     0,     0,     0,     0,     0,   117,
     118,   119,   105,     0,   106,   107,   108,   109,     0,     0,
     110,     0,     0,   111,   112,   113,   114,     0,     0,   116,
       0,     0,     0,     0,     0,   117,   118,   119,   105,     0,
     106,   107,   108,   109,     0,     0,   110,     0,     0,   111,
     112,   113,   114,     0,     0,   116,     0,     0,     0,     0,
       0,   117,   118
};

static const yytype_int16 yycheck[] =
{
      26,    34,    26,     1,    26,     4,     6,     1,    34,    14,
      34,    14,    34,     0,    14,    14,    42,    43,    42,    43,
      42,    43,    32,    28,    57,    30,    62,    63,    64,    23,
      33,    57,    26,    57,    33,    57,     5,    56,     7,    12,
      59,     5,    61,     7,    26,    39,    42,    43,    17,    18,
       5,    49,     7,    22,    18,     4,    75,    76,    77,    28,
      29,    31,    17,    18,    34,    14,    36,    22,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    31,    14,    49,    34,    17,    36,
      41,    20,    49,    22,    12,     7,    43,   130,    10,    11,
      31,    23,    26,    34,   130,    36,   130,    49,   130,    38,
      14,    42,    49,    26,   133,    14,    45,    46,    47,   152,
      49,    50,    14,   128,    14,    14,   152,     1,   152,    49,
     152,    26,     1,    15,    49,   168,   155,    11,    12,    23,
       6,    24,   168,    24,   168,    14,   168,    23,    17,    23,
       6,    20,    26,    22,    26,    24,     6,    31,    25,    24,
      34,     1,    36,    37,    38,    24,    40,    24,     1,    38,
      44,    11,    12,    15,     6,    49,    45,    46,    47,    24,
      49,    14,     1,    23,    17,    24,    26,    20,    24,    22,
      24,    49,    11,    12,    24,    26,    49,    37,    38,    26,
      40,    49,    25,    24,    44,    38,    35,    26,    52,    49,
      30,   167,    45,    46,    47,   165,    49,   157,    37,    38,
      14,    40,    57,    17,    -1,    44,    20,    -1,    22,    -1,
      49,    -1,    14,    -1,    -1,    17,    -1,     5,    20,     7,
      22,     9,    10,    -1,    38,    13,    -1,    -1,    16,    17,
      18,    45,    46,    47,    22,    49,    38,    -1,    -1,    -1,
      28,    29,    -1,    45,    46,    47,     3,    49,     5,    -1,
       7,     8,     9,    10,    -1,    -1,    13,    -1,    -1,    16,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,     3,    -1,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    13,    -1,    -1,    16,    17,    18,
      19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,     5,    -1,     7,     8,     9,    10,    -1,    -1,
      13,    -1,    -1,    16,    17,    18,    19,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,     5,    -1,
       7,     8,     9,    10,    -1,    -1,    13,    -1,    -1,    16,
      17,    18,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    52,    49,     0,    12,     1,    26,    39,    53,
      54,    55,    26,    53,    41,    23,    53,    53,    31,    34,
      36,    43,    57,    58,    49,    49,    12,    62,    14,     6,
      14,    56,     1,    11,    12,    37,    38,    40,    44,    49,
      57,    63,    64,    66,    69,    71,    74,    75,    42,    57,
      59,    60,    49,    59,    26,    26,    14,    66,    67,    14,
      14,    14,    17,    20,    22,    45,    46,    47,    49,    68,
      71,    74,    75,    76,    77,    14,     4,    14,    49,    23,
      63,    63,    26,    15,    49,    24,    56,    24,    76,    67,
      23,    50,    70,    76,     1,    49,     1,    76,    49,    77,
      77,    77,    33,    26,     3,     5,     7,     8,     9,    10,
      13,    16,    17,    18,    19,    21,    22,    28,    29,    30,
      76,    76,     1,    72,    76,     6,    65,    25,     6,    61,
      24,    24,    24,    15,    24,    24,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    24,    24,    24,     6,    73,    49,    26,    49,
      57,    66,    26,    76,    66,    76,    65,    49,    35,    25,
      73,    61,    66,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    58,    58,    59,    59,    60,
      60,    61,    61,    62,    63,    63,    63,    64,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    75,    75,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     2,     2,     0,     4,     6,     2,
       3,     0,     1,     1,     1,     5,     5,     1,     0,     3,
       4,     4,     0,     3,     2,     2,     0,     4,     3,     0,
       3,     5,     7,     5,     3,     2,     5,     2,     2,     0,
       1,     0,     1,     1,     1,     0,     1,     1,     4,     4,
       2,     0,     3,     0,     3,     7,     4,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       1,     1,     1,     2,     1,     1,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 55 "jucompiler.y" /* yacc.c:1646  */
    {
                                                    head = create_node("Program", "", 0, 0);
                                                    struct node *idd = create_node("Id", (yyvsp[-3].str), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
                                                    add_child(head, idd);
                                                    if ((yyvsp[-1].node) != NULL){
                                                        add_bro(idd,(yyvsp[-1].node));
                                                        add_child(head, (yyvsp[-1].node));
                                                    }
                                                    (yyval.node) = head;
                                                }
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 67 "jucompiler.y" /* yacc.c:1646  */
    {
                                        if ((yyvsp[0].node) != NULL){
                                            add_bro((yyvsp[-1].node), (yyvsp[0].node));
                                        }
                                        (yyval.node) = (yyvsp[-1].node);
                                    }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 73 "jucompiler.y" /* yacc.c:1646  */
    {
                                        if ((yyvsp[0].node) != NULL){
                                            add_bro((yyvsp[-1].node), (yyvsp[0].node));
                                        }
                                        (yyval.node) = (yyvsp[-1].node);
                                    }
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 79 "jucompiler.y" /* yacc.c:1646  */
    {
                                        if ((yyvsp[0].node) != NULL){
                                            (yyval.node) = (yyvsp[0].node);
                                        }
                                        else{
                                            (yyval.node) = NULL;
                                        }
                                    }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 87 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 90 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        struct node *methoddecl = create_node("MethodDecl", "", 0, 0);
                                                        add_child(methoddecl, (yyvsp[-1].node));
                                                        add_child(methoddecl, (yyvsp[0].node));
                                                        add_bro((yyvsp[-1].node), (yyvsp[0].node));
                                                        (yyval.node) = methoddecl;
                                                    }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 99 "jucompiler.y" /* yacc.c:1646  */
    {
                                                                struct node *fielddecl = create_node("FieldDecl", "", 0, 0);
                                                                struct node *idd = create_node("Id", (yyvsp[-2].str), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
                                                                add_child(fielddecl, (yyvsp[-3].node));
                                                                add_child(fielddecl, idd);
                                                                add_bro((yyvsp[-3].node), idd);
                                                                if ((yyvsp[-1].node) != NULL){
                                                                    add_bro(fielddecl, (yyvsp[-1].node));
                                                                }
                                                                (yyval.node) = fielddecl;
                                                            }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 110 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 113 "jucompiler.y" /* yacc.c:1646  */
    {
                                                struct node *fielddecl = create_node("FieldDecl", "", 0, 0);
                                                struct node *typ = create_node(tipo, "", 0, 0);
                                                struct node *idd = create_node("Id", (yyvsp[-1].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                add_child(fielddecl, typ);
                                                add_child(fielddecl, idd);
                                                add_bro(typ, idd);
                                                if ((yyvsp[0].node) != NULL){
                                                    add_bro(fielddecl, (yyvsp[0].node));
                                                }
                                                (yyval.node) = fielddecl;
                                                
                                            }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 126 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 129 "jucompiler.y" /* yacc.c:1646  */
    {
                                struct node *booly = create_node("Bool", "", (yylsp[0]).first_line, (yylsp[0]).first_column);
                                tipo = "Bool";
                                (yyval.node) = booly;
                            }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 134 "jucompiler.y" /* yacc.c:1646  */
    {
                                struct node *inty = create_node("Int", "", (yylsp[0]).first_line, (yylsp[0]).first_column);
                                tipo = "Int";
                                (yyval.node) = inty;
                            }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 139 "jucompiler.y" /* yacc.c:1646  */
    {
                                struct node *doubley = create_node("Double", "", (yylsp[0]).first_line, (yylsp[0]).first_column);
                                tipo = "Double";
                                (yyval.node) = doubley;
                            }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 146 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            struct node *methodheader = create_node("MethodHeader", "", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
                                                            struct node *parametros = create_node("MethodParams","", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
                                                            struct node *idd = create_node("Id", (yyvsp[-3].str), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
                                                            add_child(methodheader, (yyvsp[-4].node));
                                                            add_child(methodheader, idd);
                                                            add_child(methodheader, parametros);
                                                            add_child(parametros, (yyvsp[-1].node));
                                                            add_bro((yyvsp[-4].node), idd);
                                                            add_bro(idd, parametros);
                                                            (yyval.node) = methodheader;
                                                        }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 158 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            struct node *methodheader = create_node("MethodHeader", "", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
                                                            struct node *parametros = create_node("MethodParams","", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
                                                            struct node *voidy = create_node("Void", "", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
                                                            struct node *idd = create_node("Id", (yyvsp[-3].str), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
                                                            add_child(methodheader, voidy);
                                                            add_child(methodheader, idd);
                                                            add_child(methodheader, parametros);
                                                            add_child(parametros, (yyvsp[-1].node));
                                                            add_bro(voidy, idd);
                                                            add_bro(idd, parametros);
                                                            (yyval.node) = methodheader;
                                                        }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 173 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        (yyval.node) = (yyvsp[0].node);
                                                    }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 176 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 179 "jucompiler.y" /* yacc.c:1646  */
    {
                                                struct node *paramsDecl = create_node("ParamDecl","", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
                                                struct node *idd = create_node("Id", (yyvsp[-1].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                add_child(paramsDecl, (yyvsp[-2].node));
                                                add_child(paramsDecl, idd);
                                                add_bro((yyvsp[-2].node), idd);
                                                if((yyvsp[0].node) != NULL){
                                                    add_bro(paramsDecl, (yyvsp[0].node));
                                                } 
                                                (yyval.node) = paramsDecl;
                                            }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 190 "jucompiler.y" /* yacc.c:1646  */
    {
                                                struct node *paramsDecl = create_node("ParamDecl", "", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
                                                struct node *string = create_node("StringArray", "", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
                                                struct node *idd = create_node("Id",(yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
                                                add_child(paramsDecl, string);
                                                add_child(paramsDecl, idd);
                                                add_bro(string, idd);
                                                (yyval.node) = paramsDecl;
                                            }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 201 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            struct node *paramdecl = create_node("ParamDecl", "", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
                                                            struct node *idd = create_node("Id", (yyvsp[-1].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                            add_child(paramdecl, (yyvsp[-2].node));
                                                            add_child(paramdecl, idd);
                                                            add_bro((yyvsp[-2].node), idd);
                                                            if ((yyvsp[0].node) != NULL){
                                                                add_bro(paramdecl,(yyvsp[0].node));
                                                            }
                                                            (yyval.node) = paramdecl;
                                                            
                                                        }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 213 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 216 "jucompiler.y" /* yacc.c:1646  */
    {
                                                struct node *methodbody = create_node("MethodBody", "", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
                                                if ((yyvsp[-1].node) != NULL){
                                                    add_child(methodbody, (yyvsp[-1].node));
                                                }
                                                (yyval.node) = methodbody;
                                            }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 225 "jucompiler.y" /* yacc.c:1646  */
    {
                                                if ((yyvsp[-1].node) == NULL && (yyvsp[0].node) == NULL){
                                                    (yyval.node) = NULL;
                                                }
                                                else if ((yyvsp[-1].node) == NULL){
                                                    (yyval.node) = (yyvsp[0].node);
                                                }
                                                else if ((yyvsp[0].node) == NULL){
                                                    (yyval.node) = (yyvsp[-1].node);
                                                }
                                                else{
                                                    (yyval.node) = add_bro((yyvsp[-1].node), (yyvsp[0].node));
                                                }

                                            }
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 240 "jucompiler.y" /* yacc.c:1646  */
    {
                                                if ((yyvsp[0].node) != NULL){
                                                    add_bro((yyvsp[-1].node), (yyvsp[0].node));
                                                }
                                                (yyval.node) = (yyvsp[-1].node);
                                            }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 246 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 249 "jucompiler.y" /* yacc.c:1646  */
    {
                                                struct node *vardecl = create_node("VarDecl", "", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
                                                struct node *idd = create_node("Id", (yyvsp[-2].str), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
                                                add_child(vardecl, (yyvsp[-3].node));
                                                add_child(vardecl, idd);
                                                add_bro((yyvsp[-3].node), idd);
                                                if((yyvsp[-1].node) != NULL){
                                                    add_bro(vardecl, (yyvsp[-1].node));
                                                }
                                                (yyval.node) = vardecl;
                                            }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 262 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        struct node *vardecl = create_node("VarDecl", "", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                        struct node *idd = create_node("Id", (yyvsp[-1].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                        struct node *ty = create_node(tipo,"", 0, 0);
                                                        add_child(vardecl, ty);
                                                        add_child(vardecl, idd);
                                                        add_bro(ty, idd);
                                                        if ((yyvsp[0].node) != NULL){
                                                            add_bro(vardecl, (yyvsp[0].node));
                                                        }
                                                        (yyval.node) = vardecl;
                                                    }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 274 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 277 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            if ((yyvsp[-1].node) != NULL && (yyvsp[-1].node)->bros != NULL){
                                                                struct node *block = create_node("Block", "", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                                                add_child(block, (yyvsp[-1].node));
                                                                (yyval.node) = block;
                                                            }
                                                            else{
                                                                (yyval.node) = (yyvsp[-1].node);
                                                            }
                                                        }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 287 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            struct node *if1 = create_node("If","", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
                                                            add_child(if1, (yyvsp[-2].node));
                                                            if((yyvsp[0].node) != NULL){
                                                                add_child(if1, (yyvsp[0].node));
                                                                struct node *block = create_node("Block", "", (yylsp[0]).first_line, (yylsp[0]).first_column);
                                                                add_child(if1, block);
                                                                add_bro((yyvsp[-2].node), (yyvsp[0].node));
                                                                add_bro((yyvsp[0].node), block);
                                                                (yyval.node) = if1;
                                                            }
                                                            else{
                                                                struct node *block1 = create_node("Block","", 0, 0);
                                                                add_child(if1, block1);
                                                                struct node *block2 = create_node("Block", "", 0, 0);
                                                                add_child(if1, block2);
                                                                add_bro((yyvsp[-2].node), block1);
                                                                add_bro(block1, block2);
                                                                (yyval.node) = if1;
                                                            }
                                                        }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 308 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            struct node *if2 = create_node("If", "", (yylsp[-6]).first_line, (yylsp[-6]).first_column);
                                                            add_child(if2, (yyvsp[-4].node));
                                                            if((yyvsp[-2].node) != NULL){
                                                                add_child(if2, (yyvsp[-2].node));
                                                                add_bro((yyvsp[-4].node), (yyvsp[-2].node));
                                                                if((yyvsp[0].node) != NULL){
                                                                    add_child(if2, (yyvsp[0].node));
                                                                    add_bro((yyvsp[-2].node), (yyvsp[0].node));
                                                                    (yyval.node) = if2;
                                                                }else{
                                                                    struct node *block2 = create_node("Block", "", (yylsp[0]).first_line, (yylsp[0]).first_column);
                                                                    add_child(if2, block2);
                                                                    add_bro((yyvsp[-2].node), block2);
                                                                    (yyval.node) = if2;
                                                                }
                                                            }else{
                                                                struct node *block = create_node("Block", "", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
                                                                add_child(if2, block);
                                                                add_bro((yyvsp[-4].node), block);
                                                                if((yyvsp[0].node) != NULL){
                                                                    add_child(if2, (yyvsp[0].node));
                                                                    add_bro(block, (yyvsp[0].node));
                                                                    (yyval.node) = if2;
                                                                }else{
                                                                    struct node *block2 = create_node("Block", "", (yylsp[0]).first_line, (yylsp[0]).first_column);
                                                                    add_child(if2, block2);
                                                                    add_bro(block, block2);
                                                                    (yyval.node) = if2;
                                                                }
                                                            }
                                                        }
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 340 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            struct node *whi = create_node("While", "", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
                                                            add_child(whi, (yyvsp[-2].node));
                                                            if((yyvsp[0].node) != NULL){
                                                                add_child(whi, (yyvsp[0].node));
                                                                add_bro((yyvsp[-2].node), (yyvsp[0].node));
                                                                (yyval.node) = whi;
                                                            }
                                                            else{
                                                                struct node *block = create_node("Block", "", (yylsp[0]).first_line, (yylsp[0]).first_column);
                                                                add_child(whi, block);
                                                                add_bro((yyvsp[-2].node), block);
                                                                (yyval.node) = whi;
                                                            }
                                                        }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 355 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            struct node *ret = create_node("Return","", (yylsp[-2]).first_line, (yylsp[-2]).first_column);
                                                            add_child(ret,(yyvsp[-1].node));
                                                            (yyval.node) = ret;
                                                        }
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 360 "jucompiler.y" /* yacc.c:1646  */
    {                                                 
                                                            (yyval.node) = (yyvsp[-1].node);                                                 
                                                        }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 363 "jucompiler.y" /* yacc.c:1646  */
    {
                                                            struct node *pri = create_node("Print","", (yylsp[-4]).first_line, (yylsp[-4]).first_column);
                                                            add_child(pri, (yyvsp[-2].node));
                                                            (yyval.node) = pri;
                                                        }
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 368 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 371 "jucompiler.y" /* yacc.c:1646  */
    {
                                                if ((yyvsp[-1].node) == NULL && (yyvsp[0].node) == NULL){
                                                    (yyval.node) = NULL;
                                                }
                                                else if ((yyvsp[-1].node) == NULL){
                                                    (yyval.node) = (yyvsp[0].node);
                                                }
                                                else if ((yyvsp[0].node) == NULL){
                                                    (yyval.node) = (yyvsp[-1].node);
                                                }
                                                else{
                                                    (yyval.node) = add_bro((yyvsp[-1].node), (yyvsp[0].node));
                                                }
                                            }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 385 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 388 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 389 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 392 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 393 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 394 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 395 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 398 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 399 "jucompiler.y" /* yacc.c:1646  */
    {
                                            struct node *itslit = create_node("StrLit", (yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
                                            (yyval.node) = itslit;
                                        }
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 405 "jucompiler.y" /* yacc.c:1646  */
    {
                                                                struct node *call = create_node("Call", "", (yylsp[-3]).first_line, (yylsp[-3]).first_column);
                                                                struct node *idd = create_node("Id", (yyvsp[-3].str), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
                                                                add_child(call, idd);
                                                                add_child(call, (yyvsp[-1].node));
                                                                add_bro(idd, (yyvsp[-1].node));
                                                                (yyval.node) = call;
                                                            }
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 413 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 416 "jucompiler.y" /* yacc.c:1646  */
    {
                                                                if((yyvsp[0].node) != NULL){
                                                                    add_bro((yyvsp[-1].node), (yyvsp[0].node));
                                                                }
                                                                (yyval.node) = (yyvsp[-1].node);
                                                        }
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 422 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 425 "jucompiler.y" /* yacc.c:1646  */
    {
                                                                if ((yyvsp[-1].node) != NULL){
                                                                    add_bro((yyvsp[-1].node), (yyvsp[0].node));
                                                                }
                                                                (yyval.node) = (yyvsp[-1].node);
                                                            }
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 431 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 434 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *assign = create_node("Assign", "", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    struct node *idd = create_node("Id", (yyvsp[-2].str), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
                                    add_child(assign, idd);
                                    add_child(assign, (yyvsp[0].node));
                                    add_bro(idd, (yyvsp[0].node));
                                    (yyval.node) = assign;
                                }
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 444 "jucompiler.y" /* yacc.c:1646  */
    {
                                                        struct node *parseargs = create_node("ParseArgs","", (yylsp[-6]).first_line, (yylsp[-6]).first_column);
                                                        struct node *id = create_node("Id",(yyvsp[-4].str), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
                                                        add_child(parseargs,id);
                                                        add_child(parseargs,(yyvsp[-2].node));
                                                        (yyval.node) = parseargs;
                                                    }
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 451 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 454 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 455 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 458 "jucompiler.y" /* yacc.c:1646  */
    {
                                    (yyval.node) = (yyvsp[-1].node);
                                }
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 461 "jucompiler.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 462 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *add = create_node("Add","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    add_child(add,(yyvsp[-2].node));
                                    add_child(add,(yyvsp[0].node));
                                    add_bro((yyvsp[-2].node),(yyvsp[0].node));
                                    (yyval.node) = add;
                                }
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 469 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *sub = create_node("Sub","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    add_child(sub,(yyvsp[-2].node));
                                    add_child(sub,(yyvsp[0].node));
                                    add_bro((yyvsp[-2].node),(yyvsp[0].node));
                                    (yyval.node) = sub;
                                }
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 476 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *star = create_node("Mul","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    add_child(star,(yyvsp[-2].node));
                                    add_child(star,(yyvsp[0].node));
                                    add_bro((yyvsp[-2].node),(yyvsp[0].node));
                                    (yyval.node) = star;
                                }
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 483 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *div = create_node("Div","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    add_child(div,(yyvsp[-2].node));
                                    add_child(div,(yyvsp[0].node));
                                    add_bro((yyvsp[-2].node),(yyvsp[0].node));
                                    (yyval.node) = div;
                                }
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 490 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *mod = create_node("Mod","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    add_child(mod,(yyvsp[-2].node));
                                    add_child(mod,(yyvsp[0].node));
                                    add_bro((yyvsp[-2].node),(yyvsp[0].node));
                                    (yyval.node) = mod;
                                }
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 497 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *and = create_node("And","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    add_child(and,(yyvsp[-2].node));
                                    add_child(and,(yyvsp[0].node));
                                    add_bro((yyvsp[-2].node),(yyvsp[0].node));
                                    (yyval.node) = and;
                                }
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 504 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *or = create_node("Or","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    add_child(or,(yyvsp[-2].node));
                                    add_child(or,(yyvsp[0].node));
                                    add_bro((yyvsp[-2].node),(yyvsp[0].node));
                                    (yyval.node) = or;
                                }
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 511 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *xor = create_node("Xor","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    add_child(xor,(yyvsp[-2].node));
                                    add_child(xor,(yyvsp[0].node));
                                    add_bro((yyvsp[-2].node),(yyvsp[0].node));
                                    (yyval.node) = xor;
                                }
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 518 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *lshift = create_node("Lshift","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    add_child(lshift,(yyvsp[-2].node));
                                    add_child(lshift,(yyvsp[0].node));
                                    add_bro((yyvsp[-2].node),(yyvsp[0].node));
                                    (yyval.node) = lshift;
                                }
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 525 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *rshift = create_node("Rshift","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    add_child(rshift,(yyvsp[-2].node));
                                    add_child(rshift,(yyvsp[0].node));
                                    add_bro((yyvsp[-2].node),(yyvsp[0].node));
                                    (yyval.node) = rshift;
                                }
#line 2361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 532 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *eq = create_node("Eq","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    add_child(eq,(yyvsp[-2].node));
                                    add_child(eq,(yyvsp[0].node));
                                    add_bro((yyvsp[-2].node),(yyvsp[0].node));
                                    (yyval.node) = eq;
                                }
#line 2373 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 539 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *ge = create_node("Ge","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    add_child(ge,(yyvsp[-2].node));
                                    add_child(ge,(yyvsp[0].node));
                                    add_bro((yyvsp[-2].node),(yyvsp[0].node));
                                    (yyval.node) = ge;
                                }
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 546 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *gt = create_node("Gt","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    add_child(gt,(yyvsp[-2].node));
                                    add_child(gt,(yyvsp[0].node));
                                    add_bro((yyvsp[-2].node),(yyvsp[0].node));
                                    (yyval.node) = gt;
                                }
#line 2397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 553 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *le = create_node("Le","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    add_child(le,(yyvsp[-2].node));
                                    add_child(le,(yyvsp[0].node));
                                    add_bro((yyvsp[-2].node),(yyvsp[0].node));
                                    (yyval.node) = le;
                                }
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 560 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *lt = create_node("Lt","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    add_child(lt,(yyvsp[-2].node));
                                    add_child(lt,(yyvsp[0].node));
                                    add_bro((yyvsp[-2].node),(yyvsp[0].node));
                                    (yyval.node) = lt;
                                }
#line 2421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 567 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *ne = create_node("Ne","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    add_child(ne,(yyvsp[-2].node));
                                    add_child(ne,(yyvsp[0].node));
                                    add_bro((yyvsp[-2].node),(yyvsp[0].node));
                                    (yyval.node) = ne;
                                }
#line 2433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 574 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *not = create_node("Not","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    (yyval.node) = add_child(not,(yyvsp[0].node));
                                }
#line 2442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 578 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *minus = create_node("Minus","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    (yyval.node) = add_child(minus,(yyvsp[0].node));
                                }
#line 2451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 582 "jucompiler.y" /* yacc.c:1646  */
    {
                                    struct node *plus = create_node("Plus","", (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                    (yyval.node) = add_child(plus,(yyvsp[0].node));
                                }
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 586 "jucompiler.y" /* yacc.c:1646  */
    {
                                    (yyval.node) = (yyvsp[0].node);
                                }
#line 2468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 589 "jucompiler.y" /* yacc.c:1646  */
    {
                                    (yyval.node) = (yyvsp[0].node);
                                }
#line 2476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 592 "jucompiler.y" /* yacc.c:1646  */
    {
                                    (yyval.node) = create_node("Id",(yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
                                }
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 595 "jucompiler.y" /* yacc.c:1646  */
    {
                                   struct node *lengthy = create_node("Length", "", (yylsp[0]).first_line, (yylsp[0]).first_column);
                                   struct node *id = create_node("Id", (yyvsp[-1].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
                                   (yyval.node) = add_child(lengthy, id);
                                }
#line 2494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 600 "jucompiler.y" /* yacc.c:1646  */
    {
                                    (yyval.node) = create_node("DecLit", (yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
                                }
#line 2502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 603 "jucompiler.y" /* yacc.c:1646  */
    {
                                    (yyval.node) = create_node("RealLit", (yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
                                }
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 606 "jucompiler.y" /* yacc.c:1646  */
    { 
                                    (yyval.node) = create_node("BoolLit", (yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
                                }
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2522 "y.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 611 "jucompiler.y" /* yacc.c:1906  */


int main(int argc, char **argv){
    if (argc > 1){
        if (strcmp(argv[1], "-l") == 0){
            //imprime so os tokens da primeira; so analise lexical
            imprime = 1;
            erros = 1;
            yylex();
        }

        else if (strcmp(argv[1], "-t") == 0){
            // IMPRIMIR ARVORE, ja temos de dar os returns;
            erros = 1;
            return_flag = 1;
            yyparse();
            if(error_tag == 0){
                print_tree(head, 0);
            }
        }

        else if (strcmp(argv[1], "-s") == 0){
            // Analise semantica - META 3
            return_flag = 1;
            yyparse();
            create_symbol_table(head);
            imprime_erros();
            create_ast(head, global_table, 0);
            show_table();
            print_tree_annotated(head, 0);
        }

        else if (strcmp(argv[1], "-e2") == 0){
            // So analise lexical e semantica, erros da segunda meta e primeira meta, ja temos de ter os returns
            erros = 1;
            return_flag = 1;
            yyparse();
        }

        else if (strcmp(argv[1], "-e1") == 0){
            //so analise lexical, erros primeira meta;
            erros = 1;
            yylex();
        }

        else{
            return 0;
        }
    }
    if (argc == 1){
        erros = 1;
        yylex();
    }
    return 0;
}
