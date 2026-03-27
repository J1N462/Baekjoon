#include <stdio.h>
#include <string.h>
int fr=0;
int rear=0;
int queue[100000];

//일반적인 선형 큐에서 front == rear이면 비어있는 상태
int empty(){
    return fr==rear;
}

int size(){
    return rear-fr;
}

void push(int x){
    queue[rear++]=x;
}
int pop(){
    if(empty()){
        return -1;
    }
    else{
        return queue[fr++];
    }
}

int front(){
    if(empty()){
        return -1;
    }
    else{
        return queue[fr];
    }
}

int back(){
    if(empty()){
        return -1;
    }
    else{
        return queue[rear-1]; // rear는 다음 위치를 가리키므로 -1
    }
}
int main(void){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        char str[10];
        scanf("%s", str);
        if(strcmp(str, "push")==0){
            int x;
            scanf("%d", &x);
            push(x);
        }
        else if(strcmp(str, "pop")==0){
            printf("%d\n", pop());
        }
        else if(strcmp(str, "size")==0){
            printf("%d\n", size());
        }
        else if(strcmp(str, "empty")==0){
            printf("%d\n", empty());
        }
        else if(strcmp(str, "front")==0){
            printf("%d\n", front());
        }
        else if(strcmp(str, "back")==0){
            printf("%d\n", back());
        }
    }
    return 0;
}