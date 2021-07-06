#include "BinarySearchTree.hpp"

#include <iostream>
template <class T>
BinarySearchTree<T>::BinarySearchTree(void) {
  root = NULL;
}
template <class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree &Copy) {
  root = NULL;
  copy(Copy.root);
}
template <class T>
void BinarySearchTree<T>::copy(Node<T> *node) {
  if (node == NULL) {
    return;
  }
  {
    insert(node->getData());
    copy(node->getLeft());
    copy(node->getRight());
  }
}
template <class T>
BinarySearchTree<T>::~BinarySearchTree(void) {
  root = deleteAllNodes(root);
}
template <class T>
void BinarySearchTree<T>::inOrderTraverse(Node<T> *node) {
  if (node == NULL) {
    return;
  }
  inOrderTraverse(node->getLeft());
  std::cout << node->getData() << " ";
  inOrderTraverse(node->getRight());
}
template <class T>
void BinarySearchTree<T>::inOrder(void) {
  inOrderTraverse(root);
}
template <class T>
void BinarySearchTree<T>::preOrderTraverse(Node<T> *node) {
  if (node == NULL) {
    return;
  }
  std::cout << node->getData() << " ";
  preOrderTraverse(node->getLeft());
  preOrderTraverse(node->getRight());
}
template <class T>
void BinarySearchTree<T>::preOrder(void) {
  preOrderTraverse(root);
}
template <class T>
void BinarySearchTree<T>::postOrderTraverse(Node<T> *node) {
  if (node == NULL) {
    return;
  }
  postOrderTraverse(node->getLeft());
  postOrderTraverse(node->getRight());
  std::cout << node->getData() << " ";
}
template <class T>
void BinarySearchTree<T>::postOrder(void) {
  postOrderTraverse(root);
}
template <class T>
Node<T> *BinarySearchTree<T>::insert(T data, Node<T> *node) {
  if (node == NULL) {
    node = new Node<T>(data);
  } else {
    if (data > node->getData()) {
      node->setRight(insert(data, node->getRight()));
    } else {
      node->setLeft(insert(data, node->getLeft()));
    }
  }
  return node;
}
template <class T>
void BinarySearchTree<T>::insert(T data) {
  root = insert(data, root);
}
template <class T>
Node<T> *BinarySearchTree<T>::remove(T data, Node<T> *node) {
  if (node == NULL) {
    return NULL;
  } else if (data < node->getData()) {
    node->setLeft(remove(data, node->getLeft()));
  } else if (data > node->getData()) {
    node->setRight(remove(data, node->getRight()));
  } else if (node->getLeft() && node->getRight()) {
    Node<T> *temp;
    temp = node->getRight();
    while (temp->getLeft() != NULL) {
      temp = temp->getLeft();
    }
    node->setData(temp->getData());
    node->setRight(remove(node->getData(), node->getRight()));
  } else {
    Node<T> *temp;
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
template <class T>
void BinarySearchTree<T>::remove(T data) {
  root = remove(data, root);
}
template <class T>
Node<T> *BinarySearchTree<T>::deleteAllNodes(Node<T> *node) {
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
template <class T>
Node<T> *BinarySearchTree<T>::search(T data, Node<T> *node) {
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
template <class T>
Node<T> *BinarySearchTree<T>::search(T data) {
  return search(data, root);
}
template <class T>
Node<T>::Node(T d) {
  data = d;
  left = NULL;
  right = NULL;
}
template <class T>
Node<T> *Node<T>::getRight(void) {
  return right;
}
template <class T>
Node<T> *Node<T>::getLeft(void) {
  return left;
}
template <class T>
T Node<T>::getData(void) {
  return data;
}
template <class T>
void Node<T>::setLeft(Node<T> *node) {
  left = node;
}
template <class T>
void Node<T>::setRight(Node<T> *node) {
  right = node;
}
template <class T>
void Node<T>::setData(T d) {
  data = d;
}