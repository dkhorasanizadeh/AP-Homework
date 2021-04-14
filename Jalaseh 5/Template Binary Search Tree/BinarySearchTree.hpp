#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
template <class T>
class Node
{
private:
    T data;
    Node<T> *right;
    Node<T> *left;

public:
    Node(T d);
    T getData(void);
    Node<T> *getRight(void);
    Node<T> *getLeft(void);
    void setData(T d);
    void setRight(Node<T> *);
    void setLeft(Node<T> *);
};
template <class T>
class BinarySearchTree
{
public:
    BinarySearchTree(void);
    BinarySearchTree(const BinarySearchTree &Copy);
    ~BinarySearchTree(void);
    void inOrder(void);
    void preOrder(void);
    void postOrder(void);
    void insert(T data);
    void remove(T data);
    Node<T> *search(T data);

private:
    Node<T> *root;
    void inOrderTraverse(Node<T> *node);
    void preOrderTraverse(Node<T> *node);
    void postOrderTraverse(Node<T> *node);
    Node<T> *insert(T data, Node<T> *node);
    Node<T> *remove(T data, Node<T> *node);
    Node<T> *deleteAllNodes(Node<T> *node);
    Node<T> *search(T data, Node<T> *node);
    void copy(Node<T> *node);
};
#endif