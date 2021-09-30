#ifndef KOMPLEX_H_
#define KOMPLEX_H_

#include "main.h"

typedef struct comp_list{
	float var_Re;
	float var_Im;
	float var_abs;
	float var_degree;
	struct comp_list *next;
}comp_list;

comp_list *push_backward_complex(comp_list *lc, float Re, float Im);
comp_list *push_forward_complex(comp_list *lc, float Re, float Im);
void comp_list_print(comp_list *lc);
void comp_list_freelist(comp_list *lc);




#endif /* KOMPLEX_H_ */