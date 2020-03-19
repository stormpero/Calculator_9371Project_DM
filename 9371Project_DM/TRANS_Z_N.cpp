#include "Allfunc.h"
vector<int> TRANS_Z_N(vector<int> a)
{
	reverse(a.begin(), a.end());
	a.pop_back();
	reverse(a.begin(), a.end());
	return (a);
}