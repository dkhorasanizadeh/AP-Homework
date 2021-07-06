/*
--------------------------------------------------
Name    : Priority Queue
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 01/Mar/2021
--------------------------------------------------
*/
#include <iostream>
using namespace std;
struct node {
  int data;
  int priority;
  node *next;
};
node *HEAD = NULL;
int QUEUE_SIZE = 0;
node *newNode(int data, int priority);
bool enqueue(int data, int priority);
bool dequeue(void);
bool isFull(void);
bool isEmpty(void);
void removePriority(int priority);
void printQueue(void);
void enQueueInterface(void);
void queueSize(void);
void dequeuePriorityInterface(void);
void dequeueInterface(void);
void deleteItemAtIndex(int index);
bool getCommand(void);
int main(void) {
  while (getCommand())
    ;
  return 0;
}
node *newNode(int data, int priority) {
  node *temp = new node;
  temp->next = NULL;
  temp->data = data;
  temp->priority = priority;
  return temp;
}
bool enqueue(int data, int priority) {
  node *temp = newNode(data, priority);
  node *cursor = HEAD;
  bool flag = false;
  if (isEmpty()) {
    HEAD = newNode(data, priority);
    QUEUE_SIZE++;
    return true;
  } else if (!isFull()) {
    if (cursor->priority > priority) {
      temp->next = HEAD;
      HEAD = temp;
      QUEUE_SIZE++;
      return true;
    } else {
      while (cursor->next != NULL && cursor->next->priority <= priority) {
        cursor = cursor->next;
      }
      temp->next = cursor->next;
      cursor->next = temp;
      QUEUE_SIZE++;
      return true;
    }
  } else {
    return false;
  }
}
bool dequeue(void) {
  if (!isEmpty()) {
    node *cursor = HEAD;
    if (QUEUE_SIZE != 1) {
      while (cursor->next->next != NULL) {
        cursor = cursor->next;
      }
      delete cursor->next;
      cursor->next = NULL;
      QUEUE_SIZE--;
      return true;
    } else {
      delete cursor;
      HEAD = NULL;
      QUEUE_SIZE--;
      return true;
    }
  } else {
    return false;
  }
}
bool isFull(void) { return QUEUE_SIZE == 10; }
bool isEmpty(void) { return QUEUE_SIZE == 0; }
void removePriority(int priority) {
  node *cursor = HEAD;
  int index = 0;
  while (cursor->priority != priority && cursor->next != NULL) {
    cursor = cursor->next;
    index++;
  }
  while (cursor != NULL && cursor->priority == priority) {
    cursor = cursor->next;
    deleteItemAtIndex(index);
  }
}
void printQueue(void) {
  if (!isEmpty()) {
    node *cursor = HEAD;
    cout << "Data:Priority" << endl;
    while (cursor != NULL) {
      cout << cursor->data << ":" << cursor->priority << endl;
      cursor = cursor->next;
    }
  } else {
    cout << "Queue is empty." << endl;
  }
}
void enQueueInterface(void) {
  int data, priority;
  cout << "Please enter data and priority of item:" << endl;
  cin >> data >> priority;
  if (enqueue(data, priority)) {
    cout << "Item added successfully" << endl;
  } else {
    cout << "Queue is full." << endl;
  }
}
void queueSize(void) {
  if (!isEmpty()) {
    cout << "Queue Size: " << QUEUE_SIZE << endl;
  } else {
    cout << "Queue is Empty" << endl;
  }
}
void dequeuePriorityInterface(void) {
  int priority;
  cout << "Please enter the priority that you want to dequeue:" << endl;
  cin >> priority;
  removePriority(priority);
  cout << "Priority dequeued successfully." << endl;
}
void dequeueInterface(void) {
  if (dequeue()) {
    cout << "Last item Removed successfully." << endl;
  } else {
    cout << "Queue is empty." << endl;
  }
}
void deleteItemAtIndex(int index) {
  if (HEAD == NULL) {
    return;
  }
  node *firstTempPointer = HEAD, *secondTempPointer;
  int counter = 0;
  while (firstTempPointer->next != NULL && counter + 1 < index) {
    firstTempPointer = firstTempPointer->next;
    counter++;
  }
  if (index != 0) {
    struct node *secondTempPointer;
    secondTempPointer = firstTempPointer->next;
    if (secondTempPointer != NULL) {
      firstTempPointer->next = firstTempPointer->next->next;
      delete secondTempPointer;
    } else {
      firstTempPointer->next = NULL;
    }
  } else {
    HEAD = firstTempPointer->next;
    delete firstTempPointer;
  }
  QUEUE_SIZE--;
}
bool getCommand(void) {
  bool run = true;
  int choice;
  cout << "1. Enqueue Item" << endl
       << "2. Dequeue Item" << endl
       << "3. Print Queue" << endl
       << "4. Queue Size" << endl
       << "5. Dequeue Priority" << endl
       << "6. Exit" << endl;
  cin >> choice;
  switch (choice) {
    case 1:
      enQueueInterface();
      break;
    case 2:
      dequeueInterface();
      break;
    case 3:
      printQueue();
      break;
    case 4:
      queueSize();
      break;
    case 5:
      dequeuePriorityInterface();
      break;
    case 6:
      run = false;
      break;
    default:
      cout << "Invalid Choice." << endl;
      break;
  }
  return run;
}
