#include "Allfunc.h"


int main()
{
	int sign = 1; //ѕеременна€ дл€ хранени€ знака числа(1 - минус, 0 - плюс)
	vector <int> test = { 1,2,3,4 };
	vector <int> test1 = { 1,2,3,4 };
	test = ADD_NN_N(test,test1);

	for (int i = 0; i < 5; i++)
		cout << test[i];
	
}
