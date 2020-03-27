#include "Allfunc.h"	

vector<int>  MOD_ZZ_Z(vector<int> a, vector<int> b) // Ермольев Максим Викторович
{
	vector<int> q; // Частное
	vector<int> aq_or_bq; // Значение, которое хранит произведение меньшего числа на частное
		vector<int> result; // Перменнная, которая хранит результат 
	q = DIV_ZZ_Z(a, b); // Частное от деления чисел а b 
	if (COM_NN_D(a, b) == 2) // Если а, больше b
	{
		aq_or_bq = MUL_ZZ_Z(b, q); // То целая часть это частное умноженное на меньшее из 
		result = SUB_ZZ_Z(a, aq_or_bq); // Отнимаем целую часть от a
	}
	else
		if (COM_NN_D(a, b) == 1)
		{
			aq_or_bq = MUL_ZZ_Z(a, q);
			result = SUB_ZZ_Z(b, aq_or_bq);
		}

	return(result);   // Возвращаемое значение
}
