#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "main.h"

typedef struct list_triangle{
	float side_a;
	float side_b;
	float side_c;
	float terulet;
	float kerulet;
	struct list_triangle *next;
}list_triangle;

list_triangle *list_triangle_pushforward(list_triangle *l0, float a, float b, float c);
list_triangle *list_triangle_pushbackward(list_triangle *l0, float a, float b, float c);
void print_list_triangle(list_triangle *l0);
void free_list_triangle(list_triangle *l0);

#endif /* TRIANGLE_H_ */



