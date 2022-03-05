#include <iostream>
#include <Trees/BST.hpp>

#define TREE "TREE:\n\
         10.1 \n\
       /     \\ \n\
     6.4      14.2\n\
     / \\     /   \\ \n\
    3   8   12.8   14.5\n\
   /     \\   \\ \n\
  2.99   9.1   13"
      
int main(){
    std::cout << "-------- Example 2: --------" << std::endl;

    std::cout << TREE << std::endl;
    std::cout << "------------------------" << std::endl;
    tree::BST<double> bst;

    std::cout << "insert: 10.1, 14.2, 6.4, 8, 9.1, 3, 2.99, 12.8, 14.5, 13" << std::endl;
    bst.insert(10.1);
    bst.insert(14.2);
    bst.insert(6.4);
    bst.insert(8);
    bst.insert(9.1);
    bst.insert(3);
    bst.insert(2.99);
    bst.insert(12.8);
    bst.insert(14.5);
    bst.insert(13);

#ifdef DEBUG
    std::cout << "Tree: ";
    bst.Traverse();
#endif

    std::cout << "min: " << bst.min() << std::endl;
    std::cout << "size: " << bst.size() << std::endl;
    std::cout << "contains 14.2: " << std::boolalpha << bst.contains(8) << std::endl;
    std::cout << "remove: 14.2" << std::endl;
    bst.remove(14.2);
     std::cout << "size: " << bst.size() << std::endl;
    std::cout << "contains 14.2: " << std::boolalpha << bst.contains(8) << std::endl;

#ifdef DEBUG
    std::cout << "Value: ";
    bst.Traverse();
#endif

    return 0;
}