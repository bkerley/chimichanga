#ifndef CHIMI_STACK_H
#define CHIMI_STACK_H

typedef void* stack_entry;

stack_entry stack_pop();

void stack_push(stack_entry);
#endif