 /* An implementation of stack using doubly linked list */


#include <stdio.h>

struct node {
    int e;
    struct node *prev;
    struct node *next;
};

struct stack {
    int size;
    struct node *top;
};

int push(struct node *n, struct stack *s);
int pop(struct stack *s);
int peek(struct stack *s);
int is_empty(struct stack *s);

int main(int argc, char const *argv[]) {
    struct stack s;
    s.size = 0;
    s.top = NULL;

    struct node n1, n2, n3;
    n1.e = 1;
    n1.prev = n1.next = NULL;
    n2.e = 2;
    n2.prev = n2.next = NULL;
    n3.e = 3;
    n3.prev = n3.next = NULL;

    printf("pushing %d\n", push(&n1, &s));
    printf("pushing %d\n", push(&n2, &s));
    printf("pushing %d\n", push(&n3, &s));

    printf("top is %d\n", peek(&s));
    printf("poping %d\n", pop(&s));
    printf("top is %d\n", peek(&s));
    printf("poping %d\n", pop(&s));
    printf("top is %d\n", peek(&s));

    return 0;
}

int is_empty(struct stack *s) {
    return s -> size == 0;
}

int push(struct node *n, struct stack *s) {
    if (is_empty(s)) {
        s -> top = n;
    } else {
        (n -> prev) = s -> top;
        (s -> top) -> next = n;
        s -> top = n;
    }
    (s -> size)++;
    return n -> e;
}

int pop(struct stack *s) {
    if (is_empty(s)) {
        return -1;
    } else {
        int temp = (s -> top) -> e;
        s -> top = (s -> top) -> prev;
        if (s -> top != NULL) { /* not the last node */
            (s -> top) -> next = NULL;
        }
        (s -> size)--;
        return temp;
    }
}

int peek(struct stack *s) {
    if (is_empty(s)) {
        return -1;
    } else {
        return (s -> top) -> e;
    }
}
