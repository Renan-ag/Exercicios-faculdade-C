#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define Nmax 5
int opcao,op_ord;
int i=0;
char temp;
FILE *arq;


int somaIdades = 0; 
int Quant = 0;
float Media = 0;

typedef struct{
	char nome[200];
	char unidade_hospitalar[200];
	char situacao[100];
	int idade;
	int numero_quarto;
}paciente_info;

paciente_info paciente, arq_pacientes;



void MenuPrincipal(){
	system("cls");
	printf("----	MENU PRINCIPAL	---- \n");
	printf("\n1 - Entrada de Dados\n");
	printf("\n2 - Saida de Dados\n");
	printf("\n3 - Ordenação\n");
	printf("\n4 - Salvar informação no arquivo\n");
	printf("\n5 - Ler informações no arquivo\n");
	printf("\n6 - Sair\n");
	printf("\nEscolha uma das opções: ");
	scanf("%i",&opcao);
}

void Entrada(){
	system("cls");
	printf("----	ENTRADA	----\n");
	
	printf("Informe o nome do paciente:");
	scanf("%c",&temp);
	scanf("%[^\n]",paciente.nome);
	printf("\n");
	
	printf("Informe a idade do paciente:");
	scanf("%i",&paciente.idade);
	printf("\n");
	
	printf("Informe a unidade hospitalar (estado/bairro):");
	scanf("%c",&temp);
	scanf("%[^\n]",paciente.unidade_hospitalar);
	printf("\n");
	
	printf("Informe o numero do quarto do paciente:");
	scanf("%i",&paciente.numero_quarto);
	printf("\n");
	
	printf("Informe a situação do paciente:");
	scanf("%c",&temp);
	scanf("%[^\n]",paciente.situacao);
	printf("\n");
	
	system("cls");
	printf("Cadastro realizado com sucesso!");
	getch();
}

void Saida(){
	system("cls");
	printf("----  SAIDA DE DADOS  ----");
	if(paciente.idade != 0){
		printf("\nNome: %s\n",paciente.nome);
		printf("Idade: %i\n",paciente.idade);
		printf("Unidade: %s\n",paciente.unidade_hospitalar);
		printf("Quarto: %i\n",paciente.numero_quarto);
		printf("situação: %s\n",paciente.situacao);
	}
	else{ 
		printf("\nNão existem dados a serem Exibidos !");
	}
	getch();
	MenuPrincipal();
}

void Salvar_Arquivo(){
	system("cls");
	if(paciente.idade != 0){
		arq = fopen("func.dat","ab");
		fwrite(&paciente, sizeof(paciente_info),1,arq);
		fclose(arq);
		printf("Dados Salvos!");
	}else{
		printf("Não existe dados a serem salvos!");
	}
	
	getch();
	MenuPrincipal();
}

void Ler_Arquivo(){
	system("cls");
	arq = fopen("func.dat","rb");//leitura binário
    	
	while(fread(&arq_pacientes, sizeof(paciente_info),1,arq) != NULL){
		printf("Nome: %s\n", arq_pacientes.nome);
		printf("Idade: %i\n", arq_pacientes.idade);
		printf("Unidade Hospitalar: %s\n", arq_pacientes.unidade_hospitalar);
		printf("Numero do quarto:  %i\n", arq_pacientes.numero_quarto);
		printf("Situação do paciente: %s\n", arq_pacientes.situacao);
		printf("\n");
	}
    	
	fclose(arq);  
	getch();
	MenuPrincipal();
}

void Media_idade(){
	system("cls");
	arq = fopen("func.dat","rb");//leitura binário
	while(fread(&arq_pacientes, sizeof(paciente_info),1,arq) != NULL){
		somaIdades += arq_pacientes.idade;
		Quant++;
	}
	fclose(arq);
	Media = (somaIdades / Quant); 
	printf("A media das idades dos pacientes do banco de dados é de: %.2f",Media);
	printf("\n\nAperte alguma tecla para retornar ao menu...");
	getch();
	MenuPrincipal();
}

void Pesquisa_Nome(){
	system("cls");
	char nome_pesquisa[200];
	int achou = 0;
	printf("----	PESQUISA ATRAVÉS DO NOME	----\n");
	printf("Insira o nome a ser pesquisado: ");
	scanf("%c",&temp);
	scanf("%[^\n]",nome_pesquisa);
	arq = fopen("func.dat","rb");
	while(fread(&arq_pacientes, sizeof(paciente_info),1,arq) != NULL){
		if(strcmp(nome_pesquisa,arq_pacientes.nome) == 0){
			printf("Nome: %s\n", arq_pacientes.nome);
			printf("Idade: %i\n", arq_pacientes.idade);
			printf("Unidade Hospitalar: %s\n", arq_pacientes.unidade_hospitalar);
			printf("Numero do quarto:  %i\n", arq_pacientes.numero_quarto);
			printf("Situação do paciente: %s\n", arq_pacientes.situacao);
			printf("\n");
			achou = 1;
		}
	}
	
	if(!achou){
		printf("\nNão foi possivel encontrar nenhum paciente com este nome.\n\n");
	}
	
	fclose(arq);
	printf("Digite algo para retornar ao menu...");
	getch();
	MenuPrincipal();
}

void Ordenacao(){
	switch(op_ord){
		case 1:
			Media_idade();
		break;
		case 2:
			Pesquisa_Nome();
		break;
		case 5:
			MenuPrincipal();
		break;
	}
}

void Menu_Ordenacao(){
	system("cls");
	printf("----	MENU ORDENAÇÃO	---- \n");
	printf("\n1 - A Media das idades dos pacientes registrados\n");
	printf("\n2 - Pesquisar algum paciente no banco de dados através do nome\n");
	printf("\n5 - Sair\n");
	printf("\nEscolha uma das opções: ");
	scanf("%i",&op_ord);
	Ordenacao();
}

void main(){
	int fim = 0;
	setlocale(LC_ALL, "Portuguese");
	do{
		MenuPrincipal();
		switch(opcao){
			case 1:
				Entrada();
			break;
			case 2:
				Saida();
			break;
			case 3:
				Menu_Ordenacao();
			break;
			case 4:
				Salvar_Arquivo();
			break;
			case 5:
				Ler_Arquivo();
			break;
			case 6: 
				fim = 1;
			break;
			default: 
			printf("Opção  invalida\n");
			break;
			getch();
		}	
	}while(!fim);
	system("cls");
	printf("----	Fim Do Programa	----");
}



