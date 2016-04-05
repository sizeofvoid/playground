#!/bin/sh

# OpenBSD cmake build script
# install cmake, g++, gcc from ports

mkdir build; cd build;
cmake -DCMAKE_C_COMPILER=`which egcc` -DCMAKE_CXX_COMPILER=`which eg++` ../
