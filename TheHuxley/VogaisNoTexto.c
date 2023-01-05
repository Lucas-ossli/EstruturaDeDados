#include <stdio.h>
#include <stdlib.h>

//https://www.thehuxley.com/problem/803?locale=pt_BR

int main(){
	
	
	
	//printf("%c %c", (char)65, (char)97);
	int i,j;
	int vogais[2][5];
	char texto[256];
	
	scanf("%[^\n]%*c", texto);
	
	vogais[0][0] = (int)'a';
	vogais[0][1] = (int)'e';
	vogais[0][2] = (int)'i';
	vogais[0][3] = (int)'o';
	vogais[0][4] = (int)'u';
	

	
	for(i = 0 ; i < 5 ; i++){
		
		vogais[1][i] = 0;
		for(j = 0 ; j<256 && texto[j] != '\0' ; j++){
			
			int aux =  (vogais[0][i])-32;
			if((int)texto[j] == vogais[0][i] || (int)texto[j] == aux ){
				vogais[1][i]++;
			}
				
		}
		
	}
	
	printf("a %d\ne %d\ni %d\no %d\nu %d", vogais[1][0], vogais[1][1] ,vogais[1][2] ,vogais[1][3], vogais[1][4]);
	
	
	
	return 0;
}