#include <stdio.h>
#include <string.h>
int fr;
int ba;
int deque[10000];

int empty(){
    return fr==ba;
}

void push_front(int x){
    if(fr==0){
        for(int i=ba-1;i>=fr;i--){
            deque[i+1]=deque[i];
        }
        deque[fr]=x;
        ba++;
    }
    else deque[--fr]=x;
}

void push_back(int x){
    if(ba==10000){
        for(int i=fr;i<ba;i++){
            deque[i-1]=deque[i];
        }
        deque[ba-1]=x;
        fr--;
    }
    else deque[ba++]=x;
}

int pop_front(){
    if(empty()) return -1;
    else{
        return deque[fr++];
    }
}

int pop_back(){
    if(empty()) return -1;
    else{
        return deque[--ba]; // ba는 항상 다음 빈칸을 가리키므로 --ba 위치가 마지막 데이터
    }
}

int size(){
    return ba-fr;
}

int front(){
    if(empty()) return -1;
    else{
        return deque[fr];
    }
}

int back(){
    if(empty()) return -1;
    else{
        return deque[ba-1];
    }
}

int main(void){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        char str[20];
        scanf("%s", str);
        if(strcmp(str,"push_front")==0){
            int x;
            scanf("%d", &x);
            push_front(x);
        }
        else if(strcmp(str,"push_back")==0){
            int x;
            scanf("%d", &x);
            push_back(x);
        }
        else if(strcmp(str, "pop_front")==0){
            printf("%d\n", pop_front());
        }

        else if(strcmp(str, "pop_back")==0){
            printf("%d\n", pop_back());
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