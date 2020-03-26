#include "Allfunc.h"

vector<int> ADD_ZZ_Z(vector<int> num1, vector<int> num2) // Астахов Михаил
{
	vector<int> result; // Перменнная, которая хранит результат сложения
	if ((POZ_Z_D(num1) == 0 && POZ_Z_D(num2) == 0) || ((COM_NN_D(ABS_Z_N(num1), ABS_Z_N(num2)) == 0) && (POZ_Z_D(num1) != POZ_Z_D(num2)))) //  Если оба чисела равны 0 или их модули раны, но числа разного знака, то их сумма 0
		result.push_back(0);
	else
	{
		if (POZ_Z_D(num1) == POZ_Z_D(num2))//Проверим равны ли знаки чисел, если да, то суммируем
		{
			result = ADD_NN_N(ABS_Z_N(num1), ABS_Z_N(num2));
				if (POZ_Z_D(num1) == 1)//если чила были отрицательны меняем знак (т.к. числа одного знака достаточно проверить одно)
					result = MUL_ZM_Z(result); // Умножим число на -1
		}
		else
		{
			if (COM_NN_D(ABS_Z_N(num1), ABS_Z_N(num2)) == 2)//проверяем какое из чисел больше
			{
				if (POZ_Z_D(num1) == 1)
				{
					result = ADD_NN_N(ABS_Z_N(num1), ABS_Z_N(num2));//ecли первое отрицательное,то вычитаем из большего числа меньшее и менеям его знак
						result = MUL_ZM_Z(result); // Умножим число на -1
				}
				else
				{
					result = ADD_NN_N(ABS_Z_N(num1), ABS_Z_N(num2));//ecли первое положительное, то вычитаем из большего числа меньшее
				}
			}
			else
			{
				if (POZ_Z_D(num2) == 1)
				{
					result = ADD_NN_N(ABS_Z_N(num2), ABS_Z_N(num1));//ecли второе отрицательное,то вычитаем из большего числа меньшее и менеям его знак
						result = MUL_ZM_Z(result); // Умножим число на -1
				}
				else
				{
					result = ADD_NN_N(ABS_Z_N(num2), ABS_Z_N(num1));//ecли второе положительное, то вычитаем из большего числа меньшее
				}
			}
		}
	}
	return(result);   // Возвращаемое значение
}


