#include <stdio.h>

//https://www.thehuxley.com/problem/154?locale=pt_BR

int main(){
	
	   
   int i,n,total;
   total=0;
   scanf("%d",&n);
   char classificacao[n];
   scanf("%s", &classificacao);
   
   for(i=0 ; i<n ; i++){
	   
	   char aux;
	   aux = classificacao[i];
	   
	   if(aux == 'P'){
		   total = total + 2;
	   }
	   else if( aux == 'C'){
		   total = total + 2;
	   }
	   else if( aux == 'A'){
		   total= total+1;
	   }
	   
	   
   }

   printf("%d", total);

	return 0;
}