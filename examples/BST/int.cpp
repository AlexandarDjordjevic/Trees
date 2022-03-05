#include <iostream>
#include <Trees/BST.hpp>

#define TREE "TREE:\n\
         10 \n\
       /    \\ \n\
      6       14\n\
     / \\    /   \\ \n\
    3   8   12   15\n\
   /     \\   \\ \n\
  2       9    13"
      
int main(){
    std::cout << "-------- Example 2: --------" << std::endl;

    std::cout << TREE << std::endl;
    std::cout << "------------------------" << std::endl;
    tree::BST<int> bst;

    std::cout << "insert: 10, 14, 6, 8, 9, 3, 2, 12, 15, 13" << std::endl;
    bst.insert(10);
    bst.insert(14);
    bst.insert(6);
    bst.insert(8);
    bst.insert(9);
    bst.insert(3);
    bst.insert(2);
    bst.insert(12);
    bst.insert(15);
    bst.insert(13);

#ifdef DEBUG
    std::cout << "Tree: ";
    bst.Traverse();
#endif

    std::cout << "min: " << bst.min() << std::endl;
    std::cout << "size: " << bst.size() << std::endl;
    std::cout << "contains 8: " << std::boolalpha << bst.contains(8) << std::endl;
    std::cout << "remove: 8" << std::endl;
    bst.remove(8);
    std::cout << "size: " << bst.size() << std::endl;
    std::cout << "contains 8: " << std::boolalpha << bst.contains(8) << std::endl;

#ifdef DEBUG
    std::cout << "Tree: ";
    bst.Traverse();
#endif

    return 0;
}