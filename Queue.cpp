#include "Queue.hpp"

using std::cout;
using std::endl;

Queue::Queue() {
  head = nullptr;
}


Queue::~Queue() {

  while (!isEmpty()) {
    removeFront();
  }
  
}


bool Queue::isEmpty() {

  if (head) {
    return false;
  } else {
    return true;
  }

}


void Queue::addBack(int val) {

  if ( isEmpty() ) {

    head = new QueueNode;
    head->prev = head;
    head->next = head;
    head->val = val;

  } else {

    QueueNode* newBack = new QueueNode {head, head->prev, val};

    head->prev->next = newBack;
    head->prev = newBack;

  }


}


int Queue::getFront() {
    return head->val;
}


void Queue::removeFront() {

  if (head) {

    if (head->next != head) {

      QueueNode* nextHead = head->next;
      nextHead->prev = head->prev;
      head->prev->next = nextHead;
      delete head;
      head = nextHead;

    } else {

      delete head;
      head = nullptr;

    }

  }

}


void Queue::printQueue() {

  if ( !isEmpty() ) {

    QueueNode* currentNode = head;

    do {

      cout << currentNode->val << endl;
      currentNode = currentNode->next;

    } while (currentNode != head);

  } else {
    cout << "No values exist in this queue." << endl;
  }


}
