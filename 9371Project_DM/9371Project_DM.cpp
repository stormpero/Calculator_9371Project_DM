#include "Allfunc.h"


int main()
{
	int sign = 1; //ѕеременна€ дл€ хранени€ знака числа(1 - минус, 0 - плюс)
	vector <int> test = { 0,1,2,3,4 };

	test = MUL_ZM_Z(test);
	for (int i = 0; i < 5; i++)
		cout << test[i];
	
}
