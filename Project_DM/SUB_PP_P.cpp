
#include "Allfunc.h"

vector<Drob> SUB_PP_P(vector<Drob> first, vector<Drob> second)
{
	// Проверка на пустой ввод
	if (first.empty() || second.empty())
		throw "Empty input";

	// Создаем нулевую дробь
	Drob null{ vector<int> {0}, vector<int> {1} };
	// И рассчитываем разность размеров многочленов
	int sizedif(first.size() - second.size());

	// Если первый меньше второго, дополняем его нулями слева
	if (sizedif < 0)
		first.insert(first.begin, -sizedif, null);

	// Если второй меньше первого, дополняем его нулями слева
	else if (sizedif > 0)
		second.insert(first.begin, sizedif, null);

	// Последовательно считаем разность
	// соответствующих коэффициентов многочленов
	vector<Drob> result;
	for (int i(0); i < first.size(); ++i)
		result.push_back(SUB_QQ_Q(first[i], second[i]));

	return result;
}