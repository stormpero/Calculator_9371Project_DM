#include "Allfunc.h"
std::vector<int>  SUB_NN_N(std::vector<int> a, std::vector<int> b) // ≈рмольев ћаксим ¬икторович
{
	std::vector<int> result;               // ѕерменнна€, котора€ хранит результат вычитани€
	if (COM_NN_D(a, b) == 2)      // 2 если a>b, 0 если a=b, 1 если a<b
	{
		std::vector <int> result(a.size());                         //—озданим вектор, который хранит резльтат вычитани€, и назначим ему размерность большего числа
		while (a.size() != b.size())  b.insert(b.begin(), 0); // ≈сли вектор b меньше по размерности, то добавим в его начало нули
		for (int i = a.size() - 1; i >= 0; i--) // ÷икл вычитани€
		{
			result[i] = a[i] - b[i];
			if (result[i] < 0)
			{
				result[i] += 10;
				a[i - 1]--;
			}
		}
		while (result[0]==0) // ≈сли после вычитани€ в начале вектора остают€ нули, то их  нужно убрать
		{

				result.erase(result.begin());

		}
	}
	if (COM_NN_D(a, b) == 0)
	{
		result[0] = 0;           // “ак как натуральные числа равны, то их разность дает 0
	}
	if (COM_NN_D(a, b) == 1)
	{
		std::vector <int> result(b.size());                         //—озданим вектор, который хранит резльтат вычитани€, и назначим ему размерность большего числа
		while (a.size() != b.size())  a.insert(a.begin(), 0); // ≈сли вектор a меньше по размерности, то добавим в его начало нули
		for (int i = b.size() - 1; i >= 0; i--) // ÷икл вычитани€
		{
			result[i] = b[i] - a[i];
			if (result[i] < 0)
			{
				result[i] += 10;
				b[i - 1]--;
			}
		}
		while (result[0] == 0)
		{
			result.erase(result.begin());
		}
	}
	return(result);   // ¬озвращаемое значение - результат вычитани€ двух натуральных чисел
}