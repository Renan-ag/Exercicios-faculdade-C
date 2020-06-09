#include <stdio.h>
#include <conio.h>

void main(){
	//variaveis
	char lojas[8][20];
	char produtos[4][20];
	float precos[8][4];
	//contadores
	int j,i;
	
	//recebe o nome das lojas
	for(j=0;j<8;j++)
	{
		scanf("%s",lojas[j]);
	}
	//recebe o nome dos produtos
	for(i=0;i<4;i++)
	{
		scanf("%s",produtos[i]);
	}
	//recebe o valor de cada produto em cada loja
	for(i=0;i<4;i++)
	{
		for(j=0;j<8;j++)
		{
			scanf("%f",precos[i][j])
		}
	}
	// exibe os precos abaixo de  120 
	for(i=0;i<4;i++)
	{
		for(j=0;j<8;j++)
		{
			if(precos[i][j] < 120)
			{
				printf("%s %s %.2f",produtos[i],lojas[j],precos[i][j]);
			}
		}
	}
}
