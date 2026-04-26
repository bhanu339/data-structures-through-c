#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}

// Pop operation
int pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    int i, op1, op2;

    for(i = 0; i < strlen(exp); i++) {

        // If operand, push to stack
        if(isdigit(exp[i])) {
            push(exp[i] - '0');
        }

        // If operator, pop two elements and apply operation
        else {
            op2 = pop();
            op1 = pop();

            switch(exp[i]) {
                case '+':
                    push(op1 + op2);
                    break;

                case '-':
                    push(op1 - op2);
                    break;

                case '*':
                    push(op1 * op2);
                    break;

                case '/':
                    push(op1 / op2);
                    break;

                case '%':
                    push(op1 % op2);
                    break;
            }
        }
    }

    return pop(); // final result
}

int main() {
    char exp[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);

    printf("Result = %d\n", result);

    return 0;
}
