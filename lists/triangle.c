#include "triangle.h"

list_triangle *list_triangle_pushforward(list_triangle *l0, float a, float b, float c){
	list_triangle *new = (list_triangle*)malloc(sizeof(list_triangle));
	new -> side_a = a;
	new -> side_b = b;
	new -> side_c = c;
	new -> var_angle = triangle_angle(a,b,c);
	new -> terulet = triangle_Terulet(a, b, triangle_angle(a,b,c));
	new -> kerulet = triangle_Kerulet(a,b,c);
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
		printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n",p->side_a, p->side_b, p->side_c, p->var_angle, p->terulet, p->kerulet);
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
	printf("Memorie freed.\n");
}

void triangle_length(list_triangle *l0, u32 *len){
	list_triangle *p = l0;
	u32 l = 0;

	while(p != NULL){
		l++;
		p = p->next;
	}
	*len = l;
}

float triangle_Terulet(float a,float b, float a_angle){
	//float tmp = (180/PI)*a_angle;
	float m_a = b*sin(a_angle);
	return (a*m_a)/2;
}

float triangle_Kerulet(float a0, float a1, float a2){
	return a0+a1+a2;
}

/*
float triangle_Magassag(float b, float angle){
	float ang_rad = angle/(180/PI);
	printf("%f\n",ang_rad);
	return fabs(b*sin(ang_rad));
}
*/

float triangle_angle(float aa, float ba, float ca){
	float cosfi = (pow(aa,2)+pow(ba,2)-pow(ca,2))/(2*aa*ba);
	//cosfi = acos(cosfi)*(180/PI);
	cosfi = acos(cosfi);
	return cosfi;
}

/*
Radianra figyelni kell
cosfi = (a2+b2-c2)/2*ab
m_a = b*sinfi

rad = degre/(180/PI)

*/
















