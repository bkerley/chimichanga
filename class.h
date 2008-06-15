#ifndef CHIMI_CLASS_H
#define CHIMI_CLASS_H
#include "token.h"
typedef enum {
	NUMBER,
	SYMBOL,
	OPCODE
} class_type;

class_type class_id(token word);
#endif