#include "Allfunc.h"
#include "natural.h"
#include "integer.h"
#include "rational.h"
#include "polynomial.h"
#include "matrix.h"
vector<int> input_natural(); // Ввод натурального числа
void output_natural(vector <int> test); // Вывод натурального числа

vector<int> input_integer(); // Ввод целого числа
void output_integer(vector <int> test); // Вывод целого числа

Drob input_rational(); // Ввод дроби
void output_rational(Drob a); // Вывод дроби

vector<Drob> input_polinom(); // Ввод многочлена
void output_polinom(vector<Drob> polin); //Вывод многочлена

vector<vector<vector<int>>> input_matrix(); // Ввод матрицы
void output_matrix(vector<vector<vector<int>>> a); //Вывод матрицы

exc mist()
{
	exc te;
	te.file = __FILE__,
	te.line_num = __LINE__,
	te.name_exc = "Empty input";
	return te;
}
int main()
{
	// ADD_QQ_Q ЕСЛИ ЧИСЛИЕТЛЬ 0
	try
	{
		setlocale(LC_ALL,"ru");		
		vector<int> a1;
		vector<int> a2;
		
		//a1 = input_integer();	
		//output_integer(a1);
		//cout << endl;
		//a2 = input_integer();
		//output_integer(a2);
		//cout << endl << endl;
		//vector<int> a3(SUB_ZZ_Z(a1, a2));
		//output_integer(a3);

		//a1 = input_natural();
		//a2 = input_natural(); //DIV_NN_N MOD_NN_N GCF_NN_N
		//vector<int> a3(GCF_NN_N(a1, a2));
		//output_natural(a3);
		//
		//Drob test, test1;		
		//test = input_rational();
		//cout << endl;
		//test1 = input_rational();
		//test1 = ADD_QQ_Q(test, test1);
		//output_rational(test1);

		vector <Drob> test1;
		vector <Drob> test2;
		test1 = input_polinom();
		cout << endl;
		test2 = input_polinom();
		test1 = ADD_PP_P(test1,test2);
		cout << endl;
		output_polinom(test1);
		
		//vector <int> det;
		//vector<vector<vector<int>>> a,b;
		//a = input_matrix();
		//cout << endl;
		//det = MAT_Z_DET(a);
		//output_integer(det);
		//b = input_matrix();
		//cout << endl;
		//a = MAT_Z_SUM(a, b);
		//output_matrix(a);
	}
	catch (string s)
	{		
		system("color C");
		cout << "Error: " << s << endl;
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
vector<vector<vector<int>>> input_matrix()
{
	cout << "Введите размер матрицы:" << endl;
	int sizemat;
	cin >> sizemat;
	vector<vector<vector<int>>> a(sizemat);
	
	for (int i = 0; i < sizemat; i++)	
	{
		a[i].resize(sizemat);
		for (int j = 0; j < a.size(); j++)
			a[i][j] = input_integer();
	}
	
	return a;
}
void output_matrix(vector<vector<vector<int>>> a)
{
	int sd = a.size();
	int sizemat = sqrt(sd);
	for (int i = 0; i < sd; i++)
	{
		for (int j = 0; j < a.size(); j++)
		{
			output_integer(a[i][j]);
			cout << " ";
		}
			
		cout << endl;
	}
}