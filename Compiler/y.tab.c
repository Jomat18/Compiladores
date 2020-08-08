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
#line 1 "compiler.y" /* yacc.c:339  */


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define YYDEBUG 1   /* Depurador */

#include "datos.h"  /* Tabla de simbolos y codigos */

int yylex(void);
void yyerror(char *m);

#line 81 "y.tab.c" /* yacc.c:339  */

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
    INT = 258,
    FLOAT = 259,
    BOOL = 260,
    STRING = 261,
    NUM = 262,
    REAL = 263,
    BOOLEANO = 264,
    LETRAS = 265,
    FORMATO = 266,
    ID = 267,
    IF = 268,
    ELSE = 269,
    WHILE = 270,
    DO = 271,
    FOR = 272,
    TEMP = 273,
    LEENUM = 274,
    IMPRINUM = 275,
    COMENTARIO = 276,
    CENTERO = 277,
    CFLOAT = 278,
    VAR = 279,
    FUNCION = 280,
    ARREGLO = 281,
    NOT = 282,
    OR = 283,
    AND = 284,
    IGUAL = 285,
    NOIGUAL = 286,
    MENORIGUAL = 287,
    MAYORIGUAL = 288
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define BOOL 260
#define STRING 261
#define NUM 262
#define REAL 263
#define BOOLEANO 264
#define LETRAS 265
#define FORMATO 266
#define ID 267
#define IF 268
#define ELSE 269
#define WHILE 270
#define DO 271
#define FOR 272
#define TEMP 273
#define LEENUM 274
#define IMPRINUM 275
#define COMENTARIO 276
#define CENTERO 277
#define CFLOAT 278
#define VAR 279
#define FUNCION 280
#define ARREGLO 281
#define NOT 282
#define OR 283
#define AND 284
#define IGUAL 285
#define NOIGUAL 286
#define MENORIGUAL 287
#define MAYORIGUAL 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 198 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   295

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    45,    31,     2,
      47,    48,    43,    41,    49,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    46,
      39,    27,    40,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,    29,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,    30,    53,     2,     2,     2,     2,
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
      25,    26,    28,    33,    34,    35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    38,    38,    40,    40,    40,    42,    43,    43,    45,
      45,    46,    46,    48,    48,    48,    48,    50,    50,    50,
      50,    50,    51,    51,    51,    53,    54,    54,    55,    55,
      57,    58,    59,    59,    60,    60,    60,    66,    67,    69,
      70,    71,    72,    73,    74,    76,    77,    78,    79,    81,
      82,    83,    84,    85,    86,    88,    89,    90,    91,    93,
      95,    96,    96,    97,    98,    99
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "BOOL", "STRING", "NUM",
  "REAL", "BOOLEANO", "LETRAS", "FORMATO", "ID", "IF", "ELSE", "WHILE",
  "DO", "FOR", "TEMP", "LEENUM", "IMPRINUM", "COMENTARIO", "CENTERO",
  "CFLOAT", "VAR", "FUNCION", "ARREGLO", "'='", "NOT", "'^'", "'|'", "'&'",
  "'?'", "OR", "AND", "IGUAL", "NOIGUAL", "MENORIGUAL", "MAYORIGUAL",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "';'", "'('", "')'",
  "','", "'['", "']'", "'{'", "'}'", "':'", "$accept", "programaC",
  "listaDeclC", "declC", "$@1", "listComent", "comentario", "Tipo",
  "listaVar", "$@2", "$@3", "listaPar", "$@4", "bloque", "listaVarLoc",
  "listaProp", "prop", "@5", "@6", "@7", "expr", "@8", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    61,   282,    94,
     124,    38,    63,   283,   284,   285,   286,   287,   288,    60,
      62,    43,    45,    42,    47,    37,    59,    40,    41,    44,
      91,    93,   123,   125,    58
};
# endif

#define YYPACT_NINF -58

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-58)))

