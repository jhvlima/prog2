#include <stdio.h>

typedef struct {
	int x, y, z;
} tPonto;


int main(){
	tPonto ponto = {1, 2, 3};
	
	tPonto *p = &ponto;
	
	printf("(%d,%d,%d)\n", (*p).x, (*p).y, (*p).z);
	printf("(%d,%d,%d)\n", p->x, p->y, p->z);
	
    return 0;
}

