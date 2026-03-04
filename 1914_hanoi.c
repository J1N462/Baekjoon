#include <stdio.h>
void hanoi(int from, int tmp, int to, int N){

    if(N==1){
        printf("%d %d\n", from, to);
        return;
    }
    else{
        hanoi(from, to, tmp, N-1);
        printf("%d %d\n", from, to); 
        hanoi(tmp, from, to, N-1);
    }
    
}
int main(void){
    int N;
    scanf("%d", &N);

    if(N<=20){
        hanoi(1,2,3,N); 
    }
    return 0;
}
