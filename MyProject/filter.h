#ifndef FILTER_H
#define FILTER_H
#include "telephone_info.h"
info** filter(info* array[], int size, bool (*check)(info* element), int& result_size);
bool check_by_mobile(info* element);
bool check_by_date(info* element);
#endif