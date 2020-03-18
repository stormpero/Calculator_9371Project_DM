#include "Allfunc.h"

int NZER_N_B(vector<int> a) //Проверка на ноль : если число не равно нулю, то «да» иначе «нет»
{
	if ((a.size() == 1) && (a[0] == 0))
		return 0;
	else
		return 1;
}	
