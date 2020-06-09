#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define NLmax 100
#define NCmax 100
#define rmax 100

//Programa que cria uma matriz de numeros aleatorios menores que 100

void main(){
	//contadores
	int i,ki,kj,j;
	//variaveis 
	int r,NL,NC,Q[NLmax][NCmax],rdif;
	
	//Criação da matriz
	printf("Digite o numero de linhas: ");
	scanf("%d",&NL);
	printf("Digite o numero de Colunas: ");
	scanf("%d",&NC);
	
	srand(time(NULL));
	for (i=1;i<=NL;i++)
		for (j=1;j<=NC;j++){
			if ((i==1)&&(j==1)){
				r=rand()%rmax;
				Q[i][j]=r;
			}
			else{
				do{
					r=rand()%rmax;
					rdif=1;
					for (ki=1;ki<=NL;ki++)
						for (kj=1;kj<=NC;kj++){
							if (r==Q[ki][kj])
								rdif=0;
							if ((ki==i)&&(kj==j))
								exit;
						}
				}while (!rdif);
					Q[i][j]=r;
				}
		}
	printf("Lista de numeros aleatorios menor que %d \n",rmax);
	for (i=1;i<=NL;i++)
		for (j=1;j<=NC;j++){
			printf("%5d",Q[i][j]);
			if (j==NC)
				printf("\n");
			}
	getch();
}
