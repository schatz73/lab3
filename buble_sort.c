#include <stdio.h>

#include "headers.h"

int buble_sort(struct Deque deque, struct Deque *deque_sorted_buble) {
      
    struct Node *box;
    double value=0.0;
    int count=0;
    double swap=0.0;

    // int current=0;

    box = deque.front;

    while(box!=NULL) {
        value = box->value;

        if (push_back(deque_sorted_buble, value) == 1) {
            return 1;
        }

        box = box->next;

    }


    while(1) {
        count=0;
        box = deque_sorted_buble->front;


        while(box != NULL && box->next != NULL) {

            if (box->value > box->next->value) {
                count++;

                swap = box->value;
                box->value = box->next->value;
                box->next->value = swap;

                swap=0.0;

            } 

            box = box->next;
        }

        if (count==0) {
            break;
        }

    }


    return 0;

}