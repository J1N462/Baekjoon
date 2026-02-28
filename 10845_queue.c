#include <stdio.h>
#include <string.h>
int fr=-1;
int rear=0;
int queue[100000];
int empty(){
    if(fr==-1&&rear==0){ //원형 큐일때??
        return 1;
    }
    else{
        return 0;
    }
}
int size(){
    return rear-front;
}

void push(int x){
    queue[rear++]=x;
}
int pop(){
    if(empty()){
        return -1;
    }
    else{
        int e=queue[fr+1];
        for(int i=fr+1;i<=fr+size;i++){
            queue[i]=queue[i+1];
            //fr    rear
            //-1 0 1 2
            rear--;
        }
        return e;
    }
}

int front(){
    if(empty()){
        return -1;
    }
    else{
        return queue[fr+1];
    }
}

int back(){
    if(empty()){
        return -1;
    }
    else{
        return queue[rear];
    }
}
int main(void){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        char str[10];
        scanf("%s", str)
        if(strcmp(str, "push")==0){
            int x;
            scanf("%d", x);
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