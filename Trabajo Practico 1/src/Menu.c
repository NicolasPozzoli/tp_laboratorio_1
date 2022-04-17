/*
 * Menu.c
 *
 *  Created on: 16 abr. 2022
 *      Author: nicop
 */
#include <stdio.h>
#include <stdlib.h>

void MenuDos(char* opcion1,char* opcion2)
{
	printf("\n %s \t\n",opcion1);
	printf("\n %s \t\n",opcion2);
}
float PedirNumero (char* pedir)
{
	float numero;
	printf("%s",pedir);
	scanf("%f",&numero);
	return numero;
}

void MostrarValor(char* mensaje,float resultado)
{
	printf("%s $%.2f\n",mensaje,resultado);
}
void MostrarMensaje(char* mensaje)
{
	printf("%s\n",mensaje);
}
void MostrarKilometros(char* mensaje,float resultado)
{
	printf("%s %.0f km\n",mensaje,resultado);
}

