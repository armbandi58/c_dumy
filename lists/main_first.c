#include "main.h"
#include "triangle.h"

int main(int argc, char *argv[]){

	list_triangle *asd0 = NULL;
	list_triangle *asd1 = NULL;

	u32 len;

	if(argc > 1){
		for(u8 i = 1; i < argc; i++){
			if(i == (argc-1)){
				printf("%s\n",argv[i]);
			}else{
				printf("%s -- ",argv[i]);
			}	
		}
	}

	float tmp0 = 13.4, tmp1 = 8.3, tmp2 = 9.6;

	for(u8 i = 0; i < 10; i++){
		asd0 = list_triangle_pushforward(asd0, tmp0, tmp1, tmp2);
		tmp0 = tmp0+1.4;
		tmp1 = tmp1+5.6;
		tmp2 = tmp2+2.3;
		//tmp_angle += 2.7;
	}

	printf("=== Print forward. ===\n");
	print_list_triangle(asd0);
/*
	tmp0 = 3.4;
	tmp1 = 5.8; 
	tmp2 = 0.2;

	for(u8 i = 10; i > 0; i--){
		asd1 = list_triangle_pushbackward(asd1, tmp0, tmp1, tmp2);
		tmp0 += 0.3;
		tmp1 += 2.3;
		tmp2 += 0.9;
	}

	printf("=== Print backward. ===\n");
	print_list_triangle(asd1);
*/	//printf("Na mehet\n");

	triangle_length(asd0, &len);
//	triangle_length(asd0, &len);
	printf("asd0: %d,", len);
//	triangle_length(asd1, &len);
//	printf("asd1: %d.\n", len);


	free_list_triangle(asd0);
//	free_list_triangle(asd1);

	//printf("%f\n",triangle_Magassag(8.3,32.4));
	
	return 0;
}