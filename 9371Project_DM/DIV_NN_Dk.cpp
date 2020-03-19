#include "Allfunc.h"


vector<int> DIV_NN_Dk(vector<int> vector_1, vector<int> vector_2) {

	if (vector_1.empty() || vector_2.empty()) //Проверка на пустой
		throw "Empty input";



	if (COM_NN_D(vector_1, vector_2) == 1) { //Если 1й вектор < 2го
		vector<int> number = { 0 };
		return number;
	}

	if (COM_NN_D(vector_1, vector_2) == 0) { //Если векторы равны
		vector<int> number = { 1 };
		return number;
	}



	if (COM_NN_D(vector_1, vector_2) == 2) {      //Если 2й больше 1го


		vector<int> number = { 0 };               //это целая часть числа при делении 2го на 1е

		while (COM_NN_D(vector_1, vector_2) == 2) { //Далее идет подсчет целого и дополненная функция Макса, так как иначе нихрена не получалось // до $$$$$
			vector <int> a = vector_1, b = vector_2;
			vector <int> result(a.size());                         //Созданим вектор, который хранит резльтат вычитания, и назначим ему размерность большего числа
			while (a.size() != b.size())  b.insert(b.begin(), 0); // Если вектор b меньше по размерности, то добавим в его начало нули
			for (int i = a.size() - 1; i >= 0; i--) // Цикл вычитания
			{
				result[i] = a[i] - b[i];
				if (result[i] < 0)
				{
					result[i] += 10;
					a[i - 1]--;
				}
			}
			while (result[0] == 0) // Если после вычитания в начале вектора остаютя нули, то их  нужно убрать
			{

				result.erase(result.begin());

			}//$$$$$$$$

			while (b[0] == 0) // А вот тут дополнение: Если после вычетания в начале вектора остаютя нули, то их  нужно убрать 
			{

				b.erase(b.begin());

			}

			number = ADD_1N_N(number); // увеличиваем целое
			vector_1 = result;
		}



		for (int i = 1; i < number.size(); i++) { //Так как мы считаем до 1й значащей цифры то остальное заменяем нулями

			number[i] = 0;
		}



		/*for (int i = 0; i < number.size(); i++)
			cout << number[i];*/                       //Вывод оставил для пинтестов


		return number;
	}



}