//Blibliotecas
#include <stdio.h>
#include <conio.h>
//Metodo que calcula a media de V1 e V2
float CalMedia(float V1,float V2)
{
	//Variavel do metodo
	float media;
	//A var. media recebe o resultado do calculo
	media = (V1+V2)/2;
	//Retorna a var. media
	return (media);
}

void main()
{	
	//variaveis
	float Va1,Va2,Media;
	//titulo do programa
	printf("Programa para calculo de media:");
	//Pede para informar o 1° valor e o passa para a var. Va1 
	printf("\nInforme o primeiro valor: ");
	scanf("%f",&Va1);
	//Pede para informar o 2° valor e o passa para a var. Va2 
	printf("Informe o segundo valor: ");
	scanf("%f",&Va2);
	//Chama o metodo CalMedia e passa os valores Va1 e Va2 e a var. Media recebe o retorno deste metodo 
	Media = CalMedia(Va1,Va2);
	//Informa o usuario sua Media
	printf("\nSua media foi: %f",Media);
	//Para o programa até o usuario pressionar alguma tecla
	getch();
}

