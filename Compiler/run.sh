#!/bin/sh

yacc -d compiler.y

gcc y.tab.c -o compiler
#./compiler <archivo.cpp