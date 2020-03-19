#include "Allfunc.h"

vector <int>SUB_NDN_N(vector<int> a, vector<int> b, int k)
{
	vector<int> tempb = MUL_ND_N(b, k);// save result of b * k (Для того, чтобы не считать его 2 раза)

	if (COM_NN_D(tempb, a) == 2) // если b * k > a то результат = b*k - a, если b * k = a(это возможно только в том случае когда a = b = 0), то результат = b*k - a = a*k - b = 0
		return SUB_NN_N(tempb, a);
	else return SUB_NN_N(MUL_ND_N(a, k), b);// иначе результат = b*k - a,                     ( если b * k = a(это возможно только в том случае когда a = b = 0), то результат = b*k - a = a*k - b = 0 )
}