
#include "Allfunc.h"

void PAC_P_Q(vector<Drob> poly, vector<int>& LCM_de, vector<int>& GCD_num)
{
	if (poly.empty())
		throw "Empty polynomial";

	// Приравниваем НОКу знаменатель первого коэффициента многочлена
	// и НОДу числитель первого коэффициента (в виде натурального числа)
	LCM_de = poly[0].denominator;
	GCD_num = ABS_Z_N(poly[0].numerator);

	// И последовательно вычисляем его НОК и НОД с каждым следующим коэфициентом
	for (int i(1); i < poly.size(); ++i)
	{
		LCM_de = LCM_NN_N(LCM_de, poly[i].denominator);
		GCD_num = GCF_NN_N(GCD_num, ABS_Z_N(poly[i].numerator));
	}

	// Переводим НОД обратно в целое число
	GCD_num = TRANS_N_Z(GCD_num);
}