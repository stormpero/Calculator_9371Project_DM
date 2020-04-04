#include "rational.h"


///////////////////////////////////////////////////////////////////////////////////////////////     Чиганов Даниил     //

Drob SUB_QQ_Q(Drob f, Drob s)
{
	if (s.numerator[0] == 0 && s.numerator.size() == 1) // если s == 0
		return f;
	s.numerator[0] = !s.numerator[0]; // иначе инвертируем знак второго
	return ADD_QQ_Q(f, s); // вызываем ф-ию сложения целых чисел, но прибавляем мы число с противоположным знаком
	// у меня красным подчеркивается, разберитесь.
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Ермольев Максим     //

int INT_Q_B(Drob a)
{
	a = RED_Q_Q(a); //Выполним сокращение дроби
	if (a.denominator[1] == 1)  // Проверим, является ли его первый элемент еденицей в знаменателе
		return 1; // Если да, то выведем еденицу
	else
		return 0; // Если нет, то ноль
}

Drob DIV_QQ_Q(Drob a, Drob b)
{
	Drob result;
	result.numerator = MUL_ZZ_Z(a.numerator, b.denominator); // Умножим числитель дроби a на знаменатель дроби b
	result.denominator = MUL_ZZ_Z(a.denominator, b.numerator); // Аналогично для знаменателя
	result = RED_Q_Q(result); // Выполним сокращение дроби
	return(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Астахов Михаил      //

Drob MUL_QQ_Q(Drob num1, Drob num2)
{
	Drob result;	//структура дробей
	result.numerator = MUL_ZZ_Z(num1.numerator, num2.numerator); //присваемваем произведения числителей
	result.denominator = MUL_NN_N(num1.denominator, num2.denominator);  // присваемваем произведение знаменателей
	result = RED_Q_Q(result);
	return result; //возвращаем значение структуры
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Табояков Иван      //

Drob ADD_QQ_Q(Drob a, Drob b)
{
	Drob res;
	vector<int> zn1 = ABS_Z_N(a.denominator);
	vector<int> zn2 = b.denominator;
	vector <int> zn = LCM_NN_N(zn1, zn2);
	vector <int> mn = DIV_ZZ_Z(zn, zn1);
	vector <int> chisl1 = MUL_ZZ_Z(a.numerator, mn);
	vector <int> mn1 = DIV_ZZ_Z(zn, zn2);
	vector <int> chisl2 = MUL_ZZ_Z(b.numerator, mn1);
	res.numerator = ADD_ZZ_Z(chisl1, chisl2);
	res.denominator = zn;
	return res;
}

vector<int> TRANS_Q_Z(Drob a)
{
	vector<int>r = a.numerator;
	return r;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////     Жиренкин Артем      //

Drob TRANS_Z_Q(vector <int> a) 
{
	Drob p;	//Новая структура
	p.numerator = a; // Присваиваем число к числителю
	p.denominator[0] = 0;// Присваиваем 0 к знаменателю
	p.denominator.push_back(1);  // Присваиваем 1 к знаменателю
	return p; // Возвращаем структуру
}

Drob RED_Q_Q(Drob a)
{
	vector <int> one = { 1 };
	vector <int> num = ABS_Z_N(a.numerator); // Получаем абсолютную величину числителя
	vector <int> dem = ABS_Z_N(a.denominator);// Получаем абсолютную величину знаменателя
	vector <int> NOD = GCF_NN_N(num, dem);//Находим НОД дроби
	while (NOD != one) {//Пока НОД не станет равен единице

		num = DIV_ZZ_Z(num, NOD);// Получаем частное от деления числителя на НОД
		dem = DIV_ZZ_Z(dem, NOD);// Получаем частное от деления знаменателя на НОД
		NOD = GCF_NN_N(num, dem);//Находим НОД частных дроби

	};
	if (a.numerator[0] == 0) {
		num.insert(num.begin(), 0);
	}
	else {
		num.insert(num.begin(), 1);
	}
	if (a.denominator[0] == 0) {
		dem.insert(dem.begin(), 0);
	}
	else {
		dem.insert(dem.begin(), 1);
	}
	a.numerator = num;
	a.denominator = dem;
	return(a);//Возвращаем сокращенную дробь

};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////