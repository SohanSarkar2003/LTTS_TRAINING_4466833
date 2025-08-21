#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;


void enqueue(int x) {
    stack1[++top1] = x;
}


void transfer() {
    if (top2 == -1) {
        while (top1 >= 0) {
            stack2[++top2] = stack1[top1--];
        }
    }
}


void dequeue() {
    transfer();
    if (top2 >= 0) top2--;  
}


int front() {
    transfer();
    if (top2 >= 0) return stack2[top2];
    return -1; 
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int type, x;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &x);
            enqueue(x);
        } else if (type == 2) {
            dequeue();
        } else if (type == 3) {
            printf("%d\n", front());
        }
    }

    return 0;
}
