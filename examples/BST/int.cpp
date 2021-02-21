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
    Tree::BST<int> bst;

    std::cout << "Insert: 10, 14, 6, 8, 9, 3, 2, 12, 15, 13" << std::endl;
    bst.Insert(10);
    bst.Insert(14);
    bst.Insert(6);
    bst.Insert(8);
    bst.Insert(9);
    bst.Insert(3);
    bst.Insert(2);
    bst.Insert(12);
    bst.Insert(15);
    bst.Insert(13);

#ifdef DEBUG
    std::cout << "Tree: ";
    bst.Traverse();
#endif

    std::cout << "Min: " << bst.Min() << std::endl;
    std::cout << "Size: " << bst.Size() << std::endl;
    std::cout << "Contains 8: " << std::boolalpha << bst.Contains(8) << std::endl;
    std::cout << "Delete: 8" << std::endl;
    bst.Delete(8);
    std::cout << "Size: " << bst.Size() << std::endl;
    std::cout << "Contains 8: " << std::boolalpha << bst.Contains(8) << std::endl;

#ifdef DEBUG
    std::cout << "Tree: ";
    bst.Traverse();
#endif

    return 0;
}