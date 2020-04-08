#include "Allfunc.h"

vector<vector<int>> MAT_Q_SUM(vector<vector<int>> a, vector<vector<int>> b)
{
	vector<vector<int>> c(a.size());
	for (int i = 0; i < c.size(); i++)
	{


		c[i].resize((ADD_NN_N(a[i], b[i])).size());
		c[i] = ADD_ZZ_Z(a[i], b[i]);


	};
	return (c);
}