
#include "Allfunc.h"

vector<Drob> MUL_Pxk_P(vector<Drob> poly, vector<int> k)
{
	vector<Drob> result(poly);

	for (vector<int> i{ 0 }; COM_NN_D(i, k) == 1; i = ADD_1N_N(i))
	{
		Drob zero{ vector<int> {0}, vector<int> {1} };
		result.push_back(zero);
	}

	return result;
}