#include "Allfunc.h"

vector<Drob> ADD_PP_P(vector<Drob> a, vector<Drob> b) // Ермольев М.В.
{

	// Создаем нулевую дробь
	Drob null{ vector<int> {0}, vector<int> {1} };
	// И рассчитываем разность размеров многочленов
	int sizedif(a.size() - b.size());

	// Если первый меньше второго, дополняем его нулями слева
	if (sizedif < 0)
		a.insert(a.begin, -sizedif, null);

	// Если второй меньше первого, дополняем его нулями слева
	else if (sizedif > 0)
		b.insert(a.begin, sizedif, null);

	// Последовательно считаем сумму
	// соответствующих коэффициентов многочленов
	vector<Drob> result;
	for (int i(0); i < a.size(); ++i)
		result.push_back(ADD_QQ_Q(a[i], b[i]));

	return result;
}