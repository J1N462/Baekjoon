/*
if(범위 밖) return;
if(이미 방문했으면) return;

방문 처리

DFS(상)
DFS(하)
DFS(좌)
DFS(우)
*/

#include <stdio.h>
int A[50][50];
void clear(int n, int m, int N, int M){
    if(n<0 || n>=N || m<0 || m>=M)
         return;
    
    if(A[n][m]==0)
        return;

    A[n][m]=0;

    clear(n-1, m,N,M);
    clear(n+1, m,N,M);
    clear(n, m-1,N,M);
    clear(n, m+1,N,M);
}

int main(void){
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        int M,N,K;
        scanf("%d %d %d", &M, &N, &K);
        for(int n=0;n<N;n++){
            for(int m=0;m<M;m++){
                A[n][m]=0;
            }
        }
        for(int j=0;j<K;j++){
            int a,b;
            scanf("%d %d", &a, &b);
            A[b][a]=1; //배추세팅
        }
        //벌레세기
        int cnt=0;
        for(int n=0;n<N;n++){
            for(int m=0;m<M;m++){
                if(A[n][m]==1){
                    cnt++;
                    clear(n,m,N,M); //배추 소거
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}