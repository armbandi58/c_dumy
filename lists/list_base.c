#include "komplex.h"

list_triangle *list_triangle_pushforward(list_triangle *l0, float a, float b, float c){
	list_triangle *new = (list_triangle*)malloc(sizeof(list_triangle));
	new -> side_a = a;
	new -> side_b = b;
	new -> side_c = c;
	new -> next = l0;

	return new;
}

list_triangle *list_triangle_pushbackward(list_triangle *l0, float a, float b, float c){
	list_triangle *new = (list_triangle*)malloc(sizeof(list_triangle));

	new -> side_a = a;
	new -> side_b = b;
	new -> side_c = c;
	new -> next = NULL;

	if(l0 == NULL){
		return new;
	}else{
		list_triangle *tmp = l0;

		while(tmp -> next != NULL){
			tmp = tmp -> next;
		}
		tmp -> next = new;
		return l0;
	}
}



void print_list_triangle(list_triangle *l0){
	list_triangle *p = l0;
	while(p != NULL){
		printf("%.2f, %.2f, %.2f\n",p->side_a, p->side_b, p->side_c);
		p = p -> next;
	}
}

void free_list_triangle(list_triangle *l0){
	list_triangle *p = l0;
	while(p!= NULL){
		list_triangle *tmp = p -> next;
		free(p);
		p = tmp;
	}
	printf("Memorie freed\n");
}