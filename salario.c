#include <stdio.h>
#include <string.h>

// Programa que mostra uma lista de nomes e salarios e informa media salarial

void main()
{
	//variaveis
	char nome[20][30];
	float salario[20],media,SalarioTotal=0;	
	//contadores
	int i;
	
	
	for(i=0;i<20;i++){
		//scanf("%s",nome[i]);
		strcpy(nome[i],"Vanderlei");	//nome[i] = "Vanderlei";
		//scanf("%f",salario[i]);
		salario[i] = 300 + i * 10;
		SalarioTotal += salario[i]; // SalarioTotal = SalarioTotal + salario[i]; 
	}
	
	media = SalarioTotal/20;

	printf("  Nome	   |    Num.  | Salario\n");
	
	for(i = 0; i < 20; i++){
		printf("%s	%i	%.2f\n",nome[i],i,salario[i]);

	}
}
