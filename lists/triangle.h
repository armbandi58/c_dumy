#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "main.h"

typedef struct list_triangle{
	float side_a;
	float side_b;
	float side_c;
	float terulet;
	float kerulet;
	float var_angle;
	struct list_triangle *next;
}list_triangle;

list_triangle *list_triangle_pushforward(list_triangle *l0, float a, float b, float c);
list_triangle *list_triangle_pushbackward(list_triangle *l0, float a, float b, float c);
void print_list_triangle(list_triangle *l0);
void free_list_triangle(list_triangle *l0);
float triangle_Terulet(float a,float b, float a_angle);
float triangle_Kerulet(float a0, float a1, float a2);
float triangle_Magassag(float b, float angle);
void triangle_length(list_triangle *l0, u32 *len);
float triangle_angle(float aa, float ba, float ca);

#endif /* TRIANGLE_H_ */



