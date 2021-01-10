# BSTree

![Licence](https://img.shields.io/github/license/AlexandarDjordjevic/BSTree?style=flat) 
[![CodeFactor](https://www.codefactor.io/repository/github/alexandardjordjevic/bstree/badge)](https://www.codefactor.io/repository/github/alexandardjordjevic/bstree)
![Build](https://github.com/AlexandarDjordjevic/BSTree/workflows/Build/badge.svg)
![Unit tests](https://github.com/AlexandarDjordjevic/BSTree/workflows/Unit%20tests/badge.svg)

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

* `make all` - Build all targets
* `make all debug=yes` - Build all targets (debug)
* `make unit_tests` - Build unit tests
* `make run_tests` - Run tests
* `make examples` - Build examples
* `make run_example_1` - Run example 1
* `make run_example_2` - Run example 2

## API List

* `BSTree();` - Default constructor
* `void Insert(KeyType key);` - Insert new element into the tree
* `KeyType Min() const;` - Return tree min key value
* `KeyType Max() const;` - Return tree max key value
* `bool IsEmpty() const;` - Check if tree is empty
* `size_t Size() const;` - Return number of tree elements
* `bool Contains(KeyType key) const;` - Check if the BST contains given key

## Examples

_Example 1:_ Demonstrate library usage with double type  
_Example 2:_ Demonstrate library usage with integer type
