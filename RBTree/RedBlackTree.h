#pragma once
#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;
    Node(int data);
};

class RedBlackTree {
private:
    Node* root;
    void leftRotate(Node* x);
    void rightRotate(Node* y);
    void fixInsert(Node* k);
    void inorderHelper(Node* node);
    void preorderHelper(Node* node);
    void postorderHelper(Node* node);
public:
    RedBlackTree();
    void insert(int key);
    void inorder();
    void preorder();
    void postorder();
};
