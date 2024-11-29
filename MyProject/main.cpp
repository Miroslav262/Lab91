#include <iostream>
#include "constants.h"
#include "file_reader.h"
#include "telephone_info.h"
using namespace std;

int main()
{
    cout << "Laboratory work #9. GIT\n";
    cout << "Variant #9. Library Subscription\n";
    cout << "Author: Markushevski Miraslau\n";
    info* information[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        reading(information, "data.txt", size);
        cout << "***** Телефонный разговор *****\n\n";
        for (int i = 0; i < size; i++)
        {
            cout << information[i]->number << '\n';
            cout << information[i]->date.day << "." << information[i]->date.month << "." << information[i]->date.year << '\n';
            cout << information[i]->time.hours << ":" << information[i]->time.minutes << ":" << information[i]->time.seconds << '\n';
            cout << information[i]->lasting.hours << ":" << information[i]->lasting.minutes << ":" << information[i]->lasting.seconds << '\n';
            cout << information[i]->rate << '\n';
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
