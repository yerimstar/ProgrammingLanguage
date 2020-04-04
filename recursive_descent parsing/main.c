//
//  main.c
//  recursive_descent parsing
//
//  Created by yerimhuh on 2020/04/01.
//  Copyright © 2020 yerimhuh. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 64
#define is_num(c) ((c) >= '0' && (c) <= '9')
void get_next_token(void);
int expr(void);
int term(void);
int factor(void);

enum token{PLUS,STAR,LP,RP,NUMBER,END};
enum token tok;
int input;
int r;

int main(){
    get_next_token();
    r = expr();
    printf("%d",r);
   
   
   
}

void get_next_token(){
    input = getchar();
    switch(input){
        case '+':
            tok = PLUS;
            return;
        case '*':
            tok = STAR;
            return;
        case '(':
            tok = LP;
            return;
        case ')':
            tok = RP;
            return;
    }
    if(is_num(input)){
        tok = NUMBER;
        return;
    }
    }
    

int expr(){
    term();
       while(tok == PLUS){
           get_next_token();
           r += term();
       }
    return r;
}

int term(){
    r = factor();
    while(tok == STAR){
        get_next_token();
        factor();
    }
    return r;
}

void error(){
    printf("error입니다. \n");
}


int factor(){
    if(tok == NUMBER)
        get_next_token();
    else if(tok == LP){
        get_next_token();
        r = expr();
        if(tok == RP)
            get_next_token();
        else
            error();
        error();
    }
    return r;
}
