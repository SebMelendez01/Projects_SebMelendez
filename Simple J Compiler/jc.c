#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 
#include <ctype.h>

#include "token.h"
#include "stack.h"


void writeToFile(char *outputString, FILE *file) {
    fwrite(outputString, sizeof(char), strlen(outputString), file); 
}  


int fun = 0; //number of functions
char name_of_fun[200] = {0}; //name of specific function
int num_comparators;
int ifCount = 0; 
int size_of_stack = 0; 



int parseToFile(token *tok, FILE *file, stack *ifStack) {

    char outputString[5000] = {0}; 
    char *comp_str = malloc(10 * sizeof(char)); 
    char *str_arg = malloc(10 * sizeof(char)); 
    char *str_if = malloc(10 * sizeof(char));
    int low_bit; 
    int high_bit; 
    

    switch(tok->tok_type) {
    case 0: //Literals
        
      	low_bit = (short)tok->lit_num & 0xFF; 
        high_bit = (tok->lit_num >> 8) & 0xFF; 
        char *low_str = malloc(sizeof(char) * 256); 
        char *high_str = malloc(sizeof(char) * 256); 

        sprintf(low_str, "%d", low_bit); 
        sprintf(high_str, "%d", high_bit); 
        strcat(outputString, ";; LITERAL BLOCK ;; \n"); 
        strcat(outputString, "CONST R3, #");
        strcat(outputString, low_str); 
        strcat(outputString, "\n"); 

            
        strcat(outputString, "HICONST R3, #");
        strcat(outputString, high_str); 
        strcat(outputString, "\n"); 

        strcat(outputString, "STR R3, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 

        //free(low_str); 
        //free(high_str); 

        //Write To File
        writeToFile(outputString, file);  
        break; 
    case 1: //Add
        strcat(outputString, ";; ADD BLOCK ;;\n"); 
        strcat(outputString, "LDR R2, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 
        strcat(outputString, "LDR R3, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 

        //ADD Function
        strcat(outputString, "ADD R2, R2, R3\n"); 

        //Takedown
        strcat(outputString, "STR R2, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 

        //Write To File
        writeToFile(outputString, file);         
        break; 
    case 2: //Sub
        strcat(outputString, ";; SUB BLOCK ;;\n"); 
        strcat(outputString, "LDR R2, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 
        strcat(outputString, "LDR R3, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 

        //ADD Function
        strcat(outputString, "SUB R2, R2, R3\n"); 

        //Takedown
        strcat(outputString, "STR R2, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 

        //Write To File
        writeToFile(outputString, file);  
        break; 
    case 3: //Mul
        strcat(outputString, ";; MULTIPLY BLOCK ;;\n"); 
        strcat(outputString, "LDR R2, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 
        strcat(outputString, "LDR R3, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 

        //MUL Function
        strcat(outputString, "MUL R2, R2, R3\n"); 

        //Takedown
        strcat(outputString, "STR R2, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 

        //Write To File
        writeToFile(outputString, file);  
        break; 
    case 4: //Div
        strcat(outputString, ";; DIVIDE BLOCK ;;\n"); 
        strcat(outputString, "LDR R2, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 
        strcat(outputString, "LDR R3, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 

        //DIV Function
        strcat(outputString, "DIV R2, R2, R3\n"); 

        //Takedown
        strcat(outputString, "STR R2, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 
        //Write To File
        writeToFile(outputString, file);  
        break; 
    case 5: //Mod
        strcat(outputString, ";; MOD BLOCK ;;\n"); 
        strcat(outputString, "LDR R2, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 
        strcat(outputString, "LDR R3, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 

        //MOD Function
        strcat(outputString, "MOD R2, R2, R3\n"); 

        //Takedown
        strcat(outputString, "STR R2, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 

        //Write To File
        writeToFile(outputString, file);  
        break; 
    case 6: //Lt
        sprintf(comp_str, "%d", num_comparators); 

        strcat(outputString, ";; LT BLOCK ;;\n"); 
        strcat(outputString, "LDR R1, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 
        strcat(outputString, "LDR R2, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 

        strcat(outputString, "CMP R1, R2\n"); 
        
        //set up BRn
        strcat(outputString, "BRn "); 
        strcat(outputString, "LT_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n"); 

        strcat(outputString, "CONST R0, #0\n"); 
        strcat(outputString, "STR R0, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 

        //set up JMP
        strcat(outputString, "JMP END_LT_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n"); 


        strcat(outputString, "LT_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n");

        strcat(outputString, "CONST R0, #1\n"); 
        strcat(outputString, "STR R0, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 

        strcat(outputString, "END_LT_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n");

        //Write To File
        writeToFile(outputString, file);  
        //Increment the number of comparators used
        num_comparators++; 
        break; 
    case 7: //Le
        sprintf(comp_str, "%d", num_comparators); 

        strcat(outputString, ";; LE BLOCK ;;\n"); 
        strcat(outputString, "LDR R1, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 
        strcat(outputString, "LDR R2, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 

        strcat(outputString, "CMP R1, R2\n"); 
        
        //set up BRnz
        strcat(outputString, "BRnz "); 
        strcat(outputString, "LE_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n"); 

        strcat(outputString, "CONST R0, #0\n"); 
        strcat(outputString, "STR R0, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 

        //set up JMP
        strcat(outputString, "JMP END_LE_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n"); 

        strcat(outputString, "LE_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n");

        strcat(outputString, "CONST R0, #1\n"); 
        strcat(outputString, "STR R0, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 

        strcat(outputString, "END_LE_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n");

        //Write To File
        writeToFile(outputString, file);  
        //Increment the number of comparators used
        num_comparators++; 
        break; 

    case 8: //Eq
        sprintf(comp_str, "%d", num_comparators); 

        strcat(outputString, ";; EQ BLOCK ;;\n"); 
        strcat(outputString, "LDR R1, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 
        strcat(outputString, "LDR R2, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 

        strcat(outputString, "CMP R1, R2\n"); 
        
        //set up BRnz
        strcat(outputString, "BRz "); 
        strcat(outputString, "EQ_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n"); 

        strcat(outputString, "CONST R0, #0\n"); 
        strcat(outputString, "STR R0, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 

        //set up JMP
        strcat(outputString, "JMP END_EQ_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n"); 

        strcat(outputString, "EQ_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n");

        strcat(outputString, "CONST R0, #1\n"); 
        strcat(outputString, "STR R0, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 

        strcat(outputString, "END_EQ_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n");

        //Write To File
        writeToFile(outputString, file);

        //Increment the number of comparators used
        num_comparators++; 
        break;  
    case 9: //Ge   
        sprintf(comp_str, "%d", num_comparators); 

        strcat(outputString, ";; GE BLOCK ;;\n"); 
        strcat(outputString, "LDR R1, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 
        strcat(outputString, "LDR R2, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n");

        strcat(outputString, "CMP R1, R2\n"); 
        
        //set up BRnz
        strcat(outputString, "BRzp "); 
        strcat(outputString, "GE_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n"); 

        strcat(outputString, "CONST R0, #0\n"); 
        strcat(outputString, "STR R0, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 

        //set up JMP
        strcat(outputString, "JMP END_GE_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n"); 

        strcat(outputString, "GE_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n");

        strcat(outputString, "CONST R0, #1\n"); 
        strcat(outputString, "STR R0, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 


        strcat(outputString, "END_GE_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n");

        //Write To File
        writeToFile(outputString, file);  

        //Increment the number of comparators used
        num_comparators++; 
        break;  

    case 10: //Gt
        sprintf(comp_str, "%d", num_comparators); 

        strcat(outputString, ";; GT BLOCK ;;\n"); 
        strcat(outputString, "LDR R1, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 
        strcat(outputString, "LDR R2, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n");

        strcat(outputString, "CMP R1, R2\n"); 
        
        //set up BRnz
        strcat(outputString, "BRp "); 
        strcat(outputString, "GT_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n"); 

        strcat(outputString, "CONST R0, #0\n"); 
        strcat(outputString, "STR R0, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 

        //set up JMP
        strcat(outputString, "JMP END_GT_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n"); 


        strcat(outputString, "GT_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n");

        strcat(outputString, "CONST R0, #1\n"); 
        strcat(outputString, "STR R0, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 
        

        strcat(outputString, "END_GT_"); 
        strcat(outputString, comp_str); 
        strcat(outputString, "\n");

        //Write To File
        writeToFile(outputString, file);

        //Increment the number of comparators used
        num_comparators++; 
        break;  
    case 11: //And
        strcat(outputString, ";; AND BLOCK ;;\n"); 
        strcat(outputString, "LDR R2, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 
        strcat(outputString, "LDR R3, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 

        //AND Function
        strcat(outputString, "AND R2, R2, R3\n"); 

        //Takedown
        strcat(outputString, "STR R2, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 
        
        //Write To file
        writeToFile(outputString, file);  
        break; 
    case 12: //Or
        strcat(outputString, ";; OR BLOCK ;;\n"); 
        strcat(outputString, "LDR R2, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 
        strcat(outputString, "LDR R3, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 

        //OR Function
        strcat(outputString, "OR R2, R2, R3\n"); 

        //Takedown
        strcat(outputString, "STR R2, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 
        
        //Write To File
        writeToFile(outputString, file);  
        break;
    case 13: //Not
        strcat(outputString, ";; NOT BLOCK ;;\n"); 
        strcat(outputString, "LDR R2, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 
        strcat(outputString, "LDR R3, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 

        //NOT Function
        strcat(outputString, "NOT R2, R2, R3\n"); 

        //Takedown
        strcat(outputString, "STR R2, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 
        
        //Write To File
        writeToFile(outputString, file);  
        break; 
    case 14: //Drop
        strcat(outputString, ";; DROP BLOCK ;;\n");
        strcat(outputString, "ADD R6, R6, #1"); 
        //Write To File
        writeToFile(outputString, file);  
        break; 
    case 15: //Dup
        strcat(outputString, ";; DUP BLOCK ;;\n");
        strcat(outputString, "LDR R0, R6, #0\n");
        strcat(outputString, "ADD R6, R6, #-1\n");
        strcat(outputString, "STR R0, R6, #0\n");

        //Write To File
        writeToFile(outputString, file);  
        break; 
    case 16: //Swap
        strcat(outputString, ";; SWAP BLOCK ;;\n");
        strcat(outputString, "LDR R1, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 
        strcat(outputString, "LDR R2, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 

        strcat(outputString, "STR R1, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 
        strcat(outputString, "STR R2, R6, #-1\n");
        strcat(outputString, "ADD R6, R6, #-1\n");

        //Write To File
        writeToFile(outputString, file);  
        break; 
    case 17: //Rot  
        strcat(outputString, ";; ROT BLOCK ;;\n");
        strcat(outputString, "LDR R1, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 
        strcat(outputString, "LDR R2, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 
        strcat(outputString, "LDR R3, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n"); 

        strcat(outputString, "STR R2, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 
        strcat(outputString, "STR R1, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 
        strcat(outputString, "STR R3, R6, #-1\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 

        //Write To File
        writeToFile(outputString, file);  
        break; 
    case 18: //Arg 
        strcat(outputString, ";; ARGS BLOCK ;;\n"); 
        sprintf(str_arg, "%d", (tok->number_args + 2));

        strcat(outputString, "LDR R0, R5, #"); 
        strcat(outputString, str_arg); 
        strcat(outputString, "\n"); 
        strcat(outputString, "ADD R6, R6, #-1\n"); 
        strcat(outputString, "STR R0, R6, #0\n");
        
        //Write To File
        writeToFile(outputString, file);  
        break; 
    case 19: //If
        /*strcat(outputString, ";; IF BLOCK ;;\n"); 
        //Set Up if pointer
        strcat(outputString, "IF_"); 
        strcat(outputString, name_of_fun); 
        strcat(outputString, "_");
        //set up str_if for the if pointer
        size_of_stack++; 
        ifCount = ifCount + 1; 
        push(ifStack, ifCount); 
		
        sprintf(str_if, "%d", ifStack->fst->num); 
        strcat(outputString, str_if); 
        strcat(outputString, "\n");  

        strcat(outputString, "LDR R1, R6, #0\n"); 
        strcat(outputString, "ADD R6, R6, #1\n");
        strcat(outputString, "CMPI R1, #0\n"); //update NZP

        //set up BRnz pointer
        strcat(outputString, "BRnz ELSE_"); 
        strcat(outputString, name_of_fun); 
        strcat(outputString, "_"); 
        strcat(outputString, str_if);
        strcat(outputString, "\n");*/

        strcat(outputString, ";; IF BLOCK ;;\n");
        strcat(outputString, "ADD R6, R6, #1\n"); 
        strcat(outputString, "LDR R0, R6, #-1\n"); 
        strcat(outputString, "BRnz ELSE_"); 
        strcat(outputString, name_of_fun); 
        strcat(outputString, "_");
        //set up str_if for the if pointer
        size_of_stack++; 
        ifCount = ifCount + 1; 
        push(ifStack, ifCount);
        ifStack->fst->is_else = 0;  
        sprintf(str_if, "%d", ifStack->fst->num); 
        strcat(outputString, str_if); 
        strcat(outputString, "\n");  


		
        //free(str_if); 
        //Write To File
        writeToFile(outputString, file);  
        break; 
    case 20: //Else
        strcat(outputString, ";; ELSE BLOCK ;;\n"); 
        //sets up the BRnzp
        strcat(outputString, "BRnzp ENDIF_");
        strcat(outputString, name_of_fun); 
        strcat(outputString, "_"); 
        //sets up the number of strings
        
        sprintf(str_if, "%d", ifStack->fst->num);
        strcat(outputString, str_if); 
        strcat(outputString, "\n"); 

        strcat(outputString, "ELSE_"); 
        strcat(outputString, name_of_fun); 
        strcat(outputString, "_"); 
        strcat(outputString, str_if); 
        strcat(outputString, "\n"); 

        //sets the stack to see if an else statement has happened
        ifStack->fst->is_else = 1; 

        //free(str_if); 
        //Write To File
        writeToFile(outputString, file);  
        break; 
    case 21: //Endif
        
        strcat(outputString, ";; ENDIF BLOCK ;;\n"); 
        sprintf(str_if, "%d", ifStack->fst->num);
        if(ifStack->fst->is_else) {
            strcat(outputString, "ENDIF_"); 
            strcat(outputString, name_of_fun); 
            strcat(outputString, "_"); 
            strcat(outputString, str_if); 
            strcat(outputString, "\n");
        } else {
            strcat(outputString, "ELSE_"); 
            strcat(outputString, name_of_fun); 
            strcat(outputString, "_"); 
            strcat(outputString, str_if); 
            strcat(outputString, "\n"); 
        }
         

        pop(ifStack); 
        size_of_stack--; 
        //Write To File
        writeToFile(outputString, file);  
        break; 
    case 22: //Defun
        //Enter into a function
        fun = 1;  
        break; 
    case 23: //Return
        strcat(outputString, ";; RETURN BLOCK ;;\n"); 
        strcat(outputString, ";; Epilogue ;;\n"); 
        strcat(outputString, "LDR R7, R6, #0\n");
        strcat(outputString, "STR R7, R5, #2\n"); 
        strcat(outputString, "ADD R6, R5, #0\n"); 
        strcat(outputString, "LDR R5, R6, #0\n"); 
        
        strcat(outputString, "LDR R7, R6, #1\n"); 
        strcat(outputString, "ADD R6, R6, #3\n"); 
        strcat(outputString, "RET\n");
		
        writeToFile(outputString, file);  
        break; 
    case 24: //Function
    	 
        if(fun == 1) {
            strcat(outputString, "\t\t\t.CODE\n");
            strcat(outputString, "\t\t\t.FALIGN\n");
            strcat(outputString, tok->fun_name);
            strcat(outputString, "\n"); 
            strcat(outputString, ";; Prologue ;;\n"); 
            strcat(outputString, "ADD R6, R6, #-3\n"); 
            strcat(outputString, "STR R7, R6, #1\n"); 
            strcat(outputString, "STR R5, R6, #0\n"); 
            strcat(outputString, "ADD R5, R6, #0\n"); 

            fun = 0; 
            
            strcpy(name_of_fun, tok->fun_name); 
            
        } else {
            strcat(outputString, "JSR "); 
            strcat(outputString, tok->fun_name); 
            strcat(outputString, "\n"); 
            strcat(outputString, "ADD R6, R6, #-1\n");
        }
        writeToFile(outputString, file);  
        break;
        
    default: 
    	return 1; 
    	break;  
    }  
    

    //free(outputString); 
    free(comp_str); 
    free(str_arg); 
    free(str_if);
    return 0; 
} 


int main(int argc, char *argv[]) {
	/*
    FILE *inputFile = fopen(argv[1], "r"); 
    FILE *outputFile; 
    token *tok; 
    int lineNum = 0; 
    stack ifStack; 
    
    initStack(&ifStack); 
    
	

    

    
    //not content in file
    if(inputFile == NULL)  {
        printf("FILE does not exist\n");
        fclose(inputFile); 
        return 0;  
    }

    // + 2 char 
    char *fileName = malloc(100 * sizeof(char));
    char *asmFile = malloc(strlen(argv[1]) + sizeof(char) * 2);

    
    sscanf(argv[1], "%[^.].j", fileName); 
    sprintf(asmFile, "%s.asm", fileName); 


    //open output file
    outputFile = fopen(asmFile, "w"); 
    */ 

    char* filename = argv[1];
    FILE *outputFile; 
    token *tok; 
    int lineNum = 0; 
    stack ifStack; 

    FILE* inputFile = fopen(filename, "r");

    char* output = filename + strlen(filename)+3;
    strcpy(output, filename);
    output[strlen(output)-1] = '\0';
    strcat(output, "asm");

    outputFile = fopen(output, "w");


    //allocates memory to line
    char *line = malloc(200 * sizeof(char)); 

    char *sTok; 

    //iterates over lines and tokens
    while(!feof(inputFile)) {
        fgets(line, 200, inputFile); 
        
        //Determines if there is something on the line
        if(line[0] == ';' || strcmp(line, "\n") == 0) {
            continue; 
        }
		
        //iterates over the line and each token
        sTok = strtok(line, "\n\t ");
       
            
        while(sTok != NULL) {
            if(sTok[0] == ';') {
                break; 
            }
            
            //allocate token to memory
            int tokLength = strlen(sTok); 
            tok = malloc(sizeof(*tok));
            
            
             //
            if(setToken(tok, sTok, tokLength) == 0) {
                //free everything and exit
                printf("ERROR: Line #%d: unable to set up token\n", lineNum);
                //free(fileName); 
                //free(asmFile); 
                //free(line); 
                fclose(inputFile); 
                fclose(outputFile);  
                return 0; 
            }
            
            if(sTok[0] == ' ') {
            	printf("I am here"); 
            	break; 
            }
            
            if(parseToFile(tok, outputFile, &ifStack) == 1){
                //free everything and exit
                printf("ERROR: Line #%d: unable to print token to output file\n", lineNum);
                //free(fileName); 
                //free(asmFile); 
                //free(line); 
                fclose(inputFile); 
                fclose(outputFile);  
                return 0; 
            }
            printf("%d -- %s \n", tok->tok_type, sTok); 
            
            
           
            //free the old token 
            free(tok);

            /*
             * iterates over the line until a null pointer
             * sets the new token
             */
            sTok = strtok(NULL, " \r\t\n"); 
            
        }
    }

    //free(fileName); 
    //free(asmFile); 
    //free(line); 
    fclose(inputFile); 
    fclose(outputFile);
    return 0;  
}


