#ifndef DEQUE_H
#define DEQUE_H

#define MAX_SIZE 10000000

typedef struct {
    int r;
    int c;
} Element;

void init(void);
int is_empty(void);
int is_full(void);
void add_front(Element e);
void add_rear(Element e);
Element delete_front(void);
Element delete_rear(void);
Element peek_front(void);
Element peek_rear(void);

#endif
