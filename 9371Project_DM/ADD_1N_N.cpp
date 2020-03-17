#include "Allfunc.h"

vector<int> ADD_1N_N(vector<int> input)
{
    // Создаем копию входного вектора
    vector<int> res(input);

    // Проверяем если в функцию передан пустой вектор
    if (input.empty())
        throw "Empty input";

    // Сохраняем в память число 1,
    // на которое необходимо увеличить входное значение
    int mem(1);

    // В цикле идем с конца к началу вектора (пока в памяти что-то хранится)
    for (int i(input.size() - 1); mem && i >= 0; --i)
    {
        // Если цифра не попадает в диапазон 0-9,
        // кидаем исключение о неправильном вводе
        if (input[i] < 0 || input[i] > 9)
            throw "Input is not a valid number";

        res[i] = (input[i] + mem) % 10;
        mem    = (input[i] + mem) / 10;
    }

    // Если прошлись по всему вектору, но память все еще не пуста,
    // добавляем в начало новый элемент со значением из памяти
    if (mem)
        res.insert(res.begin(), mem);

    return res;
}