#include "Allfunc.h"

Drob MUL_QQ_Q(Drob num1, Drob num2) // умножение дробей
{
	Drob result;	//структура дробей
	result.numerator = MUL_ZZ_Z(num1.numerator, num2.numerator); //присваемваем произведения числителей
	result.denominator = MUL_ZZ_Z(num1.numerator, num2.numerator);  // присваемваем произведение знаменателей
	result = RED_Q_Q(result);
	return result; //возвращаем значение структуры
}
