Advent of Code 2022
----

My repositary for the Advent of Code 2022. I am aware that it's a mess. You
have to be in the root directory of the repositary to be able to run the
programs.

## Building

The project is written in C++ and requires CMake for building. Generally,
building the project on UNIXes is done in the following way:

```
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j$(nproc --all) # run this to build…
gdb build/src/Day\ 1/Day1 # …and to debug
```

