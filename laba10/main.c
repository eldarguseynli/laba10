#include "polynomial.h"

int main() {

	puts("--------------------------------------------LABA10--------------------------------------------\n");

	term *p1 = NULL; int n1;

	printf("\nInput the degree of of the 1th polynomial: ");
	while (!readIntClearly(&n1) || n1 < 0 ) puts("You should have inputed not negative integer. Try input correct number again:");
	puts("");
	create_poly(&p1, n1);
	
	puts("The first polynomial:\n");
	print_poly(p1); puts("");

	term *p2 = NULL; int n2;

	printf("\nInput the degree of the 2th polynomial : ");
	while (!readIntClearly(&n2) || n2 < 0) puts("You should have inputed not negative integer. Try input correct number again:");
	puts("");
	create_poly(&p2, n2);

	puts("The second polynomial:\n");
	print_poly(p2); puts("");

	term *p3 = NULL;
	match_poly(&p3, p1, p2);
	puts("The  result of the matching of 2 polynomials:\n");
	if (p3 == NULL) puts("There are no terms with the same degrees in the 2 polynomials");
	else print_poly(p3);

	free_poly(p1);
	free_poly(p2);
	free_poly(p3);
}


