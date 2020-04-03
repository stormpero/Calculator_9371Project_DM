#include "Allfunc.h"

Drob SUB_QQ_Q(Drob f, Drob s)
{
	if (s.numerator[0] == 0 && s.numerator.size() == 1) // если s == 0
		return f;
	s.numerator[0] = !s.numerator[0]; // иначе инвертируем знак второго
	return ADD_QQ_Q(f, s); // вызываем ф-ию сложения целых чисел, но прибавляем мы число с противоположным знаком
	// у меня красным подчеркивается, разберитесь.
}

