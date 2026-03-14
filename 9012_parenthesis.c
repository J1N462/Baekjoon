#include <stdio.h>
int stack[51];
int top=-1;
int is_empty(){
    return (top==-1);
}
void push(char *a){
    stack[++top]=a;
}
int pop(){
    return stack[top--];
}
int main(void){
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        char str[51]={'\0'}; //초기화되나 아니면 초기화 함수 만들어야하나?
        scanf("%s", str);
        for(int i=0;str[i]!='\0';i++){
            if(str[i]=='('){
                push('(');
            }
            else{
                if(is_empty()){
                    printf("NO");
                    continue;
                }
                pop();
            }
        }
        if(is_empty()){
            printf("YES");
        }
    }
    return 0;
}