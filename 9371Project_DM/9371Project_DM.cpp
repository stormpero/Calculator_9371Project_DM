#include "Allfunc.h"


int main()
{
	// Ввод числа // Приветствуется дороботка кода(ОПТИМИЗАЦИЯ)
	string s; cin >> s; 
	vector <int> test(s.length());
	for (int i = 1; i < test.size(); i++)
		test[i] = s[i] - '0';
	if (s[0] == '-') test[0] = 1;
	else { test[0] = s[0] - '0';  test.insert(test.begin(), 0); }


	for (int i = 0; i < test.size(); i++)
		cout << test[i];
	//

	//Вывод числа // Приветствуется дороботка кода(ОПТИМИЗАЦИЯ)
	if (test[0] == 1) cout << "-";
	for (int i = 1; i < test.size(); i++)
		cout << test[i];
	//
}
