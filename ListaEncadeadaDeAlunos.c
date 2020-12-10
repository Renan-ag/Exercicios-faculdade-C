#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno aluno;

struct Aluno{
	char nome[70];
	int idade;
	char genero;
	aluno *proximo;
};

char temp;
int j=0;

aluno* Inseri_infos(aluno* aluno){
	printf("Informe o nome do aluno: ");
	if(j!=0){
		scanf("%c",&temp);
	}
	scanf("%[^\n]",aluno->nome);
	printf("\n");
	printf("Informe a sua idade: ");
	scanf("%i",&aluno->idade);
	printf("\n");
	printf("Informe seu genero [M] para masculino ou [F] para feminino: ");
	scanf("%c",&temp);
	scanf("%c",&aluno->genero);	
}

void Exibe_lista(aluno* prox, aluno* inicio){
	
	prox = inicio;
	
	while(prox != NULL){
		
		printf("Nome: %s\n", prox->nome);
		printf("Idade: %i\n",prox->idade);
		printf("Genero: %c\n", prox->genero);
		printf("\n");
		
		prox = prox->proximo;			
	}
	
}

void main(){
	aluno* ponto_inicial;
	aluno* proximo_ponto;
	int resp;

	ponto_inicial = (aluno*)malloc(sizeof(aluno));
	
	if(ponto_inicial == NULL){
		exit(1);
	}
	
	proximo_ponto = ponto_inicial;
	
	while(1){
		
		Inseri_infos(proximo_ponto);
		system("cls");
		printf("Deseja continuar? <1> Sim <outro valor> Nao: ");
		scanf("%i",&resp);
		
		if(resp == 1){
			j++;
			proximo_ponto->proximo = (aluno*)malloc(sizeof(aluno));
			proximo_ponto = proximo_ponto->proximo;
			continue;
		} 
		else{
			proximo_ponto->proximo = NULL;	
			break;
		}
	}
	
	system("cls");

	Exibe_lista(proximo_ponto, ponto_inicial);
	
	system("pause");
}
