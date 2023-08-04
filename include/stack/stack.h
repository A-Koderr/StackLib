#pragma once

#include <stddef.h>
#include "EnumTypes.h"

typedef struct stack {
    size_t _size;
    void **_top;
    enum types _stack_type;
}stack;

stack *stack_init(enum types type);
int stack_push(stack *S, void *key);
void stack_pop(stack *S);
void stack_print(stack *S);
void stack_free(stack *S);