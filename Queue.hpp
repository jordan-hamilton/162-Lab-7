/*********************************************************************
** Description: Specification file for the Queue class.
*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

class Queue {

  struct QueueNode {

    QueueNode* next;
    QueueNode* prev;
    int val;

  };

  public:
    Queue();
    ~Queue();
    bool isEmpty();
    void addBack(int val);
    int getFront();
    void removeFront();
    void printQueue();

  private:
    QueueNode* head;

};

#endif
