#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "stack.h"
#include "token.h"

int main() {
	stack_entry canary;
	fprintf(stderr, "chimichanga!\n");
	stack_push('8');
	canary = stack_pop();
	fprintf(stderr, "canary %s\n",canary=='8'?"matches":"doesn't match");
	return 0;
}

void repl() {
	char* line;
	token_array* toks;
	while(1) {
		line = readline("chimi> ");
		toks = token_parse(line);
		
		
		free(line);
	}
}
