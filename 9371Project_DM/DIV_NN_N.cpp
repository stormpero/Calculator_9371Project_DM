
#include "Allfunc.h"

vector<int> DIV_NN_N(vector<int> first, vector<int> second)
{
	// Проверяем если в функцию передан пустой вектор
	if (first.empty() || second.empty())
		throw "Empty input";

	vector<int> result{ 0 }, k{ 0 };
	int i(0);
	// Пока первое число >= второго
	while (COM_NN_D(first, second) == 2 || !COM_NN_D(first, second))
	{
		// Вычисляем первую цифру деления first на second
		// умноженную на 10 в степени ее позиции
		vector<int> temp(DIV_NN_Dk(first, second));

		// Прибавляем это число к result
		result = ADD_NN_N(result, temp);

		// Теперь умножаем это число на делитель
		temp = MUL_NN_N(temp, second);

		// И отнимаем получившееся от делимого
		first = SUB_NN_N(first, temp);

		++i;
	}

	return result;
}