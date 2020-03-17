#include "Allfunc.h"
vector<int> MUL_ZM_Z(vector<int> input)
{
    vector<int> res(input);
	if (input.empty())
		throw "Empty input";
	for (int i(input.size() - 1); i >= 0; --i)
	{	
		if (input[i] < 0 || input[i] > 9)
			throw "Input is not a valid number";
		res[i] = (input[i]*(-1));	
	}
	return res;
}