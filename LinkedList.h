//
// Created by 崔继霖 on 2020/6/25.
//

#ifndef CJLSUPER_LINKEDLIST_H
#define CJLSUPER_LINKEDLIST_H

typedef int data;

typedef struct ListNode {
    data data;
    struct ListNode *next;
} ListNode;

typedef struct LinkedList {
    ListNode *head;
    int length;
} LinkedList;

ListNode *createNode(data data);

LinkedList *createLinkedList();

void *linkedListInsertHead(LinkedList *linkedList, data data);

void linkedListAppend(LinkedList *linkedList, data data);

void *linkedListDelete(LinkedList *linkedList);

void linkedListDeleteNthFromStart(LinkedList *linkedList, int index);

void linkedListDeleteNthFromEnd(LinkedList *linkedList, int index);

void linkedListReverse(LinkedList *linkedList);

void linkedListReverseFromNth(LinkedList *linkedList, int start);

void freeNode(ListNode *node);

void destroy(LinkedList *linkedList);

void printLinkedListNode(ListNode *node);

void printLinkedList(LinkedList *linkedList);

void testLinkedList();

#endif //CJLSUPER_LINKEDLIST_H
