#include "Allfunc.h"

vector<int> MUL_ZZ_Z(vector<int> a, vector<int> b) // Ермольев Максим Викторович
{
	vector<int> result; // Перменнная, которая хранит результат умножения
	if (POZ_Z_D(a) == 0 || POZ_Z_D(b) == 0) //  Если одно из чисел равно 0, то их произведение тоже равно 0
		result.push_back(0);
	else
	{
		result = MUL_NN_N(ABS_Z_N(a), ABS_Z_N(b)); // Переведем целые в натуральные и выполним умножение
		result = TRANS_N_Z(result); // Переведем натуральные в целые
		if (POZ_Z_D(a) != POZ_Z_D(b)) //Проверим равны ли знаки чисел, если нет, то поменяем знак
			result = MUL_ZM_Z(result); // Умножим число на -1
	}
	return(result);   // Возвращаемое значение
}
