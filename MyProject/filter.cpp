#include "filter.h"
#include "telephone_info.h"
#include <iostream>
info** filter(info* array[], int size, bool (*check)(info* element), int& result_size)
{
	info** result = new info * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_by_mobile(info* element)
{
	return(element->rate == "мобильный");
}

bool check_by_date(info* element)
{
	return(element->date.year == 2021 && element->date.month == 11);
}

int main()
{
	std::cout << "ins work!";
}
/*
1)Вывести все телефонные разговоры на мобильные телефоны.
2)Вывести все телефонные разговоры в ноябре 2021 года.

Методы сортировки:

1)Пирамидальная сортировка (Heap sort)
2)Быстрая сортировка (Quick sort)

Критерии сортировки:

1)По убыванию продолжительности разговора
2)По возрастанию номера телефона, а в рамках одного номера по убыванию стоимости разговора
*/