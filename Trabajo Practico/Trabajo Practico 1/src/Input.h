/*
 * Input.h
 *
 *  Created on: 5 abr. 2022
 *      Author: nicop
 */

#ifndef INPUT_H_
#define INPUT_H_

int getFloat(char mensaje[],int reintentos, int minimo, int maximo, char mensajeError[], int *pNumeroIngresado);
int getCharacter(char* pResultado, char* mensaje, char* mensajeError, char min, char max, int reintentos);

#endif /* INPUT_H_ */
