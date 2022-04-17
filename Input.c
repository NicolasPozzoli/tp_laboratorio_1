/*
 * Input.c
 *
 *  Created on: 5 abr. 2022
 *      Author: nicop
 */

#include <stdio.h>
#include <stdlib.h>

int getFloat(char mensaje[],int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado)
{
	int retorno=-1;
	int auxiliarFloat;
	int retornoScanf;


	if(mensaje!=NULL && minimo < maximo && mensajeError!=NULL && pNumeroIngresado!=NULL && reintentos>0)
	{
		printf("%s",mensaje);
		retornoScanf= scanf("%d",&auxiliarFloat);
		do {
			if(retornoScanf !=1 || auxiliarFloat > maximo || auxiliarFloat < minimo)
			{
				printf("%s",mensajeError);
				retornoScanf= scanf("%d",&auxiliarFloat);
				reintentos--;
			}
			else
			{
				reintentos=0;
				*pNumeroIngresado=auxiliarFloat;
				retorno=0;
			}
		}while(reintentos>0);
	}
	return retorno;
}
int getCharacter(char* pResultado, char* mensaje, char* mensajeError, char min, char max, int reintentos)
{
	int retorno = -1;
	char bufferChar; //Ingreso del user


	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0)
	{
		do
		{
			fflush(stdin);
			printf("%s",mensaje);
			scanf("%c",&bufferChar);
			if(bufferChar<=max && bufferChar>=min)
			{
				*pResultado = bufferChar;
				retorno=0;
				break; //dejo de reinitentar porque salio bien
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}
		while(reintentos >= 0);
		return retorno;
	}
	return retorno;
}


