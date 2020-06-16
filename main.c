#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkedList.h"

Node *createNode(data value) {
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->value = value;
    return node;
}

LinkedList *createLinkedList() {
    LinkedList *linkedList = malloc(sizeof(LinkedList));
    assert(linkedList != NULL);
    linkedList->head = NULL;
    linkedList->length = 0;
    return linkedList;
}

void appendLinkedList(LinkedList *linkedList, data value) {
    if (NULL == linkedList) {
        return;
    }

    Node *current = linkedList->head;
    Node *tail = NULL;
    if (NULL == current) {
        linkedList->head = createNode(value);
        linkedList->head->next = NULL;
        return;
    }

    while (current != NULL) {
        tail = current;
        current = current->next;
    }

    if (NULL == current) {
        tail->next = createNode(value);
        tail->next->next = NULL;
    }

}


void reverseLinkedList(LinkedList *linkedList) {
    if (NULL == linkedList || NULL == linkedList->head) {
        return;
    }
    Node *current = NULL;
    current = linkedList->head;
    Node *pre = NULL;
    Node *temp = NULL;
    while (NULL != current) {
        temp = current->next;// 步骤1：
        current->next = pre;//步骤2：
        pre = current;// 步骤3：
        current = temp;// 步骤4：
    }

    // 1，3，4是遍历，2是原地翻转

    if (pre != NULL) {
        linkedList->head = pre;
    }
}


Node *getIntersectionNode(Node *headA, Node *headB){


}

void printLinkedList(LinkedList *linkedList) {
    if (NULL == linkedList || NULL == linkedList->head) {
        return;
    }
    Node *current = linkedList->head;
    printf("**************** print linkedList ****************\n");
    printf("length==> %d\n", linkedList->length);
    while (NULL != current) {
        printf("node==>[%p | %d]--->\n", current, current->value);
        current = current->next;
    }
    printf("***************************************************\n");
}

void test_list() {
    LinkedList *linkedList = createLinkedList();
    appendLinkedList(linkedList, 0);
    appendLinkedList(linkedList, 1);
    appendLinkedList(linkedList, 2);
    appendLinkedList(linkedList, 6);
    appendLinkedList(linkedList, 9);
    printLinkedList(linkedList);

    reverseLinkedList(linkedList);
    printLinkedList(linkedList);

}

int main() {
    test_list();
    return 0;
}



