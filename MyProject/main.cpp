#include <iostream>
#include <Windows.h>
#include <locale.h>
#include "constants.h"
#include "file_reader.h"
#include "telephone_info.h"
#include "filter.h"
#include "sort.h"
using namespace std;
int main()
{
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
    cout << "Laboratory work #9. GIT\n";
    cout << "Variant #9. Library Subscription\n";
    cout << "Author: Markushevski Miraslau\n";
    cout << "Group: 24Ping1d\n";
    info** information= new info*[MAX_FILE_ROWS_COUNT];
    info** result_info;
    int size, result_size;
    bool method, criteriy, filter_criteria;
    cout << "Введите метод сортировки\n";
    cout << "Доступные методы сортировки:\n";
    cout << "0 - Пирамидальная сортировка (Heap sort)\n"; //metod = 0
    cout << "1 - Быстрая сортировка (Quick sort)\n"; //metjod = 1
    cin >> method;
    cout << "\n";
    cout << "Введите критерий сортировки\n";
    cout << "Доступные критерии сортировки:\n";
    cout << "0 - По убыванию продолжительности разговора\n"; //criteriy = 0, inverse = 0
    cout << "1 - По возрастанию номера телефона\n"; //criteriy = 1, inverse = 1
    cin >> criteriy;
    cout << "Введите параметр сортировки\n";
    cout << "Доступные параметры сортировки:\n";
    cout << "0 - Вывести все телефонные разговоры на мобильные телефоны\n";//parametr = 0
    cout << "1 - Вывести все телефонные разговоры в ноябре 2021 года\n";//parametr = 1
    cin >> filter_criteria;
    try
    {
        reading(information, "data.txt", size);
        result_info = sorting(information, size, method, criteriy, filter_criteria, result_size);
        cout_info(result_info, result_size, criteriy);
        delete []information;
        delete []result_info;
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
    system("pause");
}
