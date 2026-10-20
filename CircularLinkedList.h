#ifndef CIRCULAR_LINKEDLIST_H
#define CIRCULAR_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct CircularLinkedList {
    Node *head;
    Node *tail;
    int size;
} CircularLinkedList;

CircularLinkedList* createNewCircularLinkedList(void);
Node* createNewNode(int data);

void insertAtEnd(CircularLinkedList *list, int data);
void insertAtBeginning(CircularLinkedList *list, int data);
void insertAtPosition(CircularLinkedList *list, int data, int position);

void deleteFirstNode(CircularLinkedList *list);
void deleteLastNode(CircularLinkedList *list);
void deleteNodeAtPosition(CircularLinkedList *list, int position);

/* Searching and displaying */
bool search(CircularLinkedList *list, int data);
void printList(CircularLinkedList *list);
void printListReverse(CircularLinkedList *list);

void reverseList(CircularLinkedList *list);
void reverseListRecursive(CircularLinkedList *list);
void reverseListRecursiveHelper(Node *node);

/* Other operations */
void deleteList(CircularLinkedList *list);
Node* findMiddleNode(CircularLinkedList *list);
Node* findMaximumNode(CircularLinkedList *list);
Node* findMinimumNode(CircularLinkedList *list);
CircularLinkedList* mergeTwoLists(
    CircularLinkedList *list1,
    CircularLinkedList *list2
);
void sortLinkedList(CircularLinkedList *list);
CircularLinkedList* mergeTwoSortedLists(
    CircularLinkedList *list1,
    CircularLinkedList *list2
);

/* Memory cleanup */
void freeList(CircularLinkedList *list);

#endif
