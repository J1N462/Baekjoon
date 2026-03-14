#include <stdio.h>

double stack[101]; //피연산자 스택
int top=-1;

void push(double x){
    stack[++top]=x;
}
double pop(){
    return stack[top--];
}
int main(void){
    int N;
    scanf("%d", &N); //피연산자 개수
    char str[101];
    int a[101];
    scanf("%s", str); //후위표기식
    for(int i=0;i<N;i++){ //피연산자
        scanf("%d", &a[i]);
    }
    //연산
    //연산자가 나오면 이전 두 피연산자를 계산한다
    //연산자가 나올경우 이 값과 이전 피연산자를 연산한다
    //피연산자가 나올경우 이전값은 스택에 넣어두고 다음으로 진행한다

    //a[str[i]-'A'] //수

    for(int i=0;str[i]!='\0';i++){
        if('A'<=str[i]&&'Z'>=str[i]){
            push(a[str[i]-'A']);
        }
        else{
            double r = pop();
            double l = pop();
            if(str[i]=='+'){
                push(l+r);
            }
            else if(str[i]=='-'){
                push(l-r);
            }
            else if(str[i]=='*'){
                push(l*r);
            }
            else if(str[i]=='/'){
                push(l/r);
            }
        }

    }

    printf("%.2f\n", stack[top]);
    return 0;
}