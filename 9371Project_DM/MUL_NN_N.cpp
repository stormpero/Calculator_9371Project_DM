
#include "Allfunc.h"

vector<int> MUL_NN_N(vector<int> first, vector<int> second)
{
    // Проверяем если в функцию передан пустой вектор
    if (first.empty() || second.empty())
        throw "Empty input";

    // Сделаем бОльший по длине вектор первым
    if (first.size() < second.size())
    {
        vector<int> temp(first);
        first = second;
        second = temp;
    }

    vector<int> result{ 0 }, k{ 0 };
    for (int i(second.size() - 1); i >= 0; --i, k = ADD_1N_N(k))
    {
        // Перемножаем первый вектор на каждую цифру второго
        vector<int> addition(MUL_ND_N(first, second[i]));

        // Сдвигаем число на 1 разряд влево (как в умножении в столбик)
        addition = MUL_Nk_N(addition, k);

        // Складываем все эти числа и записываем в результат
        result = ADD_NN_N(result, addition);
    }

    return result;
}