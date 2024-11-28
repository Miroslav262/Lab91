#ifndef TELEPHONE_INFO_H
#define TELEPHONE_INFO_H

#include "constants.h"
//номер дата время продолжительность тариф стоимость
struct date
{
    int day;
    int month;
    int year;
};
struct time_
{
    int hours;
    int minutes;
    int seconds;
};
struct info
{
    char number[MAX_STRING_SIZE];
    date date;
    time_ time;
    time_ lasting;
    char rate[MAX_STRING_SIZE];
    double cost;
};


#endif