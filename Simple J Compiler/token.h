
/*
 *      Literals[0]
 *      Add[1], Sub[2], Mul[3], Div[4], Mod[5],
 *      Lt[6], Le[7], Eq[8], Ge[9], Gt[10],
 *      And[11], Or[12], Not[13], 
 *      Drop[14], Dup[15], Swap[16], Rot[17], Arg[18],
 *      If[19], Else[20], Endif[21], 
 *      Defun[22], Return[23], Printnum[24], Endl[25],
 *      Function[26]
 */
typedef struct token_struct {
    enum {
        Literals,
        Add, Sub, Mul, Div, Mod,
        Lt, Le, Eq, Ge, Gt,
        And, Or, Not, 
        Drop, Dup, Swap, Rot, Arg,
        If, Else, Endif, 
        Defun, Return,// Printnum, Endl,
        Function
    } tok_type; 
    int lit_num;
    int number_args; 
    char *fun_name;
} token; 


int setToken(token *tok, char *charTok, int tokLength); 
int checkChar(char *charTok); 
//void writeToFile(char *outString, FILE *file);
//int parseFile(token *tok, FILE *file, stack *ifStack);
