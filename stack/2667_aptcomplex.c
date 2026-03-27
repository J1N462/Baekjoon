#include <stdio.h>
int A[25][25];
int clear(int N, int i, int j){

}
int main(void){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &A[i][j]);
        }
    }
    //총단지수
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(A[i][j]==1){
                clear(N, i, j);
                cnt++;
            }
        }
    }
    //각 단지내 집의 수를 오름차순으로 정렬


    return 0;
}