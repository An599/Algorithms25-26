#include "RedBlackTree.h"

int main() {
    RedBlackTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);
    tree.insert(5);
    std::cout << "Inorder: ";
    tree.inorder();
    std::cout << "Preorder: ";
    tree.preorder();
    std::cout << "Postorder: ";
    tree.postorder();
}
