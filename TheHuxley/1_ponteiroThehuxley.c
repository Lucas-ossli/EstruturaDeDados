#include <stdio.h>
#include <stdlib.h>

//https://www.thehuxley.com/problem/235?locale=pt_BR

int main(){
	
	int vetor[15],impar[6],par[6],i,j;
	
	for(i = 0 ; i<6 ; i++){
	impar[i] = 0;
	par[i] = 0;
	}
	//vetor = (int *)malloc(15 * sizeof(int));
	
	
	
	for (i=0 ; i<15 ; i++){
		//scanf("%d", &vetor[i]);
     	vetor[i] = rand()%87;
     	
     	if(vetor[i]%2 > 0){
			impar[impar[5]] = vetor[i];
			
			impar[5]++; 
			 
		}else{
			par[par[5]] = vetor[i];
			
			par[5]++; 
		}
     	
     	if(par[5]==5){
			 
			for(j=0 ; j < 5 ; j++){
				
				if(par[j] > 0){
					printf("\npar[%d] = %d",j,par[j]);
					par[j] = 0;
				}
			} 
			 par[5] = 0;
		}
		if(impar[5] == 5){
			for(j=0 ; j < 5 ; j++){
				
				if(impar[j] > 0){
					printf("\nimpar[%d] = %d",j,impar[j]);
					impar[j] = 0;
				}
			} 
			impar[5] = 0;
		}
     	
     	
	}
	
	
	
	if(impar[5]>0){
		
		for(i = 0 ;i < impar[5] ; i++){
			
			printf("\nimpar[%d] = %d",i,impar[i]);
		}
	}
	
	if(par[5]>0){
		
		for(i = 0 ;i < par[5] ; i++){
			
			printf("\npar[%d] = %d",i,par[i]);
		}
	}
	
	
	return 0;
}