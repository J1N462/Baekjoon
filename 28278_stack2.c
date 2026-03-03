#include <stdio.h>

int stack[1000000];
int top=-1;

int empty(){
    return top==-1;
}

void push(int x){
    stack[++top]=x;
}

int pop(){
    if(empty()){
        return -1;
    }
    return stack[top--];
}

int size(){
    return top+1;
}

int peek(){
    if(empty()){
        return -1;
    }
    return stack[top];
}

//정수를 저장하는 스택
int main(void){
    int N;
    scanf("%d", &N);

    for(int i=0;i<N;i++){
        int a;
        scanf("%d", &a);
        if(a==1){
            int x;
            scanf("%d", &x);
            push(x);
        }
        else if(a==2){
            printf("%d\n", pop());
        }
        else if(a==3){
            printf("%d\n", size());
        }
        else if(a==4){
            printf("%d\n", empty());
        }
        else if(a==5){
            printf("%d\n", peek());
        }
    }

    return 0;
}