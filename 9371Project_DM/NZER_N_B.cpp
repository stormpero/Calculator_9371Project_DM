#include "Allfunc.h"

int NZER_N_B(vector<int> a)
{
	if ((a.size() == 2) && (a[1] == 0)) // Смотрим размер, и элемент
		return false;
	else
		return true;
}