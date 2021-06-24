#include <iostream>
#include <windows.h>
#include "main.h"

#define N1 10000
#define N2 30000
#define N3 70000
#define N4 100000

using namespace std;

int main()
{
    SetConsoleCP (1251);
    SetConsoleOutputCP (1251);

    cout << "\t1. Тестирование массива без повторяющихся ключей" << endl;
    cout << "\t2. Тестирование массива с повторяющимися ключами" << endl;
    cout << "\t0. выход" << endl;

    char menu;

    do {
        cin >> menu;
        switch (menu){
        case '1':
            sorting testN1 (N1);
            testN1.create_array();
            testN1.sort_on();
            break;
        }
        system ("pause");
    } while (menu != '0');


    return 0;
}
