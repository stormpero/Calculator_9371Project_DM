#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct Drob
{
	vector <int> numerator = { 0 };
	vector <int> denominator = { 0 };
};

////////////////////////////////////////////////////////////Рациональные числа////////////////////////////////////////////////////////////

Drob TRANS_Z_Q(vector <int> a); //Преобразование целого в дробное // Жиренкин Артём

int INT_Q_B(Drob a);// Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное) // Ермольев Максим Викторович

Drob DIV_QQ_Q(Drob a, Drob b); // Деление дробей(делитель отличен от нуля) // Ермольев Максим Викторович

Drob SUB_QQ_Q(Drob f, Drob s); // Vichitanie dvuh chisel // danya

////////////////////////////////////////////////////////////Рациональные числа////////////////////////////////////////////////////////////
//
//
//
//
//
////////////////////////////////////////////////////////////Многочлены////////////////////////////////////////////////////////////

vector<Drob> MUL_Pxk_P(vector<Drob> poly, vector<int> k); // Домножение многочлена на x^k // Михаил Киришский

int DEG_P_N(vector <Drob> a); // Степень многочлена //Старосельский Александр

Drob LED_P_Q(vector <Drob> polynominal); // Старшимй коэффициент многочлена //Даниил

vector<vector<int>> MAT_Q_SUM(vector<vector<int>> a, vector<vector<int>> b, int row);// Сложение матриц//Жиренкин Артем

vector<Drob> SUB_PP_P(vector<Drob> first, vector<Drob> second); // Вычитание многчленов // Михаил Киришский