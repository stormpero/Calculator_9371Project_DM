#include "Allfunc.h"


vector<int> DIV_NN_Dk(vector<int> vector_1, vector<int> vector_2) {

	if (vector_1.empty() || vector_2.empty()) //ѕроверка на пустой
		throw "Empty input";



	if (COM_NN_D(vector_1, vector_2) == 1) { //≈сли 1й вектор < 2го
		vector<int> number = { 0 };
		return number;
	}

	if (COM_NN_D(vector_1, vector_2) == 0) { //≈сли векторы равны
		vector<int> number = { 1 };
		return number;
	}



	if (COM_NN_D(vector_1, vector_2) == 2) {      //≈сли 2й больше 1го


		vector<int> number = { 0 };               //это цела€ часть числа при делении 2го на 1е

		while (COM_NN_D(vector_1, vector_2) == 2 ) { //ƒалее идет подсчет целого и дополненна€ функци€ ћакса, так как иначе нихрена не получалось // до $$$$$
			vector <int> a = vector_1, b = vector_2;
			vector <int> result(a.size());                         //—озданим вектор, который хранит резльтат вычитани€, и назначим ему размерность большего числа
			while (a.size() != b.size())  b.insert(b.begin(), 0); // ≈сли вектор b меньше по размерности, то добавим в его начало нули
			for (int i = a.size() - 1; i >= 0; i--) // ÷икл вычитани€
			{
				result[i] = a[i] - b[i];
				if (result[i] < 0)
				{
					result[i] += 10;
					a[i - 1]--;
				}
			}
			while (result[0] == 0) // ≈сли после вычитани€ в начале вектора остают€ нули, то их  нужно убрать
			{

				result.erase(result.begin());

			}//$$$$$$$$

			while (b[0] == 0) // ј вот тут дополнение: ≈сли после вычетани€ в начале вектора остают€ нули, то их  нужно убрать 
			{

				b.erase(b.begin());

			}

			number = ADD_1N_N(number); // увеличиваем целое
			vector_1 = result;
		}

		if (COM_NN_D(vector_1, vector_2) == 0) // если дел€тс€ нацело, то увеличиваем вектор еще на 1цу
			number = ADD_1N_N(number);



		for (int i = 1; i < number.size(); i++) { //“ак как мы считаем до 1й значащей цифры то остальное замен€ем нул€ми

			number[i] = 0;
		}



		/*for (int i = 0; i < number.size(); i++)
			cout << number[i];*/                       //¬ывод оставил дл€ пинтестов


		return number;
	}



}