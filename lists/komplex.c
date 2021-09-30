#include "komplex.h"

comp_list *push_forward_complex(comp_list *lc, float Re, float Im){
	comp_list *new_p = (comp_list*)malloc(sizeof(comp_list));

	new_p -> var_Re = Re;
	new_p -> var_Im = Im;
	new_p -> next = lc;

	return new_p;
}

comp_list *push_backward_complex(comp_list *lc, float Re, float Im){
	comp_list *new_forward = (comp_list*)malloc(sizeof(comp_list));

	new_forward -> var_Re = Re;
	new_forward -> var_Im = Im;
	new_forward -> next = NULL;

	if(lc == NULL){
		return new_forward;
	}else{
		comp_list *tmp = lc;
		while(tmp -> next != NULL){
			tmp = tmp->next;
		}
		tmp -> next = new_forward;
		return lc;
	}
}

void comp_list_print(comp_list *lc){
	comp_list *tmp = lc;

	while(tmp != NULL){
		printf("%.2f\t-\t%.2f\n", tmp -> var_Re, tmp -> var_Im);
		tmp = tmp->next;
	}
}

void comp_list_freelist(comp_list *lc){
	comp_list *tmp = lc;

	while(tmp != NULL){
		comp_list *p = tmp -> next;
		free(tmp);
		tmp = p;
	}
	printf("Memorie freed(complex).\n");
}
