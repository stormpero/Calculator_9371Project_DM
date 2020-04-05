#include "polynomial.h"

///////////////////////////////////////////////////////////////////////////////////////////////     Старосельский Александр     //

int DEG_P_N(vector <Drob> a)
{
	return a.size() - 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Михаил Киришский     //

vector<Drob> MUL_Pxk_P(vector<Drob> poly, vector<int> k)
{
	vector<Drob> result(poly);

	for (vector<int> i{ 0 }; COM_NN_D(i, k) == 1; i = ADD_1N_N(i))
	{
		// Сдвигаем коэффициенты налево k раз,
		// а свободное пространство заполняем нулями
		Drob zero{ vector<int> {0}, vector<int> {1} };
		result.push_back(zero);
	}

	return result;
}

void FAC_P_Q(vector<Drob> poly, vector<int>& LCM_de, vector<int>& GCD_num)
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

vector<Drob> SUB_PP_P(vector<Drob> first, vector<Drob> second)
{
	// Проверка на пустой ввод
	if (first.empty() || second.empty())
		throw "Empty input";

	// Создаем нулевую дробь
	Drob null{ vector<int> {0}, vector<int> {1} };
	// И рассчитываем разность размеров многочленов
	int sizedif(first.size() - second.size());

	// Если первый меньше второго, дополняем его нулями слева
	if (sizedif < 0)
		first.insert(first.begin(), -sizedif, null);

	// Если второй меньше первого, дополняем его нулями слева
	else if (sizedif > 0)
		second.insert(first.begin(), sizedif, null);

	// Последовательно считаем разность
	// соответствующих коэффициентов многочленов
	vector<Drob> result;
	for (int i(0); i < first.size(); ++i)
		result.push_back(SUB_QQ_Q(first[i], second[i]));

	return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Чиганов Даниил     //

vector <Drob> MOD_PP_P(vector <Drob> f, vector <Drob> s)
{
	return SUB_PP_P(f, MUL_PP_P(DIV_PP_P(f, s), s)); // Сначала получаем целую часть деления f на s, затем умножаем результат на делитель (т. е s). То, что в результате получилось, вычитаем из делимого (т. е f)	
}

Drob LED_P_Q(vector <Drob> polynominal)
{
	if (polynominal.empty())
		throw "Wrong input";
	return polynominal[polynominal.size() - 1]; //возвращаем самую первую структуру
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Ермольев Максим     //

vector<Drob> ADD_PP_P(vector<Drob> a, vector<Drob> b)
{

	// Создаем нулевую дробь
	Drob null{ vector<int> {0}, vector<int> {1} };
	// И рассчитываем разность размеров многочленов
	int sizedif(a.size() - b.size());

	// Если первый меньше второго, дополняем его нулями слева
	if (sizedif < 0)
		a.insert(a.begin(), -sizedif, null);

	// Если второй меньше первого, дополняем его нулями слева
	else if (sizedif > 0)
		b.insert(a.begin(), sizedif, null);

	// Последовательно считаем сумму
	// соответствующих коэффициентов многочленов
	vector<Drob> result;
	for (int i(0); i < a.size(); ++i)
		result.push_back(ADD_QQ_Q(a[i], b[i]));

	return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Астахов Михаил      //



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Игорь Темников      //

vector<Drob> MUL_PQ_P(vector<Drob> polynomial, Drob fraction)
{
	for (int i = polynomial.size() - 1; i >= 0; i--) // Цикл вычитания
		polynomial[i] = MUL_QQ_Q(polynomial[i], fraction);
	return (polynomial);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Табояков Иван      //



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Жиренкин Артем      //

vector<Drob> DIV_PP_P(vector<Drob> a, vector<Drob> b) 
{
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
