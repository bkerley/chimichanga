#include "eval.h"
#include "class.h"

void eval(token_array* line) {
	size_t i;
	token cur_word;
	class_type cur_class;
	for (i = 0; i < line->count; i++) {
		cur_word = line->body[i];
		cur_class = class_id(cur_word);
	}
}