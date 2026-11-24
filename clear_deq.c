#include <stdio.h>
#include <stdlib.h>

#include "headers.h"

void clear_deq(struct Deque *deque) {

    struct Node *box = deque->front;

    while (box != NULL) {
        struct Node *next_box = box->next;
        free(box);
        box = next_box;
    }

    deque->front = NULL;
    deque->back = NULL;
    deque->len = 0;


}