#define YYTABLE_NINF -25

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -20,     8,    95,    -7,   -58,   -58,   -58,   -58,   -58,   -58,
       4,   -58,   -58,    19,    -2,   -58,   -58,    -4,    -7,    95,
      36,    48,   -58,    59,    12,    15,   -58,    27,    31,    29,
     -58,    46,    -7,   -58,    95,    95,   -58,    36,   -58,    42,
      30,    95,   -58,   -58,   -58,   -58,   -16,    49,    55,    57,
      73,    44,   -58,    44,   -58,   -58,    -7,   239,    -7,   -58,
      44,    44,   -58,    44,    44,   239,   118,   -58,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,   -58,    44,    98,   135,    44,   203,   152,
     -58,   239,    74,   250,   250,   -38,   -38,   -38,   -38,   -38,
     -38,   101,   101,   -58,   -58,   -58,   239,    66,   -58,   169,
      44,   -58,    44,    44,    77,   -58,   221,   239,   239,   -58,
      77,    44,   -58,   186,    77,   -58
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     2,     4,     1,    13,    14,    15,    16,     3,
       0,    11,     9,    19,     0,     7,    17,     0,    12,     0,
       0,     0,     6,     0,     0,    19,    18,     0,    22,     0,
      21,     0,    12,     8,     0,    27,    23,     0,    29,     0,
       0,    27,    57,    60,    58,    59,    56,     0,     0,     0,
       0,     0,    30,     0,    25,    31,    12,    39,    12,    61,
       0,     0,    34,     0,     0,    42,     0,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     0,
      65,    54,     0,    40,    41,    43,    44,    47,    48,    45,
      46,    49,    50,    51,    52,    53,    62,    63,    32,     0,
       0,    38,     0,     0,     0,    35,     0,    55,    64,    33,
       0,     0,    36,     0,     0,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,   -58,   -58,   -58,   -58,    17,    39,    -5,   -58,
     -58,    87,   -58,    93,    84,   -58,   -57,   -58,   -58,   -58,
     -51,   -58
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     9,    19,     3,    12,    23,    14,    20,
      17,    24,    31,    55,    38,    40,    56,   114,    87,   120,
      57,    84
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      65,   -10,    66,    78,    79,    80,    81,    82,     4,    85,
      86,    59,    88,    89,    11,    26,    13,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    39,   106,    60,    22,   109,    42,    43,    44,
      45,    10,    46,    47,    18,    48,    21,    49,    25,    35,
      50,    42,    43,    44,    45,    27,    46,   119,    51,   116,
      29,   117,   118,   122,    16,   -20,    15,   125,    16,   -20,
     123,    28,    51,    67,    37,    83,    52,    53,    30,   -24,
      37,    32,    32,    54,    42,    43,    44,    45,    41,    46,
      47,    53,    48,   113,    49,    34,    61,    50,     5,     6,
       7,     8,    62,    68,    63,    51,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      64,    36,    33,    52,    53,    58,     0,    68,   112,    32,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    80,    81,    82,    68,     0,   107,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    68,     0,    90,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    68,     0,   108,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    68,     0,
     111,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    68,     0,   115,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    68,     0,   124,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,   110,
      68,     0,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,   121,    68,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82
};

