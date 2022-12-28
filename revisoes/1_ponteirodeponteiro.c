#include <stdio.h>

void main(){
	
	int x =5;
	int *p1 = &x;
	int **p2 = &p1;
	
	printf("x:%p \np1:%p \np1:%p \np2:%p \np2:%p", &x, &p1, p1, p2, **p2);
	
	
	
	
	return 0 ;
}