#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define COLUMN 235
#define ROWS 60
#define MAGICNUMBER 0
void createWave(int number, int xyz[ROWS][COLUMN]);
void printMatrix(int xyz[ROWS][COLUMN]);


void printMatrix(int xyz[ROWS][COLUMN]){
	int i,j;
	for(i = 0 ; i< ROWS ; i++ )  
	{
		for(j = 0 ; j< COLUMN ; j++ )
		{
			printf("%d", xyz[i][j]); 
			if(j==COLUMN-1){
				printf("\n");
			}
		}
	} 
	printf("\n"); 
	
}
void createWave(int number, int xyz[ROWS][COLUMN])
{
	int i;
	if(number ==COLUMN){
		number--;
	}
	for(i = ROWS-1 ; i >= 0 ; i-- )
	{
		//xyz[row][column]
		if(xyz[i][number] == MAGICNUMBER){
			xyz[i][number] = 1;
			return;
		}
	} 	
}

int main(){
	
    time_t t1; 
    srand((unsigned) time(&t1)); 
	
	int x,i,j,y;
	int matrix[ROWS][COLUMN];
	for(i = 0 ; i< ROWS ; i++ )  
	{
		for(j = 0 ; j< COLUMN ; j++ )
		{
			matrix[i][j] = MAGICNUMBER; 
		}
	} 	
	system("cls");
	y=0;
	x=0;
	for(i = 0 ; i< (ROWS*COLUMN)/5 ; i++ )  
	{
		for(j = 0 ; j< 10 ; j++ )
		{
			x = rand() % COLUMN/10;
			y = y + x;
			if(j==9)
			{
			  createWave(y, matrix);
			  y=0;
			}
		}
	} 	

	printMatrix(matrix);
	
	return 0;
	
}