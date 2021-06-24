#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

class sorting {
    int N = 0;
    int *arr = 0;
    void bubble(int *arr);
    void radixPass(short Offset, long N, int* source, int* dest, long* count);
    void createCounters(int* data, long* counters, long N);
    void swap(int* a, int* b);
public:
    sorting (int n);
    ~sorting ();
    void ShellSort (int *a);
    void ShellSortFibonachi (int *a);
    void radixSort (int* &in, long N);
    void create_array ();
    void create_array_repit_key();
    void print_array ();
    int* copy_array ();
    void sort_on ();
};


#endif // MAIN_H_INCLUDED
