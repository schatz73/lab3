#include <stdio.h>
#include <stdlib.h>

#include "headers.h"

void mode_down(double *array, int len) {
    int left=0;
    int right=0;
    int larger=0;
    double swap=0.0;
    int index=0;

    while (index < len/2) {
        left = index*2 + 1;
        right = left + 1;
        larger = left;

        if (right < len && *(array + right) > *(array + left)) {
            larger = right;
        }

        if (*(array + index) >= *(array + larger)) {
            break;
        }

        swap = *(array + index);
        *(array + index) = *(array + larger);
        *(array + larger) = swap;

        index = larger;

    }


}

int pyramidal_sort(struct Deque deque, struct Deque *deque_sorted_pyramidal) {

    // struct Deque deque_copy = deque;
    double max_num=0;
    int count=0;
    double swap=0.0;
    int index=0;
    double value=0.0;
    int index_up=0;

    struct Node *current = deque.front;

    double *array = malloc(sizeof(double) * deque.len);

    if (array == NULL) {
        return 1;
    }


    for (int i=0; i<deque.len; i++) {
        *(array+i) = current->value;

        current = current->next;
    }

    for (int i = 1; i < deque.len; i++) {
        value = *(array + i);
        index = i;

        while (index > 0) {
            index_up = (index - 1) / 2;

            if (*(array + index_up) >= value) {
                break;
            }

            *(array + index) = *(array + index_up);
            index = index_up;
        }

        *(array + index) = value;

    }


    for (int i = deque.len - 1; i > 0; i--) {

        swap = *array;
        *array = *(array + i);
        *(array + i) = swap;

        mode_down(array, i);
    }

    for (int i = 0; i < deque.len; i++) {
        value = *(array + i);

        if (push_back(deque_sorted_pyramidal, value) == 1) {
            free(array);
            return 1;
        }

    }

    free(array);

    return 0;

}