#include "BinarySearchTree.hpp"

#include <iostream>
BinarySearchTree::BinarySearchTree(void) { root = NULL; }
BinarySearchTree::BinarySearchTree(const BinarySearchTree &Copy) {
  root = NULL;
  copy(Copy.root);
}
void BinarySearchTree::copy(BinarySearchTree::Node *node) {
  if (node == NULL) {
    return;
  }
  {
    insert(node->getData());
    copy(node->getLeft());
    copy(node->getRight());
  }
}
BinarySearchTree::~BinarySearchTree(void) { root = deleteAllNodes(root); }
void BinarySearchTree::inOrderTraverse(BinarySearchTree::Node *node) {
  if (node == NULL) {
    return;
  }
  inOrderTraverse(node->getLeft());
  std::cout << node->getData() << " ";
  inOrderTraverse(node->getRight());
}
void BinarySearchTree::inOrder(void) {
  inOrderTraverse(root);
  std::cout << std::endl;
}
void BinarySearchTree::preOrderTraverse(BinarySearchTree::Node *node) {
  if (node == NULL) {
    return;
  }
  std::cout << node->getData() << " ";
  preOrderTraverse(node->getLeft());
  preOrderTraverse(node->getRight());
}
void BinarySearchTree::preOrder(void) {
  preOrderTraverse(root);
  std::cout << std::endl;
}
void BinarySearchTree::postOrderTraverse(BinarySearchTree::Node *node) {
  if (node == NULL) {
    return;
  }
  postOrderTraverse(node->getLeft());
  postOrderTraverse(node->getRight());
  std::cout << node->getData() << " ";
}
void BinarySearchTree::postOrder(void) {
  postOrderTraverse(root);
  std::cout << std::endl;
}
BinarySearchTree::Node *BinarySearchTree::insert(int data,
                                                 BinarySearchTree::Node *node) {
  if (node == NULL) {
    node = new BinarySearchTree::Node(data);
  } else {
    if (data > node->getData()) {
      node->setRight(insert(data, node->getRight()));
    } else {
      node->setLeft(insert(data, node->getLeft()));
    }
  }
  return node;
}
void BinarySearchTree::insert(int data) { root = insert(data, root); }
BinarySearchTree::Node *BinarySearchTree::remove(int data,
                                                 BinarySearchTree::Node *node) {
  if (node == NULL) {
    return NULL;
  } else if (data < node->getData()) {
    node->setLeft(remove(data, node->getLeft()));
  } else if (data > node->getData()) {
    node->setRight(remove(data, node->getRight()));
  } else if (node->getLeft() && node->getRight()) {
    Node *temp;
    temp = node->getRight();
    while (temp->getLeft() != NULL) {
      temp = temp->getLeft();
    }
    node->setData(temp->getData());
    node->setRight(remove(node->getData(), node->getRight()));
  } else {
    Node *temp;
    temp = node;
    if (node->getLeft() == NULL) {
      node = node->getRight();
    } else if (node->getRight() == NULL) {
      node = node->getLeft();
    }
    delete temp;
  }
  return node;
}
void BinarySearchTree::remove(int data) { root = remove(data, root); }
BinarySearchTree::Node *BinarySearchTree::deleteAllNodes(
    BinarySearchTree::Node *node) {
  if (node == NULL) {
    return NULL;
  }
  {
    deleteAllNodes(node->getLeft());
    deleteAllNodes(node->getRight());
    delete node;
  }
  return NULL;
}
BinarySearchTree::Node *BinarySearchTree::search(int data,
                                                 BinarySearchTree::Node *node) {
  if (node == NULL) {
    return NULL;
  } else if (data < node->getData()) {
    return search(data, node->getLeft());
  } else if (data > node->getData()) {
    return search(data, node->getRight());
  } else {
    return node;
  }
}
BinarySearchTree::Node *BinarySearchTree::search(int data) {
  return search(data, root);
}
BinarySearchTree::Node::Node(int d) {
  data = d;
  left = NULL;
  right = NULL;
}
BinarySearchTree::Node *BinarySearchTree::Node::getRight(void) { return right; }
BinarySearchTree::Node *BinarySearchTree::Node::getLeft(void) { return left; }
int BinarySearchTree::Node::getData(void) { return data; }
void BinarySearchTree::Node::setLeft(BinarySearchTree::Node *node) {
  left = node;
}
void BinarySearchTree::Node::setRight(BinarySearchTree::Node *node) {
  right = node;
}
void BinarySearchTree::Node::setData(int d) { data = d; }