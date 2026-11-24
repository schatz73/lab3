#ifndef HEADERS_H
#define HEADERS_H

#define START_MEMORY 2
#define MEMORY 100


struct Deque {
    struct Node *front;
    struct Node *back;
    int len;
};

struct Node {
    double value;
    struct Node *prev;
    struct Node *next;
};


#endif