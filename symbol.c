#include <stdlib.h>
#include <stdio.h>
#include "symbol.h"

token symbol_to_opcode(token symbol) {
	if (symbol[0] != ':') {
		fprintf(stderr,
			"Tried to de-symbol a non-symbol %s (%s:%d)", symbol, __FILE__, __LINE__);
		exit(-1);
	}
	return symbol + 1;
}

typedef struct _symbol_dictionary {
	token current;
	struct _symbol_dictionary* left;
	struct _symbol_dictionary* right;
} symbol_dictionary;

symbol_dictionary* get_dict() {
	static symbol_dictionary* dict = NULL;
	
	if (dict) return dict;
	
	dict = calloc(1, sizeof(symbol_dictionary));
	return dict;
}

symbol_dictionary* traverse_word(token word) {
	
}

stack_entry symbol_intern(token word) {
	
}

token symbol_extern(stack_entry intern) {
	
}
