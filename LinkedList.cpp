//
// Created by 崔继霖 on 2020/6/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkedList.h"

ListNode *createNode(data data) {
    ListNode *node = static_cast<ListNode *>(malloc(sizeof(ListNode)));
    assert(NULL != node);
    node->data = data;
    node->next = nullptr;// 注意野指针
    return node;
}

LinkedList *createLinkedList() {
    LinkedList *linkedList = static_cast<LinkedList *>(malloc(sizeof(LinkedList)));
    assert(NULL != linkedList);
    linkedList->length = 0;
    linkedList->head = nullptr;
    return linkedList;
}

void *linkedListInsertHead(LinkedList *linkedList, data data) {
    printf("************** linkedListInsertHead *****************\n");
    assert(NULL != linkedList);
    assert(NULL != linkedList->head);
    ListNode *current = linkedList->head;
    ListNode *head = createNode(data);
    assert(NULL != head);
    head->next = current;
    linkedList->head = head;
    linkedList->length += 1;
}


void linkedListAppend(LinkedList *linkedList, data data) {
    assert(NULL != linkedList);
    if (NULL == linkedList->head) {
        linkedList->head = createNode(data);
        linkedList->length = 1;
        return;
    }
    ListNode *current = linkedList->head;
    ListNode *pre = nullptr;
    while (current) {
        pre = current;
        current = current->next;
    }
    pre->next = createNode(data);
    linkedList->length += 1;
}

void *linkedListDelete(LinkedList *linkedList) {
    printf("************** linkedListDelete *****************\n");
    assert(NULL != linkedList);
    ListNode *current = linkedList->head;
    assert(NULL != current);
    ListNode *pre = nullptr;
    while (current->next) {
        pre = current;
        current = current->next;
    }

    if (NULL == pre) {
        linkedList->head = nullptr;
        linkedList->length = 0;
    } else {
        pre->next = nullptr;
        linkedList->length -= 1;
    }
}

void linkedListDeleteNthFromStart(LinkedList *linkedList, int index) {
    printf("************** linkedListDeleteNthFromStart，index= %d *****************\n", index);
    if (NULL == linkedList || NULL == linkedList->head) {
        return;
    }
    if (index < 0 || index > linkedList->length - 1) {
        printf("Error: out of bounds!");
        return;
    }

    ListNode *temp = linkedList->head;
    linkedList->head = createNode(-1);//fake head;
    linkedList->head->next = temp;

    ListNode *current = linkedList->head;
    ListNode *pre = linkedList->head;
    int count = -1;
    while (NULL != current && index > count++) {
        pre = current;
        current = current->next;
    }
    // delete node
    pre->next = current->next;

    freeNode(current);
    freeNode(linkedList->head);
    linkedList->head = linkedList->head->next;
    linkedList->length -= 1;

    printLinkedList(linkedList);
}

void linkedListDeleteNthFromEnd(LinkedList *linkedList, int n) {
    if (NULL == linkedList) {
        return;
    }
    if (n < 1 || n > linkedList->length) {
        printf("Error: out of bounds!");
        return;
    }
    ListNode *nHead = createNode(-1);
    nHead->next = linkedList->head;
    linkedList->head = nHead;

    ListNode *fast = linkedList->head;
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }
    ListNode *slow = linkedList->head;
    int count = 0;
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
        count++;
    }
    printf("slow = %d\n", slow->data);
    slow->next = slow->next->next;
    linkedList->head = linkedList->head->next;
    printLinkedList(linkedList);

}

void linkedListReverse(LinkedList *linkedList){

}

void linkedListReverseFromNth(LinkedList *linkedList, int start);


void freeNode(ListNode *node) {
    free(node);
    node = nullptr;
}

void destroy(LinkedList *linkedList) {
    printf("************** destroy *****************\n");
    if (NULL == linkedList) {
        return;
    }
    if (NULL == linkedList->head) {
        free(linkedList);
        return;
    }
    ListNode *current = linkedList->head;
    while (current) {
        ListNode *temp = current;
        current = current->next;
        freeNode(temp);
    }
    linkedList->head->next = nullptr;
    linkedList->head = nullptr;
    freeNode(linkedList->head);
    linkedList = nullptr;
    free(linkedList);
}

/** 打印 */
void printLinkedList(LinkedList *linkedList) {
    if (NULL == linkedList) {
        printf("The linkedlist is NULL\n");
    }
    ListNode *current = linkedList->head;
    printf("\n*******************************\n");
    if (nullptr == current) {
        printf("The linkedlist is empty\n");
        printf("*******************************\n");
        return;
    }
    printf("size = %d, head = %d\n", linkedList->length, linkedList->head->data);
    printf("[ ");
    while (current) {
        printf(" %d ", current->data);
        current = current->next;
    }

    printf(" ]\n");
    printf("*******************************\n");


}

void testLinkedList() {
    LinkedList *linkedList = createLinkedList();
    assert(linkedList);
    for (int i = 1; i < 6; i++) {
        linkedListAppend(linkedList, i);
    }
    printLinkedList(linkedList);

//    linkedListDelete(linkedList);
//    linkedListDelete(linkedList);
//    printLinkedList(linkedList);

//    linkedListInsertHead(linkedList, 10);
//    linkedListInsertHead(linkedList, 11);
//    printLinkedList(linkedList);

//    destroy(linkedList);
//    printLinkedList(linkedList);
//    linkedListDeleteNthFromStart(linkedList, 6);
//    linkedListDeleteNthFromStart(linkedList, 1);
//    linkedListDeleteNthFromStart(linkedList, 0);

//    linkedListDeleteNthFromEnd(linkedList, 5);
//    linkedListDeleteNthFromEnd(linkedList, 1);
//    linkedListDeleteNthFromEnd(linkedList, 1);
//    linkedListDeleteNthFromEnd(linkedList, 1);
//    linkedListDeleteNthFromEnd(linkedList, 1);


}

int main() {
    testLinkedList();
    return 0;
}

