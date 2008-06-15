#ifndef CHIMI_TOKEN_H
#define CHIMI_TOKEN_H
typedef char* token;

typedef struct {
	size_t count;
	token* body;
	} token_array;

	token_array* token_parse(char* line);
	void token_free(token_array*);
#endif
