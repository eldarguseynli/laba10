#include "polynomial.h"
#include <malloc.h>
#include <math.h>

void create_poly(term **head, int n) { //create polynomial of n degree
	
	int k; //coefficient
	while (1) {
		for (int i = 0; i < n + 1; i++) {
			printf("Input the coefficient of x^%d: ", i);
			if (!readIntClearly(&k)) { puts("\nYou had to inputed number. Input it correctly again.\n"); i--; continue; } //if invalid value try to continue
			if (k) addFront(head, i, k);																				  //the input of coefficient
		}																												  //else add it to the list
		if (*head) return; else { puts("\nYou should have inputed at least 1 term with non-zero coefficient\n"); continue; }
	}
}

void print_poly(term *head) {
	term *p = head;
	if (head->k < 0) printf("-");
	while (p->next) {
		printf("%dx^%d", abs(p->k), p->deg);
		if (p->next->k >= 0) printf(" + "); else printf(" - ");
		p = p->next;  //print consequently all terms in polynomial but the last term without "+"
	}
	if (p->deg == 0) printf("%d", abs(p->k)); else printf("%dx^%d", abs(p->k), p->deg); //handle the situation when we have coefficient near zero degree term or
	printf("\n");														      
}


void addFront(term **head, unsigned int deg, int k){ //add the front element
	term *p = malloc(sizeof(term));
	p->deg = deg;
	p->k = k;
	if (!*head) {
		p->next = NULL;
		*head = p;
	}
	else
	{
		p->next = *head;
		*head = p;
	}
}

void match_poly(term **head_of_new, term *head1, term *head2) {
	term *tmp1 = head1, *tmp10 = NULL;
	term *tmp2 = head2, *tmp20 = NULL;

	while (tmp10 != head1 && tmp20 != head2)
	{
		while (tmp1->next != tmp10) tmp1 = tmp1->next; //consequently take every time new elemnt from the end in two lists 
		while (tmp2->next != tmp20) tmp2 = tmp2->next;
	
		if (tmp1->deg > tmp2->deg) tmp20 = tmp2; //if deg1 > deg2 => go to the next element in the first list from the end
		else if (tmp1->deg < tmp2->deg) tmp10 = tmp1; //if deg1 < deg2 => go to the next element in the second list from the end
		else {
			addFront(head_of_new, tmp1->deg, tmp1->k + tmp2->k); //then add this term to the new list and make iteration in 2 list simultaneously
			tmp10 = tmp1; tmp20 = tmp2;
		}

		tmp1 = head1; tmp2 = head2; //back the buffers to the begining of list
	}
}

void free_poly(term *poly) { //free the memory from list`s elements
	
	term *tmp;
	while (poly != NULL)
	{
		tmp = poly->next;
		free(poly);
		poly = tmp;
	}
}