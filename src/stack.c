#include "stack/stack.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Internal functions declaration
void *_stack_push_LONG(void *ptr_long);
void *_stack_push_STR(void *ptr_str);

stack *stack_init(enum types type) {
    stack *ptr = malloc(sizeof(stack));
    ptr->_stack_type = type;
    ptr->_top = NULL;
    ptr->_size = 0;
    return ptr;
}

// Returns -1, Unrecoverable error.
// Returns -2, Internal Error Retry. 
int stack_push(stack *S, void *key) {
    if (S == NULL) {
        fprintf(stderr, "stack_push : Uninitialised stack ptr\nCall stack_init()\n");
        return -1;
    }
    if (key == NULL) {
       fprintf(stderr, "stack_push : NULL ptr passed\n");
       return -1;
    }
    void **ptr = realloc(S->_top, sizeof(void *)*(S->_size+1));
    if (ptr == NULL) {
        fprintf(stderr, "stack_push : Reallocation of ptr failed. \nRetry alloaction old mem block still intact.\n");
        return -2;
    }
    S->_top = ptr;
    if (S->_stack_type == LONG) {
        S->_top[S->_size] = _stack_push_LONG(key);
    } else if(S->_stack_type == STR) {
        S->_top[S->_stack_type] = _stack_push_STR(key);
    }

    // When mem alloc failed.
    if(S->_top[S->_size] == NULL) {
        return -2;
    }

    // Everything is fine
    ++S->_size;
    return 0;
}

void stack_pop(stack *S) {
    if (S->_size > 0) {
        --S->_size;
        free(S->_top[S->_size]);
        S->_top[S->_size] = NULL;
        void **ptr = NULL;
        if(S->_size>0)
            ptr = realloc(S->_top, sizeof(void *)*(S->_size));
        else {
            free(S->_top);
            ptr = NULL;
        }
        if(ptr == NULL && S->_size>0) {
            fprintf(stderr, "stack_pop : Realloc Failed, Memory corruption may occur.\n");
        }
        S->_top = ptr;
        ptr = NULL;
    } else {
        fprintf(stderr, "stack_pop : Failed, Stack empty!\n");
    }
}

void stack_print(stack *S) {
    if (S->_size>0) {
        if (S->_stack_type == LONG) {
            for(size_t i = S->_size; i>0; i--) {
                printf("%ld\n",*(long*)S->_top[i-1]);
            }
        }else if (S->_stack_type == STR) {
            for(size_t i = S->_size; i>0; i--) {
                printf("%s\n",(char *)S->_top[i-1]);
            }
        }
    } else {
        fprintf(stderr, "stack_print : Failed, Stack Empty!\n");
    }
}

void stack_free(stack *S) {
    for(size_t i = 0; i<S->_size; i++)
        free(S->_top[i]);
    free(S->_top);
    free(S);
}
void *_stack_push_LONG(void *ptr_long) {
    long *ptr = NULL;
    ptr = (long *)malloc(sizeof(long));
    if (ptr == NULL) {
        fprintf(stderr, "stack_push : malloc failed while allocating %lu bytes.\n", sizeof(long));
        return NULL;
    }
    *ptr = *(long *)ptr_long;
    return ptr;
}

void *_stack_push_STR(void *ptr_str) {
    char *ptr = NULL;
    size_t i = 0;
    char *temp = (char *)ptr_str;
    while(temp[i] != '\0' && i != (ULLONG_MAX-1))
        ++i;
    ptr = malloc(sizeof(char)*(i+1));
    if (ptr == NULL) {
        fprintf(stderr, "stack_push : malloc failed while allocating %lu.\n", sizeof(char)*(i+1));
        return NULL;
    }
    strncpy(ptr, ptr_str, i);
    ptr[i] = '\0';
    return ptr;
}