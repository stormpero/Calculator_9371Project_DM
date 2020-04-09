#include "Allfunc.h"
#include "natural.h"
#include "integer.h"
#include "rational.h"
#include "polynomial.h"
vector<int> input_natural(); // Ввод натурального числа
void output_natural(vector <int> test); // Вывод натурального числа

vector<int> input_integer(); // Ввод целого числа
void output_integer(vector <int> test); // Вывод целого числа

Drob input_rational(); // Ввод дроби
void output_rational(Drob a); // Вывод дроби

vector<Drob> input_polinom(); // Ввод многочлена
void output_polinom(vector<Drob> polin); //Вывод многочлена

vector<vector<int>> input_matrix(); // Ввод матрицы
void output_matrix(vector<vector<int>> a); //Вывод матрицы

int main()
{
	try
	{
		setlocale(LC_ALL,"ru");

		vector<int> a31;
		a31 = input_integer();
		output_integer(a31);

		//vector<int> a32;
		//a32 = input_natural();
		//output_natural(a32);

		//Drob test;
		//test = input_rational(); 
		//output_rational(test);

		//vector <Drob> test1;
		//test1 = input_polinom();
		//output_polinom(test1);

		/*vector<vector<int>> a;
		a = input_matrix();
		output_matrix(a);*/
	}
	catch (const char* er)
	{
		system("color C");
		cout << "Error: " << er << endl;
		system("color 0");
	}
}

vector<int> input_natural()
{
	string s; cin >> s;
	vector <int> test(s.length());
	for (int i = 0; i < test.size(); i++)
		test[i] = s[i] - '0';
	return test;
}
void output_natural(vector <int> test) // Вывод числа 
{
	for (int i = 0; i < test.size(); i++)
		cout << test[i];
}
//
vector<int> input_integer() // Ввод числа 
{
	string s; cin >> s;
	vector <int> test(s.length());
	for (int i = 1; i < test.size(); i++)
		test[i] = s[i] - '0';
	if (s[0] == '-') test[0] = 1;
	else { test[0] = s[0] - '0';  test.insert(test.begin(), 0); }
	return test;
}
void output_integer(vector <int> test) // Вывод числа 
{
	if (test[0] == 1) cout << "-";
	for (int i = 1; i < test.size(); i++)
		cout << test[i];
}
//
Drob input_rational() // Ввод числа 
{
	Drob number;

	cout << "Введите числитель:" << endl;
	string s; cin >> s;
	number.numerator.resize(s.length());
	for (int i = 1; i < number.numerator.size(); i++)
		number.numerator[i] = s[i] - '0';
	if (s[0] == '-') number.numerator[0] = 1;
	else { number.numerator[0] = s[0] - '0';  number.numerator.insert(number.numerator.begin(), 0); }

	cout << "Введите знаменатель:" << endl;
	cin >> s;
	number.denominator.resize(s.length());
	for (int i = 0; i < number.denominator.size(); i++)
		number.denominator[i] = s[i] - '0';

	return number;
}
void output_rational(Drob a)
{
	if (a.numerator[0] == 1) cout << "-";
	for (int i = 1; i < a.numerator.size(); i++)
		cout << a.numerator[i];
	cout<<"\\";
	for (int i = 0; i < a.denominator.size(); i++)
		cout << a.denominator[i];
}
vector<Drob> input_polinom()
{		
	cout << "Введите степень многочлена:" << endl;
	int degree; cin >> degree; degree++;
	vector<Drob> a(degree);
	for (int i = a.size()-1; i >= 0; i--)	
		a[i] = input_rational();	
	return a;
}
void output_polinom(vector<Drob> polin)
{
	for (int i = polin.size() - 1; i >= 1; i--)
	{
		output_rational(polin[i]);
		cout << "x^"<< i;
		cout << " + ";
	}
	output_rational(polin[0]);
}
vector<vector<int>> input_matrix()
{
	cout << "Введите размер матрицы:" << endl;
	int sizemat;
	cin >> sizemat;
	vector<vector<int>> a(sizemat*sizemat);
	
	for (int i = 0; i < a.size(); i++)	
		a[i] = input_integer();
	
	return a;
}
void output_matrix(vector<vector<int>> a)
{
	int sd = a.size();
	int sizemat = sqrt(sd);
	for (int i = 0; i < sd; i++)
	{
		if (i == sizemat)
		{
			cout << endl;
			sizemat += sizemat;
		}
			
		output_integer(a[i]);
		cout << " ";
	}
}