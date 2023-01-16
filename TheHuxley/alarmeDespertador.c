#include <stdio.h>

//https://www.thehuxley.com/problem/661?locale=pt_BR

int main(){

    int h1,m1,h2,m2,i,inicio,termino;

    scanf("%d %d %d %d", &h1, &m1, &h2, &m2 );
    while( h1+m1+h2+m2 != 0 ){
        //inicio = 0;
        inicio = (h1*60)+m1;
        //termino = 0;
        termino = (h2*60)+m2;

        if( h1 < h2 || h1 == h2){
        	
        	if(h1 == h2){
            	if(m1 < m2 ){
    				printf("\n%d", termino - inicio);
    			}else{
					termino = termino + (24*60);
            		printf("\n%d", termino - inicio);
				}
        	}else{
				printf("\n%d", termino - inicio);
			}
           
        }else{
            termino = termino + (24*60);
            printf("\n%d", termino - inicio);
        }

        scanf("%d %d %d %d", &h1, &m1, &h2, &m2 );

    }

    return 0;
}