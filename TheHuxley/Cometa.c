#include <stdio.h>

//https://www.thehuxley.com/problem/178?locale=pt_BR

int main(){
	
	
	int entrada,aux,referencia;
	
	referencia = 1986;
	scanf("%d", &entrada);
	//76
	
	while(entrada > referencia)
	{
		referencia = referencia+76;
	}
	
	referencia = referencia-76;
	
	if(entrada - referencia < 76){
		aux = 76 - (entrada - referencia) ;
		entrada = entrada + aux;
	}else{
		
		entrada = entrada + 76;
	}
	
	printf("%d\n",entrada);
	return 0;
}