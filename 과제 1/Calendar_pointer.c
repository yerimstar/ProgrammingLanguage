//
//  Calendar_pointer.c
//  Calendar_Pointer
//
//  Created by yerimhuh on 2020/03/22.
//  Copyright © 2020 yerimhuh. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int year;
int firstday;
int ***head;

int basemonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

void setpointer(){
    int i,j;
    int ***first;
    int **second;
    
    head = (int***)calloc(12,sizeof(int**));
    first = head;
    for(i = 0; i < 12; i++){
        *first = (int**)calloc(6,sizeof(int*));
        second = *first;
        first++;
        for(j = 0; j < 6; j++){
            *second = (int*)calloc(7,sizeof(int));
            second++;
        }
    }
    
    
    
}

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
    int*** first = head;
    int** second;
    int* third = NULL;
    int i,j,k,l;
    int daycnt;
    
    for(k = 1; k < year; k++){
        leapcnt += leapyear(k);
    } // 입력받은 년도까지 윤년이 몇 번인지 저장한다.
    
    inputyear = year-1;
    firstday = (inputyear*365+leapcnt+1)%7; //1월1일이 무슨 요일인지 정해주는 식
    
     first = head;
     for(i = 0; i < 12; i++){
        daycnt = 0;
        second = *first;
        for(j = 0; j < 6; j++){
           third = *second;
            for(k = 0; k < 7; k++){
                daycnt++;
                *third = daycnt-firstday;
                    if(*third < 1 || *third > basemonth[i])
                        *third = 0;
                    third++;
                    }
            second++;
            }
         firstday = first_day(i);
         first++;
        }
    
    for(i = 0; i < 4; i++){
            printf("--------------%d월-------------\t--------------%d월-------------\t--------------%d월-------------\n",i*3+1,i*3+2,i*3+3);
            printf(" 일   월   화   수   목   금   토 \t 일   월   화   수   목   금   토 \t 일   월   화   수   목   금   토 \n");
            printf("-------------------------------\t-------------------------------\t-------------------------------\n");
        
                for(j = 0; j < 6; j++){
                    first = head;
                    for(k = 0; k < i*3; k++)
                        first++;
                    for(k = (i*3); k < i*3+3; k++){
                        second = *first;
                        for(l = 0;  l < j; l++)
                            second++;
                        third = *second;
                        for(l = 0; l < 7; l++){
                            if(*third == 0){
                                printf("    ");
                                third++;
                                continue;
                            }
                            else{
                                printf("%3d ",*third);
                                third++;
                            }
                            }
                        first++;
                        printf("\t");
                    }
                    printf("\n");
                }
                    printf("\n\n");
                }
        
    }
    

         
    

int main(){
   
    printf("년도를 입력하세요 : ");
    scanf("%d",&year);
    setpointer();
    if(leapyear(year) == 1)
               basemonth[1] = 29;
    
    calendar(year);
}
