#include <stdio.h>
#include <stdlib.h>

#include "headers.h"

void clear_deq(struct Deque *deque) {

    struct Node *box = deque->front;
    struct Node *next;
    

    while (box != NULL) {

        next = box->next;

        free(box);

        box = next;
        
    }

    deque->front = NULL;
    deque->back = NULL;
    deque->len = 0;


}