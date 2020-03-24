#include "Allfunc.h"

Drob DIV_QQ_Q(Drob a, Drob b) // Ермольев Максим Викторович
{
	Drob result;
	result.numerator = MUL_ZZ_Z(a.numerator, b.denominator); // Умножим числитель дроби a на знаменатель дроби b
	result.denominator = MUL_ZZ_Z(a.denominator, b.numerator); // Аналогично для знаменателя
	result = RED_Q_Q(result); // Выполним сокращение дроби
	return(result);
}
