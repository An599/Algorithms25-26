#include "RedBlackTree.h"

Node::Node(int data) {
    this->data = data;
    color = RED;
    left = right = parent = nullptr;
}

RedBlackTree::RedBlackTree() {
    root = nullptr;
}

void RedBlackTree::leftRotate(Node* x) {
    Node* y = x->right;

    x->right = y->left;

    if (y->left != nullptr)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void RedBlackTree::rightRotate(Node* y) {
    Node* x = y->left;

    y->left = x->right;

    if (x->right != nullptr)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == nullptr)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

void RedBlackTree::fixInsert(Node* k) {
    Node* u;

    while (k->parent != nullptr && k->parent->color == RED) {

        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;

            if (u != nullptr && u->color == RED) {
                u->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            }
            else {
                if (k == k->parent->left) {
                    k = k->parent;
                    rightRotate(k);
                }

                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                leftRotate(k->parent->parent);
            }
        }
        else {
            u = k->parent->parent->right;

            if (u != nullptr && u->color == RED) {
                u->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            }
            else {
                if (k == k->parent->right) {
                    k = k->parent;
                    leftRotate(k);
                }

                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                rightRotate(k->parent->parent);
            }
        }

        if (k == root)
            break;
    }

    root->color = BLACK;
}

void RedBlackTree::insert(int key) {
    Node* node = new Node(key);

    Node* y = nullptr;
    Node* x = root;

    while (x != nullptr) {
        y = x;
        if (node->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    node->parent = y;

    if (y == nullptr)
        root = node;
    else if (node->data < y->data)
        y->left = node;
    else
        y->right = node;

    if (node->parent == nullptr) {
        node->color = BLACK;
        return;
    }

    if (node->parent->parent == nullptr)
        return;

    fixInsert(node);
}

void RedBlackTree::inorderHelper(Node* node) {
    if (node == nullptr)
        return;

    inorderHelper(node->left);
    std::cout << node->data << " ";
    inorderHelper(node->right);
}

void RedBlackTree::inorder() {
    inorderHelper(root);
    std::cout << std::endl;
}

void RedBlackTree::preorder() {
    preorderHelper(root);
    std::cout << std::endl;
}

void RedBlackTree::postorder() {
    postorderHelper(root);
    std::cout << std::endl;
}

void RedBlackTree::preorderHelper(Node* node) {
    if (node == nullptr)
        return;

    std::cout << node->data << " ";
    preorderHelper(node->left);
    preorderHelper(node->right);
}

void RedBlackTree::postorderHelper(Node* node) {
    if (node == nullptr)
        return;

    postorderHelper(node->left);
    postorderHelper(node->right);
    std::cout << node->data << " ";
}
