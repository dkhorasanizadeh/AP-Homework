template <class T>
class List;
template <class T>
class TwoDList;
template <class T>
std::ostream &operator<<(std::ostream &out, TwoDList<T> &L);
template <class T>
class Node {
 public:
  Node(T _data, Node<T> *_next = NULL);
  T getData() const { return data; };
  friend class List<T>;
  friend class TwoDList<T>;
  friend std::ostream &operator<<<T>(std::ostream &out, TwoDList<T> &L);

 private:
  T data;
  Node<T> *next;
};
template <class T>
class List {
 private:
  Node<T> *head;
  List<T> *next;
  int size;

 public:
  List();
  void insert(T ins);
  void remove(void);
  T &operator[](int index);
  friend class TwoDList<T>;
  friend std::ostream &operator<<<T>(std::ostream &out, TwoDList<T> &L);
};
template <class T>
class TwoDList {
 private:
  List<T> *head;
  int size;

 public:
  TwoDList();
  void insert(List<T>);
  void insert(T);
  List<T> &operator()(int index);
  T &operator()(int i, int j);
  friend std::ostream &operator<<<T>(std::ostream &out, TwoDList<T> &L);
};
template <class T>
Node<T>::Node(T _data, Node<T> *_next) {
  data = _data;
  next = _next;
}
template <class T>
List<T>::List() {
  size = 0;
  head = NULL;
  next = NULL;
}
template <class T>
void List<T>::insert(T ins) {
  if (head == NULL) {
    head = new Node<T>(ins);
    size++;
    return;
  }
  Node<T> *p = head;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = new Node<T>(ins);
  size++;
}
template <class T>
void List<T>::remove(void) {
  if (head == NULL) {
    return;
  }
  Node<T> *p = head;
  Node<T> *q = head;
  while (p->getNext() != NULL) {
    q = p;
    p = p->getNext();
  }
  q->next = NULL;
  delete p;
  size--;
}
template <class T>
T &List<T>::operator[](int i) {
  if (i >= size) {
    return head->data;
  }
  int index = 0;
  Node<T> *p = head;
  while (index < i) {
    index++;
    p = p->next;
  }
  return p->data;
}
template <class T>
TwoDList<T>::TwoDList() {
  head = NULL;
  size = 0;
}
template <class T>
void TwoDList<T>::insert(List<T> insList) {
  if (head == NULL) {
    head = &insList;
    size++;
    return;
  }
  List<T> *p = head;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = &insList;
  size++;
}
template <class T>
void TwoDList<T>::insert(T ins) {
  List<T> *insList;
  insList = new List<T>;
  insList->insert(ins);
  if (head == NULL) {
    head = insList;
    size++;
    return;
  }
  List<T> *p = head;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = insList;
  size++;
}
template <class T>
std::ostream &operator<<(std::ostream &out, TwoDList<T> &L) {
  List<T> *p = L.head;
  while (p != NULL) {
    Node<T> *q = p->head;
    while (q != NULL) {
      out << q->data << " ";
      q = q->next;
    }
    out << std::endl;
    p = p->next;
  }
  return out;
}
template <class T>
List<T> &TwoDList<T>::operator()(int i) {
  if (i >= size) {
    return head->data;
  }
  int index = 0;
  List<T> *p = head;
  while (index < i) {
    index++;
    p = p->next;
  }
  return p->data;
}
template <class T>
T &TwoDList<T>::operator()(int i, int j) {
  if (i >= size) {
    return head->head->data;
  }
  int index = 0;
  List<T> *p = head;
  while (index < i) {
    index++;
    p = p->next;
  }
  if (i >= p->size) {
    return p->head->data;
  }
  index = 0;
  Node<T> *q = p->head;
  while (index < j) {
    index++;
    q = q->next;
  }
  return q->data;
}