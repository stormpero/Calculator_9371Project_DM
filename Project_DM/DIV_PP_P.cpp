#include "Allfunc.h"
#include "rational.h"
#include "natural.h"
#include "integer.h"

vector<Drob> DIV_PP_P(vector<Drob> a, vector<Drob> b) {

	vector<Drob> old, jun, newe, result, priv;
	vector<int> xk;
	Drob k;
	int i;
	if (DEG_P_N(a) > DEG_P_N(b)) { //  определяем степень многочлена А и многочлена В.И чья степень больше, тот будет делимым, многочлен с меньшей степенью будет делителем
		old = a;
		jun = b;
	}
	else
	{
		old = b;
		jun = a;
	};
	k = jun[jun.size() - 1];//старший коэффициент многочлена-делителя

	i = (old.size() - jun.size());//размерность нашего частного
	while (DEG_P_N(old) >= DEG_P_N(jun))//пока степень большего многочлена больше степени меньшего
	{
		xk[0] = (old.size() - jun.size());//находим k для x^k
		newe = MUL_Pxk_P(jun, xk);//умножаем младший многочлен на x^k
		result = MUL_PQ_P(newe, old[old.size() - 1]);//умножаем полученный вектор на старший коэффициент большего многочлена
		priv[i] = old[old.size() - 1];//заносим старший коэффициент частного в вектор
		i--;
		if ((((k.numerator[0] == 0 && k.denominator[0] == 0) || (k.numerator[0] == 1 && k.denominator[0] == 1)) && ((old[old.size() - 1].numerator[0] == 0 && old[old.size() - 1].denominator[0] == 0) || (old[old.size() - 1].numerator[0] == 1 && old[old.size() - 1].denominator[0] == 1))) || (((k.numerator[0] == 0 && k.denominator[0] == 1) || (k.numerator[0] == 1 && k.denominator[0] == 0)) && ((old[old.size() - 1].numerator[0] == 0 && old[old.size() - 1].denominator[0] == 1) || (old[old.size() - 1].numerator[0] == 1 && old[old.size() - 1].denominator[0] == 0))))//Условие проверяющее,нужно ли складывать или вычитать многочлены
		{
			old = SUB_PP_P(old, result);
		}
		else {
			old = ADD_PP_P(old, result);
		}
		old.pop_back();
	};

	return(priv);
};