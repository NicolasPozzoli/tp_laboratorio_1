/*
 * Calculos.c
 *
 *  Created on: 16 abr. 2022
 *      Author: nicop
 */


float CalcularDescuento(float precio, float porcentaje)
{
	float descuentoDebitoAerolineas;
	descuentoDebitoAerolineas=precio/100*porcentaje;
	return descuentoDebitoAerolineas;
}
float CalcularBtc (float precio)
{
	float valorBtc;

	valorBtc=precio/4606954.55;
	return valorBtc;
}
float CalcularPrecioPorKm (float precio, float km)
{
	float precioPorKm;
	precioPorKm=precio/km;
	return precioPorKm;
}
