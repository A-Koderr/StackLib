#include <stdio.h>
#include "stack/stack.h"
int main(void) {
    stack *S = stack_init(int);
    printf("%s", S->_type);
}