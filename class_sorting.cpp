#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
using namespace std;

sorting:: sorting (int n){
    N = n;
    arr = new int [N];
}
sorting:: ~sorting (){
    delete [] arr;
}
void sorting:: create_array(){
    ifstream f;
    f.open ("test_numbers.txt");
    for (int i=0; i<N; i++){
        f >> arr[i];
    }
    cout << "Создание массива без повторяющихся ключей на "<< N <<" элементов" << endl << endl;
}

void sorting:: print_array (){
    for (int i=0; i<N; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int* sorting:: copy_array (){
    int* new_arr;
    new_arr = new int [N];
    for (int i=0; i<N; i++)
        new_arr[i] = arr[i];
    return new_arr;
}
void sorting:: sort_on (){

    cout << "Неупорядоченный массив" << endl;
    cout << "Сортировка пузырьком" << endl;
    bubble(copy_array());
    cout << "Сортировка методом Шелла" << endl;

    cout << "Упорядоченный массив" << endl;

}
void sorting:: bubble(int * a)      //сортировка пузырьком
{
	long long int main_count =0, extra_count = 0;
    clock_t  t0, t;
    t0 = clock();
	int tmp, i, j;

	for (i = 1,++extra_count; i < N; i++, ++extra_count){
		for (j = N-1, ++extra_count; j >= i;  ++extra_count, j--){
			if (a[j-1] > a[j]){    //отсортируем по возрастанию
				tmp = a[j-1];    main_count++;
				a[j-1] = a[j]; main_count++;
				a[j] = tmp;      main_count++;
			}
		}
	}

    t = clock();
	cout << "\tКоличество основных присваиваний: " << main_count << endl;
	cout << "\tКоличество вспомогательных присваиваний: " << extra_count << endl;
	cout << "\tВремя работы алгоритма: " << double(t-t0)/CLOCKS_PER_SEC << endl;
}
void sorting::ShellSort (int *a)     //сортировка Шелла
{
    long long main_count =0, extra_count = 0;
    clock_t t0, t1;
    t0 = clock();
    const int t=(int)(log(N)/log(2)-1);
    extra_count++;
    int i, j, k, m, x;
    int *h = (int *) malloc (t*sizeof(int));

    h[t-1] = 1; extra_count++;
    for (m=t-2, extra_count++; m>=0; m--, extra_count++)
    {
        h[m]= h[m+1] * 2 + 1;   extra_count++;
    }
    for (m=0, extra_count++; m<t; m++,     extra_count++)                                 //последовательно перебираем все расстояния
    {
        k = h[m];   extra_count++;
        for (i=k, extra_count++; i<N; i++, extra_count++)                             //до конца цикла метод вставки с учетом шага h[m]
        {
            x = a[i];   main_count++;
            j = i-k;    extra_count++;
            while (j>=0 && x<a[j])
            {
                a[j+k]=a[j];    main_count++;
                j -= k;         extra_count++;
            }
            a[j+k] = x;         main_count++;
        }
    }
    free (h);
    t1 = clock();
	cout << "Количество основных присваиваний: " << main_count << endl;
	cout << "Количество вспомогательных присваиваний: " << extra_count << endl;
	cout << "Время работы алгоритма: " << double(t-t0)/CLOCKS_PER_SEC << endl;
}
void sorting::ShellSortFibonachi (int *a)     //сортировка Шелла (шаг задается числами фибоначчи)
{
    long long main_count =0, extra_count = 0;
    clock_t t0, t1;
    t0 = clock();

    int t = 0;
    for (int i = 1, j = 1; i < N / 2; t++){
        i = i + j;
        j = i - j;
    }
    int i, j, k, m, x;
    int *h = (int *) malloc (t*sizeof(int));
    h[t-1] = 1; extra_count++;
    h[t-2] = 2; extra_count++;

    for (m=t-2, extra_count++; m>=1; m--, extra_count++)
    {
        h[m-1]= h[m] + h[m+1];   extra_count++;
    }
    for (m=0, extra_count++; m<t; m++,extra_count++)                                 //последовательно перебираем все расстояния
    {
        k = h[m];   extra_count++;
        for (i=k, extra_count++; i<N; i++, extra_count++)                             //до конца цикла метод вставки с учетом шага h[m]
        {
            x = a[i];   main_count++;
            j = i-k;    extra_count++;
            while (j>=0 && x<a[j])
            {
                a[j+k]=a[j];    main_count++;
                j -= k;         extra_count++;
            }
            a[j+k] = x;         main_count++;
        }
    }
    free (h);

    t1 = clock();
	cout << "Количество основных присваиваний: " << main_count << endl;
	cout << "Количество вспомогательных присваиваний: "<< extra_count << endl;
    cout << "Время работы алгоритма: " << double (t-t0)/CLOCKS_PER_SEC << endl;
}
// поразрядная сортировка


// Количество присваиваний
// Количество вспомогательных присваиваний
// Время работы алгоритма
long long main_count =0, extra_count = 0;

void sorting::swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    extra_count += 3;
}

// Создать счетчики.
// data-сортируемый массив, counters-массив для счетчиков, N-число элементов в data

void sorting::createCounters(int* data, long* counters, long N) {
    // i-й массив count расположен, начиная с адреса counters+256*i
    memset(counters, 0, 256 * sizeof(int) * sizeof(long));

    unsigned char* bp = (unsigned char*)data;
    unsigned char* dataEnd = (unsigned char*)(data + N);
    unsigned int short i;

    while (bp != dataEnd) {
        // увеличиваем количество байт со значением *bp
        // i - текущий массив счетчиков
        for (i = 0; i < sizeof(int); i++) {
            counters[256 * i + *bp++]++;
        }
    }
}

// Функция radixPass принимает в качестве параметров
// номер байта Offset,
// число элементов N,
// исходный массив source,
// массив dest, куда будут записываться числа, отсортированные по байту Offset
// массив счетчиков count, соответствующий текущему проходу.

void sorting::radixPass(short Offset, long N, int* source, int* dest, long* count) {
    // временные переменные
    int* sp;
    long s, c, i, * cp;
    unsigned char* bp;


    // шаг 3
    s = 0; // временная переменная, хранящая сумму на данный момент
    cp = count;
    /*+*/extra_count += 2;
    int cou = 0;
    for (/*+*/extra_count += 1, i = 256; i > 0; /*+*/extra_count += 2, --i, ++cp) {
        c = *cp;
        *cp = s;
        s += c;
        main_count ++;
        /*+*/extra_count += 2;
        cou++;
    }

    cou = 0;
    // шаг 4
    bp = (unsigned char*)source + Offset;
    /*+*/extra_count += 1;
    sp = source;
    /*+*/extra_count += 1;
    for (/*+*/extra_count++, i = N; i > 0; --i, bp += sizeof(int), ++sp, extra_count += 3) {
        cp = count + *bp;
        dest[*cp] = *sp;
        ++(*cp);
        main_count++;
        /*+*/extra_count += 2;

        cou++;
    }
}

// сортируется массив in из N элементов
void sorting::radixSort (int* &in, long N) {
    int *out = new int[N];
    long *counters = new long[sizeof(int)*256], *count;
    createCounters(in, counters, N);
    for (unsigned int short i=0; i<sizeof(int); i++) {
        count = counters + 256*i; // count - массив счетчиков для i-го разряда
        if ( count[0] == N ) continue; // (*** см ниже)
        radixPass (i, N, in, out, count); // после каждого шага входной и
        swap(in, out); // выходной массивы меняются местами
    }
     // по окончании проходов
    delete out; // вся информация остается во входном массиве.
    delete counters;
}

