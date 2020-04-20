#include "rational.h"


///////////////////////////////////////////////////////////////////////////////////////////////     ×èãàíîâ Äàíèèë     //

Drob SUB_QQ_Q(Drob f, Drob s)
{
	if (POZ_Z_D(s.numerator) == 0) // åñëè s == 0
		return f;
	s.numerator = MUL_ZM_Z(s.numerator); // èíà÷å èíâåðòèðóåì çíàê âòîðîãî
	return ADD_QQ_Q(f, s); // âûçûâàåì ô-èþ ñëîæåíèÿ öåëûõ ÷èñåë, íî ïðèáàâëÿåì ìû ÷èñëî ñ ïðîòèâîïîëîæíûì çíàêîì	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Åðìîëüåâ Ìàêñèì     //

int INT_Q_B(Drob a)
{
	a = RED_Q_Q(a); //Âûïîëíèì ñîêðàùåíèå äðîáè
	if (a.denominator[0] == 1 && a.denominator.size() == 1)  // Ïðîâåðèì, ÿâëÿåòñÿ ëè åãî ïåðâûé ýëåìåíò åäèíèöåé â çíàìåíàòåëå
		return 1; // Åñëè äà, òî âûâåäåì åäèíèöó
	else
		return 0; // Åñëè íåò, òî íîëü
}

Drob DIV_QQ_Q(Drob a, Drob b)
{


	if (POZ_Z_D(b.numerator) == 0)
		throw "Zero devider";
	result.numerator = MUL_ZZ_Z(a.numerator, TRANS_N_Z(b.denominator)); // Óìíîæèì ÷èñëèòåëü äðîáè a íà çíàìåíàòåëü äðîáè b
	result.denominator = MUL_NN_N(a.denominator, TRANS_Z_N(b.numerator)); // Àíàëîãè÷íî äëÿ çíàìåíàòåëÿ
	if (POZ_Z_D(result.numerator) == 0)
	{
		result = RED_Q_Q(result);
		return result;
	}
	if ((POZ_Z_D(a.numerator) == POZ_Z_D(b.numerator)))
		result.numerator[0] = 0;
	else
		result.numerator[0] = 1;

	result = RED_Q_Q(result); // Âûïîëíèì ñîêðàùåíèå äðîáè

	return(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Àñòàõîâ Ìèõàèë      //

Drob MUL_QQ_Q(Drob num1, Drob num2)
{
	Drob result;	//ñòðóêòóðà äðîáåé
	result.numerator = MUL_ZZ_Z(num1.numerator, num2.numerator); //ïðèñâàåìâàåì ïðîèçâåäåíèÿ ÷èñëèòåëåé
	result.denominator = MUL_NN_N(num1.denominator, num2.denominator);  // ïðèñâàåìâàåì ïðîèçâåäåíèå çíàìåíàòåëåé
	result = RED_Q_Q(result);
	return result; //âîçâðàùàåì çíà÷åíèå ñòðóêòóðû
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Òàáîÿêîâ Èâàí      //

Drob ADD_QQ_Q(Drob a, Drob b) 
{
	Drob res;
	a = RED_Q_Q(a);
	b = RED_Q_Q(b);
	if ((a.denominator == b.denominator) && (POZ_Z_D(ADD_ZZ_Z(a.numerator, b.numerator)) == 0))
	{
		res.numerator.push_back(0);
		res.numerator.push_back(0);
		res.denominator.push_back(1);
		return res;
	}
	vector <int> f = LCM_NN_N(a.denominator, b.denominator);

	a.numerator = MUL_ZZ_Z(a.numerator, TRANS_N_Z(DIV_NN_N(f, a.denominator)));
	b.numerator = MUL_ZZ_Z(b.numerator, TRANS_N_Z(DIV_NN_N(f, b.denominator)));

	res.numerator = ADD_ZZ_Z(a.numerator, b.numerator);
	res.denominator = f;

	return res;
}

vector<int> TRANS_Q_Z(Drob a)
{
	vector <int> one = { 1 };
	a = RED_Q_Q(a);
	if (a.denominator != one)
		throw "Error, impossible to make integer of rational";
	return a.numerator;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Æèðåíêèí Àðòåì      //

Drob TRANS_Z_Q(vector <int> a) 
{
	Drob p;	//Íîâàÿ ñòðóêòóðà
	p.numerator = a; // Ïðèñâàèâàåì ÷èñëî ê ÷èñëèòåëþ	
	p.denominator.push_back(1);  // Ïðèñâàèâàåì 1 ê çíàìåíàòåëþ
	return p; // Âîçâðàùàåì ñòðóêòóðó
}

Drob RED_Q_Q(Drob a)
{
	if (POZ_Z_D(a.numerator) == 0)
	{
		a.denominator = { 1 };
		return a;
	}
	vector<int> Nod = GCF_NN_N(ABS_Z_N(a.numerator), a.denominator);
	a.denominator = DIV_NN_N(a.denominator, Nod);
	Nod.insert(Nod.begin(), 0);
	a.numerator = DIV_ZZ_Z(a.numerator, Nod);	
	
	return a;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////