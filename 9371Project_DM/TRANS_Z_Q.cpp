#include "Allfunc.h"

Drob TRANS_Z_Q(vector <int> a) // Преобразование целого в дробное
{
	Drob p;	//Новая структура
	p.numerator = a; // Присваиваем число к числителю
	p.denominator[0] = 0;// Присваиваем 0 к знаменателю
	p.denominator.push_back(1);  // Присваиваем 1 к знаменателю
	return p; // Возвращаем структуру
}
