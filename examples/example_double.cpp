#include <iostream>
#include <BSTree.hpp>

int main(){
    std::cout << "Example Double" << std::endl;

    BSTree<double> bst;

    bst.Insert(10.0);
    bst.Insert(10.5);
    bst.Insert(10.9);
    bst.Insert(8.0);
    bst.Insert(9.0);
    bst.Insert(3.5);
    bst.Insert(4.9);
    bst.Insert(12.1);
    bst.Insert(15.6);
    bst.Insert(13.7);
    bst.Contains(10);
    std::cout << "Size: " << bst.Size() << std::endl;
    std::cout << "Min: " << bst.Min() << std::endl;
    std::cout << "Contains 10.5: " << bst.Contains(10.5) << std::endl;
#ifdef DEBUG
    std::cout << "Value: ";
    bst.Print();
#endif

    return 0;
}