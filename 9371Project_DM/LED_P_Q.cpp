#include "Allfunc.h"

int LED_P_Q(vector<Drob> polynominal)
{
	if(polynominal.empty())
		throw "Empty input";
	else
		return polynominal.size(); // старшая степень многочлена равна размеру вектора 
}