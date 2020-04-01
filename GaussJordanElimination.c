#include <stdio.h>
#include <math.h>

#define MAX_DIM 3
 
void printmatrix(float a[3][4], int n)
{
    int i,j;
    for(i = 1; i<=n; i++){
         printf("\n");
        for(j=1; j<=n+1; j++){
            printf("%f  ",a[i-1][j-1]);
        }
    }
   
} // 행렬 값을 보여주는 함수
 
int main()
{
    float a[MAX_DIM][MAX_DIM+1];
    float x[3] = {0, 0, 0};
    float temp,temp2;
 
    int n=3;
    int i,j,k,l;

    printf("행렬 값을 입력하세요 \n");
    for(i=1; i<=n; i++){
        for(j=1; j<=n+1; j++){
            scanf("%f", &(a[i-1][j-1]));
        }
    }
    printf("\n");

    printmatrix(a,n);
 
    for(k=1; k<=n; k++){
        temp = a[k-1][k-1];
        if(temp == 0){    // a[i][i]의 값이 0일 경우 행을 교환해준다.
            for(j=k; j<=n+1; j++){
                for(l = k; l < n; l++){
                    if(a[l][j-1] != 0){
                        temp2 = a[k-1][j-1];
                        a[k-1][j-1] = a[l][j-1];
                        a[k][j-1] = temp2;
                        break;
                    }
                }
            } 
            temp = a[k-1][k-1];    // 행을 교환한 후 그 값을 temp에 저장해놓는다.
        }
        for(j=k; j<=n+1; j++){
            a[k-1][j-1] = a[k-1][j-1]/temp;
        }
        for(i=k+1; i<=n; i++){
            temp = a[i-1][k-1];
            for(j=k; j<=n+1; j++){
                a[i-1][j-1] = a[i-1][j-1] - temp*a[k-1][j-1];
            }
        }
        printf("\n");
        printmatrix(a,n);        // Gauss 소거법
    }
    x[n-1] = a[n-1][n];
 
 
    for(k=n-1; k>=1; k--){
        x[k-1] = a[k-1][n];
        for(j= k+1; j<=n; j++){
            x[k-1] = x[k-1] - a[k-1][j-1]*x[j-1];
            a[k-1][j-1] = 0;
        }
        a[k-1][n] = x[k-1];
        printf("\n");
        
        printmatrix(a,n);
    }
    
    printf("\n\n");
    printf("x = %f\n",x[0]);
    printf("y = %f\n",x[1]);
    printf("z = %f\n",x[2]); // x,y,z 값 출력하기
    printf("\n");
}

