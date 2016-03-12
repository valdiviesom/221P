//LinkedListQueue.cpp
#ifndef _LINKEDLISTQUEUE_CPP
#define _LINKEDLISTQUEUE_CPP

#include "LinkedListQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>

LinkedListQueue::LinkedListQueue() {
    // TODO:  Initialize any member variables as needed in the constructor.
    head = NULL;
    tail = NULL;
    size = 0;
}

void LinkedListQueue::add(MazeState *elem) {
    // TODO:  Implement this.
    struct node *toAdd = malloc(sizeof(struct node));
    toAdd->data = elem;
    toAdd->next = NULL;
    if (head == NULL) {
        head = toAdd;
        head->next = NULL;
        tail = toAdd;
    }
    else if (head == tail) {
        tail = toAdd;
        head->next = tail;
    }
    else {
        tail->next = toAdd;
        tail = tail->next;
    }
    size++;
}

MazeState *LinkedListQueue::remove() {
    // TODO:  Implement this.
    MazeState *ret = head->data;
    head = head->next;
    size--;
    return ret;
}

bool LinkedListQueue::is_empty() {
    // TODO:  Implement this.
    return size == 0;
}

LinkedListQueue::~LinkedListQueue() {
    // TODO:  Implement the destructor.  Be sure to delete everything.
    struct node *toDel;
    while (size != 0) {
        toDel = head;
        head = head->next;
        free(head->data);
        free(head);
        size--;
    }
}

#endif

