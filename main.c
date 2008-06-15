#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "stack.h"
#include "token.h"

int main() {
	fprintf(stderr, "chimichanga!\n");
	repl();
	return 0;
}

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
		
		free(toks);
		free(line);
	}
}
