#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol.h"

typedef struct _symbol_dictionary {
	interned_symbol* current;
	struct _symbol_dictionary* left;
	struct _symbol_dictionary* right;
} symbol_dictionary;

symbol_dictionary* get_dict() {
	static symbol_dictionary* dict = NULL;
	
	if (dict) return dict;
	
	dict = calloc(1, sizeof(symbol_dictionary));
	return dict;
}

symbol_dictionary* candidate_check(symbol_dictionary* candidate) {
	if (!candidate) {
		return calloc(1, sizeof(symbol_dictionary));
	}
	return candidate;
}

interned_symbol* fetch_word(token word) {
	int comparison;
	symbol_dictionary* tree = get_dict();
	while(1) {
		if (!tree->current) {
			tree->current = calloc(1, sizeof(interned_symbol));
			tree->current->symbol = strdup(word);
			return tree->current;
		}
		
		comparison = strcmp(word, tree->current->symbol);
		
		if (comparison > 0) {
			tree->left = candidate_check(tree->left);
			tree = tree->left;
		}
		else if (comparison < 0) {
			tree->right = candidate_check(tree->right);
			tree = tree->right;
		}
		else {
			return tree->current;
		}
		
	}
}

stack_entry symbol_intern(token word) {
	interned_symbol* sym = fetch_word(word);
	return (stack_entry)sym;
}

interned_symbol* symbol_extern(stack_entry intern) {
	interned_symbol* sym = (interned_symbol*)intern;
	return sym;
}
