#include "Allfunc.h";
vector<Drob> NMR_P_P(vector<Drob> polynomial)
{
	vector<Drob> pr = DER_P_P(polynomial);
	vector <Drob> nod = GCF_P_P(polynomial, pr);
	if((nod[0].numerator == 1) && (nod[0].denominator == 1)) {
		polynomial = DIV_PP_P(polynomial, pr);
	}

	return polynomial;
}