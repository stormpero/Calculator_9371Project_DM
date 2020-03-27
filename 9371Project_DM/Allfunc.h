#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct Drob
{
	vector <int> numerator = { 0 };
	vector <int> denominator = { 0 };
};
////////////////////////////////////////////////////////////Натуральные числа////////////////////////////////////////////////////////////



////////////////////////// Старосельский Александр  ///////////////////////////////////

int NZER_N_B(vector<int> a_Z);  // Проверка на ноль: если число не равно нулю, то «да» иначе «нет»

vector<int> GCF_NN_N(vector<int> a, vector<int> b); // НОД натуральных чисел

//////////////////////////////////////////////////////////////////////////////


////////////////////////// Михаил Киришский //////////////////////////////////

vector<int> ADD_1N_N(vector<int> input);  // Добавление 1 к натуральному числу

vector<int> MUL_NN_N(vector<int> first, vector<int> second); // Перемножение натуральных чисел

vector<int> DIV_NN_N(vector<int> first, vector<int> second); // Кратное от деления 2 натуральных чисел

//////////////////////////////////////////////////////////////////////////////


////////////////////////// Чиганов Даниил ///////////////////////////////////

vector <int>MUL_Nk_N(vector<int> N, vector<int> k); //Умножить натуральное число на 10^k

vector <int>SUB_NDN_N(vector<int> a, vector<int> b, int k); //Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом 

vector <int>MOD_NN_N(vector<int> a, vector<int> b); //Остаток от деления большего натурального числа на меньшее или равное натуральное с остатком(делитель отличен от нуля) 

//////////////////////////////////////////////////////////////////////////////	


////////////////////////// Ермольев Максим ///////////////////////////////////

vector<int>  SUB_NN_N(vector<int> a, vector<int> b);  // Вычитание из первого большего натурального числа второго меньшего или равного

//////////////////////////////////////////////////////////////////////////////


////////////////////////// Астахов Михаил  ///////////////////////////////////

int COM_NN_D(vector<int> num1, vector<int> num2); //Сравнение натуральных чисел: 2 - если первое больше второго, 0, если равно, 1 иначе. 

//////////////////////////////////////////////////////////////////////////////


////////////////////////// Игорь Темников  ///////////////////////////////////

vector<int> DIV_NN_Dk(vector<int> vector_1, vector<int> vector_2); //+++ Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k,где k - номер позиции этой цифры (номер считается с нуля)

//////////////////////////////////////////////////////////////////////////////


////////////////////////// Табояков Иван  ///////////////////////////////////

vector<int> TRANS_N_Z(vector<int> input);//Преобразование натурального числа в целое//

//////////////////////////////////////////////////////////////////////////////


////////////////////////// Жиренкин Артем   ///////////////////////////////////

vector<int> ADD_NN_N(vector<int> a, vector<int> b);//Сложение натуральных чисел

//////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////Натуральные числа////////////////////////////////////////////////////////////
//
//
//
//
//
////////////////////////////////////////////////////////////Целые числа////////////////////////////////////////////////////////////

vector<int> ABS_Z_N(vector<int> a);  // Абсолютная величина числа, результат - натуральное //Старосельский Александр

vector<int> MUL_ND_N(vector<int> entry, int number); //Умножение целого на цифру //Игорян

vector<int> MUL_ZM_Z(vector<int> input); //Умножение целого числа на -1 //Табояков Иван

vector<int> TRANS_Z_N(vector<int> a);//Преобразование целого неотрицательного в натуральное//Жиренкин Артем

int POZ_Z_D(vector<int> num); // Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное) // Астахов Михаил 

vector<int> MUL_ZZ_Z(vector<int> a, vector<int> b); // Умножение целых чисел // Ермольев Максим Викторович

vector<int> ADD_ZZ_Z(vector<int> num1, vector<int> num2); // Сложение целых чисел // Астахов Михаил

vector<int> MOD_ZZ_Z(vector<int> a, vector<int> b); // Остаток от деления большего целого числа на меньшее или равное натуральное с остатком(делитель отличен от нуля) // Ермольев Максим Викторович

vector<int> SUB_ZZ_Z(vector<int> vector_1, vector<int> vector_2); // Вычитание целых чисел // Игорь Темников

vector<int> DIV_ZZ_Z(vector<int> vector_1_N, vector<int> vector_2_N, vector<int> vector_3_Z);// Частное от деления большего целого числа на меньшее или равное натуральное с остатком // Игорь Темников

////////////////////////////////////////////////////////////Целые числа////////////////////////////////////////////////////////////
//
//
//
//
//
////////////////////////////////////////////////////////////Рациональные числа////////////////////////////////////////////////////////////

Drob TRANS_Z_Q(vector <int> a); //Преобразование целого в дробное // Жиренкин Артём

int INT_Q_B(Drob a);// Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное) // Ермольев Максим Викторович

Drob DIV_QQ_Q(Drob a, Drob b); // Деление дробей(делитель отличен от нуля) // Ермольев Максим Викторович

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

