#include "processing.h"
#include "sort.h"
int process(info** array, int size)
{
	double sum_count = 0, sum_time = 0;
	for (int i = 0; i<size; i++) 
	{
		sum_count += make_seconds(array[i]) * array[i]->cost;
		sum_time += make_seconds(array[i]);
	}
	return sum_count / sum_time;

}