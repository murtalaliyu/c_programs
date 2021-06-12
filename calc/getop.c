#include <stdio.h>
#include <ctype.h>
#include "calc.h"
#include "getungetch.c"

/* getop: get next character or numeric operand */
int getop(char s[]) {
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t');

	s[1] = '\0';

	if (!isdigit(c) && c != '.') {
		return c;			// not a number
	}

	i = 0;

	if (isdigit(c)) {		// collect integer part
		while (isdigit(s[++i] = c = getch()));
	}

	if (c == '.') {			// collect fraction part
		while (isdigit(s[++i] = c = getch()));
	}

	s[i] = '\0';

	if (c != EOF) {
		ungetch(c);
	}

	/*printf("string num: ");
	int j = 0;
	while (j < i) {
		printf("%c", s[j++]);
	}
	printf("\n");*/

	return NUMBER;
}