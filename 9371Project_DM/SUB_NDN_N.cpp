#include "Allfunc.h"

vector <int>SUB_NDN_N(vector<int> a, vector<int> b, int k)
{
	vector<int> tempb = MUL_ND_N(b, k);// save result of b * k (Для того, чтобы не считать его 2 раза)
	vector<int> null = { 0 };

	if (COM_NN_D(tempb, a) == 2) // Если bk > a, то result = bk - a
		return SUB_NN_N(tempb, a);
	else if (k != 0) //иначе если k != 0, то result = ak - b  (Здесь же учтем случай, когда ak=b и bk=a, при k != 0 такое возможно, когда a = b = 0, или a = b = k = 1   =>  result = ak - b)
		return SUB_NN_N(MUL_ND_N(a, k), b);
	else if ((k == 0) && (b == null) || ((k == 0) && (a == null))) return null; // если k = 0, то       ak - b <= 0    и   bk - a <= 0      при этом равным нулю одно из этих выражений может только если a = 0 или b = 0
	else throw "wrong number";  // иначе неотрицательного результата нет
}