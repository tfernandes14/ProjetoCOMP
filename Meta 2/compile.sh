#!/bin/sh

yacc -d jucompiler.y
lex jucompiler.l
bison -y -d -t -v jucompiler.y
clang-3.9 -o jucompiler y.tab.c lex.yy.c
zip -r jucompiler.zip jucompiler.l jucompiler.y lex.yy.c y.tab.c y.tab.h
