#include <stddef.h>
#include <stdio.h>
#include "stack/stack.h"

int main(void) {
    stack *ST = stack_init(LONG);
    long kk = 78;
    for(int i=0; i<5; ++i) {
        ++kk;
        stack_push(ST, &kk);
    }
    stack_print(ST);
    stack_free(ST);
}