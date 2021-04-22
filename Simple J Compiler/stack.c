
#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#include "stack.h"

//Check These
void pop(stack *s) {
    stack_elt *elt;
    if(s->fst) {
		elt = s->fst; 
    }
	if ((s->fst)->nxt == NULL) {
		s->fst = NULL; 
		
	} else {
		s->fst = elt->nxt; 
	}

}

void push(stack *s, int number) {
    stack_elt *elt = malloc(sizeof(elt)); 
    elt->num = number; 
    elt->nxt = s->fst;
    //printf("asdfasdf"); 
    //exit(0);
    s->fst = elt; 

}

void initStack(stack *s) {
	s->fst = NULL; 
}





