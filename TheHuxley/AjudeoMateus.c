//#include <stdlib.h>

#include <stdio.h>

//https://thehuxley.com/problem/3337?locale=pt_BR

int main(){
	
	int x0,x1,y0,y1,z0,z1,n,sobra;
	
	//x= palheta
 	//y = corda
 	//z = pedal
 	//minimo palheta
 	//minimo pedal
 	//max corda // se sobra incrementa nos outros;
 	
 	
 	scanf("%d",&n);
 	
 	scanf("%d %d %d %d %d %d",&x0, &x1, &y0, &y1, &z0, &z1);
 	sobra = n - (x0 + z0) ;
 	if( sobra >= y0 ){
		 
		 n = sobra;
		 if (sobra > y1){
			 
			 sobra = sobra - y1;
			 
			 if(sobra+x0 > x1){
				 sobra = x1 -(sobra+x0);
				 printf("S\n%d %d %d",x1, n, z0+sobra);
			 }else{
			 	printf("S\n%d %d %d",x0+sobra, n, z0);
			 	
			 }
			 
			 
			 
		 }else{
		 	 printf("S\n%d %d %d",x0, n, z0);
		 }
		 
	 }else{
		 printf("N");
	 }
 	
	return 0;
	
}