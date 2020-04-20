#include "polynomial.h"

///////////////////////////////////////////////////////////////////////////////////////////////     Ñòàðîñåëüñêèé Àëåêñàíäð     //

int DEG_P_N(vector <Drob> a)
{
	return a.size() - 1;
}

vector<Drob> GCF_PP_P(vector<Drob> fir, vector<Drob> sec) // ÎØÈÁÊÀ
{	
	vector <Drob> temp;
	if (DEG_P_N(sec) > DEG_P_N(fir))
		swap(fir, sec);
	temp = MOD_PP_P(fir, sec);
	//else if (DEG_P_N(fir) == DEG_P_N(sec)) 
	//{
	//	Drob drop = SUB_QQ_Q(fir[DEG_P_N(fir)], sec[DEG_P_N(sec)]);
	//	if (drop.numerator[0] == 1) 
	//		swap(num1, num2);
	//}
	//while (num2 != null) // Öèêë ïîêà b != 0
	//{
	//	vector <Drob> c; //Âñïîìîãàòåëüíûé âåêòîð
	//	c = MOD_PP_P(num1, num2); // Îñòàòîê îò äåëåíèÿ a íà b
	//	num1 = num2;
	//	num2 = c;
	//}

	while (temp.size() != 1 || POZ_Z_D(temp[0].numerator) != 0)
	{
		fir = sec;
		sec = temp;
		temp = MOD_PP_P(fir, sec);
	}
	return sec;	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Ìèõàèë Êèðèøñêèé     //

vector <Drob> MUL_Pxk_P(vector<Drob> poly, vector<int> k)
{
	vector<Drob> result(poly);

	for (vector<int> i{ 0 }; COM_NN_D(i, k) == 1; i = ADD_1N_N(i))
	{
		// Ñäâèãàåì êîýôôèöèåíòû íàëåâî k ðàç,
		// à ñâîáîäíîå ïðîñòðàíñòâî çàïîëíÿåì íóëÿìè
		Drob zero{ vector<int> {0, 0}, vector<int> {1} };
		result.insert(result.begin(), zero);
	}

	return result;
}

void FAC_P_Q(vector<Drob> poly, vector<int>& LCM_de, vector<int>& GCD_num)
{
	if (poly.empty())
		throw "Empty polynomial";

	// è ÍÎÄó ÷èñëèòåëü ïåðâîãî êîýôôèöèåíòà (â âèäå íàòóðàëüíîãî ÷èñëà)
	// Ïðèðàâíèâàåì ÍÎÊó çíàìåíàòåëü ïåðâîãî êîýôôèöèåíòà ìíîãî÷ëåíà
	GCD_num = ABS_Z_N(poly[0].numerator);
	LCM_de = poly[0].denominator;

	// È ïîñëåäîâàòåëüíî âû÷èñëÿåì åãî ÍÎÄ è ÍÎÊ ñ êàæäûì ñëåäóþùèì êîýôèöèåíòîì
	for (int i(1); i < poly.size(); ++i)
	{
		GCD_num = GCF_NN_N(GCD_num, ABS_Z_N(poly[i].numerator));
		LCM_de = LCM_NN_N(LCM_de, poly[i].denominator);
	}

	// Ïåðåâîäèì ÍÎÄ îáðàòíî â öåëîå ÷èñëî
	GCD_num = TRANS_N_Z(GCD_num);
}

vector<Drob> SUB_PP_P(vector<Drob> first, vector<Drob> second)
{
	// Ïðîâåðêà íà ïóñòîé ââîä
	if (first.empty() || second.empty())
		throw "Empty input";

	// Ñîçäàåì íóëåâóþ äðîáü
	Drob null{ vector<int> {0, 0}, vector<int> {1} };
	// È ðàññ÷èòûâàåì ðàçíîñòü ðàçìåðîâ ìíîãî÷ëåíîâ
	int sizedif(first.size() - second.size());

	// Åñëè ïåðâûé ìåíüøå âòîðîãî, äîïîëíÿåì åãî íóëÿìè ñëåâà
	if (sizedif < 0)
		first.insert(first.begin(), -sizedif, null);

	// Åñëè âòîðîé ìåíüøå ïåðâîãî, äîïîëíÿåì åãî íóëÿìè ñëåâà
	else if (sizedif > 0)
		second.insert(first.begin(), sizedif, null);

	// Ïîñëåäîâàòåëüíî ñ÷èòàåì ðàçíîñòü
	// ñîîòâåòñòâóþùèõ êîýôôèöèåíòîâ ìíîãî÷ëåíîâ
	vector<Drob> result;
	for (int i(0); i < first.size(); i++)
		result.push_back(SUB_QQ_Q(first[i], second[i]));
	for (int i = result.size() - 1; (POZ_Z_D(result[i].numerator) == 0) && i != 0; i--)
	{
		result.pop_back();
	}
	return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     ×èãàíîâ Äàíèèë     //

vector <Drob> MOD_PP_P(vector <Drob> f, vector <Drob> s)
{	
	return SUB_PP_P(f, MUL_PP_P(DIV_PP_P(f, s), s)); // Ñíà÷àëà ïîëó÷àåì öåëóþ ÷àñòü äåëåíèÿ f íà s, çàòåì óìíîæàåì ðåçóëüòàò íà äåëèòåëü (ò. å s). Òî, ÷òî â ðåçóëüòàòå ïîëó÷èëîñü, âû÷èòàåì èç äåëèìîãî (ò. å f)	
}

Drob LED_P_Q(vector <Drob> polynominal)
{
	if (polynominal.empty())
		throw "Wrong input";
	return polynominal[polynominal.size() - 1]; //âîçâðàùàåì ïîñëåäíþþ ñòðóêòóðó
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Åðìîëüåâ Ìàêñèì     //

vector<Drob> ADD_PP_P(vector<Drob> a, vector<Drob> b)
{

	// Ñîçäàåì íóëåâóþ äðîáü
	Drob null{ vector<int> {0, 0}, vector<int> {1} };
	// È ðàññ÷èòûâàåì ðàçíîñòü ðàçìåðîâ ìíîãî÷ëåíîâ
	int sizedif(a.size() - b.size());

	// Åñëè ïåðâûé ìåíüøå âòîðîãî, äîïîëíÿåì åãî íóëÿìè ñëåâà
	if (sizedif < 0)
		a.insert(a.begin(), -sizedif, null);

	// Åñëè âòîðîé ìåíüøå ïåðâîãî, äîïîëíÿåì åãî íóëÿìè ñëåâà
	else if (sizedif > 0)
		b.insert(a.begin(), sizedif, null);

	// Ïîñëåäîâàòåëüíî ñ÷èòàåì ñóììó
	// ñîîòâåòñòâóþùèõ êîýôôèöèåíòîâ ìíîãî÷ëåíîâ
	vector<Drob> result;
	for (int i(0); i < a.size(); i++)
		result.push_back(ADD_QQ_Q(a[i], b[i]));

	return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Àñòàõîâ Ìèõàèë      //

vector <Drob> MUL_PP_P(vector <Drob> f, vector <Drob> s) 
{
	vector <Drob> result;
	result = MUL_PQ_P(f, s[0]); // Óìíîæàåì ïåðâûé ìíîãî÷ëåí íà ñâîáîäíûé ÷ëåí âòîðîãî


	vector <int> ssize;
	int n = s.size();
	while (n != 0)              // Çäåñü êîñòûëü. Òàê êàê MUL_Pxk_P íà âõîä ïðèíèìàåò ìíîãî÷ëåí è âåêòîð, à s.size() ýòî ïðîñòî ÷èñëî òèïà int. Ïîýòîìó ïðèøëîñü ïðåîáðàçîâûâàòü int ê vector <int>
	{
		ssize.push_back(n % 10);
		n /= 10;
	}
	for (int i = 0; i < ssize.size() / 2; i++)
	{
		swap(ssize[i], ssize[ssize.size() - 1 - i]);
	}
	int kk = 1;
	for (vector <int> k = { 1 }; k != ssize; k = ADD_1N_N(k)) // Óìíîæàåì ïåðâûé ìíîãî÷ëåí íà x^k âòîðîãî ìíîãî÷ëåíà è ïðèáàâëÿåì ïîëó÷èâøèåñÿ ê ðåçóëüòàòó äî òåõ ïîð ïîêà ìíîãîî÷ëåí íå êîí÷èòñÿ
	{		
		if (POZ_Z_D(s[kk].numerator) != 0) // ýòî óñëîâèå ÷èñòî ðàäè îïòèìèçàöèè, ÷òîáû ïðîãà íå ïåðåìíîæàëà íàïðàñíî îäèí ìíîãî÷ëåí íà x^k, êîãäà êîýôôèöèåíò ïåðåä x^k ðàâåí íóëþ
			result = ADD_PP_P(result, MUL_PQ_P(MUL_Pxk_P(f, k), s[kk]));
		kk++;
	}
	return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Èãîðü Òåìíèêîâ      //

vector<Drob> MUL_PQ_P(vector<Drob> polynomial, Drob fraction)
{
	for (int i = polynomial.size() - 1; i >= 0; i--) // Öèêë âû÷èòàíèÿ
		polynomial[i] = MUL_QQ_Q(polynomial[i], fraction);
	return (polynomial);
}

vector<Drob> DER_P_P(vector<Drob> polynomial)
{
	Drob i;	//îòâå÷àåò çà ñòåïåíü (âèä a/1)
	i.numerator.push_back(0);
	i.denominator.push_back(1);
	polynomial.erase(polynomial.begin());//÷èñòèì ñâîáîäíûé ÷ëåí íà 0
	for(int k = polynomial.size() - 1; k >= 0; k--)
	{
		for (int size = k; size > 0; size--)
			i.numerator = ADD_1N_N(i.numerator);
		i.numerator = ADD_1N_N(i.numerator);
		i.numerator.insert(i.numerator.begin(), 0);
		polynomial[k] = MUL_QQ_Q(polynomial[k], i);
		i.numerator.resize(1);
		i.denominator.resize(1);
		i.numerator[0] = 0;
		i.denominator[0] = 1;
	}
	return (polynomial);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Òàáîÿêîâ Èâàí      //

vector<Drob> NMR_P_P(vector<Drob> polynomial)
{
	vector<Drob> pr = DER_P_P(polynomial);
	vector <Drob> nod = GCF_PP_P(polynomial, pr);
	if ((nod[0].numerator[0] == 1) && (nod[0].denominator[0] == 1)) 
		polynomial = DIV_PP_P(polynomial, pr);
	
	return polynomial;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Æèðåíêèí Àðòåì      //

vector<Drob> DIV_PP_P(vector<Drob> a, vector<Drob> b) 
{
	//vector<Drob> old = { {vector <int>{ 0 }, vector <int> {1}} }, jun = old, newe = old, result = old, priv = old;
	//vector<int> xk = { 0 };
	//Drob k = { vector <int> {0} ,vector <int> {1} };
	//int i;
	//if (DEG_P_N(a) > DEG_P_N(b)) { //  îïðåäåëÿåì ñòåïåíü ìíîãî÷ëåíà À è ìíîãî÷ëåíà Â.È ÷üÿ ñòåïåíü áîëüøå, òîò áóäåò äåëèìûì, ìíîãî÷ëåí ñ ìåíüøåé ñòåïåíüþ áóäåò äåëèòåëåì
	//	old = a;
	//	jun = b;
	//}
	//else
	//{
	//	old = b;
	//	jun = a;
	//};
	//k = jun[jun.size() - 1];//ñòàðøèé êîýôôèöèåíò ìíîãî÷ëåíà-äåëèòåëÿ

	//i = (old.size() - jun.size());//ðàçìåðíîñòü íàøåãî ÷àñòíîãî
	//while (DEG_P_N(old) >= DEG_P_N(jun))//ïîêà ñòåïåíü áîëüøåãî ìíîãî÷ëåíà áîëüøå ñòåïåíè ìåíüøåãî
	//{
	//	xk[0] = (old.size() - jun.size());//íàõîäèì k äëÿ x^k
	//	newe = MUL_Pxk_P(jun, xk);//óìíîæàåì ìëàäøèé ìíîãî÷ëåí íà x^k
	//	result = MUL_PQ_P(newe, old[old.size() - 1]);//óìíîæàåì ïîëó÷åííûé âåêòîð íà ñòàðøèé êîýôôèöèåíò áîëüøåãî ìíîãî÷ëåíà
	//	priv[i] = old[old.size() - 1];//çàíîñèì ñòàðøèé êîýôôèöèåíò ÷àñòíîãî â âåêòîð
	//	i--;
	//	if ((((k.numerator[0] == 0 && k.denominator[0] == 0) || (k.numerator[0] == 1 && k.denominator[0] == 1)) && ((old[old.size() - 1].numerator[0] == 0 && old[old.size() - 1].denominator[0] == 0) || (old[old.size() - 1].numerator[0] == 1 && old[old.size() - 1].denominator[0] == 1))) || (((k.numerator[0] == 0 && k.denominator[0] == 1) || (k.numerator[0] == 1 && k.denominator[0] == 0)) && ((old[old.size() - 1].numerator[0] == 0 && old[old.size() - 1].denominator[0] == 1) || (old[old.size() - 1].numerator[0] == 1 && old[old.size() - 1].denominator[0] == 0))))//Óñëîâèå ïðîâåðÿþùåå,íóæíî ëè ñêëàäûâàòü èëè âû÷èòàòü ìíîãî÷ëåíû
	//	{
	//		old = SUB_PP_P(old, result);
	//	}
	//	else {
	//		old = ADD_PP_P(old, result);
	//	}
	//	old.pop_back();
	//};

	/*return(priv);*/
	if (DEG_P_N(b) > DEG_P_N(a))
		swap(a, b);

	Drob number;
	vector <Drob> div_a_b;
	div_a_b.resize(a.size() - b.size() + 1);
	for (int i = 0; i < div_a_b.size(); i++)
	{
		div_a_b[i].numerator.push_back(0);
		div_a_b[i].numerator.push_back(0);
		div_a_b[i].denominator.push_back(1);
	}

	int i = 0;
	while (DEG_P_N(a) >= DEG_P_N(b) && !(a.size() == 1 && POZ_Z_D(a[0].numerator) == 0))
	{
		number = DIV_QQ_Q(a[a.size() - 1], b[b.size() - 1]);
		div_a_b[div_a_b.size() - 1 - i] = number;
		vector <int> vect = { 0 };

		for (int j = 0; j < div_a_b.size() - 1 - i; j++)
			vect = ADD_1N_N(vect);

		a = SUB_PP_P(a, MUL_PQ_P(MUL_Pxk_P(b, vect), number));
		i++;
	}
	return div_a_b;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
