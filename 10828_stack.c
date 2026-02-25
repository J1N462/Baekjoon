#include <stdio.h>
#include <string.h>
int top=-1;
int stack[1000000];
int empty(){
    if(top==-1){
        return 1;
    }
    return 0;
}
void push(int x){
    stack[top+1]=x;
    top++;
}
int pop(){
    int x=stack[top+1];
    stack[top--]=NULL;
    return x;
}
int size(){
    return  top+1;
}

int top(){
    if(empty()==1){
        return -1;
    }
    else return stack[top+1];
}

int main(void){
    //command
    int N;
    char str[10];
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%s", str);
        if(strcmp(str,push)==0){
            int x;
            scanf("%d", x);
            push(x);
        }
        else if(strcmp(str, pop)==0){
            pop();
        }
        else if(strcmp(str, size)==0){
            size();
        }
        else if(strcmp(str, empty)==0){
            printf("%d",empty());
        }
        else if(strcmp(str, top==0)){
            printf("%d",top());
        }
    }
    return 0;
}
