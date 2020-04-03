#include "Allfunc.h"

vector<Drob> MUL_PQ_P(vector<Drob> polynomial, Drob fraction)
{
	for (int i = polynomial.size() - 1; i >= 0; i--) // Цикл вычитания
		polynomial[i] = MUL_QQ_Q(polynomial[i], fraction);
	return (polynomial);
}