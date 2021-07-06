class BinarySearchTree {
 public:
  class Node {
   public:
    Node(int d);
    int getData(void);
    BinarySearchTree::Node *getRight(void);
    BinarySearchTree::Node *getLeft(void);
    void setData(int d);
    void setRight(BinarySearchTree::Node *);
    void setLeft(BinarySearchTree::Node *);

   private:
    int data;
    BinarySearchTree::Node *right;
    BinarySearchTree::Node *left;
  };
  BinarySearchTree(void);
  BinarySearchTree(const BinarySearchTree &Copy);
  ~BinarySearchTree(void);
  void inOrder(void);
  void preOrder(void);
  void postOrder(void);
  void insert(int data);
  void remove(int data);
  BinarySearchTree::Node *search(int data);

 private:
  BinarySearchTree::Node *root;
  void inOrderTraverse(BinarySearchTree::Node *node);
  void preOrderTraverse(BinarySearchTree::Node *node);
  void postOrderTraverse(BinarySearchTree::Node *node);
  BinarySearchTree::Node *insert(int data, BinarySearchTree::Node *node);
  BinarySearchTree::Node *remove(int data, BinarySearchTree::Node *node);
  BinarySearchTree::Node *deleteAllNodes(BinarySearchTree::Node *node);
  BinarySearchTree::Node *search(int data, BinarySearchTree::Node *node);
  void copy(BinarySearchTree::Node *node);
};