#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define N 4
#pragma warning (disable:4996)

void primenum(int n);
void version3(int n);
void version4(int n);
void version5(int n);

int main()
{

    int input[N] = {100,1000,5000,10000};
    for (int i = 0; i < N; ++i)
    {
        printf("==========N : %d==========\n", input[i]);
        primenum(input[i]);
        version3(input[i]);
        version4(input[i]);
        version5(input[i]);
        printf("==========================\n");
    }
}
void primenum(int n){
    int primenum;//소수이면 1 아니면 0을 저장한다.
    int checknum;//소수인지 비교하는 값
    int i = 0;
     
    clock_t start, end;
    srand((unsigned int)time(NULL));
    start = clock();
     

    checknum = 2;//1은 소수가 아니기 때문에 2부터 검사한다.

    while(i < n){
    primenum = 1;
    for(int j = 2; j < checknum; j++){
        if(checknum % j == 0){
            primenum = 0;
            break;
            
        }
        
        }
        if(primenum == 1){ // 소수이다.
             i++;
        }
         checknum++;
     }
    
    end = clock();//종료 시간 측정
    printf("primenum(%d)'s time: ", n);
    printf("%.3lfmsec\n", (double)end - start);
    
}

void version3(int n){
    clock_t start, end;
    srand((unsigned int)time(NULL));
    start = clock();
    int number = 2;
    int count = 1;
    int prim;

    while (1){
        ++number;
        prim = 0; //소수라고 가정하고시작

        for (int i = 2; i <= number-1; ++i){
            if (number%i == 0) //사이에 나눠떨어지는게있으면
                prim = 1; //소수 아님
        }
        if (prim==0){
            count++;
        }
        if (count == n)
            break;
    }
    end = clock();
    printf("version3(%d)'s time: ", n);
    printf("%.3lfmsec\n", (double)end - start);
}

void version4(int n){
    int i, k, lim, x;
    int prim;
    int p[10001];
    clock_t start, end;
    srand((unsigned int)time(NULL));
    start = clock();
    
    p[1] = 2;
    x = 1;
    lim = 1;
    for (i = 2; i <= n; i++){
        x = x + 2;
        k = 2;
        prim = 1;
        while (prim && (k < lim))
        {
            if (p[k] == 0)
                break;
            prim = (x%p[k] != 0);
            ++k;
        }
        if (prim)
            p[i] = x;
        else
            --i;
    }
    end = clock();
    printf("version4(%d)'s time:", n);
    printf("%.3lfmsec\n",(double)end - start);
}


void version5(int n){
    int i, k, lim, x;
    int prim;
    int p[10001];
    clock_t start, end;
    srand((unsigned int)time(NULL));
    start = clock();
    p[1] = 2;

    x = 1;
    lim = 1;
    for (i = 2; i <= n; ++i){
        x = x + 2;
        if (sqrt(p[lim]) <= x)
        {
            lim++;
        }
        k = 2;
        prim = 1;
        while (prim && (k < lim))
        {
            if (p[k] == 0)
                break;
            prim = (x%p[k] != 0);
            ++k;
        }
        if (prim)
            p[i] = x;
        else
            --i;
    }
    end = clock();
    printf("version5(%d)'s time:", n);
        printf("%.3lfmsec\n", (double)end - start);
}
