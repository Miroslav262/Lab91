#include "telephone_info.h"
#include "processing.h"
double make_m(info* element)
{
	return element->lasting.hours * 60 + element->lasting.minutes + element->lasting.seconds/60;
}
double process(info** array, int size)
{
	double sum_count = 0, sum_time = 0;
	for (int i = 0; i<size; i++) 
	{
		sum_count += (make_m(array[i]) * (array[i]->cost));
		sum_time += make_m(array[i]);
	}
	return (sum_count / sum_time);

}
//Найти среднюю стоимость одной секунды разговора 
//(общую стоимость всех разговоров разделить на суммарную продолжительность в секундах)