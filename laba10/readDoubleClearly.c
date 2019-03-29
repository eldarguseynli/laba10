#include "interact_with_us.h"

int readDoubleClearly(double *x) {
	if (!(scanf("%lf", x))) {
		clear(); return 0;
	}
	clear();
	return 1;
}

int readIntClearly(int *n) {
	if (!(scanf("%d", n))) {
		clear(); return 0;
	}
	clear();
	return 1;
}

void clear(void) //func clears stdin buffer
{
	char c = 1;
	while (c = getchar() != '\n' && c != EOF); //read all symbols from stdin buffer until the EOF or \n
}