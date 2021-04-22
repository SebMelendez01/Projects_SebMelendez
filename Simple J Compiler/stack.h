

typedef struct stack_elt_struct{
       int num; 
       int is_else; 
       struct stack_elt_struct *nxt; 
} stack_elt; 

typedef struct stack_struct {
    stack_elt *fst; 
} stack; 

void pop(stack *s); 
void push(stack *s, int number);
void initStack(stack *s); 



