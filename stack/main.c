#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list_stack.h"

StackNode *createNode(data value) {
    StackNode *node = malloc(sizeof(StackNode));
    node->value = value;
    node->next = NULL;
    return node;
}

LinkedListStack *createStack() {
    LinkedListStack *stack = malloc(sizeof(LinkedListStack));
    stack->top = NULL;
    return stack;
}

StackNode *pushStack(LinkedListStack *stack, data value) {
    assert(stack);
    StackNode *top = createNode(value);
    top->next = stack->top;
    stack->top = top;
    return top;
}

StackNode *pop(LinkedListStack *stack) {
    assert(stack);
    if (NULL == stack->top) {
        return NULL;
    }
    StackNode *temp = stack->top->next;
    printf("pop element:%d\n",stack->top->value);
    free(stack->top);
    stack->top = temp;
    return temp;
}

void *printStack(LinkedListStack *stack) {
    assert(stack);
    printf("Stack:");
    StackNode *cur = stack->top;
    assert(cur);
    do {
        printf(" %d ", cur->value);
        cur = cur->next;
    } while (NULL != cur);
    printf("\n");

}

void test_stack() {
    LinkedListStack *stack = createStack();
    pushStack(stack, 0);
    pushStack(stack, 1);
    pushStack(stack, 2);
    pushStack(stack, 3);

    printStack(stack);
    pop(stack);
    printStack(stack);
}

int main() {
    test_stack();
    return 0;
}
