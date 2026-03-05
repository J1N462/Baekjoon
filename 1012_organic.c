#include <stdio.h>
int A[50][50];
void clear(int * a, int m, int n, int N, int M){
    if(n-1>=0) {A[n-1][m]=0; clear(&A[n-1][m], n-1, m,N,M);}
    if(n+1<N) {A[n+1][m]=0; clear(&A[n+1][m], n+1, m,N,M);}
    if(m+1>=0) {A[n][m+1]=0; clear(&A[n][m+1], n, m+1,N,M);}
    if(m-1<M) {A[n][m-1]=0; clear(&A[n][m-1], n, m-1,N,M);}
    return;
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
            scanf("%d %d", &b, &a);
            A[b][a]=1; //배추세팅
        }
        //벌레세기
        int cnt=0;
        for(int n=0;n<N;n++){
            for(int m=0;m<M;m++){
                if(A[n][m]==1){
                    cnt++;
                    clear(&A[n][m], n, m,N,M); //배추 소거
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}