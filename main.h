#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

class sorting {
    int N = 0;
    int *arr = nullptr;
    void bubble(int *arr);
    void ShellSort(int *a);
    void ShellSortFibonachi (int *a);
    void reverse_array ();
public:
    sorting (int n);
    ~sorting ();
    void create_array ();
    void create_array_repit_key();
    void print_array ();
    void sort_on ();
};


#endif // MAIN_H_INCLUDED
