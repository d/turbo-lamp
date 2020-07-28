## Turbo Lamp

|Build Status|License|
|:---:|:---:|
|[![Build Status](https://travis-ci.com/d/turbo-lamp.svg?branch=develop)](https://travis-ci.com/d/turbo-lamp)|[![License: AGPL v3](https://img.shields.io/badge/License-AGPL%20v3-blue.svg)](https://www.gnu.org/licenses/agpl-3.0)|

## Making C++ Template Work For You
Hans asked me a question over Slack: given a type `R` that we know how to print, and a container, how do we only print the containers with elements we know how to print?

## How to build
1. Build with CMake.

   For those less intimately familiar with CMake, start with the [hack script](hack/hack):

   ```shell script
   hack/hack gen Debug build.debug
   hack/hack build build.debug
   ```

1. Formatting:
   1. We format all headers and C++ code with [clang-format](https://clang.llvm.org/docs/ClangFormat.html). As of writing, we are using release 10.
      For convenience, the hack script can also handle wholesale formatting:

      ```shell script
      hack/hack fmt
      ```

   1. The `CMakeLists.txt` file is formatted with [cmake_format](https://github.com/cheshirekow/cmake_format)
