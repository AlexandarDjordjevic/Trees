# BST

![Licence](https://img.shields.io/github/license/AlexandarDjordjevic/BST?style=flat) 
[![CodeFactor](https://www.codefactor.io/repository/github/alexandardjordjevic/bstree/badge/master)](https://www.codefactor.io/repository/github/alexandardjordjevic/bstree/overview/master)
[![Build](https://github.com/AlexandarDjordjevic/BSTree/actions/workflows/test-code.yml/badge.svg)](https://github.com/AlexandarDjordjevic/BSTree/actions/workflows/test-code.yml)

Binary Search Tree data structure implementation.

* `C++11` C++ version
* `make` build system
* `g++` C++ compiler
* `STL` only libraries

## Requirements

* make
* gcc
* c++11

## Build

* `make all <debug=yes>` - Build all targets. Debug is optional
* `make unit_tests` - Build unit tests
* `make run_tests` - Run tests
* `make examples <debug=yes>` - Build examples. Debug is optional
* `make run_example_1 <debug=yes>` - Run example 1. Debug is optional
* `make run_example_2 <debug=yes>` - Run example 2. Debug is optional

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
