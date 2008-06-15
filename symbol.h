#ifndef CHIMI_SYMBOL_H
#define CHIMI_SYMBOL_H
#include "stack.h"
#include "token.h"

stack_entry symbol_intern(token word);
token symbol_extern(stack_entry intern);

token symbol_to_opcode(token word);

#endif