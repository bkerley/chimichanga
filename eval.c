#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "symbol.h"
#include "eval.h"
#include "class.h"

void eval(token_array* line) {
	size_t i;
	token cur_word;
	class_type cur_class;
	for (i = 0; i < line->count; i++) {
		cur_word = line->body[i];
		cur_class = class_id(cur_word);
		
		//the big switch
		switch (cur_class) {
			case SYMBOL:
				stack_push(symbol_intern(cur_word));
				break;
			case NUMBER:
				stack_push((stack_entry)strtol(cur_word, NULL, 0));
				break;
			case OPCODE:
				fprintf(stderr,
					"Should be executing %s right now (%s:%d)\n", cur_word, __FILE__, __LINE__);
				break;
		}
	}
}