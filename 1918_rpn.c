//괄호 -> 곱 나누기 -> 합차
#include <stdio.h>
#include <string.h>
char stack[101];
int top=-1;
int cal(char a){
    if(a=='('||a==')') return 0;
    else if(a=='*'||a=='/') return 1;
    else if(a=='+'||a=='-') return 2;
    return 0;
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

        //피연산자
        if('A'<=rpn[i] && 'Z'>=rpn[i]){
            printf("%c", rpn[i]);
        }

        // 2. '(' → 스택에 push
        else if(rpn[i] == '('){
            push('(');
        }

        // )만나면 다 pop()
        else if(rpn[i]==')'){
            while(top != -1 && stack[top]!='('){
                pop();
            }   
            top--;
        }

        //연산자
        else{
            while( top != -1 && peak() != '(' && cal(peak()) <= cal(rpn[i])){
                pop();
            }
            push(rpn[i]);
        }
       
    }

    while(top!=-1){
        pop();
    }
    
    return 0;
}