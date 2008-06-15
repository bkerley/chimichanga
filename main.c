#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "stack.h"
#include "token.h"
#include "eval.h"
#include "init.h"

void repl() {
	char* line;
	token_array* toks;
	while(1) {
		line = readline("chimi> ");
		if (!line) {
			fprintf(stderr, "\nEOF in repl (%s:%d)\n", __FILE__, __LINE__);
			return;
		}
		toks = token_parse(line);
		printf("%ld toks\n", toks->count);
		eval(toks);
		token_free(toks);
		free(line);
	}
}

int main() {
	fprintf(stderr, "chimichanga!\n");
	init_register();
	repl();
	return 0;
}

