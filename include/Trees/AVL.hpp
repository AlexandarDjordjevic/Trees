/**
 * @author Aleksandar Djordjevic (alexandar1608@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <vector>
#include <memory>
#include <exception>

#ifdef DEBUG
#include <iostream>
#endif

namespace Tree{

template <class KEY_T>
class AVL{
private:
    struct Node
    {
        Node() 
            : m_left{nullptr}, m_right{nullptr}, m_key{}
        {
        }

        Node(KEY_T key) 
            : m_left{nullptr}, m_right{nullptr}, m_key{key}
        {
        }   

        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;

        Node(Node&&) = delete;
        Node& operator=(Node&&) = delete;

        Node* m_left;
        Node* m_right;
        KEY_T m_key;
    };
    
public:
    /**
     * @brief Default constructor
     * 
     */
    AVL()
        : m_root{nullptr}, m_size{0}
    {        
    };

    /**
     * @brief Default destructor
     * 
     */
    ~AVL(){
        release_node(m_root);
    }

    AVL(const AVL&) = delete;
    AVL& operator=(const AVL&) = delete;
    AVL(AVL&&) = delete;
    AVL& operator=(AVL &&) = delete;

    /**
     * @brief insert new element into the tree
     * 
     * @param key 
     */
    void insert(KEY_T key){
        m_root = insert_helper(m_root, key);
    }

    /**
     * @brief remove key for the tree
     * 
     * @param key to delete
     */
    void remove(KEY_T key){
        m_root = delete_helper(m_root, key);
    }

    /**
     * @brief Return tree min key value
     * 
     * @return KEY_T 
     */
    KEY_T min() const{
        if (is_empty()){
            throw std::length_error("Tree is empty");
        }
        return MinHelper(m_root);
    }

    /**
     * @brief Return tree max key value
     * 
     * @return KEY_T 
     */
    KEY_T max() const{
        if (is_empty()) {
            throw std::length_error("Tree is empty");
        }
        auto max{m_root} ;
        while (max->m_right) {
            max = max->m_right;
        }
        return max->m_key;
    }

    /**
     * @brief Check if tree is empty
     * 
     * @return true 
     * @return false 
     */
    bool is_empty() const{
        return m_root == nullptr;
    }

    /**
     * @brief Return number of tree elements
     * 
     * @return size_t 
     */
    size_t size() const{
        return m_size;
    }

    /**
     * @brief Check if the AVL contains given key
     * 
     * @param key 
     * @return true 
     * @return false 
     */
    bool contains(KEY_T key) const{
       return contains_helper(m_root, key);
    }
    
    /**
     * @brief This function return in-order vector of keys
     * 
     * @return std::vector<KEY_T>
     */
    std::vector<KEY_T> traverse_inorder(){
        std::vector<KEY_T> array(m_size);
        traverse_inorder_helper(m_root, array);
        return array;
    }

#ifdef DEBUG
    /**
     * @brief This function is used to print keys in ascending order
     * 
     */
    void traverse() const{
        std::cout << "[ ";
        print_helper(m_root);
        std::cout << "]" << std::endl;
    }
#endif
    
private:
    Node* traverse_inorder_helper(Node* root, std::shared_ptr<std::vector<KEY_T>> array){
        if (root != nullptr){
            if(root->m_left) traverse_inorder_helper(root->m_left, array);
            array->emplace_back(root->m_key);
            if(root->m_right) traverse_inorder_helper(root->m_right, array);
        }
        return root;
    }

    Node* insert_helper(Node* node, KEY_T key){
        if (node == nullptr){
            m_size++;
            return new Node(key);
        }
        if (key < node->m_key){
            node->m_left = insert_helper(node->m_left, key);
        }
        else 
        {
            node->m_right = insert_helper(node->m_right, key);
        }

        return node;
    }

    void release_node(Node* node){
        if (is_empty() == false){
            if (node->m_left)
                release_node(node->m_left);
            if (node->m_right)
                release_node(node->m_right);
            delete node;
        }
    }

    bool contains_helper(const Node* root, KEY_T key) const{
        if (root->m_key > key)
            return (root->m_left) && contains_helper(root->m_left, key);
        else if (root->m_key < key)
            return (root->m_right) && contains_helper(root->m_right, key);
        else 
            return true;
    }   

    KEY_T min_helper(const Node* root) const{
        auto min = root;
        while (min->m_left) min = min->m_left;
        return min->m_key;
    }

    Node* delete_helper(Node* root, KEY_T key){
        if (root == nullptr) return root;

        if (key > root->m_key)
            root->m_right = delete_helper(root->m_right, key);
        else if (key < root->m_key)
            root->m_left = delete_helper(root->m_left, key);
        else{
            if (root->m_left == nullptr && root->m_right == nullptr){
                delete root;
                root = nullptr;
                m_size--;
            } else if (root->m_left == nullptr){
                auto right = root->m_right;
                delete root;
                root = right;
                m_size--;
            } else if (root->m_right == nullptr){
                auto left = root->m_left;
                delete root;
                root = left;
                m_size--;
            } else {
                auto min = MinHelper(root->m_right);
                root->m_key = min;
                root->m_right = delete_helper(root->m_right, min);
            }
        }
        return root;
    }

#ifdef DEBUG
    void print_helper(const Node* node) const{
        if (node->m_left)
            print_helper(node->m_left);
        std::cout << node->m_key << ' ';
        if (node->m_right)
            print_helper(node->m_right);
    }
#endif

private:
    Node* m_root{nullptr};
    size_t m_size{0};
};
} //namespace Tree