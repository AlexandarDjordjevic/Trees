#include <iostream>
#include <BSTree.hpp>

int main(){
    std::cout << "Example Int" << std::endl;

    BSTree<int> bst;

    bst.Insert(10);
    bst.Insert(14);
    bst.Insert(6);
    bst.Insert(8);
    bst.Insert(9);
    bst.Insert(3);
    bst.Insert(4);
    bst.Insert(12);
    bst.Insert(15);
    bst.Insert(13);
    bst.Contains(10);
    std::cout << "Size: " << bst.Size() << std::endl;
    std::cout << "Min: " << bst.Min() << std::endl;
    std::cout << "Contains 10: " << bst.Contains(10) << std::endl;
#ifdef DEBUG
    std::cout << "Value: ";
    bst.Print();
#endif

    return 0;
}