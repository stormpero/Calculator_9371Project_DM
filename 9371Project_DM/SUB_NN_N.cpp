#include "Allfunc.h"
vector<int>  SUB_NN_N(vector<int> a, vector<int> b) // �������� ������ ����������
{	            
	if (COM_NN_D(a, b) == 2)      // 2 ���� a>b, 0 ���� a=b, 1 ���� a<b
	{
		vector <int> result(a.size());                         //�������� ������, ������� ������ �������� ���������, � �������� ��� ����������� �������� �����
		while (a.size() != b.size())  b.insert(b.begin(), 0); // ���� ������ b ������ �� �����������, �� ������� � ��� ������ ����
		for (int i = a.size() - 1; i >= 0; i--) // ���� ���������
		{
			result[i] = a[i] - b[i];
			if (result[i] < 0)
			{
				result[i] += 10;
				a[i - 1]--;
			}
		}
		while (result[0]==0) // ���� ����� ��������� � ������ ������� ������� ����, �� ��  ����� ������
		{
			result.erase(result.begin());
		}
		return result;
	}
	if (COM_NN_D(a, b) == 0)
	{
		vector <int> result = { 0 }; // ��� ��� ����������� ����� �����, �� �� �������� ���� 0
		return result;          
	}
	if (COM_NN_D(a, b) == 1)
	{
		vector <int> result(b.size());                         //�������� ������, ������� ������ �������� ���������, � �������� ��� ����������� �������� �����
		while (a.size() != b.size())  a.insert(a.begin(), 0); // ���� ������ a ������ �� �����������, �� ������� � ��� ������ ����
		for (int i = b.size() - 1; i >= 0; i--) // ���� ���������
		{
			result[i] = b[i] - a[i];
			if (result[i] < 0)
			{
				result[i] += 10;
				b[i - 1]--;
			}
		}
		while (result[0] == 0)
		{
			result.erase(result.begin());
		}
		return result;   // ������������ �������� - ��������� ��������� ���� ����������� �����
	}	
}