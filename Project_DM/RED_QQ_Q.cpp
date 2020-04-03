#include "Allfunc.h"
#include "integer.h"

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