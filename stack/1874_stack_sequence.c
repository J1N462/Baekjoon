//anstack에 있는 수가 1~n 하나씩 들어오는 수보다 큰 경우 push()
//anstack에 있는 수가 1~n 하나씩 들어오는 수랑 같은 경우 push() pop()
//anstack에 있는 수가 1~n 하나씩 들어오는 수보다 작은 경우 stack()과 같은지 확인 후 같다면 pop() or NO
#include <stdio.h>
int stack[1000000];
int top=-1;
char sol[10000000];
int sol_top=-1;

int is_empty(){
    return top==-1;
}
void push(int e){
    stack[++top]=e;
    sol[++sol_top]='+';
    return;
}
void pop(){
    top--;
    sol[++sol_top]='-';
    return;
}

int main(void){
    int n;
    scanf("%d", &n);
    int anstack[1000000];
    for(int i=0;i<n;i++){
        scanf("%d", &anstack[i]);
    }
    for(int i=0,j=1;i<n;i++){
        while(anstack[i]>=j){
            push(j++);
        }
        if(stack[top]==anstack[i]){
            pop();
        }
        else{
            printf("NO\n");
            return 0;
        }
        
    }
    for(int i=0;i<=sol_top;i++){
        printf("%c\n", sol[i]);
    }
    return 0;
}