#include <stdio.h>
int main(void){
    int n,m;
    scanf("%d %d", &n, &m);

    int A[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &A[i][j]);
        }
    }

    int k;
    scanf("%d %d", &m, &k);
    int B[100][100];
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            scanf("%d", &B[i][j]);
        }
    }

    int C[100][100]={0, };
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            for(int h=0;h<m;h++){
                C[i][j]+=A[i][h]*B[h][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}