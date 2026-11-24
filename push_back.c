#include <stdio.h>
#include <stdlib.h>

#include "headers.h"


int push_back(struct Deque *deque, double value) {
    struct Node *box = malloc(sizeof(struct Node));

    if (box==NULL) {
        return 1;
    }

    struct Node *last = deque->back;

    box->value = value;
    box->prev = last;
    box->next = NULL;

    if (last == NULL) {
        deque->front = box;
    } else {
        last->next = box;
    }

    deque->back = box;
    deque->len++;


    return 0;
}