#!/bin/sh

yacc -d compilador.y
gcc y.tab.c -o compiler
#./compiler <archivo.cpp