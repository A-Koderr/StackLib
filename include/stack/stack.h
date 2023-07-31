#pragma once
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
typedef struct stack{
    char *_type;
    size_t _size;
    void *_top;
}stack;

// #define stack_init(ptr, stack_type)     \
//     if(sizeof(stack_type)) {             \
//     ptr = malloc(sizeof(stack));        \
//     ptr->_type = malloc(sizeof(strlen(#stack_type))+1); \
//     strcpy(ptr->_type, #stack_type);    \
//     ptr->_size = 0;                     \
//     ptr->_top = NULL;                   \
//     }      

stack *_stack_init(char *stack_type){
    stack * ptr = malloc(sizeof(stack));
    ptr->_size = 0;
    ptr->_type = malloc(sizeof(strlen(stack_type))+1);
    strcpy(ptr->_type, stack_type);
    return ptr;
}


#define stack_init(stack_type)  \
    _stack_init(#stack_type);    \
    sizeof(stack_type)