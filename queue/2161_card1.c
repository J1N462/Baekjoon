#include <stdio.h>
#include <stdlib.h>
int MAX;
int queue[1000];
int front=-1;
int rear=-1;
void init_queue(){
    front=-1;
    rear=-1;
}
int is_empty(){
    return front==rear;
}
int is_full(){
    return (rear+1)%MAX==front;
}

void enqueue(int e){
    if(is_full()){
        return;
    }
    rear=(rear+1)%MAX;
    queue[rear]=e;
    return;
}
int dequeue(){
    if(is_empty()){
        return 0;
    
    }
    front=(front+1)%MAX;
    return queue[front];
}


int main(void){
    int N;
    scanf("%d", &N);
    MAX=N;
    init_queue();
    for(int i=1;i<=N;i++){
        enqueue(i);
    }
    for(int i=0;i<2*N;i++){
        if (i==2*(N-1)){
            printf("%d ", dequeue());
            return 0;
        }
        if(i%2==0){
            printf("%d ",dequeue());
        }
        else{
            int e=dequeue();
            enqueue(e);
        }
    }
    return 0;
}

//dequeue<-1234 <-enqueue