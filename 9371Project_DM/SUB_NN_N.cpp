#include "Allfunc.h"
std::vector<int>  SUB_NN_N(std::vector<int> a, std::vector<int> b) // Ермольев Максим Викторович
{
	std::vector<int> result;               // Перменнная, которая хранит результат вычитания
	if (COM_NN_D(a, b) == 2)      // 2 если a>b, 0 если a=b, 1 если a<b
	{
		std::vector <int> result(a.size());                         //Созданим вектор, который хранит резльтат вычитания, и назначим ему размерность большего числа
		while (a.size() != b.size())  b.insert(b.begin(), 0); // Если вектор b меньше по размерности, то добавим в его начало нули
		for (int i = a.size() - 1; i >= 0; i--) // Цикл вычитания
		{
			result[i] = a[i] - b[i];
			if (result[i] < 0)
			{
				result[i] += 10;
				a[i - 1]--;
			}
		}
		if (result[0] == 0)        //Если в начале остался ноль, нужно убрать его
			result.erase(result.begin());

	}
	if (COM_NN_D(a, b) == 0)
	{
		result[0] = 0;           // Так как натуральные числа равны, то их разность дает 0
	}
	if (COM_NN_D(a, b) == 1)
	{
		std::vector <int> result(b.size());                         //Созданим вектор, который хранит резльтат вычитания, и назначим ему размерность большего числа
		while (a.size() != b.size())  a.insert(a.begin(), 0); // Если вектор a меньше по размерности, то добавим в его начало нули
		for (int i = b.size() - 1; i >= 0; i--) // Цикл вычитания
		{
			result[i] = b[i] - a[i];
			if (result[i] < 0)
			{
				result[i] += 10;
				b[i - 1]--;
			}
		}
		if (result[0] == 0)        //Если в начале остался ноль, нужно убрать его
			result.erase(result.begin());
	}
	return(result);   // Возвращаемое значение - результат вычитания двух натуральных чисел
}