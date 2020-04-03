#include "Allfunc.h"

Drob LED_P_Q(vector <Drob> polynominal)
{
	if (polynominal.empty())
		throw "Wrong input";
	return polynominal[0]; //возвращаем самую первую структуру
}


