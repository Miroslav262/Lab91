#ifndef FILE_READER_H
#define FILE_READER_H
#include "telephone_info.h"
#include "file_reader.h"
date convert_date(char* str);
time_ convert_time(char* str);
void reading(info* info_name[], const char* path, int& size);

#endif