#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "token.h"

typedef enum {
	WHITESPACE,
	TOKEN
} token_state;

typedef enum {
	SPCSPC,
	SPCTOK,
	TOKSPC,
	TOKTOK
} token_trans;

token_state classify(char c) {
	if (isspace(c)) {
		return WHITESPACE;
	}
	
	return TOKEN;
}

token_trans transition(token_state prev, token_state cur) {
	switch (prev) {
		case WHITESPACE:
			switch (cur) {
				case WHITESPACE:
					return SPCSPC;
				case TOKEN:
					return SPCTOK;
			}
		case TOKEN:
			switch (cur) {
				case WHITESPACE:
					return TOKSPC;
				case TOKEN:
					return TOKTOK;
			}
	}
	return SPCSPC;
}

size_t count_token(char* line) {
	size_t count = 0;
	size_t len = strlen(line);
	size_t i;
	token_state prev_state = WHITESPACE;
	token_state cur_state;
	token_trans cross;
	
	for(i = 0; i < len; i++) {
		cur_state = classify(line[i]);
		cross = transition(prev_state, cur_state);
		
		if (cross == SPCTOK) {
			count++;
		}
		prev_state = cur_state;
	}
	return count;
}

void insert_toks(char* line, token_array* toks) {
	size_t len = strlen(line);
	size_t i;
	token_state prev_state = WHITESPACE;
	token_state cur_state;
	token_trans cross;
	size_t start = 0;
	size_t tok_len;
	long cur_tok = 0;
	
	for(i = 0; i < len; i++) {
		cur_state = classify(line[i]);
		cross = transition(prev_state, cur_state);
		
		switch (cross) {
			case SPCTOK:
				start = i;
				break;
			case TOKSPC:
				tok_len = i - start;
				toks->body[cur_tok] = calloc(tok_len + 1, sizeof(char));
				memcpy(toks->body[cur_tok], line + start, tok_len);
				cur_tok++;
				break;
			default:
				break;
		}
		
		prev_state = cur_state;
	}
}

token_array* token_parse(char* line) {
	token_array* toks;
	toks = calloc(1, sizeof(token_array));
	toks->count = count_token(line);
	toks->body = calloc(toks->count, sizeof(token));
	insert_toks(line, toks);
	
	return toks;
}
