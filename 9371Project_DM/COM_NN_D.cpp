#include "Allfunc.h"

int COM_NN_D(vector<int> num1, vector<int> num2)
{
	int s = 0;
	if (num1.size() == num2.size())  //если у чисел одинаковое колл-во разрядов
	{
		for (int i = 0; i < num1.size(); i++)//уравниваем каждый разр¤д в отдельности
		{
			s = 0;
			if (num1[i] == num2[i])
				s = 1; //разряды равны
			if (s != 1) //если разряд не равен, то смотрим какой из них больше
			{
				if (num1[i] > num2[i])
					return 2;
				if (num1[i] < num2[i])
					return 1;
				break;
			}
		}
	}

	if (s == 1) //каждые разряды равны
		return 0;

	if (num1.size() < num2.size())
		return 1;

	if (num1.size() > num2.size())
		return 2;
}