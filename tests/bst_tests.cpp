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

TEST(BST, MinEmptyTree){
    BSTree<int> bst;
    ASSERT_THROW(bst.Min(), std::length_error);
}
TEST(BST, Max){
    BSTree<int> bst;
    bst.Insert(10);
    bst.Insert(14);
    bst.Insert(26);
    ASSERT_EQ(26, bst.Max());
}


TEST(BST, MaxEmptyTree){
    BSTree<int> bst;
    ASSERT_THROW(bst.Max(), std::length_error);
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

TEST(BST, DeleteLeafNode){
    BSTree<int> bst;
    bst.Insert(10);
    bst.Insert(14);
    bst.Insert(6);
    ASSERT_TRUE(bst.Contains(14));
    auto size = bst.Size();
    bst.Delete(14);
    ASSERT_FALSE(bst.Contains(14));
    ASSERT_EQ(size - 1, bst.Size());
}

TEST(BST, DeleteRootNode){
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
    auto size = bst.Size();
    ASSERT_TRUE(bst.Contains(10));
    bst.Delete(10);
    ASSERT_FALSE(bst.Contains(10));
    ASSERT_EQ(size - 1, bst.Size());
}

TEST(BST, DeleteNodeWithBothChildren){
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
    auto size = bst.Size();
    ASSERT_TRUE(bst.Contains(14));
    bst.Delete(14);
    ASSERT_FALSE(bst.Contains(14));
    ASSERT_EQ(size - 1, bst.Size());
}

TEST(BST, DeleteNodeWithOnlyLeftChild){
    BSTree<int> bst;
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
    auto size = bst.Size();
    ASSERT_TRUE(bst.Contains(3));
    bst.Delete(3);
    ASSERT_FALSE(bst.Contains(3));
    ASSERT_EQ(size - 1, bst.Size());
}

TEST(BST, DeleteNodeWithOnlyRightChild){
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
    auto size = bst.Size();
    ASSERT_TRUE(bst.Contains(8));
    bst.Delete(8);
    ASSERT_FALSE(bst.Contains(8));
    ASSERT_EQ(size - 1, bst.Size());
}

TEST(BST, DeleteNonexistingKey){
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
    auto size = bst.Size();
    bst.Delete(16);
    ASSERT_EQ(size, bst.Size());
}

TEST(BST, InorderTraversal){
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
    std::vector<int> expected{3, 4, 6, 8, 9, 10, 12, 13, 14, 15};
    ASSERT_EQ(expected, *bst.TraverseInorder());
}