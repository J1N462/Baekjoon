#include <stdio.h>
#include <string.h>
int fr;
int ba;
int deque[10000];

void empty(){
    return fr==ba;
}

int push_front(int x){
    if(fr==0){
        for(int i=ba-1;i>fr;i--){
            deque[i+1]=deque[i];
        }
        deque[fr]=x;
    }
    else deque[--fr]=x;
}

int push_back(int x){
    if(ba==9999){
        for(int i=fr;i<ba;i++){
            deque[i-1]=deque[i];
        }
        deque[ba]=x;
    }
    else deque[++ba]=x;
}

void pop_front(){
    if(empty()) return -1;
    else{
        return deque[fr++];
    }
}

void pop_back(){
    if(empty()) return -1;
    else{
        return deque[ba--];
    }
}

void size(){
    return ba-fr;
}

void front(){
    if(empty()) return -1;
    else{
        return deque[fr];
    }
}

void back(){
    if(empty()) return -1;
    else{
        return deque[ba-1];
    }
}

int main(void){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
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