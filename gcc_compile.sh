#!/usr/bin/env bash

# The pwd must be the repository folder (ie; monsters) for the script to work

set -e    # halt on first error

# use 'g++' as the compiler
CPP='g++'

# be aggressive about warnings and errors
W_FLAGS='-Wall -Wextra -Werror -Wfatal-errors -Wpedantic -pedantic-errors -fdiagnostics-show-location=once -std=c++11'

# get hash of the last commit
hash=$(git log | head -n1 | cut -d " " -f 2 | cut -c 1-6)

# clear out previous executables
rm -rf ./binaries/Linux_Binary_*

# Ensure we're formatted everywhere.
clang-format-6.0 -i $(find source -iname '*.[ch]*' -not -path '*/SDL2/*')

# compile
$CPP -c ./source/main.cpp -o ./source/main.o $W_FLAGS
$CPP -o ./binaries/Linux_Binary_$hash ./source/main.o $W_FLAGS

# clear out object files
rm -f ./source/*.o
