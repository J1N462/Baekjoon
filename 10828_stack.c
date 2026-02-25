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
    stack[++top]=x;
}
int pop(){
    if (empty()) return -1;
    int x=stack[top];
    top--;
    return x;
}
int size(){
    return  top+1;
}

int top_x(){
    if(empty()==1){
        return -1;
    }
    else return stack[top];
}

int main(void){
    //command
    int N;
    char str[10];
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%s", str);
        if(strcmp(str,"push")==0){
            int x;
            scanf("%d", &x);
            push(x);
        }
        else if(strcmp(str, "pop")==0){
            printf("%d\n",pop());
        }
        else if(strcmp(str, "size")==0){
            printf("%d\n",size());
        }
        else if(strcmp(str, "empty")==0){
            printf("%d\n",empty());
        }
        else if(strcmp(str, "top")==0){
            printf("%d\n",top_x());
        }
    }
    return 0;
}