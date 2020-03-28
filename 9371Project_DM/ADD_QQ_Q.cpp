#include "Allfunc.h";

Drob ADD_QQ_Q (Drob a, Drob b)
{
	Drob res;
	vector<int> zn1 = ABS_Z_N(a.denominator);
	vector<int> zn2 = ABS_Z_N(b.denominator);
	vector <int> zn = LCM_NN_N(zn1,zn2);
	vector <int> mn = DIV_ZZ_Z(zn,zn1);
	vector <int> chisl1 = MUL_ZZ_Z(a.numerator, mn);
	vector <int> mn1 = DIV_ZZ_Z(zn, zn2);
	vector <int> chisl2 = MUL_ZZ_Z(b.numerator, mn1);
	res.numerator = ADD_ZZ_Z(chisl1, chisl2);
	res.denominator = zn;
	return res;
}