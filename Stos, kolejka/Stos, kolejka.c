#include <stdio.h>

#define SIZE 10
#define OK 1
#define OVERFLOW -1
#define UNDERFLOW -2

int stack[SIZE];
int top = 0;

int stack_push(int n) {
    if (top >= SIZE) return OVERFLOW;
    stack[top++] = n;
    return OK;
}

int stack_pop(void) {
    if (top <= 0) return UNDERFLOW;
    return stack[--top];
}

int stack_state(void) {
    return top;
}

int main() {
    int mode;
    scanf("%d", &mode);

    if (mode == 1) {
        int x;
        while (1) {
            if (scanf("%d", &x) != 1) break;
            if (x == 0) {
                printf("%d\n", stack_state());
                for (int i = 0; i < stack_state(); i++)
                    printf("%d\n", stack[i]);
                break;
            } else if (x > 0) {
                stack_push(x);
            } else {
                int val = stack_pop();
                printf("%d\n", val);
            }
        }
    }

    return 0;
}