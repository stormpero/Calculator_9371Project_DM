#include "Allfunc.h"

vector<int> GCF_NN_N(vector<int> a, vector<int> b)
{
	while (NZER_N_B(b)) // Цикл пока b != 0
	{
		vector <int> c; //Вспомогательный вектор
		c = MOD_NN_N(a, b); // Остаток от деления a на b
		a = b;
		b = c;
	}
	return a;
}