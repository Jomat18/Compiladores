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
    NUM = 260,
    REAL = 261,
    FORMATO = 262,
    ID = 263,
    IF = 264,
    ELSE = 265,
    WHILE = 266,
    DO = 267,
    FOR = 268,
    LEENUM = 269,
    IMPRINUM = 270,
    COMENTARIO = 271,
    CENTERO = 272,
    CFLOAT = 273,
    VAR = 274,
    FUNCION = 275,
    ARREGLO = 276,
    NOT = 277,
    OR = 278,
    AND = 279,
    IGUAL = 280,
    NOIGUAL = 281,
    MENORIGUAL = 282,
    MAYORIGUAL = 283
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define NUM 260
#define REAL 261
#define FORMATO 262
#define ID 263
#define IF 264
#define ELSE 265
#define WHILE 266
#define DO 267
#define FOR 268
#define LEENUM 269
#define IMPRINUM 270
#define COMENTARIO 271
#define CENTERO 272
#define CFLOAT 273
#define VAR 274
#define FUNCION 275
#define ARREGLO 276
#define NOT 277
#define OR 278
#define AND 279
#define IGUAL 280
#define NOIGUAL 281
#define MENORIGUAL 282
#define MAYORIGUAL 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
