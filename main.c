#include <stdio.h>
#include "stack.h"

int main() {
	stack_entry canary;
	fprintf(stderr, "chimichanga!\n");
	stack_push('8');
	canary = stack_pop();
	fprintf(stderr, "canary %s\n",canary=='8'?"matches":"doesn't match");
	return 0;
}
