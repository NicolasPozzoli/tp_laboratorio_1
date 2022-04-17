/*
 ============================================================================
 Name        : Trabajo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "Calculos.h"
#include "Menu.h"

int main(void) {
	setbuf (stdout ,NULL);
	int opcion;
	char opcionC;
	float precioAerolineas;
	float precioLatam;
	int kilometros;
	float descuentoAerolineas;
	float debitoAerolineas;
	float interesAerolineas;
	float creditoAerolineas;
	float precioBtcAerolineas;
	float precioPorKmAerolineas;
	float diferenciaPrecios;
	float descuentoLatam;
	float debitoLatam;
	float interesLatam;
	float creditoLatam;
	float precioBtcLatam;
	float precioPorKmLatam;
	precioAerolineas=0;
	precioLatam=0;

	do
	{
	if(getFloat("\n    MENU DE OPCIONES\n"									//MENU
				"-----------------------\n"
				"\n1.--> Ingresar km.\n\n"
				"2.--> Ingresar Precio de Vuelos.\n\n"
				"3.--> Calcular todos los costos.\n\n"
				"4.--> Informar Resultados.\n\n"
				"5.--> Carga forzada de datos.\n\n"
				"6.--> Salir.\n\n"
				"Escoja una opcion: \n"
			, 3, 1, 6, "Opcion no valida, Intente nuevamente\n", &opcion)==0)
		{
			switch(opcion)
			{
				case 1:
					if(getFloat("Ingrese Kilometros: ", 3, 1, 50000, "Error. Intente nuevamente: ", &kilometros)==0)
					{
						MostrarKilometros("\nKilometros: ", kilometros);
					}
							//INGRESO KM

					break;
				case 2:
					if(getCharacter(&opcionC, "y.--> Precio vuelo Aerolineas\n"
												"z.--> Precio vuelo LATAM\n", "Opcion no valida, Intente nuevamente\n", 'y', 'z', 3)==0)
					{

						switch(opcionC)
						{
						case 'y':
							precioAerolineas=PedirNumero("Ingrese precio: ");
							MostrarValor("\nPrecio Aerolineas: ", precioAerolineas);
							break;
						case 'z':
							precioLatam=PedirNumero("Ingrese precio: ");
							MostrarValor("\nPrecio Latam: ", precioLatam);
							MostrarValor("\nPrecio Aerolineas: ", precioAerolineas);
							break;
						}
					}

					break;
				case 3:					   														//CALCULOS

						descuentoAerolineas = CalcularDescuento(precioAerolineas, 10);
						debitoAerolineas = precioAerolineas-descuentoAerolineas;
						interesAerolineas = CalcularDescuento(precioAerolineas, 25);
						creditoAerolineas = precioAerolineas+interesAerolineas;
						precioBtcAerolineas = CalcularBtc(precioAerolineas);
						precioPorKmAerolineas = CalcularPrecioPorKm (precioAerolineas,kilometros);


						descuentoLatam = CalcularDescuento(precioLatam, 10);
						debitoLatam = precioLatam-descuentoLatam;
						interesLatam = CalcularDescuento(precioLatam, 25);
						creditoLatam = precioLatam+interesLatam;
						precioBtcLatam = CalcularBtc(precioLatam);
						precioPorKmLatam = CalcularPrecioPorKm (precioLatam,kilometros);


					if(precioAerolineas>=precioLatam)
					{
						diferenciaPrecios=precioAerolineas-precioLatam;
					}
					else
					{
						diferenciaPrecios=precioLatam-precioAerolineas;
					}
					break;
				case 4:
					MostrarKilometros("Kilometros: ", kilometros);
					MostrarValor("\n Precio LATAM: ", precioLatam);
					if(precioLatam!=0 && precioLatam>0)
					{
						MostrarValor("\n Precio con tarjeta de débito: ", debitoLatam);
						MostrarValor(" Precio con tarjeta de credito: ", creditoLatam);
						printf(" Precio pagando con Bitcoin: %f BTC\n",precioBtcLatam); 	//USE PRINTF PARA QUE MUESTRE MAS DECIMALES
						MostrarValor(" Precio unitario por km: ", precioPorKmLatam);
					}
					else
					{
						MostrarMensaje("No se ingreso precio LATAM\n");
					}
					MostrarValor("\n Precio Aerolineas: ", precioAerolineas);
					if(precioAerolineas!=0 && precioAerolineas>0)
					{
						MostrarValor("\n Precio con tarjeta de débito: ", debitoAerolineas);
						MostrarValor(" Precio con tarjeta de credito: ", creditoAerolineas);
						printf(" Precio pagando con Bitcoin: %f BTC\n",precioBtcAerolineas);
						MostrarValor(" Precio unitario por km: ", precioPorKmAerolineas);

						MostrarValor("\n Diferencia de precios: ", diferenciaPrecios);
					}
					else
					{
						MostrarMensaje("No se ingreso precio Aerolineas\n");
					}
					break;
				case 5:
					kilometros=7090;
					precioAerolineas=162965;
					precioLatam=159339;
					descuentoAerolineas = CalcularDescuento(precioAerolineas, 10);
					debitoAerolineas = precioAerolineas-descuentoAerolineas;
					interesAerolineas = CalcularDescuento(precioAerolineas, 25);
					creditoAerolineas = precioAerolineas+interesAerolineas;
					precioBtcAerolineas = CalcularBtc(precioAerolineas);
					precioPorKmAerolineas = CalcularPrecioPorKm (precioAerolineas,kilometros);
					diferenciaPrecios=precioAerolineas-precioLatam;

					descuentoLatam = CalcularDescuento(precioLatam, 10);
					debitoLatam = precioLatam-descuentoLatam;
					interesLatam = CalcularDescuento(precioLatam, 25);
					creditoLatam = precioLatam+interesLatam;
					precioBtcLatam = CalcularBtc(precioLatam);
					precioPorKmLatam = CalcularPrecioPorKm (precioLatam,kilometros);

					MostrarKilometros("Kilometros: ", kilometros);
					MostrarValor("\n Precio Aerolineas: ", precioAerolineas);
					MostrarValor("\n Precio con tarjeta de débito: ", debitoAerolineas);
					MostrarValor(" Precio con tarjeta de credito: ", creditoAerolineas);
					printf(" Precio pagando con Bitcoin: %f BTC\n",precioBtcAerolineas);
					MostrarValor(" Precio unitario por km: ", precioPorKmAerolineas);
					MostrarValor("\n Precio LATAM: ", precioLatam);
					MostrarValor("\n Precio con tarjeta de débito: ", debitoLatam);
					MostrarValor(" Precio con tarjeta de credito: ", creditoLatam);
					printf(" Precio pagando con Bitcoin: %f BTC\n",precioBtcLatam); 	//USE PRINTF PARA QUE MUESTRE MAS DECIMALES
					MostrarValor(" Precio unitario por km: ", precioPorKmLatam);
					MostrarValor("\n Diferencia de precios: ", diferenciaPrecios);
					break;
			}
		}
	}while(opcion!=6);

	printf("Programa Finalizado");

	return EXIT_SUCCESS;
}


