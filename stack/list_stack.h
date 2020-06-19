//
// Created by 崔继霖 on 2020/6/19.
//

#ifndef STACK_LIST_STACK_H
#define STACK_LIST_STACK_H

#define data int
#define FALSE 0
#define TRUE 1

typedef struct StackNode {
    data value;
    struct StackNode *next;
} StackNode;

typedef struct LinkedListStack {
    StackNode *top;
} LinkedListStack;

StackNode *createNode(data value);

LinkedListStack *createStack();

StackNode *pushStack(LinkedListStack *stack, data value);

StackNode *pop(LinkedListStack *stack);

void *destroyStack(LinkedListStack *stack);

void *printStack(LinkedListStack *stack);

int *isEmptyStack(LinkedListStack *stack);

void test_stack();

#endif //STACK_LIST_STACK_H
