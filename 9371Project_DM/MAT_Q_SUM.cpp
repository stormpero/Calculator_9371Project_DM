#include "Allfunc.h"

vector<vector<int>> MAT_Q_SUM(vector<vector<int>> a, vector<vector<int>> b)
{
	vector<vector<int>> c(a.size());//добавляем двумерный вектор,в который будет вноситься результат сложения
	for (int i = 0; i < a.size(); i++)
	{
		c[i].resize(a.size());
		for (int j = 0; j < a.size(); j++)
			c[i][j] = a[i][j] + b[i][j];//сложение элементов матриц
	};
	return(c);//возвращаем результирующую матрицу
}