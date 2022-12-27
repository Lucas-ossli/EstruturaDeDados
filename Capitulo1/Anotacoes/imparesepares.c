#include <stdio.h>
#include <stdlib.h>

//https://thehuxley.com/problem/235?locale=pt_BR

int main(){
    int par[6],impar[6],i,input[15];
    //printf("sucesso");
	zerarvetor(&par);
	zerarvetor(&impar);

    for(i=0 ; i< 15 ; i++){
        scanf("%d", &input[i]);
        //input[i] = rand()%88;
        
    }
    
    for(i=0 ; i <15;i++){
    	
		if(input[i]%2 != 0){
	        impar[impar[5]] = input[i];
	        impar[5]++;
	    }else{
	        par[par[5]] = input[i];
	        par[5]++;
	    }
	    
	    if(par[5]==5){
	        imprimirPar(&par);
	    }
	    if(impar[5]==5){
	        imprimirimpar(&impar);
	    }
    
	}
    
	imprimirimpar(&impar);
	imprimirPar(&par);

	
    return 0;
}

void imprimirPar(int *vetor){
   int j;
    for( j=0; j<5 ; j++){
        if(vetor[j] != 0){
        printf("\npar[%d] = %d",j, vetor[j]);
        vetor[j] = 0;
        }else{
            j=6;
        }
    }
    vetor[5] = 0;
}

void imprimirimpar(int *vetor){
    int j;
    for(j=0; j<5 ; j++){
        if(vetor[j] != 0){
        printf("\nimpar[%d] = %d",j, vetor[j]);
        vetor[j] = 0;
        }else{
            j=6;
        }
    }
    vetor[5] = 0;
}

void zerarvetor(int *vetor){
    int i;
    for(i = 0 ; i<6 ; i++){
       vetor[i] = 0;
    }
}
