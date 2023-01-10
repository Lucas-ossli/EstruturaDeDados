#include <stdio.h>
#include <stdlib.h>

struct sname {
	char *first;
	char midinit;
	char *last
};


//OU


typedef struct  {
	char *first;
	char midinit;
	char *last
} SNAME;

int main(){
	
	struct sname abc[10];
	//OU
	SNAME cde[10];
	
	char *texto;
	texto = "ccccccccccccccccccccccc";
	abc[0].first = "aaaaaaaaaaaaaaaaaaaaa";
	abc[1].first = "bbbbbbbbbbbbbbbbbbbbb";
	abc[2].first = texto;
	
	printf("\n\n%s", abc[0].first );
	printf("\n\n%s", abc[1].first );
	printf("\n\n%s", abc[2].first );
	
	texto = abc[0].first;
	
	printf("\n\n%s", texto);
	
	//Verificando se a passagem foi por ponteiro ou cópia de valor OBS:Foi cópia mesmo
	texto="fffffffffffff";
	printf("\n\n%s", abc[0].first );
	
    printf("\n\n");
	return 0;
}