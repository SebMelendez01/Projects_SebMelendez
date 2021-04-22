
#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#include "token.h"
#include "stack.h"
//#include "printnum.h"


////////////////////////////////////////////////
////////////////////////////////////////////////GO BACK THROUGH TO REGISTERS
////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////

int setToken(token *tok, char *charTok, int tokLength) {
    //0
    //hexadecimal literals
  
    if(charTok[0] == '0' && charTok[1] == 'x') {
       	
        //converts hex to int
        tok->lit_num = strtol(charTok, NULL, 16); 
        tok->tok_type = 0;
        return 1; 
    
    //Posative decimal literals
    } else if(isdigit(charTok[0])) {
        //printf("sadfasdfasdf\n");
        int num = atoi(charTok); 
        tok->tok_type = 0;
        tok->lit_num = num; 
        return 1; 
    //Negative decimal literals
    } else if(charTok[0] == '-' && isdigit(charTok[1])) {
        int num = atoi(charTok);
        tok->tok_type = 0;
        tok->lit_num = num; 
        return 1; 
    //1
    } else if (strcmp(charTok, "+") == 0) {
        tok->tok_type = 1; 
        return 1; 
    //2
    } else if (strcmp(charTok, "-") == 0) {
        tok->tok_type = 2; 
        return 1; 
    //3
    } else if (strcmp(charTok, "*") == 0) {
        tok->tok_type = 3; 
        return 1; 
    //4
    } else if (strcmp(charTok, "/") == 0) {
        tok->tok_type = 4; 
        return 1; 
    //5
    } else if (strcmp(charTok, "%") == 0) {
        tok->tok_type = 5; 
        return 1; 
    //6
    } else if (strcmp(charTok, "lt") == 0) {
        tok->tok_type = 6;
        return 1; 
    //7
    } else if (strcmp(charTok, "le") == 0) {
        tok->tok_type = 7; 
        return 1; 
    //8
    } else if (strcmp(charTok, "eq") == 0) {
        tok->tok_type = 8; 
        return 1; 
    //9
    } else if (strcmp(charTok, "ge") == 0) {
        tok->tok_type = 9; 
        return 1; 
    //10
    } else if (strcmp(charTok, "gt") == 0) {
        tok->tok_type = 10; 
        return 1; 
    //11
    } else if (strcmp(charTok, "and") == 0) {
        tok->tok_type = 11; 
        return 1; 
    //12
    } else if (strcmp(charTok, "or") == 0) {
        tok->tok_type = 12; 
        return 1; 
    //13
    } else if (strcmp(charTok, "not") == 0) {
        tok->tok_type = 13; 
        return 1; 
    //14
    } else if (strcmp(charTok, "drop") == 0) {
        tok->tok_type = 14; 
        return 1; 
    //15
    } else if (strcmp(charTok, "dup") == 0) {
        tok->tok_type = 15; 
        return 1; 
    //16
    } else if (strcmp(charTok, "swap") == 0) {
        tok->tok_type = 16; 
        return 1; 
    //17
    } else if (strcmp(charTok, "rot") == 0) {
        tok->tok_type = 17; 
        return 1; 
    
    //18
    } else if (charTok[0] == 'a' && charTok[1] == 'r' && charTok[2] == 'g' && tokLength > 3 && tokLength < 6) {
        tok->tok_type = 18;
        if(tokLength == 4) { 
            tok->number_args = charTok[3] - 48; 
            return 1; 
        } else if (tokLength == 5) {
            char *sNum = malloc(2*sizeof(char)); 
            sNum = &charTok[4]; 
            strcat(sNum, &charTok[5]); 
            int num = atoi(sNum); 
            tok->number_args = num;
            //free(sNum); 
            //arg num is greater that 20
            if(num > 20)
                return 0; 
            return 1; 
        //arg num is greater that 100
        } else {
            return 0; 
        }
    //19
    } else if (strcmp(charTok, "if") == 0) {
        tok->tok_type = 19; 
        return 1; 
    //20
    } else if (strcmp(charTok, "else") == 0) {
        tok->tok_type = 20; 
        return 1;
    //21
    } else if (strcmp(charTok, "endif") == 0) {
        tok->tok_type = 21; 
        return 1; 
    //22
    } else if (strcmp(charTok, "defun") == 0) {
        
        tok->tok_type = 22; 
        
        return 1; 
    //23
    } else if (strcmp(charTok, "return") == 0) {
        tok->tok_type = 23; 
        return 1; 
    /*24
    } else if (strcmp(charTok, "printNum") == 0) {
        tok->tok_type = 24; 
        return 1; 
    //25
    } else if (strcmp(charTok, "endl") == 0) {
        tok->tok_type = 25; 
        return 1; 
    *///24 function name
    } else {
        
        if(charTok[0] == '_')
            return 0; 
        if((checkChar(charTok)) == 1){
            return 0; 
        }
        tok->tok_type = 24; 
        tok->fun_name = charTok; 
        
        return 1; 
    }
    //Dont deal with broken tokens
}

int checkChar(char* charTok) {
    int length = strlen(charTok); 
    int i; 
    for(i = 0; i < length; i++) {
        if(charTok[i] == '`' || charTok[i] == '!' || charTok[i] == '@' || charTok[i] == '#' ||
           charTok[i] == '$' || charTok[i] == '^' || charTok[i] == '&' || charTok[i] == '(' ||
           charTok[i] == ')' || charTok[i] == '{' || charTok[i] == '}' || charTok[i] == '|' ||
           charTok[i] == ':' || charTok[i] == '"' || charTok[i] == '<' || charTok[i] == '>' ||
           charTok[i] == ',' || charTok[i] == '.' || charTok[i] == '?' || charTok[i] == '~' || 
           charTok[i] == '[' || charTok[i] == ']' || charTok[i] == '=') 
            return 1;  
    }
    return 0;
}
