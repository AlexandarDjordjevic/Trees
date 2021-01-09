#include <gtest/gtest.h>
#include <BSTree.hpp>


TEST(BST, IsEmpty){
    BSTree<int> bst;
    ASSERT_TRUE(bst.IsEmpty());
    bst.Insert(15);
    ASSERT_FALSE(bst.IsEmpty());
}

TEST(BST, Insert){
    BSTree<int> bst;
    bst.Insert(10);
    ASSERT_FALSE(bst.IsEmpty());
    bst.Insert(14);
    bst.Insert(6);
    ASSERT_EQ(3, bst.Size());
}

TEST(BST, Min){
    BSTree<int> bst;
    bst.Insert(10);
    bst.Insert(14);
    bst.Insert(6);
    ASSERT_EQ(6, bst.Min());
}

TEST(BST, Max){
    BSTree<int> bst;
    bst.Insert(10);
    bst.Insert(14);
    bst.Insert(26);
    ASSERT_EQ(26, bst.Max());
}

TEST(BST, Size){
    BSTree<int> bst;
    ASSERT_EQ(0, bst.Size());
    bst.Insert(10);
    ASSERT_EQ(1, bst.Size());
    bst.Insert(14);
    ASSERT_EQ(2, bst.Size());
    bst.Insert(6);
    ASSERT_EQ(3, bst.Size());
}

TEST(BST, Contains){
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
    ASSERT_TRUE(bst.Contains(10));
    ASSERT_FALSE(bst.Contains(120));
    ASSERT_TRUE(bst.Contains(12));
    ASSERT_TRUE(bst.Contains(3));
}
// TEST(BST, AscendingVector){
//     BSTree<int> bst;
//     bst.Insert(10);
//     bst.Insert(14);
//     bst.Insert(6);
//     ASSERT_EQ((std::vector<int>{6, 10, 14}), bst.ToAscendingVector());
// }


// TEST(BST, DescendingVector){
//     BSTree<int> bst;
//     bst.Insert(10);
//     bst.Insert(14);
//     bst.Insert(6);
//     ASSERT_EQ((std::vector<int>{14, 10, 6}), bst.ToDescendingVector());
// }

// TEST(BST, RemoveLeafNode){
//     BSTree<int> bst;
//     bst.Insert(10);
//     bst.Insert(14);
//     bst.Insert(6);
//     bst.Delete(14);
//     ASSERT_EQ((std::vector<int>{6, 10}), bst.ToAscendingVector());
// }

// TEST(BST, RemoveRootNode){
//     BSTree<int> bst;
//     bst.Insert(10);
//     bst.Insert(14);
//     bst.Insert(6);
//     bst.Insert(8);
//     bst.Insert(9);
//     bst.Insert(3);
//     bst.Insert(4);
//     bst.Insert(12);
//     bst.Insert(15);
//     bst.Insert(13);
//     bst.Delete(10);
//     ASSERT_EQ((std::vector<int>{3, 4, 6, 8, 9, 12, 13, 14, 15}), bst.ToAscendingVector());
// }