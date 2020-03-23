#include "Allfunc.h"

vector<int> input() // Ввод числа // Приветствуется дороботка кода(ОПТИМИЗАЦИЯ)
{
	string s; cin >> s;	
	vector <int> test(s.length());
	for (int i = 1; i < test.size(); i++)
		test[i] = s[i] - '0';
	if (s[0] == '-') test[0] = 1;
	else { test[0] = s[0] - '0';  test.insert(test.begin(), 0); }
	return test;	
}		

void output(vector <int> test) // Вывод числа // Приветствуется дороботка кода(ОПТИМИЗАЦИЯ)
{
	if (test[0] == 1) cout << "-";
	for (int i = 1; i < test.size(); i++)
		cout << test[i];
}
int main()
{
	vector<int> t2 = { 5,0 }; // Наше число, которое должно попасть в числитель
	vector<int> t3 = { 2,5 };

	t3 = GCF_NN_N(t2, t3);


	for (int i = 0; i < t3.size(); i++)
		cout << t3[i];





	//Drob x = TRANS_Z_Q(t2);// Копираю вектор из функции в новый вектор
	//for (int i = 0; i < x.numerator.size(); i++)// Вывод числителя
	//	cout << x.numerator[i];
	//cout << endl;
	//for (int i = 0; i < x.denominator.size(); i++)// Вывод знаменателя
	//	cout << x.denominator[i];


	//vector <Drob> test;
	//test[0].numerator[0] = 1;
	//

	//
	//vector<int> t2 = { 1,3,5,7 };
	//vector<int> t3;
	//vector<int> t1 = { 0,3,5 };
	//for (int i = 0; i < t3.size(); i++)
	//	cout << t3[i];
	//
	// output(input());	
}

