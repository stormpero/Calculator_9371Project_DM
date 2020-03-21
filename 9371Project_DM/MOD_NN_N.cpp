#include "Allfunc.h"

vector <int>MOD_NN_N(vector<int> first, vector<int> second)
{
	// Проверяем если в функцию передан пустой вектор
	if (first.empty() || second.empty())
		throw "Empty input";
	if (COM_NN_D(first, second) == 1)
	{
		vector <int>* p = new vector<int>;
		*p = first;
		first = second;
		second = *p;
		delete[]p;
	}

	/*
	Если делать эту прогу по адекватному, то получится что-то вроде этого:

	return SUB_NN_N(first, MUL_NN_N(second, DIV_NN_N(first, second)));



	НО у меня в требованиях проги указано, что мне нужно воспользоваться этими функциями:   DIV_NN_N    SUB_NDN_N
	Понятия не имею зачем(мб работать будет быстрее), но я это сделал (не факт, что эта прога будет работать на всех числах, но я пытался исправить все ошибки)
	*/

	vector <int> remains = { 0 };
	vector <int> num;
	vector <int> null = { 0 };
	short quotient;
	// иммитируем деление чисел first и second в столбик и таким образом считаем конечный остаток.
	int i = 0;
	while ((i < first.size()) && ((second.size() + i) <= first.size()) || ((remains != null) && ((remains.size() + i) <= first.size())))
	{
		if (remains == null) // если отстаток равен нулю
		{
			num.reserve(second.size()); // возьмем первые несколько чисел делимого, такие, чтобы полученное число делилось на делитель. (кол-во разрядов этого числа должно равняться или превышать на один колво разрядов делителя)
			for (; i < second.size; i++)
				num[i] = first[i];
		}
		else // инача
		{
			num.reserve(remains.size()); // если остаток не равен нулю
			for (int j = 0; j < remains.size; j++) //возьмем остаток и добавим в него числа из делимого столько, чтобы колво разрядов равнялось колву разрядов делятеля
				num[j] = remains[j];
			while (num.size() != second.size())
			{
				num.push_back(first[i]);
				i++;
			}
		}
		if ((COM_NN_D(num, second) == 1)) // если полученное число получилось меньше делителя, тогда добавляем к нему еще один разряд из делимого(не забывая сделать проверку, что делимое обладает нужным колвом разрядов)
			if ((1 + i) <= first.size())// в таком случае это число будет гарантировано делиться на делитель
				num.push_back(first[i++]);
			else return num; // если разрядов у делимого не осталось, тогда получившиеся число и есть остаток от деления

		remains = SUB_NDN_N(num, second, (DIV_NN_N(num, second))[0]); // считаем остаток деления числа, которое мы получили выше на делитель, затем повторяем ту же самую операцию, до тех пор пока у делимого не закончатся цифры
		num.clear();
	}
	if (i < first.size())
	{
		remains.clear();
		remains.reserve(first.size() - i);
		for (int j = 0; j < remains.size(); j++)
			remains[i] = first[i];
	}
	return remains;

}
