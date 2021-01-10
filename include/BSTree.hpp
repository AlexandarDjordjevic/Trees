/**
 * @author Aleksandar Djordjevic (alexandar1608@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

#ifdef DEBUG
#include <iostream>
#endif

template <class KeyType>
class BSTree{
private:
    struct Node
    {
        Node() 
            : m_Left(nullptr), m_Right(nullptr), m_Key(0)
        {
        }

        Node(KeyType key) 
            : m_Left(nullptr), m_Right(nullptr), m_Key(key)
        {
        }   

        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;

        Node(Node&&) = delete;
        Node& operator=(Node&&) = delete;

        Node* m_Left;
        Node* m_Right;
        KeyType m_Key;
    };
    
public:
    /**
     * @brief Default constructor
     * 
     */
    BSTree()
        : m_Root(nullptr), m_Size(0)
    {        
    };

    /**
     * @brief Default destructor
     * 
     */
    ~BSTree(){
        FreeNode(m_Root);
    }

    BSTree(const BSTree&) = delete;
    BSTree& operator=(const BSTree&) = delete;
    BSTree(BSTree&&) = delete;
    BSTree& operator=(BSTree &&) = delete;

    /**
     * @brief Insert new element into the tree
     * 
     * @param key 
     */
    void Insert(KeyType key){
        m_Root = InsertHelper(m_Root, key);
    }

    /**
     * @brief Delete key for the tree
     * 
     * @param key to delete
     */
    void Delete(KeyType key){
        m_Root = DeleteHelper(m_Root, key);
    }

    /**
     * @brief Return tree min key value
     * 
     * @return KeyType 
     */
    KeyType Min() const{
        if (IsEmpty()) throw std::length_error("Tree is empty");
        return MinHelper(m_Root);
    }

    /**
     * @brief Return tree max key value
     * 
     * @return KeyType 
     */
    KeyType Max() const{
        if (IsEmpty()) throw std::length_error("Tree is empty");
        auto max = m_Root;
        while (max->m_Right) max = max->m_Right;
        return max->m_Key;
    }

    /**
     * @brief Check if tree is empty
     * 
     * @return true 
     * @return false 
     */
    bool IsEmpty() const{
        return m_Root == nullptr;
    }

    /**
     * @brief Return number of tree elements
     * 
     * @return size_t 
     */
    size_t Size() const{
        return m_Size;
    }

    /**
     * @brief Check if the BST contains given key
     * 
     * @param key 
     * @return true 
     * @return false 
     */
    bool Contains(KeyType key) const{
       return ContainsHelper(m_Root, key);
    }
    
#ifdef DEBUG
    /**
     * @brief This function is used to print keys in ascending order
     * 
     */
    void Traverse() const{
        std::cout << "[ ";
        PrintHelper(m_Root);
        std::cout << "]" << std::endl;
    }
#endif
    
private:
    Node* InsertHelper(Node* node, KeyType key){
        if (node == nullptr){
            m_Size++;
            return new Node(key);
        }
        if (key < node->m_Key){
            node->m_Left = InsertHelper(node->m_Left, key);
        }
        else 
        {
            node->m_Right = InsertHelper(node->m_Right, key);
        }

        return node;
    }

    void FreeNode(Node* node){
        if (IsEmpty() == false){
            if (node->m_Left)
                FreeNode(node->m_Left);
            if (node->m_Right)
                FreeNode(node->m_Right);
            delete node;
        }
    }

    bool ContainsHelper(const Node* root, KeyType key) const{
        if (root->m_Key > key)
            return (root->m_Left) ? ContainsHelper(root->m_Left, key) : false;
        else if (root->m_Key < key)
            return (root->m_Right) ? ContainsHelper(root->m_Right, key) : false;
        else 
            return true;
    }   

    KeyType MinHelper(const Node* root) const{
        auto min = root;
        while (min->m_Left) min = min->m_Left;
        return min->m_Key;
    }

    Node* DeleteHelper(Node* root, KeyType key){
        if (root == nullptr) return root;

        if (key > root->m_Key)
            root->m_Right = DeleteHelper(root->m_Right, key);
        else if (key < root->m_Key)
            root->m_Left = DeleteHelper(root->m_Left, key);
        else{
            if (root->m_Left == nullptr && root->m_Right == nullptr){
                delete root;
                root = nullptr;
                m_Size--;
            } else if (root->m_Left == nullptr){
                auto right = root->m_Right;
                delete root;
                root = right;
                m_Size--;
            } else if (root->m_Right == nullptr){
                auto left = root->m_Left;
                delete root;
                root = left;
                m_Size--;
            } else {
                auto min = MinHelper(root->m_Right);
                root->m_Key = min;
                root->m_Right = DeleteHelper(root->m_Right, min);
            }
        }
        return root;
    }

#ifdef DEBUG
    void PrintHelper(const Node* node) const{
        if (node->m_Left)
            PrintHelper(node->m_Left);
        std::cout << node->m_Key << ' ';
        if (node->m_Right)
            PrintHelper(node->m_Right);
    }
#endif

private:
    Node* m_Root = nullptr;
    size_t m_Size = 0;
};

