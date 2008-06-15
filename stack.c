#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stack.h"

#define STACK_SIZE 256L

typedef struct {
	stack_entry* top;
	stack_entry* bottom;
	size_t maxsize;
	size_t count;
} stack_header;

stack_header* get_stack() {
	static stack_header* current_stack = NULL;
	
	if (current_stack) return current_stack;
	
	current_stack = calloc(1, sizeof(stack_header));
	current_stack->maxsize = STACK_SIZE;
	current_stack->bottom = calloc(STACK_SIZE, sizeof(stack_entry));
	current_stack->top = current_stack->bottom;
	current_stack->count = 0;
	
	if (!current_stack->bottom) {
		fprintf(stderr,
			"Failed to alloc stack size of %ld (%s:%d)\n", STACK_SIZE, __FILE__, __LINE__);
		exit(-1);
	}
	return current_stack;
}

int stack_empty(stack_header* stk) {
	return !stk->count;
}

int stack_full(stack_header* stk) {
	return stk->count == stk->maxsize;
}

void double_stack(stack_header* stk) {
	stack_entry* trial = calloc(stk->maxsize*2, sizeof(stack_entry));
	if (!trial) {
		fprintf(stderr,
			"Failed to double stack size to %ld (%s:%d)\n", stk->maxsize*2, __FILE__, __LINE__);
		exit(-1);
	}
	
	memcpy(trial, stk->bottom, stk->maxsize);
	free(stk->bottom);
	stk->bottom = trial;
	stk->top = stk->bottom + (stk->count * sizeof(stack_entry));
}

stack_entry stack_pop() {
	stack_header* current_stack = get_stack();
	stack_entry popped_value;
	if(stack_empty(current_stack)) {
		fprintf(stderr,
			"Tried to pop an empty stack (%s:%d)\n", __FILE__, __LINE__);
		exit(-1);
	}
	
	popped_value = *(current_stack->top);
	current_stack->top -= sizeof(stack_entry);
	current_stack->count --;
	
	return popped_value;
}

void stack_push(stack_entry pushed_value) {
	stack_header* current_stack = get_stack();
	if(stack_full(current_stack)) {
		double_stack(current_stack);
	}
	
	current_stack->count ++;
	current_stack->top += sizeof(stack_entry);
	*(current_stack->top) = pushed_value;
}