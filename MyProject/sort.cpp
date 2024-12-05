#include "sort.h"
#include "telephone_info.h"
#include "filter.h"
#include <iostream>
long long make_seconds(info*element)
{
	return element->lasting.hours*3600+element->lasting.minutes*60+element->lasting.seconds;
}
long long make_number(info *element)
{
	long long number_=element->number[1]-48;
	for(int i = 2; i<=12; i++)
	{
		number_ = number_*10+(element->number[i]-48);
	}
	return number_;
}
void swap_info(info**arr, int i, int j)
{
info buf = *arr[i];
*arr[i] = *arr[j];
*arr[j] = buf;
}
void qsort(info**arr, int L_point, int R_point, long long(*criteriy)(info*data))
{
  int L = L_point;
  int R = R_point;
  int center = (L_point+R_point)/2;
  while(L<R)
    {
      if(criteriy(arr[L])<=criteriy(arr[center]) && L<center) L++;
      if(criteriy(arr[R])>=criteriy(arr[center]) && R>center) R--;
      if(criteriy(arr[L])>=criteriy(arr[center]) && criteriy(arr[R])<=criteriy(arr[center]))
      {
        swap_info(arr, L, R);
        if(L == center)
        {
          center = R;
        }
        else if(R == center)
        {
          center = L;
        }
      }
    }
  if(L - L_point>1) qsort(arr, L_point, center, criteriy);
  if(R_point-R>1) qsort(arr, R, R_point, criteriy);
}
void heaping(info**arr, int size, int element, long long(*criteriy)(info*data))
{
  int flag = -1;
if(2*element+2 <= size-1) flag = 0;
if(element==size-1) flag = 2;//куча завершена
if(2*element+1 == size-1) flag = 1;//полукуча
    if(flag == 0)
    {
      heaping(arr, size, 2*element+1, criteriy);
      heaping(arr, size, 2*element+2, criteriy);
      if(criteriy(arr[2*element+1])>=criteriy(arr[2*element+2]) && criteriy(arr[2*element+1])>criteriy(arr[element]))
      {
        swap_info(arr, 2*element+1, element);
      }
      else if(criteriy(arr[2*element+1])<criteriy(arr[2*element+2]) && criteriy(arr[2*element+2])>criteriy(arr[element]))
      {
        swap_info(arr, 2*element+2, element);
      }
    }
    else if(flag == 1)
    {
      if(criteriy(arr[2*element+1])>criteriy(arr[element]))
      {
        swap_info(arr, 2*element+1, element);
      }
    }
}
void heapsort(info**arr, int size, long long(*criteriy)(info*data))
{
  for(int i = size-1; i>=0; i--)
  {
    heaping(arr, i+1, 0, criteriy);
    swap_info(arr, 0, i);
  }
}
info** sorting(info** array, int size, bool method, bool kreteriy, bool filter_criteria, int & result_size)
{
    info** filtered;
    if (!filter_criteria)
    {
        filtered = filter(array, size, check_by_mobile, result_size); // фильтрация по тарифу "мобильный"
    }
    else 
    {
        filtered = filter(array, size, check_by_date, result_size); // фильтрация по ноябрю 21 года
    }
		if(!kreteriy)
		{
			if(method)
			{
        qsort(filtered, 0, result_size - 1, make_seconds);//quick, по продолжительности
			}
			else
			{
        heapsort(filtered, result_size, make_seconds);//heap, по продолжительности
			}
		}
		else 
		{
			if(method)
			{
        qsort(filtered, 0, result_size - 1, make_number);//quick, по номеру
			}
			else
			{
        heapsort(filtered, result_size, make_number);//heap, по номеру
			}
		}
    return filtered;
}
void cout_info(info** information, int size, bool inverse)
{
    if (inverse) {
        for (int i = 0; i < size; i++)
        {
            /********** вывод номера **********/
            std::cout << "Номер: ";
            std::cout << information[i]->number << '\n';
            /********** дата звонка **********/
            std::cout << "Дата звонка: ";
            std::cout << information[i]->date.day << "." << information[i]->date.month << "." << information[i]->date.year << '\n';
            /********** время звонка **********/
            std::cout << "Время звонка: ";
            std::cout << information[i]->time.hours << ":" << information[i]->time.minutes << ":" << information[i]->time.seconds << '\n';
            /********** продолжительность звонка **********/
            std::cout << "Продолжительность звонка: ";
            std::cout << information[i]->lasting.hours << ":" << information[i]->lasting.minutes << ":" << information[i]->lasting.seconds << '\n';
            /********** тариф **********/
            std::cout << "Тариф: ";
            std::cout << information[i]->rate << '\n';
            /********** стоимость минуты разговвора **********/
            std::cout << "Стоимость минуты разговвора: ";
            std::cout << information[i]->cost << '\n';
            std::cout << '\n';
        }
    }
    else
    {
        for (int i = size - 1; i >= 0; i--)
        {
            /********** вывод номера **********/
            std::cout << "Номер: ";
            std::cout << information[i]->number << '\n';
            /********** дата звонка **********/
            std::cout << "Дата звонка: ";
            std::cout << information[i]->date.day << "." << information[i]->date.month << "." << information[i]->date.year << '\n';
            /********** время звонка **********/
            std::cout << "Время звонка: ";
            std::cout << information[i]->time.hours << ":" << information[i]->time.minutes << ":" << information[i]->time.seconds << '\n';
            /********** продолжительность звонка **********/
            std::cout << "Продолжительность звонка: ";
            std::cout << information[i]->lasting.hours << ":" << information[i]->lasting.minutes << ":" << information[i]->lasting.seconds << '\n';
            /********** тариф **********/
            std::cout << "Тариф: ";
            std::cout << information[i]->rate << '\n';
            /********** стоимость минуты разговвора **********/
            std::cout << "Стоимость минуты разговвора: ";
            std::cout << information[i]->cost << '\n';
            std::cout << '\n';
        }
    }
}
/*
1)Вывести все телефонные разговоры на мобильные телефоны.
2)Вывести все телефонные разговоры в ноябре 2021 года.

Методы сортировки:

1)Пирамидальная сортировка (Heap sort)
2)Быстрая сортировка (Quick sort)

Критерии сортировки:

1)По убыванию продолжительности разговора
2)По возрастанию номера телефона
*/