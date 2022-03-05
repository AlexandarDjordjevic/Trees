#include <gtest/gtest.h>
#include <Trees/BST.hpp>

struct Bst : public ::testing::Test{
    tree::BST<int> bst;
};

TEST_F(Bst, is_empty){
    ASSERT_TRUE(bst.is_empty());
    bst.insert(15);
    ASSERT_FALSE(bst.is_empty());
}

TEST_F(Bst, insert){
    bst.insert(10);
    ASSERT_FALSE(bst.is_empty());
    bst.insert(14);
    bst.insert(6);
    ASSERT_EQ(3, bst.size());
}

TEST_F(Bst, min){
    bst.insert(10);
    bst.insert(14);
    bst.insert(6);
    ASSERT_EQ(6, bst.min());
}

TEST_F(Bst, MinEmptyTree){
    ASSERT_THROW(bst.min(), std::length_error);
}
TEST_F(Bst, max){
    bst.insert(10);
    bst.insert(14);
    bst.insert(26);
    ASSERT_EQ(26, bst.max());
}


TEST_F(Bst, MaxEmptyTree){
    ASSERT_THROW(bst.max(), std::length_error);
}
TEST_F(Bst, size){
    ASSERT_EQ(0, bst.size());
    bst.insert(10);
    ASSERT_EQ(1, bst.size());
    bst.insert(14);
    ASSERT_EQ(2, bst.size());
    bst.insert(6);
    ASSERT_EQ(3, bst.size());
}

TEST_F(Bst, contains){
    std::vector<int> elements{10, 14, 6, 8, 9, 3, 4, 12, 15, 13};
    for (auto element : elements){
        bst.insert(element);
    }
    ASSERT_TRUE(bst.contains(10));
    ASSERT_FALSE(bst.contains(120));
    ASSERT_TRUE(bst.contains(12));
    ASSERT_TRUE(bst.contains(3));
}

TEST_F(Bst, DeleteLeafNode){
    bst.insert(10);
    bst.insert(14);
    bst.insert(6);
    ASSERT_TRUE(bst.contains(14));
    auto size = bst.size();
    bst.remove(14);
    ASSERT_FALSE(bst.contains(14));
    ASSERT_EQ(size - 1, bst.size());
}

TEST_F(Bst, DeleteRootNode){
    std::vector<int> elements{10, 14, 6, 8, 9, 3, 4, 12, 15, 13};
    for (auto element : elements){
        bst.insert(element);
    }
    auto size = bst.size();
    ASSERT_TRUE(bst.contains(10));
    bst.remove(10);
    ASSERT_FALSE(bst.contains(10));
    ASSERT_EQ(size - 1, bst.size());
}

TEST_F(Bst, DeleteNodeWithBothChildren){
    std::vector<int> elements{10, 14, 6, 8, 9, 3, 4, 12, 15, 13};
    for (auto element : elements){
        bst.insert(element);
    }
    auto size = bst.size();
    ASSERT_TRUE(bst.contains(14));
    bst.remove(14);
    ASSERT_FALSE(bst.contains(14));
    ASSERT_EQ(size - 1, bst.size());
}

TEST_F(Bst, DeleteNodeWithOnlyLeftChild){
    std::vector<int> elements{10, 14, 6, 8, 9, 3, 4, 12, 15, 13};
    for (auto element : elements){
        bst.insert(element);
    }
    auto size = bst.size();
    ASSERT_TRUE(bst.contains(3));
    bst.remove(3);
    ASSERT_FALSE(bst.contains(3));
    ASSERT_EQ(size - 1, bst.size());
}

TEST_F(Bst, DeleteNodeWithOnlyRightChild){
    std::vector<int> elements{10, 14, 6, 8, 9, 3, 4, 12, 15, 13};
    for (auto element : elements){
        bst.insert(element);
    }
    auto size = bst.size();
    ASSERT_TRUE(bst.contains(8));
    bst.remove(8);
    ASSERT_FALSE(bst.contains(8));
    ASSERT_EQ(size - 1, bst.size());
}

TEST_F(Bst, DeleteNonexistingKey){
    std::vector<int> elements{10, 14, 6, 8, 9, 3, 4, 12, 15, 13};
    for (auto element : elements){
        bst.insert(element);
    }
    auto size = bst.size();
    bst.remove(16);
    ASSERT_EQ(size, bst.size());
}

TEST_F(Bst, InorderTraversal){
    std::vector<int> elements{10, 14, 6, 8, 9, 3, 4, 12, 15, 13};
    std::vector<int> expected{3, 4, 6, 8, 9, 10, 12, 13, 14, 15};
    for (auto element : elements){
        bst.insert(element);
    }
    ASSERT_EQ(expected, bst.traverse_inorder());
}
