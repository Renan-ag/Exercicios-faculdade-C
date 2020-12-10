#include<stdio.h>
#include<stdlib.h>

	int pilha[9];
	int contador = 0;
	

void main(){

	int menu = 0;
	system("cls");
	printf("	MENU\n\n");
	
	printf("1- Inserir valor novo.\n");
	printf("2- Exibe valores na pilha.\n");
	printf("3- Remove valor do topo da pilha.\n");
	
	printf("\n Digite aonde deseja ir: ");
	scanf("%i",&menu);
	
	switch(menu){
		case 1: 
			Inserir();
		break;
		case 2: 
			Exibe();
		break;
		case 3:
			Remover();
		break;
	}
	
}
 
void Inserir(){
	system("cls");
	printf("Informe o valor a ser inserido: ");
	scanf("%i",&pilha[contador]);
	
	contador++;
	main();
}

void Exibe(){
	system("cls");
	for(int i=0; i < contador; i++){
		printf("-> %i\n", pilha[i]);
	}
	getch();
	main();
}

void Remover(){
	system("cls");
	printf("Ultimo valor removido com sucesso!!");
	
	pilha[contador] = 0;
	contador--;
	
	getch();
	main();
}
