#include "natural.h"

///////////////////////////////////////////////////////////////////////////////////////////////     Ñòàðîñåëüñêèé Àëåêñàíäð     //

bool NZER_N_B(vector<int> a_Z) // Ïðîâåðêà íà íîëü: åñëè ÷èñëî íå ðàâíî íóëþ, òî «äà» èíà÷å «íåò» 
{
	if ((a_Z[0] == 0) && (a_Z.size() == 1))
		return false;
	else
		return true;
}

vector<int> GCF_NN_N(vector<int> a, vector<int> b) // ÍÎÄ íàòóðàëüíûõ ÷èñåë
{
	if (!NZER_N_B(a) || !NZER_N_B(b))
		throw ((string)" 0 into NOD = Error \nIn File: " + __FILE__ + "\nIn line: " + to_string(__LINE__));
	if (COM_NN_D(a, b) == 1) // 2 - num1 > num2, 0 - num1=num2, 1 - num2 > num1
		swap(a, b);
	while (NZER_N_B(b)) // Öèêë ïîêà b != 0
	{
		vector <int> c; //Âñïîìîãàòåëüíûé âåêòîð
		c = MOD_NN_N(a, b); // Îñòàòîê îò äåëåíèÿ a íà b		
		a = b;
		b = c;
	}
	return a;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////     Ìèõàèë Êèðèøñêèé     //

vector<int> ADD_1N_N(vector<int> input) // Äîáàâëåíèå 1 ê íàòóðàëüíîìó ÷èñëó
{
	// Ñîçäàåì êîïèþ âõîäíîãî âåêòîðà
	vector<int> res(input);

	// Ïðîâåðÿåì åñëè â ôóíêöèþ ïåðåäàí ïóñòîé âåêòîð
	if (input.empty())
		throw ((string)"Empty input \nIn File: " + __FILE__ + "\nIn line: " + to_string(__LINE__));

	// Ñîõðàíÿåì â ïàìÿòü ÷èñëî 1,
	// íà êîòîðîå íåîáõîäèìî óâåëè÷èòü âõîäíîå çíà÷åíèå
	int mem(1);

	// Â öèêëå èäåì ñ êîíöà ê íà÷àëó âåêòîðà (ïîêà â ïàìÿòè ÷òî-òî õðàíèòñÿ)
	for (int i(input.size() - 1); mem && i >= 0; --i)
	{
		// Åñëè öèôðà íå ïîïàäàåò â äèàïàçîí 0-9,
		// êèäàåì èñêëþ÷åíèå î íåïðàâèëüíîì ââîäå
		if (input[i] < 0 || input[i] > 9)
			throw ((string)"Input is not a valid number \nIn File: " + __FILE__ + "\nIn line: " + to_string(__LINE__));

		res[i] = (input[i] + mem) % 10;
		mem = (input[i] + mem) / 10;
	}

	// Åñëè ïðîøëèñü ïî âñåìó âåêòîðó, íî ïàìÿòü âñå åùå íå ïóñòà,
	// äîáàâëÿåì â íà÷àëî íîâûé ýëåìåíò ñî çíà÷åíèåì èç ïàìÿòè
	if (mem)
		res.insert(res.begin(), mem);

	return res;
}

vector<int> MUL_NN_N(vector<int> first, vector<int> second) // Ïåðåìíîæåíèå íàòóðàëüíûõ ÷èñåë
{
	// Ïðîâåðÿåì åñëè â ôóíêöèþ ïåðåäàí ïóñòîé âåêòîð
	if (first.empty() || second.empty())
		throw ((string)"Empty input \nIn File: " + __FILE__ + "\nIn line: " + to_string(__LINE__));

	// Ñäåëàåì áîëüøèé ïî äëèíå âåêòîð ïåðâûì
	if (first.size() < second.size())
	{
		swap(first, second);
	}

	vector<int> result{ 0 }, k{ 0 };
	for (int i(second.size() - 1); i >= 0; i--, k = ADD_1N_N(k))
	{
		// Ïåðåìíîæàåì ïåðâûé âåêòîð íà êàæäóþ öèôðó âòîðîãî
		vector<int> addition(MUL_ND_N(first, second[i]));

		// Ñäâèãàåì ÷èñëî íà 1 ðàçðÿä âëåâî (êàê â óìíîæåíèè â ñòîëáèê)
		addition = MUL_Nk_N(addition, k);

		// Ñêëàäûâàåì âñå ýòè ÷èñëà è çàïèñûâàåì â ðåçóëüòàò
		result = ADD_NN_N(result, addition);
	}
	return result;
}

vector<int> DIV_NN_N(vector<int> first, vector<int> second) // Êðàòíîå îò äåëåíèÿ 2 íàòóðàëüíûõ ÷èñåë
{
	// Ïðîâåðÿåì åñëè â ôóíêöèþ ïåðåäàí ïóñòîé âåêòîð
	if (first.empty() || second.empty())
		throw ((string)"Empty input \nIn File: " + __FILE__ + "\nIn line: " + to_string(__LINE__));

	vector<int> result{ 0 }, k{ 0 };
	int i(0);
	// Ïîêà ïåðâîå ÷èñëî >= âòîðîãî
	while (COM_NN_D(first, second) == 2 || COM_NN_D(first, second) == 0)
	{
		// Âû÷èñëÿåì ïåðâóþ öèôðó äåëåíèÿ first íà second
		// óìíîæåííóþ íà 10 â ñòåïåíè åå ïîçèöèè
		vector<int> temp(DIV_NN_Dk(first, second));

		// Ïðèáàâëÿåì ýòî ÷èñëî ê result
		result = ADD_NN_N(result, temp);

		// Òåïåðü óìíîæàåì ýòî ÷èñëî íà äåëèòåëü
		temp = MUL_NN_N(temp, second);

		// È îòíèìàåì ïîëó÷èâøååñÿ îò äåëèìîãî
		first = SUB_NN_N(first, temp);

		++i;
	}
	return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////     ×èãàíîâ Äàíèèë     //

vector <int>MUL_Nk_N(vector<int> N, vector<int> k) // Óìíîæèòü íàòóðàëüíîå ÷èñëî íà 10^k
{
	// Ïðîâåðÿåì åñëè â ôóíêöèþ ïåðåäàí ïóñòîé âåêòîð
	if (N.empty() || k.empty())
		throw ((string)"Empty input \nIn File: " + __FILE__ + "\nIn line: " + to_string(__LINE__));
	//Ïðîâåðÿåì ÷òîáû ââîäèìûå äàííûå áûëè íàòóðàëüíûìè ÷èñëàìè
	//Äî òåõ ïîð ïîêà i íå ðàâíî k ïðèáàâëÿòü â êîíåö ÷èñëà 0, ÷òî ýêâèâàëåíòíî óìíîæåíèþ íà 10
	for (vector <int>i = { 0 }; i != k; i = ADD_1N_N(i))
		N.push_back(0);
	return N;
}

vector <int>SUB_NDN_N(vector<int> a, vector<int> b, int k) // Âû÷èòàíèå èç íàòóðàëüíîãî äðóãîãî íàòóðàëüíîãî, óìíîæåííîãî íà öèôðó äëÿ ñëó÷àÿ ñ íåîòðèöàòåëüíûì ðåçóëüòàòîì
{
	// Ïðîâåðÿåì åñëè â ôóíêöèþ ïåðåäàí ïóñòîé âåêòîð
	if (a.empty() || b.empty())
		throw ((string)"Empty input \nIn File: " + __FILE__ + "\nIn line: " + to_string(__LINE__));
	vector<int> bk = MUL_ND_N(b, k);// save result of b * k (Äëÿ òîãî, ÷òîáû íå ñ÷èòàòü åãî 2 ðàçà)
	vector<int> ak = MUL_ND_N(a, k);
	short abk = COM_NN_D(a, bk);
	short bak = COM_NN_D(b, ak);

	if (abk == 2 || abk == 0) // Åñëè a > bk èëè a = bk, result = a - bk
		return SUB_NN_N(a, bk);
	else if (bak == 2 || bak == 0)// Åñëè b > ak èëè b = ak, result = b - ak
		return SUB_NN_N(b, ak);
	else throw ((string)"Wrong input \nIn File: " + __FILE__ + "\nIn line: " + to_string(__LINE__)); // Èíà÷à
}

vector <int>MOD_NN_N(vector<int> first, vector<int> second) // Îñòàòîê îò äåëåíèÿ áîëüøåãî íàòóðàëüíîãî ÷èñëà íà ìåíüøåå èëè ðàâíîå íàòóðàëüíîå ñ îñòàòêîì(äåëèòåëü îòëè÷åí îò íóëÿ)
{
	// Ïðîâåðÿåì åñëè â ôóíêöèþ ïåðåäàí ïóñòîé âåêòîð
	if (first.empty() || second.empty())
		throw ((string)"Empty input \nIn File: " + __FILE__ + "\nIn line: " + to_string(__LINE__));

	if (COM_NN_D(first, second) == 1)
		swap(first, second);

	return SUB_NN_N(first, MUL_NN_N(second, DIV_NN_N(first, second)));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////     Åðìîëüåâ Ìàêñèì     //

vector<int> SUB_NN_N(vector<int> a, vector<int> b) // Âû÷èòàíèå èç ïåðâîãî áîëüøåãî íàòóðàëüíîãî ÷èñëà âòîðîãî ìåíüøåãî èëè ðàâíîãî
{
	if (a.empty() || b.empty())
		throw ((string)"Empty input \nIn File: " + __FILE__ + "\nIn line: " + to_string(__LINE__));

	if (COM_NN_D(a, b) == 2)      // 2 åñëè a>b, 0 åñëè a=b, 1 åñëè a<b
	{
		vector <int> result(a.size());                         //Ñîçäàíèì âåêòîð, êîòîðûé õðàíèò ðåçëüòàò âû÷èòàíèÿ, è íàçíà÷èì åìó ðàçìåðíîñòü áîëüøåãî ÷èñëà
		while (a.size() != b.size())  b.insert(b.begin(), 0); // Åñëè âåêòîð b ìåíüøå ïî ðàçìåðíîñòè, òî äîáàâèì â åãî íà÷àëî íóëè
		for (int i = a.size() - 1; i >= 0; i--) // Öèêë âû÷èòàíèÿ
		{
			result[i] = a[i] - b[i];
			if (result[i] < 0)
			{
				result[i] += 10;
				a[i - 1]--;
			}
		}
		while (result[0] == 0) // Åñëè ïîñëå âû÷èòàíèÿ â íà÷àëå âåêòîðà îñòàþòÿ íóëè, òî èõ  íóæíî óáðàòü
		{
			result.erase(result.begin());
		}
		return result;
	}
	if (COM_NN_D(a, b) == 0)
	{
		vector <int> result = { 0 }; // Òàê êàê íàòóðàëüíûå ÷èñëà ðàâíû, òî èõ ðàçíîñòü äàåò 0
		return result;
	}
	if (COM_NN_D(a, b) == 1)
	{
		vector <int> result(b.size());                         //Ñîçäàíèì âåêòîð, êîòîðûé õðàíèò ðåçëüòàò âû÷èòàíèÿ, è íàçíà÷èì åìó ðàçìåðíîñòü áîëüøåãî ÷èñëà
		while (a.size() != b.size())  a.insert(a.begin(), 0); // Åñëè âåêòîð a ìåíüøå ïî ðàçìåðíîñòè, òî äîáàâèì â åãî íà÷àëî íóëè
		for (int i = b.size() - 1; i >= 0; i--) // Öèêë âû÷èòàíèÿ
		{
			result[i] = b[i] - a[i];
			if (result[i] < 0)
			{
				result[i] += 10;
				b[i - 1]--;
			}
		}
		while (result[0] == 0)
		{
			result.erase(result.begin());
		}
		return result;   // Âîçâðàùàåìîå çíà÷åíèå - ðåçóëüòàò âû÷èòàíèÿ äâóõ íàòóðàëüíûõ ÷èñåë
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////     Àñòàõîâ Ìèõàèë      //

int COM_NN_D(vector<int> num1, vector<int> num2) // 2 - num1 > num2, 0 - num1=num2, 1 - num2 > num1
{
	if (num1.size() > num2.size())	return 2; // Åñëè num1 > num2  - 2
	else if (num1.size() < num2.size())	return 1; // Åñëè num1 < num2  - 1
	else // Åñëè num1 = num2  - 0
	{
		for (int i = 0; i < num1.size(); i++)
		{
			if (num1[i] > num2[i])
				return 2;
			else if (num1[i] < num2[i])
				return 1;
		}
		return 0;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////     Èãîðü Òåìíèêîâ      //

vector<int> DIV_NN_Dk(vector<int> vector_1, vector<int> vector_2) // Âû÷èñëåíèå ïåðâîé öèôðû äåëåíèÿ áîëüøåãî íàòóðàëüíîãî íà ìåíüøåå, 
{																  // äîìíîæåííîå íà 10^k,ãäå k - íîìåð ïîçèöèè ýòîé öèôðû (íîìåð ñ÷èòàåòñÿ ñ íóëÿ)
	if (vector_1.empty() || vector_2.empty()) //Ïðîâåðêà íà ïóñòîé
		throw "Empty input";

	vector <int> result;

	if (COM_NN_D(vector_1, vector_2) == 1)
	{ //Åñëè 1é âåêòîð < 2ãî
		result.resize(1);
		result[0] = 0;
		return result;
	}

	if (COM_NN_D(vector_1, vector_2) == 0)
	{ //Åñëè âåêòîðû ðàâíû
		result.resize(1);
		result[0] = 1;
		return result;
	}

	bool check = true;
	for (int i = 0; i < vector_2.size(); i++)
	{
		if (vector_1[i] > vector_2[i])
		{
			check = false;
			result.resize(vector_1.size() - vector_2.size() + 1);
			break;
		}
		else if (vector_1[i] < vector_2[i])
		{
			check = false;
			result.resize(vector_1.size() - vector_2.size());
			break;
		}
	}
	if (check)
		result.resize(vector_1.size() - vector_2.size() + 1);
	vector <int> temp;
	int i = 0;
	for (; i < vector_2.size(); i++)
	{
		temp.push_back(vector_1[i]);
	}
	if (COM_NN_D(vector_2, temp) == 2)
		temp.push_back(vector_1[i]);
	short k = 9;
	vector <int> v2k = MUL_ND_N(vector_2, k);
	while (COM_NN_D(v2k, temp) == 2)
	{
		k--;
		v2k = MUL_ND_N(vector_2, k);
	}
	result[0] = k;
	return result;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////     Òàáîÿêîâ Èâàí      //

vector<int> TRANS_N_Z(vector<int> input) // Ïðåîáðàçîâàíèå íàòóðàëüíîãî ÷èñëà â öåëîå
{
	input.insert(input.begin(), 0);
	return input;
}

vector<int> LCM_NN_N(vector<int> vector_1, vector<int> vector_2)
{
	return DIV_NN_N(MUL_NN_N(vector_1, vector_2), GCF_NN_N(vector_1, vector_2));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////     Æèðåíêèí Àðòåì      //

vector<int> ADD_NN_N(vector<int> a, vector<int> b) // Ñëîæåíèå íàòóðàëüíûõ ÷èñåë
{
	// Ïðîâåðÿåì åñëè â ôóíêöèþ ïåðåäàí ïóñòîé âåêòîð
	if (a.empty() || b.empty())
		throw "Empty input";
	if (!NZER_N_B(a)) return b;
	if (!NZER_N_B(b)) return a;
	vector<int> c;

	int one = 0; // Ïåðåìåííàÿ äëÿ õðàíåíèÿ íîâîãî ðàçðÿäà
	if (COM_NN_D(a, b) == 2)      // 2 åñëè a>b, 0 åñëè a=b, 1 åñëè a<b
	{
		int k = a.size() - b.size();
		for (int i = 0; i < k; i++)
			b.insert(b.begin(), 0); // Óðàâíèâàåì ÷èñëî äî îäíîãî êîë-âà çíàêîâ
	}
	else
	{
		int k = b.size() - a.size();
		for (int i = 0; i < k; i++)
			a.insert(a.begin(), 0); // Óðàâíèâàåì ÷èñëî äî îäíîãî êîë-âà çíàêîâ
	}
	for (int i = a.size() - 1; i >= 0; i--)
	{
		if ((a[i] + b[i] + one) > 9) // Åñëè ñóììà ðàçðÿäîâ áîëüøå 9, çàïèñûâàåì 1 â ïåðåìåííóþ 
		{
			c.insert(c.begin(), (a[i] + b[i] + one) % 10);
			one = 1;
		}
		else
		{
			c.insert(c.begin(), a[i] + b[i] + one);
			one = 0;
		}
	}
	if (one == 1) // Åñëè îñòàëàñü 1, òî äîáàâëÿåì åù¸ îäèí ðàçðÿä
		c.insert(c.begin(), 1);

	return c;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
