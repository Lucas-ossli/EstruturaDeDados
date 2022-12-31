#include <stdio.h>
#include <stdlib.h>

//https://www.thehuxley.com/problem/550?locale=pt_BR

void sumMaxValue(int *soma, int x[], int y[], int z[]);

int main(){
	
	int a,b,c,seedX,seedY,seedZ,soma,i;
	int arrayX[10], arrayY[10],arrayZ[10];
	
	scanf("%d  %d  %d  %d  %d  %d",&a,&b,&c,&seedX,&seedY,&seedZ);
	
	arrayX[0] = seedX;
	arrayY[0] = seedY;
	arrayZ[0] = seedZ;
	
	for(i=1 ; i<10 ; i++ ){
		
		arrayX[i] = (arrayX[i-1] * b+c )%a;
		arrayY[i] = (arrayY[i-1] * a+b )%c;
		arrayZ[i] = (arrayZ[i-1] * c+a )%b;
		
	}
	
	sumMaxValue(&soma, arrayX, arrayY, arrayZ);
	soma = soma %((a/b)+c);
	printf("%d\n", soma);
	
	
	return 0;
}



void sumMaxValue(int *soma, int x[], int y[], int z[]){
	
	int i,maxX,maxY,maxZ;
	
	maxX=x[0];
	maxY=y[0];
	maxZ=z[0];
	
	for (i=1 ; i <10 ; i++){
		
		if(x[i] > maxX){
			maxX = x[i];
		}
		
		if(y[i] > maxY){
			maxY = y[i];
		}
		
		if(z[i] > maxZ){
			maxZ = z[i];
		}
		
		
	}
	
	*soma= maxX + maxY + maxZ;
	
}