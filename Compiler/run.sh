#!/bin/sh

yacc -d compiler.y

gcc y.tab.c -o compiler -lm