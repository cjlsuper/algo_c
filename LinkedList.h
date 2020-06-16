//
// Created by 崔继霖 on 2020/6/16.
//

#ifndef ALGO_C_LINKEDLIST_H
#define ALGO_C_LINKEDLIST_H


typedef int data;
typedef struct Node {
    data value;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    int length;
} LinkedList;

Node *createNode(data value);

LinkedList *createLinkedList();

void appendLinkedList(LinkedList *linkedList, data value);

void deleteNode();

void reverseLinkedList(LinkedList *linkedList);

// 相交链表
Node *getIntersectionNode(Node *headA, Node *headB);

void printLinkedList(LinkedList *linkedList);

void test_list();

#endif //ALGO_C_LINKEDLIST_H
