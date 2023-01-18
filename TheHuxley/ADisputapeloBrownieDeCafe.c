#include <stdio.h>

//https://www.thehuxley.com/problem/4090?locale=pt_BR

//pedro cor, luiza fla

int main(){
	
	int pedro=0, luiza=0,fla=0,cor=0,i;
	float flaPontos, corPontos;
	char time[5];
	
	
	scanf("%c %c %c %c %c", &time[0], &time[1], &time[2], &time[3], &time[4]);
	
	//Vitorias
	for(i=0 ; i <5 ; i++){
		if(time[i] == 'c' ){
			cor++;
		}else{
			fla++;
		}
	}
	
	if(cor>fla){
	   pedro = pedro + 40;	 
	}else{
	   luiza = luiza + 40;	 
	}
	
	//Jogadores 
	scanf("%d %d", &fla, &cor);
	if(fla == 1 ){
		luiza = luiza + 20;
	}
	
	if(cor == 1){
		pedro = pedro + 20;
	}
	
	
	//gols de cada time
	scanf("%d %d", &fla, &cor);
	
	if(cor>fla){
	   pedro = pedro + 15;	 
	}else{
	   luiza = luiza + 15;	 
	}
	
	//Media de gols
	scanf("%f %f", &flaPontos, &corPontos);
	
	if(corPontos >= 2){
		pedro = pedro+10;
	}
	if(flaPontos >= 2){
		luiza = luiza + 10;
	}
	
	if(pedro > luiza){
		printf("Pedro tem mais chances de comer o brownie\nPontos:%d", pedro);
	}else{
		printf("Luiza tem mais chances de comer o brownie\nPontos:%d", luiza);
	}
	
	
	
	
	return 0;
}