/*
--------------------------------------------------
Name    : Binary Search Tree
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 23/Mar/2021
--------------------------------------------------
*/
#include <iostream>
#include "BinarySearchTree.hpp"
int main(void)
{
    BinarySearchTree<int> a;
    a.insert(5);
    a.insert(2);
    a.insert(3);
    a.insert(1);
    a.insert(7);
    a.insert(12);
    a.insert(20);
    a.insert(32);
    a.insert(6);
    a.insert(9);
    Node<int> *b = a.search(12);
    std::cout << b->getRight()->getData() << std::endl;
    a.remove(12);
    a.inOrder();
    BinarySearchTree<int> c = a;
    c.postOrder();
    return 0;
}