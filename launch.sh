#!/bin/sh
export DYLD_LIBRARY_PATH=ext/SFML-2.2/lib

mkdir bin

make && ./bin/Client $*
