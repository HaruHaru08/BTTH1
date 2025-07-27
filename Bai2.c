#include <stdio.h>
#include <string.h>

typedef struct Operation {
    char action[1001];
    char value[1001];
}Operation;
typedef struct Stack {
    Operation* data;
    int top;
    int cap;
}Stack;

Stack* createStack(int cap) {
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->top=-1;
    stack->cap=cap;
    stack->data=(Operation*)malloc(sizeof(Operation)*cap);
    return stack;
}
int isFull(Stack* stack) {
    return stack->top==stack->cap-1;
}
int isEmpty(Stack* stack) {
    return stack->top==-1;
}
void push(Stack* stack,Operation* str) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->top++;
    strncpy(stack->data[stack->top].action,str->action,1001);
    strncpy(stack->data[stack->top].value,str->value,1001);
}
int main() {
    int choice;
    do {
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while (choice!=5);
    return 0;
}