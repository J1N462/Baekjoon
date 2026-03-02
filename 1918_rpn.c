//괄호 -> 곱 나누기 -> 합차
#include <stdio.h>
#include <string.h>
char stack[101];
int top=-1;
int cal(char a){
    if(a=='('||a==')') return 0;
    else if(a=='*'||a=='/') return 1;
    else if(a=='+'||a=='-') return 2;
}
int peak(){
    return stack[top];
}
void pop(){
    printf("%c", stack[top--]);
}

void push(char a){
    stack[++top]=a;
}

int main(void){
    char rpn[101];
    scanf("%s", rpn);

    for(int i=0;rpn[i]!='\0';i++){

        if('A'>=rpn[i]||'Z'<=rpn[i]){
            printf("%c", rpn[i]);
        }
        else if(rpn[i]=='('){
            while(rpn[i]!=')'){
                pop();
            }   
            top--;
        }
        else if(cal(rpn[i])>cal(peak())){
            push(rpn[i]);
        }
        else{
            pop();
        }
    }

    while(top!=-1){
        pop();
    }
    
    return 0;
}