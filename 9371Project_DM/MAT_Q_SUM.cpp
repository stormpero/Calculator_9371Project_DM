#include "Allfunc.h"

vector<vector<int>> MAT_Q_SUM(vector<vector<int>> a, vector<vector<int>> b, int row)
{
	vector<vector<int>> c(row);//добавляем двумерный вектор,в который будет вноситься результат сложения
	for (int i = 0; i < row; i++)
	{
		c[i].resize(row);
		for (int j = 0; j < row; j++)
			c[i][j] = a[i][j] + b[i][j];//сложение элементов матриц
	};
	return(c);//возвращаем результирующую матрицу
}