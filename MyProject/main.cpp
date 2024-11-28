#include <iostream>
#include <Windows.h>
#include <locale.h>
#include "constants.h"
#include "file_reader.h"
#include "telephone_info.h"
using namespace std;

int main()
{
    cout << "Laboratory work #9. GIT\n";
    cout << "Variant #9. Library Subscription\n";
    cout << "Author: Markushevski Miraslau\n";
    cout << "Group: 24Ping1d\n";
    info* information[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        reading(information, "data.txt", size);
        cout << "***** Телефонный разговор *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** вывод номера **********/
            cout << "Номер: ";
            cout << information[i]->number << '\n';
            /********** дата звонка **********/
            cout << "Дата звонка: ";
            cout << information[i]->date.day << "." << information[i]->date.month << "." << information[i]->date.year << '\n';
            /********** время звонка **********/
            cout << "Время звонка: ";
            cout << information[i]->time.hours << ":" << information[i]->time.minutes << ":" << information[i]->time.seconds << '\n';
            /********** продолжительность звонка **********/
            cout << "Продолжительность звонка: ";
            cout << information[i]->lasting.hours << ":" << information[i]->lasting.minutes << ":" << information[i]->lasting.seconds << '\n';
            /********** тариф **********/
            cout << "Тариф: ";
            cout << information[i]->rate << '\n';
            /********** стоимость минуты разговвора **********/
            cout << "Стоимость минуты разговвора: ";
            cout << information[i]->cost << '\n';
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete information[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
    system("pause");
}