Advent of Code 2022
----

My repositary for the Advent of Code 2022.

## Building

The project is written in C++ and requires CMake for building. Generally,
building the project on UNIXes is done in the following way:

```
cmake -B build
cmake --build build -j$(nproc --all) # run this to build
```

