#include "interact_with_us.h"

typedef struct term{
	unsigned int deg;
	int k; //coefficient of term
	struct term *next;
}term;

void addFront(term **head, unsigned int deg, int k);
void create_poly(term **head, int n);
void print_poly(term *head);
void match_poly(term **head_of_new, term *head1, term *head2);
void free_poly(term *poly);