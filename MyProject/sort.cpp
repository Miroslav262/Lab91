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