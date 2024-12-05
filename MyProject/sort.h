#ifndef SORT_H
#define SORT_H
#include "telephone_info.h"
long long make_seconds(info* element);
long long make_number(info* element);
void swap_info(info** arr, int i, int j);
void qsort(info** arr, int L_point, int R_point, long long(*criteriy)(info* data));
void heaping(info** arr, int size, int element, long long(*criteriy)(info* data));
void heapsort(info** arr, int size, long long(*criteriy)(info* data));
#endif