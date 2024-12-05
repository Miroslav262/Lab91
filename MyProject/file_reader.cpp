#include "constants.h"
#include "telephone_info.h"
#include <fstream>
date convert_date(char* str)
{
	date arr;
	arr.day = atoi(str);
	arr.month = atoi(str + sizeof(char) * 3);
	arr.year = atoi(str + sizeof(char) * 6);
	return arr;
}
time_ convert_time(char* str)
{
	time_ arr;
	arr.hours = atoi(str);
	arr.minutes = atoi(str + sizeof(char) * 3);
	arr.seconds = atoi(str + sizeof(char) * 6);
	return arr;
}
void reading(info* info_name[], const char* path, int& size)
{
	std::ifstream file;
	file.open(path);
	if (file.is_open())
	{
		size = 0;
		while (!file.eof())
		{
			info* arr = new info;
			file >> arr->number;
			char* date_char = new char[10];
			file >> date_char;
			arr->date = convert_date(date_char);

			char* time = new char[8];
			file >> time;
			arr->time = convert_time(time);

			char* lasting = new char[8];
			file >> lasting;
			arr->lasting = convert_time(lasting);

			file >> arr->rate;

			file >> arr->cost;
			info_name[size] = arr;
			size++;
		}
	}
	else
	{
		throw "Ошибка открытия файла";
	}
}