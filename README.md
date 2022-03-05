# BST

[![Build](https://github.com/AlexandarDjordjevic/Trees/actions/workflows/test-code.yml/badge.svg)](https://github.com/AlexandarDjordjevic/Trees/actions/workflows/test-code.yml)
[![CodeFactor](https://www.codefactor.io/repository/github/alexandardjordjevic/trees/badge)](https://www.codefactor.io/repository/github/alexandardjordjevic/trees)
![Licence](https://img.shields.io/github/license/AlexandarDjordjevic/Trees?style=flat) 

Binary Search Tree data structure implementation.

* `C++11` C++ version
* `CMake` build system
* `g++` C++ compiler
* `STL` only libraries

## Requirements

* CMake 3.8
* gcc
* c++11

## Build

```shell
    mkdir build
    cmake . -B build
    cmake --build build --target all
```

## API List

* `BST();` - Default constructor
* `void insert(KEY_T key);` - insert new element into the tree
* `void remove(KEY_T key);` - remove element from the tree
* `KEY_T min() const;` - Return tree min key value
* `KEY_T max() const;` - Return tree max key value
* `bool is_empty() const;` - Check if tree is empty
* `size_t size() const;` - Return number of tree elements
* `bool contains(KEY_T key) const;` - Check if the BST contains given key

## Examples

_Example 1:_ Demonstrate library usage with double type  
_Example 2:_ Demonstrate library usage with integer type
