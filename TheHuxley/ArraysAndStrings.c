#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//https://www.hackerrank.com/challenges/frequency-of-digits-1/problem?isFullScreen=true


int main() {
    
    char texto[1000];
    scanf("%[^\n]%*c", texto);
    int ocorrencia[10][1];
    int i;
    
    for(i = 0 ; i<10 ; i++){
        ocorrencia[i][0] = 0;
    }
    
    for(i = 0 ; i < strlen(texto) ; i++){
		
        if((int)texto[i] >= 48 && (int)texto[i] <= 57 ){
            
			char aux = texto[i];
			ocorrencia[atoi(&aux)][0]++;
        }

    }
    
    for(i = 0 ; i<10 ; i++){
        printf("%d ",ocorrencia[i][0]);
    }
    
    return 0;
}
