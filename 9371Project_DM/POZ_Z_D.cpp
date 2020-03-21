#include "Allfunc.h"

int POZ_Z_D(vector<int> num)
{
	if ((num[0] == 0) && (num.size() == 1))
		return 0;
	else if (num[0] == 1)
		return 1;
	else
		return 2;
}