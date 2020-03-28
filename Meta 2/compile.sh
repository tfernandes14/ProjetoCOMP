#!/bin/sh

lex jucompiler.l
bison -y -d -t -v jucompiler.y
clang-3.9 -o jucompiler y.tab.c lex.yy.c