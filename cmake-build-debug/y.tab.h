/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 117 "/home/quanjunyuan/CLionProjects/DataBase4/cmake-build-debug/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_QUANJUNYUAN_CLIONPROJECTS_DATABASE4_CMAKE_BUILD_DEBUG_Y_TAB_H_INCLUDED  */
