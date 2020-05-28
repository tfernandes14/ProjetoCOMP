#!/bin/sh

yacc -d jucompiler.y
lex jucompiler.l
bison -y -d -t -v jucompiler.y
clang-3.9 -o jucompiler -Wall -g -Wno-unused-function *.c
zip -r jucompiler.zip jucompiler.l jucompiler.y lex.yy.c y.tab.c y.tab.h semantics_ast.c semantics_ast.h symbol_table.c symbol_table.h llvm.c llvm.h
