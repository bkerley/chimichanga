#include <ctype.h>
#include "class.h"

class_type class_id(token word) {
	if (word[0] == ':') return SYMBOL;
	if (isdigit(word[0])) return NUMBER;
	return OPCODE;
}