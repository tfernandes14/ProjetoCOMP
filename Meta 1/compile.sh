#!/bin/sh

flex jucompiler.l
clang-3.9 -o jucompiler lex.yy.c
