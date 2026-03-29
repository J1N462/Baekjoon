#include "deque.h"

Element deque[MAX_SIZE];
int front = 0;
int rear = 0;

void init(void){
    front = rear = 0;
}

int is_empty(void){
    return front == rear;
}

int is_full(void){
    return (rear + 1) % MAX_SIZE == front;
}

void add_front(Element e){
    if(is_full()){
        return;
    }
    deque[front] = e;
    front = (front - 1 + MAX_SIZE) % MAX_SIZE;
}

void add_rear(Element e){
    if(is_full()){
        return;
    }
    rear = (rear + 1) % MAX_SIZE;
    deque[rear] = e;
}

Element delete_front(void){
    if(is_empty()){
        return (Element){-1, -1};
    }
    front = (front + 1) % MAX_SIZE;
    return deque[front];
}


Element delete_rear(void){
    if(is_empty()){
        return (Element){-1, -1};
    }
    Element tmp = deque[rear];
    rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
    return tmp;
}


Element peek_front(void){
    if(is_empty()){
        return (Element){-1, -1};
    }
    return deque[(front + 1) % MAX_SIZE];
}

Element peek_rear(void){
    if(is_empty()){
        return (Element){-1, -1};
    }
    return deque[rear];
}
