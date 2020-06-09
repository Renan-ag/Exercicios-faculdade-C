#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define NLmax 100
#define NCmax 100
#define rmax 100

void main(){
	//contadores
	int i,ki,kj,j;
	//variaveis 
	int r,NL,NC,NL2,NC2,M[NLmax][NCmax],N[NLmax][NCmax],rdif,quantNum = 0;
	int maior[7]= {0, 0, 0, 0, 0, 0,0};
	
	NL = 4; 
	NC = 6;
	
	NL2 = 6; 
	NC2 = 4;
	//Seed(pseudorandom)
	srand(time(NULL));
	
	//geração de matriz com numeros aleatorios
	//Matriz M
	for (i=1;i<=NL;i++)
		for (j=1;j<=NC;j++){
			if ((i==1)&&(j==1)){
				r=rand()%rmax;
				M[i][j]=r;
			}
			else{
				do{
					r=rand()%rmax;
					rdif=1;
					for (ki=1;ki<=NL;ki++)
						for (kj=1;kj<=NC;kj++){
							if (r==M[ki][kj])
								rdif=0;
							if ((ki==i)&&(kj==j))
								exit;
						}
				}while (!rdif);
					M[i][j]=r;
				}
		}
	// MATRIZ N
	for (i=1;i<=NL2;i++)
		for (j=1;j<=NC2;j++){
			if ((i==1)&&(j==1)){
				r=rand()%rmax;
				N[i][j]=r;
			}
			else{
				do{
					r=rand()%rmax;
					rdif=1;
					for (ki=1;ki<=NL2;ki++)
						for (kj=1;kj<=NC2;kj++){
							if (r==N[ki][kj])
								rdif=0;
							if ((ki==i)&&(kj==j))
								exit;
						}
				}while (!rdif);
					N[i][j]=r;
				}
		}		

	//titulo 
	printf("Soma a linha M com a coluna N");
	printf("\n\n");	
	//Titulo matriz M
	printf("Matriz M");
	printf("\n\n");	
	//exibe Matriz M
	for (i=1;i<=NL;i++)
		for (j=1;j<=NC;j++){
			printf("%5d",M[i][j]);
			if (j==NC)
				printf("\n");
			}
	//Titulo matriz N
	printf("\n");
	printf("Matriz N");
	printf("\n\n");
	//exibe a matriz N
	for (i=1;i<=NL2;i++)
		for (j=1;j<=NC2;j++){
			printf("%5d",N[i][j]);
			if (j==NC2)
				printf("\n");
			}
	/////////////////////////////////
	//Soma e exibe a linha M com a coluna N
	printf("\n");
	printf("A soma da linha M com a coluna N -> ");
	for (i=1;i<=NC2;i++)
		for (j=1;j<=NC;j++){
			printf("%i ",M[i][j] + N[j][i]);
		}
	//Para o programa
	printf("\n\n");
	system("PAUSE");
}
