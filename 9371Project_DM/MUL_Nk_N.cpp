#include "Allfunc.h"

vector <int>MUL_Nk_N(vector<int> N, vector<int> k)
{
	// Проверяем если в функцию передан пустой вектор
	if (N.empty() || k.empty())
		throw "Empty input";
	//Проверяем чтобы вводимые данные были натуральными числами
	//До тех пор пока i не равно k прибавлять в конец числа 0, что эквивалентно умножению на 10
	for (vector <int>i(0); i != k; i = ADD_1N_N(i))
		N.push_back(0);
	return N;
}