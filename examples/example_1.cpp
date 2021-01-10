#include <iostream>
#include <BSTree.hpp>

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
    BSTree<double> bst;

    std::cout << "Insert: 10.1, 14.2, 6.4, 8, 9.1, 3, 2.99, 12.8, 14.5, 13" << std::endl;
    bst.Insert(10.1);
    bst.Insert(14.2);
    bst.Insert(6.4);
    bst.Insert(8);
    bst.Insert(9.1);
    bst.Insert(3);
    bst.Insert(2.99);
    bst.Insert(12.8);
    bst.Insert(14.5);
    bst.Insert(13);

#ifdef DEBUG
    std::cout << "Tree: ";
    bst.Traverse();
#endif

    std::cout << "Min: " << bst.Min() << std::endl;
    std::cout << "Size: " << bst.Size() << std::endl;
    std::cout << "Contains 14.2: " << std::boolalpha << bst.Contains(8) << std::endl;
    std::cout << "Delete: 14.2" << std::endl;
    bst.Delete(14.2);
     std::cout << "Size: " << bst.Size() << std::endl;
    std::cout << "Contains 14.2: " << std::boolalpha << bst.Contains(8) << std::endl;

#ifdef DEBUG
    std::cout << "Value: ";
    bst.Traverse();
#endif

    return 0;
}