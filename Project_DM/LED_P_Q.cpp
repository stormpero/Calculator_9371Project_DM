#include "Allfunc.h"

Drob LED_P_Q(vector <Drob> polynominal)
{
	if (polynominal.empty())
		throw "Wrong input";
	return polynominal[polynominal.size()-1]; //возвращаем самую первую структуру
}


