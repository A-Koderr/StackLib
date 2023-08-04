#include <stddef.h>
#include <stdio.h>
#include "stack/stack.h"

#define el 5

int main(void) {
    stack *ST = stack_init(LONG);
    long kk = 78;
    for(int i=0; i<el; ++i) {
        ++kk;
        stack_push(ST, &kk);
    }
    for(int i=0; i<el+1; ++i) {
        printf("Current Stack : \n");
        stack_print(ST);
        printf("\n");
        stack_pop(ST);
    }
    stack_free(ST);
}