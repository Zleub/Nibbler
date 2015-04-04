#!/bin/sh
export DYLD_LIBRARY_PATH=ext/SFML-2.2/lib

make && ./bin/Client $*
