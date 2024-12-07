#!/bin/bash

set -e

cd build
make clean
qmake6 ../VKeyboard.pro
make
./VKeyboard