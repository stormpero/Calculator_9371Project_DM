#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct Drob
{
	vector <int> numerator = { 0 };
	vector <int> denominator = { 0 };
};

////////////////////////////////////////////////////////////Многочлены////////////////////////////////////////////////////////////

vector<Drob> MUL_Pxk_P(vector<Drob> poly, vector<int> k); // Домножение многочлена на x^k // Михаил Киришский

int DEG_P_N(vector <Drob> a); // Степень многочлена //Старосельский Александр

Drob LED_P_Q(vector <Drob> polynominal); // Старшимй коэффициент многочлена //Даниил

vector<Drob> SUB_PP_P(vector<Drob> first, vector<Drob> second); // Вычитание многчленов // Михаил Киришский

vector <Drob> MOD_PP_P(vector <Drob> f, vector <Drob> s); // Остаток деления многочлена на многочлен