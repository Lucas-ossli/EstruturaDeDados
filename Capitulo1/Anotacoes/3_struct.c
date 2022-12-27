#include <stdio.h>
#include <stdlib.h>


int main(){
	
	struct FUNCIONARIO{
		
		int codigo;
		char *nome;
		char sexo;
		float salario;
	};
	
	
	struct FUNCIONARIO func;
	func.codigo = 01;
	func.nome = "Mayume";
	func.sexo = 'F';
	func.salario = 2500.57;
	
	
	
	printf("\nsizeof Funcionario codigo: %d", sizeof(func.codigo));
	printf("\nsizeof Funcionario nome: %d", sizeof(func.nome));
	printf("\nsizeof Funcionario sexo: %d", sizeof(func.sexo));
	printf("\nsizeof Funcionario salario: %d", sizeof(func.salario));
	
	
	printf("\nsizeof Funcionario: %d", sizeof(func));
	printf("\nNome: %s \t|Salario: %.2f",func.nome,func.salario);
	
	return 0;
}