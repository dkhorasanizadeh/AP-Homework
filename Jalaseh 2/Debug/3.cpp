#include <iostream>
#define MAX_SIZE 200
#define DEBUG_PRINT(node) cout << node->x << endl;
using namespace std;

typedef struct alfa *alfaptr;
struct alfa {
  long long x;
  alfaptr next;
};

alfaptr rear = NULL, front = NULL;
int arr[MAX_SIZE];

void push(int x) {
  alfaptr node;
  node = new alfa;
  node->x = x;
  node->next = NULL;
  if (!front) {
    front = node;
    rear = node;
  } else {
    rear->next = node;
    rear = node;
  }
}
void pop() {
  if (!front) {
    cout << "ERROR1" << endl;
  } else {
    if (front == rear) {
      delete front;
      front = NULL;
      rear = NULL;
    } else {
      alfaptr node;
      node = front->next;
      delete front;
      front = node;
    }
  }
}
void search(int x) {
  alfaptr node = front;
  for (int counter = 0; node; counter++, node = node->next) {
    if (node->x == x) {
      cout << counter << endl;
      return;
    }
  }
  cout << "ERROR 2" << endl;
}
void rpop() {
  if (rear == front) {
    delete front;
    front = NULL;
    rear = NULL;
  } else {
    alfaptr node = front;
    while (node->next->next) {
      node = node->next;
    }
    delete rear;
    rear = node;
    rear->next = NULL;
  }
}
void set() {
  alfaptr node = front;
  for (int i = 0; i < MAX_SIZE && node; i++, node = node->next) {
    arr[i] = node->x;
  }
}
int size() {
  alfaptr node = front;
  int counter = 0;
  while (node) {
    counter++;
    node = node->next;
  }
  return counter;
}
void show() {
  if (front) {
    for (int i = 0; i < MAX_SIZE; i++) cout << arr[i] << " ";
  } else {
    cout << "ERROR3" << endl;
  }
}
int average() {
  alfaptr node = front;
  int sum = 0, count = 0;
  while (node) {
    sum += node->x;
    count++;
    node = node->next;
  }
  return sum / count;
}
int main(void) {
  int cmd;
  long long int x;
  while (true) {
    cin >> cmd;
    switch (cmd) {
      case 1:
        cin >> x;
        push(x);
        break;
      case 2:
        pop();
        break;
      case 3:
        rpop();
        break;
      case 4:
        cin >> x;
        search(x);
        break;
      case 5:
        set();
        break;
      case 6:
        show();
        break;
      case 7:
        cout << size() << endl;
        break;
      case 8:
        cout << average() << endl;
        break;
      case 10:
        exit(0);
    }
  }
}