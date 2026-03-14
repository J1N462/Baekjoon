#include <stdio.h>
int stack[51];
int top;
void init(){
    top=-1;
}
int is_empty(){
    return (top==-1);
}
void push(char a){
    stack[++top]=a;
}
int pop(){
    return stack[top--];
}
int main(void){
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        int print=0; //Yes
        init();
        char str[51];
        scanf("%s", str);
        for(int j=0;str[j]!='\0';j++){
            if(str[j]=='('){
                push('(');
            }
            else{
                if(is_empty()){
                    print=1; //NO
                    break;
                }
                pop();
            }
        }
        if(is_empty()&&print==0){
            printf("YES\n");
        }
        else{
            printf("NO\n");

        }
    }
    return 0;
}

/*
괄호가 남아잇는 채로 반복문이 종료된 경우
괄호가 없는데 오른쪽괄호가 들어온 경우
-no
else -yes
*/