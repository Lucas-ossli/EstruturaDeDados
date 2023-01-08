#include <stdlib.h>
#include <stdio.h>

//https://www.thehuxley.com/problem/3362?locale=pt_BR


int main(){
	
	int a,b;
	
	scanf("%d",&a);
	scanf("%d",&b);
	
	for(a ; a<=b ; a++){
		
		printf("\n%d",(a*a - 4*a + 5) );
		
	}
	
	return 0;
}