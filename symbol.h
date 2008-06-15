#ifndef CHIMI_SYMBOL_H
#define CHIMI_SYMBOL_H
#include "stack.h"
#include "token.h"

typedef struct {
	token symbol;
	void (*cdispatch)();
} interned_symbol;

stack_entry symbol_intern(token word);
interned_symbol* symbol_extern(stack_entry intern);

#endif