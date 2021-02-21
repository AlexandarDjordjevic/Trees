# BST

[![Build](https://github.com/AlexandarDjordjevic/Trees/actions/workflows/test-code.yml/badge.svg)](https://github.com/AlexandarDjordjevic/Trees/actions/workflows/test-code.yml)
[![CodeFactor](https://www.codefactor.io/repository/github/alexandardjordjevic/trees/badge)](https://www.codefactor.io/repository/github/alexandardjordjevic/trees)
![Licence](https://img.shields.io/github/license/AlexandarDjordjevic/BST?style=flat) 

Binary Search Tree data structure implementation.

* `C++11` C++ version
* `make` build system
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
* `void Insert(KeyType key);` - Insert new element into the tree
* `void Delete(KeyType key);` - Delete element from the tree
* `KeyType Min() const;` - Return tree min key value
* `KeyType Max() const;` - Return tree max key value
* `bool IsEmpty() const;` - Check if tree is empty
* `size_t Size() const;` - Return number of tree elements
* `bool Contains(KeyType key) const;` - Check if the BST contains given key

## Examples

_Example 1:_ Demonstrate library usage with double type  
_Example 2:_ Demonstrate library usage with integer type
