#include "Allfunc.h"

int NZER_N_B(vector<int> a)
{
	if ((a.size() == 1 | 2) && (a[a.size()] == 0)) // Смотрим размер, и элемент
		return false;
	else
		return true;
}