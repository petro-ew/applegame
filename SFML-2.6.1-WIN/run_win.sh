#!/bin/bash
cmake . -DCMAKE_TOOLCHAIN_FILE=windows.cmake CMakeLists.txt && make
