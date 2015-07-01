#!/usr/bin/env bash

DIR=$( cd "$( dirname "$0" )" && pwd )

cd ${DIR}/src

flex -+ -o lexer.cc lexer.ll
bison -L C++ -d parser.yy

cd ${DIR}/.out
cmake ..
make
cd ${DIR}
