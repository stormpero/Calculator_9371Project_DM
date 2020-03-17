#include "Allfunc.h"

std::vector<int> MUL_ZM_Z(std::vector<int> input)
{
	std::vector<int> res(input);
	if (input.empty() )
		throw "Empty input";
	for (int i(input.size() - 1); i >= 0; --i)
	{
		res[i] = input[i] * (-1);	
	}
	return res;
}