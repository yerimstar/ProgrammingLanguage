//
//  Calendar_array.c
//  Project_PL
//
//  Created by yerimhuh on 2020/03/21.
//  Copyright © 2020 yerimhuh. All rights reserved.
//

#include <stdio.h>
int basemonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int firstday;
int year;

int leapyear(int a){
    if(a % 4 == 0){
        if(a % 100 == 0){
            if(a % 400 == 0){
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
} // 입력받은 년도가 윤년인지 검사하는 함수

int first_day(int i){
    if((i == 0)|(i == 2)| (i == 4) | (i == 6) | (i == 7) |( i == 9) | (i == 11))
        firstday = (firstday + 31) % 7;
    else if((i == 3) | ( i == 5)| (i == 8) | (i == 10))
        firstday = (firstday + 30) % 7;
    else if(i == 1){
        if(leapyear(year))
            firstday = (firstday + 29)% 7;
        else
            firstday = (firstday + 28) % 7;
    }
    return firstday;
}//매 달 1일이 시작하는 요일을 정해주는 함수

void calendar(int year){
    
    int inputyear;
    int leapcnt=0;
    int month[12][6][7]= {0};
    int i,j,k,l;
    int daycnt;
    
    for(k = 1; k < year; k++){
        leapcnt += leapyear(k);
    }// 입력받은 년도까지 윤년이 몇 번인지 저장한다.
    
    inputyear = year-1;
    firstday = (inputyear*365+leapcnt+1)%7; //1월1일이 무슨 요일인지 정해주는 식
    
     for(i = 0; i < 12; i++){
        daycnt = 0;
        for(j = 0; j < 6; j++){
            for(k = 0; k < 7; k++){
                daycnt++;
                month[i][j][k] = daycnt-firstday;
                    if(month[i][j][k] < 1 || month[i][j][k] > basemonth[i])
                        month[i][j][k] = 0;
                    }
            }
         firstday = first_day(i);
        } // 3차원 배열에 날짜를 저장해준다.
        
    for(l = 0; l < 4; l++){
        printf("--------------%d월-------------\t--------------%d월-------------\t--------------%d월-------------\n",l*3+1,l*3+2,l*3+3);
            printf(" 일   월   화   수   목   금   토 \t 일   월   화   수   목   금   토 \t 일   월   화   수   목   금   토 \n");
            printf("-------------------------------\t-------------------------------\t-------------------------------\n");
            for(i = 0; i < 6; i++){
                for(j = 0; j < 3; j++){
                    for(k = 0; k < 7; k++){
                        if(month[(l*3)+j][i][k] == 0){
                            printf("    ");
                            continue;
                        }
                        printf("%3d ",month[(l*3)+j][i][k]);
                    }
                    printf("\t");
                }
                printf("\n");
            }
                printf("\n\n");
            }
    
}


     

int main(){
    while(1){
        printf("년도를 입력하세요 : ");
        scanf("%d",&year);
        
        if(leapyear(year) == 1)
            basemonth[1] = 29;
        
        calendar(year);
        
    }
}
    
    
