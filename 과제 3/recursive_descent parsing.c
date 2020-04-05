//
//  main.c
//  recursive_descent parsing
//
//  Created by yerimhuh on 2020/04/01.
//  Copyright © 2020 yerimhuh. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 64
#define is_num(c) ((c) >= '0' && (c) <= '9')
void get_next_token(void);
int expr(void);
int term(void);
int factor(void);

enum token{PLUS = 0,STAR,LP,RP,NUMBER,END};
enum token tok;
int input;
int r = 0;


int main(){
    get_next_token();
    r = expr();
    printf("계산 결과 = %d\n",r);
    while(tok == END){
        printf("프로그램 끝\n");
        exit(1);
    }
}

void get_next_token(){
    
    while((input = getchar()) != EOF){
        if( input == ' ' || input == '\t')
              continue;
        break;
    } // 공백을 무시하고 계산
    switch(input){
        case '+':
            tok = PLUS;
            return ;
        case '*':
            tok = STAR;
            return ;
        case '(':
            tok = LP;
            return ;
        case ')':
            tok = RP;
            return ;
    }

    if(is_num(input)){
        input = input-'0';
        tok = NUMBER;
        return ;
       }
    
    if(input == 10){
        fflush(stdin);
        tok = END;
    }//enter키를 입력했을 때, 프로그램 종료를 의미
}
int expr(){
    r = term();
       while(tok == PLUS){
           r = term();
           get_next_token();
           r = r + term(); // 덧셈 계산
       }
    return r;
}

int term(){
    r = factor();
    while(tok == STAR){
        r = factor();
        get_next_token();
        r = r * factor(); // 곱셈 계산
    }
    return r;
}

void error(){
    printf("error입니다. \n");
    exit(1);
} // error 발생시 error 출력 후 프로그램 종료


int factor(){
    if(tok == NUMBER){
        r = input;
        get_next_token();
    } // 정수 값 입력시 정수 값 저장
    else if(tok == LP){
        get_next_token();
        r = expr();
        if(tok == RP){
            get_next_token();
            r = expr();
        } // 괄호 계산
        else{
            if(tok == END)
                return r;
            else
                error();
        }
    }
    else{
        if(tok == PLUS || tok == STAR)
            return r;
        else
            error();
    }
    return r;
}