static const yytype_int8 yycheck[] =
{
      51,    21,    53,    41,    42,    43,    44,    45,     0,    60,
      61,    27,    63,    64,    21,    20,    12,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    37,    84,    50,    18,    87,     7,     8,     9,
      10,     2,    12,    13,    46,    15,    50,    17,    12,    32,
      20,     7,     8,     9,    10,     7,    12,   114,    28,   110,
      48,   112,   113,   120,    49,    50,    47,   124,    49,    50,
     121,    12,    28,    56,    35,    58,    46,    47,    51,    48,
      41,    52,    52,    53,     7,     8,     9,    10,    46,    12,
      13,    47,    15,    27,    17,    49,    47,    20,     3,     4,
       5,     6,    47,    29,    47,    28,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      47,    34,    29,    46,    47,    41,    -1,    29,    54,    52,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    43,    44,    45,    29,    -1,    51,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    29,    -1,    48,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    29,    -1,    48,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    29,    -1,
      48,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    29,    -1,    48,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    29,    -1,    48,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      29,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    29,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    56,    57,    60,     0,     3,     4,     5,     6,    58,
      62,    21,    61,    12,    63,    47,    49,    65,    46,    59,
      64,    50,    61,    62,    66,    12,    63,     7,    12,    48,
      51,    67,    52,    68,    49,    61,    66,    62,    69,    63,
      70,    46,     7,     8,     9,    10,    12,    13,    15,    17,
      20,    28,    46,    47,    53,    68,    71,    75,    69,    27,
      50,    47,    47,    47,    47,    75,    75,    61,    29,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    61,    76,    75,    75,    73,    75,    75,
      48,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    51,    48,    75,
      46,    48,    54,    27,    72,    48,    75,    75,    75,    71,
      74,    46,    71,    75,    48,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    57,    58,    59,    58,    60,
      60,    61,    61,    62,    62,    62,    62,    64,    63,    63,
      65,    63,    67,    66,    66,    68,    69,    69,    70,    70,
      71,    71,    72,    71,    73,    74,    71,    71,    71,    71,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    76,    75,    75,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     4,     0,     7,     2,
       0,     1,     0,     1,     1,     1,     1,     0,     4,     1,
       0,     5,     0,     5,     2,     5,     5,     0,     3,     0,
       1,     1,     0,     6,     0,     0,     7,     9,     4,     1,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     1,     1,     1,     1,
       1,     0,     4,     4,     6,     3
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
        case 7:
#line 43 "compiler.y" /* yacc.c:1646  */
    { IS(lexema,(yyvsp[-2]),FUNCION);}
#line 1395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 50 "compiler.y" /* yacc.c:1646  */
    { IS(lexema,tipoVar,VAR); }
#line 1401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 50 "compiler.y" /* yacc.c:1646  */
    { IS(lexema,tipoVar,VAR); }
#line 1407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 50 "compiler.y" /* yacc.c:1646  */
    { IS(lexema,tipoVar,ARREGLO); }
#line 1413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 51 "compiler.y" /* yacc.c:1646  */
    { IS(lexema,(yyvsp[-1]),VAR); }
#line 1419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 51 "compiler.y" /* yacc.c:1646  */
    { IS(lexema,(yyvsp[-1]),VAR); }
#line 1425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 59 "compiler.y" /* yacc.c:1646  */
    { genCodigo(SALTARF,(yyvsp[-1]),0,(yyval)); (yyval) = cx; }
#line 1431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 59 "compiler.y" /* yacc.c:1646  */
    { TABCOD[(yyvsp[-1])].a3 = cx + 1;  }
#line 1437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 60 "compiler.y" /* yacc.c:1646  */
    {(yyval) = cx + 1;}
#line 1443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 60 "compiler.y" /* yacc.c:1646  */
    {genCodigo(SALTARF,(yyvsp[-1]),0,-1); /* Destino no resuelto */
	   						                         (yyval) = cx; /* Falta llenar cuarto componente de este salto */}
#line 1450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 63 "compiler.y" /* yacc.c:1646  */
    {genCodigo(SALTAR,0,0,(yyvsp[-4])); /* Ir al comienzo de la expresión */
							                         TABCOD[(yyvsp[-1])].a3 = cx + 1; /* Llenando destino de sltar falso */
				                                    }
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 67 "compiler.y" /* yacc.c:1646  */
    {genCodigo(IMPRINUM,(yyvsp[-1]),0,0);}
#line 1464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 70 "compiler.y" /* yacc.c:1646  */
    {int p = localizaSimbolo(lexema); int n = genvartemp(p); genCodigo(OPER_OR,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 71 "compiler.y" /* yacc.c:1646  */
    {int p = localizaSimbolo(lexema); int n = genvartemp(p); genCodigo(OPER_AND,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 72 "compiler.y" /* yacc.c:1646  */
    {int p = localizaSimbolo(lexema); int n = genvartemp(p); genCodigo(NEGACION,n,(yyvsp[0]),0); (yyval)=n;}
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 73 "compiler.y" /* yacc.c:1646  */
    {int n = genvartemp(0);	genCodigo(IGUAL,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 74 "compiler.y" /* yacc.c:1646  */
    {int n = genvartemp(0);	genCodigo(NOIGUAL,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 76 "compiler.y" /* yacc.c:1646  */
    {int n = genvartemp(0);	genCodigo(MENOR,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 77 "compiler.y" /* yacc.c:1646  */
    {int n = genvartemp(0);	genCodigo(MAYOR,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 78 "compiler.y" /* yacc.c:1646  */
    {int n = genvartemp(0);	genCodigo(MENOR_IGUAL,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 79 "compiler.y" /* yacc.c:1646  */
    {int n = genvartemp(0);	genCodigo(MAYOR_IGUAL,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 81 "compiler.y" /* yacc.c:1646  */
    {int p = localizaSimbolo(lexema); int n = genvartemp(p); genCodigo(SUMAR,n,(yyvsp[-2]),(yyvsp[0]));  (yyval)=n;}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 82 "compiler.y" /* yacc.c:1646  */
    {int p = localizaSimbolo(lexema); int n = genvartemp(p); genCodigo(RESTAR,n,(yyvsp[-2]),(yyvsp[0]));(yyval)=n;}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 83 "compiler.y" /* yacc.c:1646  */
    {int p = localizaSimbolo(lexema); int n = genvartemp(p); genCodigo(MULTIPLICAR,n,(yyvsp[-2]),(yyvsp[0]));(yyval)=n;}
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 84 "compiler.y" /* yacc.c:1646  */
    {int p = localizaSimbolo(lexema); int n = genvartemp(p); genCodigo(DIVIDIR,n,(yyvsp[-2]),(yyvsp[0]));(yyval)=n;}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 85 "compiler.y" /* yacc.c:1646  */
    {int p = localizaSimbolo(lexema); int n = genvartemp(p); genCodigo(MODULO,n,(yyvsp[-2]),(yyvsp[0]));(yyval)=n;}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 86 "compiler.y" /* yacc.c:1646  */
    {int p = localizaSimbolo(lexema); int n = genvartemp(p); genCodigo(POTENCIA,n,(yyvsp[-2]),(yyvsp[0]));(yyval)=n;}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 89 "compiler.y" /* yacc.c:1646  */
    {(yyval) = localizaSimbolo(lexema);}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 90 "compiler.y" /* yacc.c:1646  */
    {IS(lexema,INT,NUM);(yyval) = localizaSimbolo(lexema);TS[(yyval)].a3.entero = atoi(lexema);}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 91 "compiler.y" /* yacc.c:1646  */
    {IS(lexema,BOOL,BOOLEANO);(yyval) = localizaSimbolo(lexema);strcpy(TS[(yyval)].a3.booleano,lexema);}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 93 "compiler.y" /* yacc.c:1646  */
    {IS(lexema,STRING,LETRAS);(yyval) = localizaSimbolo(lexema);strcpy(TS[(yyval)].a3.cadena,lexema);}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 95 "compiler.y" /* yacc.c:1646  */
    {float v; IS(lexema,FLOAT,REAL);(yyval) = localizaSimbolo(lexema);	sscanf(lexema,"%f",&v);TS[(yyval)].a3.real = v;}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 96 "compiler.y" /* yacc.c:1646  */
    { (yyval) = localizaSimbolo(lexema); }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 96 "compiler.y" /* yacc.c:1646  */
    {genCodigo(MOVER,(yyvsp[-1]),(yyvsp[0]),0);}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 99 "compiler.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1606 "y.tab.c" /* yacc.c:1646  */
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
#line 101 "compiler.y" /* yacc.c:1906  */


void genCodigo(int op,int a1,int a2,int a3)
{
	tipoCodigo *p;

	p = &TABCOD[cx++];
	p->op = op;
	p->a1 = a1;
	p->a2 = a2;
	p->a3 = a3;

}

int genvartemp(int pos)
{	
	char t[30];
	sprintf(t,"T%-2d",indicevartemp++);
	strcpy(TS[nTS].nombre,t);
	TS[nTS].a1 = TS[pos].a1;
	TS[nTS].a2 = TEMP;
	TS[nTS].linea = numeroLinea+1;
	if (TS[nTS].a1==INT)
		strcpy(TS[nTS].tipo,"int");
	else if (TS[nTS].a1==FLOAT)
		strcpy(TS[nTS].tipo,"float");
	else if (TS[nTS].a1==STRING)
		strcpy(TS[nTS].tipo,"string");	
	else {
		if (pos!=-1)
			strcpy(TS[nTS].tipo,"bool");	
	}

	if (TS[nTS].a2==VAR)
		strcpy(TS[nTS].clase,"var");
	else if (TS[nTS].a2==FUNCION)
		strcpy(TS[nTS].clase,"func");
	else if (TS[nTS].a2==ARREGLO)
		strcpy(TS[nTS].clase,"array");	
	else 
		strcpy(TS[nTS].clase,"temp");		

	return nTS++;
}

void muestraCodigo()
{
	int i,op,a1,a2,a3;
	for(i=0;i<=cx;i++) {
		op = TABCOD[i].op; a1 = TABCOD[i].a1;
		a2 = TABCOD[i].a2; a3 = TABCOD[i].a3;
		printf("%2d) ",i);

		if (a1==-1 || a2==-1 || a3==-1) {
			printf("Error: variable no declarada linea ");
			if (a2!=-1)
				printf("%d\n",TS[a2].linea);
			else {
				if (a3!=-1)
					printf("%d\n",TS[a3].linea);			
			}	
			exit(0);
		}

		switch(op)
		{
		case SUMAR: if(TS[a3].a1 == INT && TS[a2].a1 == INT)
						printf("SUMAR %s = %s + %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
					else if(TS[a3].a1 == FLOAT && TS[a2].a1 == FLOAT)
						printf("SUMAR %s = %s + %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
					else {
						printf("Error: asignando tipo diferente %s linea %d\n", TS[a1].nombre,TS[a2].linea);
						exit(0);		
					}		
	 				break;	
		
		case MENOR: printf("MENOR %s = %s < %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case MENOR_IGUAL: printf("MENOR_IGUAL %s = %s <= %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case MAYOR: printf("MAYOR %s = %s > %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case MAYOR_IGUAL: printf("MAYOR_IGUAL %s = %s >= %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case SALTAR: printf("SALTAR %d \n",a3);break;
		case SALTARV: printf("SALTARV %s %d \n",TS[a1].nombre,a3);break;
		case SALTARF: printf("SALTARF %s %d \n",TS[a1].nombre,a3);break;
		case MOVER: 
					if(TS[a1].a1 == INT && TS[a2].a1 == INT)
						printf("MOVER %s %s \n",TS[a1].nombre,TS[a2].nombre);
					else if(TS[a1].a1 == FLOAT && TS[a2].a1 == FLOAT)
						printf("MOVER %s %s \n",TS[a1].nombre,TS[a2].nombre);
					else if(TS[a1].a1 == BOOL && TS[a2].a1 == BOOL)
						printf("MOVER %s %s \n",TS[a1].nombre,TS[a2].nombre);	
					else if(TS[a1].a1 == STRING && TS[a2].a1 == STRING)
						printf("MOVER %s %s \n",TS[a1].nombre,TS[a2].nombre);		
					else if(TS[a1].a1 == BOOL && TS[a2].a1 == INT)
						printf("MOVER %s %s \n",TS[a1].nombre,TS[a2].nombre);			
					else {
						printf("Error: asignando tipo diferente %s linea %d\n", TS[a1].nombre, TS[a2].linea);
						exit(0);		
					}		
	 				break;
		case IMPRINUM: printf("IMPRINUM %s \n",TS[a1].nombre);break;
		
        case RESTAR      : if(TS[a3].a1 == INT && TS[a2].a1 == INT)
								printf("RESTAR %s = %s - %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
							else if(TS[a3].a1 == FLOAT && TS[a2].a1 == FLOAT)
								printf("RESTAR %s = %s - %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
							else {
								printf("Error: asignando tipo diferente %s linea %d\n", TS[a1].nombre,TS[a2].linea);
								exit(0);		
							}		
			 				break;	
        case MULTIPLICAR : 
        				if(TS[a3].a1 == INT && TS[a2].a1 == INT)
							printf("MULTIPLICAR %s = %s * %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
						else if(TS[a3].a1 == FLOAT && TS[a2].a1 == FLOAT)
							printf("MULTIPLICAR %s = %s * %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
						else {
							printf("Error: asignando tipo diferente %s linea %d\n", TS[a1].nombre, TS[a2].linea);
							exit(0);		
						}		
		 				break;	
        case DIVIDIR : 
        				if(TS[a3].a1 == INT && TS[a2].a1 == INT)
							printf("DIVIDIR %s = %s / %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
						else if(TS[a3].a1 == FLOAT && TS[a2].a1 == FLOAT)
							printf("DIVIDIR %s = %s / %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
						else {
							printf("Error: asignando tipo diferente %s linea %d\n", TS[a1].nombre, TS[a2].linea);
							exit(0);		
						}		
		 				break;	
		case MODULO : 
        				if(TS[a3].a1 == INT && TS[a2].a1 == INT)
							printf("MODULO %s = %s %% %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
						else {
							printf("Error: asignando tipo diferente %s linea %d\n", TS[a1].nombre, TS[a2].linea);
							exit(0);		
						}		
		 				break;	 				
        case POTENCIA : 
        				if(TS[a3].a1 == INT && TS[a2].a1 == INT)
							printf("POTENCIA %s = %s ^ %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
						else {
							printf("Error: asignando tipo diferente %s linea %d\n", TS[a1].nombre, TS[a2].linea);
							exit(0);		
						}		
		 				break;


		case OPER_OR: printf("OR %s = %s || %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case OPER_AND: printf("AND %s = %s && %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;

		case NEGACION: 
						if (TS[a2].a1 == BOOL)
							printf("NOT %s = ! %s\n",TS[a1].nombre, TS[a2].nombre);
						else {
							printf("Error: operacion invalida %s linea %d\n", TS[a1].nombre,TS[a2].linea);
							exit(0);			
						}		
		 				break;		
		case IGUAL: printf("IGUAL %s = %s == %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case NOIGUAL: printf("NOIGUAL %s = %s != %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;

		}
	}
	return;
}


int localizaSimbolo(char *n)
{
	int i;
	for(i=0;i<nTS;i++) 
		if(strcmp(n,TS[i].nombre) == 0) 
			return i;

	return -1;
}

void IS(char *lexema, int tipo, int clase)
{
	int posicion;
	posicion = localizaSimbolo(lexema);

	if(posicion>=0) {
		if(TS[posicion].a2==VAR) {
			if(TS[posicion].a1==tipo)
				printf("Error: redeclaracion de %s %s linea %d\n",TS[posicion].tipo,lexema,numeroLinea+1);
			else	
				printf("Error: conflicto declaracion %s %s linea %d\n",TS[posicion].tipo,lexema,numeroLinea+1);
			exit(0);
		}
	}

	else 
	{
		strcpy(TS[nTS].nombre,lexema);
		TS[nTS].a1 = tipo;
		TS[nTS].a2 = clase;
		TS[nTS].linea = numeroLinea+1;
		if (TS[nTS].a1==INT)
			strcpy(TS[nTS].tipo,"int");
		else if (TS[nTS].a1==FLOAT)
			strcpy(TS[nTS].tipo,"float");
		else if (TS[nTS].a1==STRING)
			strcpy(TS[nTS].tipo,"string");	
		else		
			strcpy(TS[nTS].tipo,"bool");

		if (TS[nTS].a2==VAR)
			strcpy(TS[nTS].clase,"var");
		else if (TS[nTS].a2==FUNCION)
			strcpy(TS[nTS].clase,"func");
		else if (TS[nTS].a2==ARREGLO)
			strcpy(TS[nTS].clase,"array");	
		else 
			strcpy(TS[nTS].clase,"temp");		

		nTS++;
	}	
}

void muestraSimbolo()
{
	int i;
	printf("\t\t\tTabla de Simbolos \n");
	for(i=0,pTS=TS;i<nTS;i++,pTS++) {
		if (pTS->a1==INT) {
			pTS->espacio = sizeof(pTS->a3.entero);
			printf("%20s \t%s \t%s \t%d \t%zu\n",pTS->nombre,pTS->tipo,pTS->clase,pTS->a3.entero,pTS->espacio);
		}
		else if (pTS->a1==FLOAT) {
			pTS->espacio = sizeof(pTS->a3.real);
			printf("%20s \t%s \t%s \t%g \t%zu\n",pTS->nombre,pTS->tipo,pTS->clase,pTS->a3.real,pTS->espacio);
		}
		else if (pTS->a1==BOOL) {
			pTS->espacio = sizeof(pTS->a3.booleano);
			printf("%20s \t%s \t%s \t%s \t%zu\n",pTS->nombre,pTS->tipo,pTS->clase,pTS->a3.booleano,pTS->espacio);		
		}
		else {
			pTS->espacio = sizeof(pTS->a3.cadena);
			printf("%20s \t%s \t%s \t%s \t%zu\n",pTS->nombre,pTS->tipo,pTS->clase,pTS->a3.cadena,pTS->espacio);	
		}
	}
} 

void tabla_codigo()
{
	int i;
	printf("\t\t\tTabla de Codigos \n");
	for(i=0;i<cx;i++) 
			printf("%d %20d \t%d \t%d \t%d\n",i+1,TABCOD[i].op,TABCOD[i].a1,TABCOD[i].a2,TABCOD[i].a3);
} 

// Generacion de codigo intermedio: (3AC) codigo de 3 direcciones

void interprete(){
	int icx,op,a1,a2,a3;
	float v;
	printf("Programa en ejecución: \n");
	icx = 0;

	while(1)
	{
		if(icx==cx+1) break;
		op = TABCOD[icx].op;
		a1 = TABCOD[icx].a1;
		a2 = TABCOD[icx].a2;
		a3 = TABCOD[icx].a3;
		switch(op)
		{
			case SALTAR : icx = a3; continue;
			case SALTARF : 
						   if(TS[a1].a3.entero==0) { icx = a3; continue;}
						   else break;

			case IMPRINUM : 
							if(TS[a1].a1 == INT)
								printf("    %s %d\n",TS[a1].nombre,TS[a1].a3.entero); 
							else if(TS[a1].a1 == BOOL)
								printf("    %s %s\n",TS[a1].nombre,TS[a1].a3.booleano); 	
							else if(TS[a1].a1 == STRING)
								printf("    %s %s\n",TS[a1].nombre,TS[a1].a3.cadena); 		
							else	
								printf("    %s %8.2f\n",TS[a1].nombre,TS[a1].a3.real);
							break;

			case MOVER : 	if(TS[a1].a1 == INT)
								TS[a1].a3.entero = TS[a2].a3.entero;
							else if(TS[a1].a1 == FLOAT)
								TS[a1].a3.real = TS[a2].a3.real;
							else if(TS[a1].a1 == STRING) 
								strcpy(TS[a1].a3.cadena,TS[a2].a3.cadena);	
							else {
								strcpy(TS[a1].a3.booleano,TS[a2].a3.booleano);
								TS[a2].a3.entero = 0;	
							}
			 				break;

			case MENOR :    {  int t;
								t = (TS[a2].a3.entero < TS[a3].a3.entero);
								strcpy(TS[a1].a3.booleano,"false");
								if (t==1)
									strcpy(TS[a1].a3.booleano,"true");								
							}	
						 	break;
			case MENOR_IGUAL :  {  int t;
								t = (TS[a2].a3.entero <= TS[a3].a3.entero);
								strcpy(TS[a1].a3.booleano,"false");
								if (t==1)
									strcpy(TS[a1].a3.booleano,"true");								
								}	
						 		break;
			case MAYOR : {  int t;
								t = (TS[a2].a3.entero > TS[a3].a3.entero);
								strcpy(TS[a1].a3.booleano,"false");
								if (t==1)
									strcpy(TS[a1].a3.booleano,"true");								
							}	
						 	break;
			case MAYOR_IGUAL : {  int t;
								t = (TS[a2].a3.entero >= TS[a3].a3.entero);
								strcpy(TS[a1].a3.booleano,"false");
								if (t==1)
									strcpy(TS[a1].a3.booleano,"true");								
							}	
						 	break;

			case SUMAR : if(TS[a1].a1 == INT)
							TS[a1].a3.entero = TS[a2].a3.entero + TS[a3].a3.entero;
						 else	
							TS[a1].a3.real = TS[a2].a3.real + TS[a3].a3.real;
						 break;
		
            case RESTAR :   if(TS[a1].a1 == INT)
								TS[a1].a3.entero = TS[a2].a3.entero - TS[a3].a3.entero;
							else	
								TS[a1].a3.real = TS[a2].a3.real - TS[a3].a3.real;
							break;
            case MULTIPLICAR :  if(TS[a1].a1 == INT)
									TS[a1].a3.entero = TS[a2].a3.entero * TS[a3].a3.entero;
								else	
									TS[a1].a3.real = TS[a2].a3.real * TS[a3].a3.real;
								break;
            case DIVIDIR     :  if(TS[a1].a1 == INT)
									TS[a1].a3.entero = TS[a2].a3.entero / TS[a3].a3.entero;
								else	
									TS[a1].a3.real = TS[a2].a3.real / TS[a3].a3.real;
								break;
			case MODULO     :  if(TS[a1].a1 == INT)
									TS[a1].a3.entero = TS[a2].a3.entero % TS[a3].a3.entero;
								break;					
			case POTENCIA   :  if(TS[a1].a1 == INT)
									TS[a1].a3.entero =  (int) pow((double) TS[a2].a3.entero,TS[a3].a3.entero);
								break;					


            case OPER_OR :  {
	            				int t1 = 0, t2 = 0, t3;
	            				if (strcmp(TS[a2].a3.booleano,"true")==0) 
	            					t1 = 1;

	            				if (strcmp(TS[a3].a3.booleano,"true")==0)
	            					t2 = 1;	

	            				t3 = t1 || t2; 
	            				strcpy(TS[a1].a3.booleano,"false");
	            				if (t3==1)
	            					strcpy(TS[a1].a3.booleano,"true");
            				}
            				break;		
            case OPER_AND : {
	            				int t1 = 0, t2 = 0, t3;
	            				if (strcmp(TS[a2].a3.booleano,"true")==0) 
	            					t1 = 1;

	            				if (strcmp(TS[a3].a3.booleano,"true")==0)
	            					t2 = 1;	

	            				t3 = t1 && t2; 
	            				strcpy(TS[a1].a3.booleano,"false");
	            				if (t3==1)
	            					strcpy(TS[a1].a3.booleano,"true");
            				}
            				break;		
            case NEGACION: 
            				if (strcmp(TS[a2].a3.booleano,"true")==0)
            			   		strcpy(TS[a1].a3.booleano,"false");
            			   	else	
            				 	strcpy(TS[a1].a3.booleano,"true");
            				break;

            case IGUAL : {  int t;
								t = (TS[a2].a3.entero == TS[a3].a3.entero);
								strcpy(TS[a1].a3.booleano,"false");
								if (t==1)
									strcpy(TS[a1].a3.booleano,"true");								
							}	
						 	break;
            case NOIGUAL : {  int t;
								t = (TS[a2].a3.entero != TS[a3].a3.entero);
								strcpy(TS[a1].a3.booleano,"false");
								if (t==1)
									strcpy(TS[a1].a3.booleano,"true");								
							}	
						 	break;
		}
		icx++;
	}  
}  


// Analizador lexico
int yylex()
{
	int c;  
	char *p;

	do {
		c=getchar(); 
		if (c=='\n')
    		++numeroLinea;
	}while(isspace(c));
  
  	if (isalpha(c))
    { 
    	p=lexema;
		do  { *p++=c; c=getchar(); } while (isalpha(c));

		ungetc(c,stdin); *p=0;

		if (strcmp(lexema,"if")==0) return IF;
		if (strcmp(lexema,"else")==0) return ELSE;
		if (strcmp(lexema,"int")==0) return tipoVar=yylval=INT;
		if (strcmp(lexema,"float")==0) return tipoVar=yylval=FLOAT;
		if (strcmp(lexema,"while")==0) return WHILE;
		if (strcmp(lexema,"for")==0) return FOR;
		if (strcmp(lexema,"do")==0) return DO;
		if (strcmp(lexema,"print")==0) return IMPRINUM;
		if (strcmp(lexema,"bool")==0) return tipoVar=yylval=BOOL;
		if (strcmp(lexema,"true")==0) return yylval=BOOLEANO;
		if (strcmp(lexema,"false")==0) return yylval=BOOLEANO;
		if (strcmp(lexema,"string")==0) return tipoVar=yylval=STRING;
      
      	return yylval=ID;
    }

    if (c==EOF) 
    	return EOF;
  
    if ( c=='(' || c==')' || c==';' || c==',' || c=='{' || c=='}' ||
         c==',' || c=='*' || c=='+' || c=='-' || c=='?' ||
         c=='[' || c==']' || c=='%' || c=='^') return yylval=c;

	if(c=='/') 
	{	c=getchar();
    	if(c=='/') 
    	{
			do c=getchar(); while(c!='\n');
			if (c=='\n')
    			++numeroLinea;
			return COMENTARIO;
    	}

		if(c=='*') 
		{ 
			do {
				c=getchar();
				if (c=='\n')
    				++numeroLinea; 
			}while(c!='*');

			c=getchar();
		 	return COMENTARIO;
		}

		ungetc(c,stdin); return '/';
	}     

    if ( c=='!') 
    { 
    	c=getchar();
    	if(c=='=') return NOIGUAL;
    	ungetc(c,stdin); return NOT;
    }
    	
    if ( c=='=' ) 
    {
    	c=getchar();
    	if(c=='=') return IGUAL;
    	ungetc(c,stdin); return '=';
    }
    	
    if ( c=='>' ) 
    {
    	c=getchar();
    	if(c=='=') return MAYORIGUAL;
    	ungetc(c,stdin); return '>';
    }
    	
    if ( c=='<' ) 
    {
    	c=getchar();
    	if(c=='=') return MENORIGUAL;
    	ungetc(c,stdin); return '<';
    }

    if ( c=='&' ) 
    {
    	c=getchar();
    	if(c=='&') return AND;
    	ungetc(c,stdin); return '&';
    }

    if ( c=='|' ) 
    {
    	c=getchar();
    	if(c=='|') return OR;
    	ungetc(c,stdin); return '|';
    }

    if (c=='\"')
    {	
    	p=lexema;
    	c=getchar();
		do  { *p++=c; c=getchar(); } while (c!='\"');

		*p=0;
		c=getchar();
		return yylval=LETRAS;
    }

    if (isdigit(c)) 
    { 
    	p=lexema;
      	do  { *p++=c; c=getchar(); } while (isdigit(c));

      	if(c=='.') 
      	{	do  { *p++=c; c=getchar(); } while (isdigit(c));
      		ungetc(c,stdin); 
      		*p=0; 
      		return yylval=REAL;
      	}

      	ungetc(c,stdin); *p=0;
    	return yylval=NUM;
    }
    	
    yyerror("caracter no valido\n");
}

void yyerror(char *m)  { 
	printf("%s\n",m); 
	exit(0);
}
	
int main()  
{
	yyparse(); // llama automaticamente a yylex para obtener cada token
	printf("\n");
	muestraSimbolo();
	printf("\n");
	muestraCodigo();
	interprete();
	printf("\n");
	muestraSimbolo();
	return 0;
}
