#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100 // Maximum stack size

int top = -1;
int stack[MAX_SIZE];

// Function to check if the stack is empty
int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

// Function to push an element into the stack
void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack is Full\n");
        return;
    }
    top++;
    stack[top] = value;
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack is Empty\n");
        return -1;
    } else {
        int value = stack[top];
        top--;
        return value;
    }
}

int main() {
    int ch,val;
    while (1) {
        printf("\n Enter 1 for push\n");
        printf("\n Enter 2 for pop\n");
        printf("\n Enter 3 for peep\n");
        printf("\n Enter 4 to exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
            printf("ENTER VALUE:");
            scanf("%d",&val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                //peep();
                break;
            case 4:
                exit(0);
        }
    }

    return 0;
}
