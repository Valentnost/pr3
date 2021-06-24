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
    cout << "�������� ������� ��� ������������� ������ �� "<< N <<" ���������" << endl << endl;
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

    cout << "��������������� ������" << endl;
    cout << "���������� ���������" << endl;
    bubble(copy_array());
    cout << "���������� ������� �����" << endl;

    cout << "������������� ������" << endl;

}
void sorting:: bubble(int * a)      //���������� ���������
{
	long long int main_count =0, extra_count = 0;
    clock_t  t0, t;
    t0 = clock();
	int tmp, i, j;

	for (i = 1,++extra_count; i < N; i++, ++extra_count){
		for (j = N-1, ++extra_count; j >= i;  ++extra_count, j--){
			if (a[j-1] > a[j]){    //����������� �� �����������
				tmp = a[j-1];    main_count++;
				a[j-1] = a[j]; main_count++;
				a[j] = tmp;      main_count++;
			}
		}
	}

    t = clock();
	cout << "\t���������� �������� ������������: " << main_count << endl;
	cout << "\t���������� ��������������� ������������: " << extra_count << endl;
	cout << "\t����� ������ ���������: " << double(t-t0)/CLOCKS_PER_SEC << endl;
}
void sorting::ShellSort (int *a)     //���������� �����
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
    for (m=0, extra_count++; m<t; m++,     extra_count++)                                 //��������������� ���������� ��� ����������
    {
        k = h[m];   extra_count++;
        for (i=k, extra_count++; i<N; i++, extra_count++)                             //�� ����� ����� ����� ������� � ������ ���� h[m]
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
	cout << "���������� �������� ������������: " << main_count << endl;
	cout << "���������� ��������������� ������������: " << extra_count << endl;
	cout << "����� ������ ���������: " << double(t-t0)/CLOCKS_PER_SEC << endl;
}
void sorting::ShellSortFibonachi (int *a)     //���������� ����� (��� �������� ������� ���������)
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
    for (m=0, extra_count++; m<t; m++,extra_count++)                                 //��������������� ���������� ��� ����������
    {
        k = h[m];   extra_count++;
        for (i=k, extra_count++; i<N; i++, extra_count++)                             //�� ����� ����� ����� ������� � ������ ���� h[m]
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
	cout << "���������� �������� ������������: " << main_count << endl;
	cout << "���������� ��������������� ������������: "<< extra_count << endl;
    cout << "����� ������ ���������: " << double (t-t0)/CLOCKS_PER_SEC << endl;
}
// ����������� ����������


// ���������� ������������
// ���������� ��������������� ������������
// ����� ������ ���������
long long main_count =0, extra_count = 0;

void sorting::swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    extra_count += 3;
}

// ������� ��������.
// data-����������� ������, counters-������ ��� ���������, N-����� ��������� � data

void sorting::createCounters(int* data, long* counters, long N) {
    // i-� ������ count ����������, ������� � ������ counters+256*i
    memset(counters, 0, 256 * sizeof(int) * sizeof(long));

    unsigned char* bp = (unsigned char*)data;
    unsigned char* dataEnd = (unsigned char*)(data + N);
    unsigned int short i;

    while (bp != dataEnd) {
        // ����������� ���������� ���� �� ��������� *bp
        // i - ������� ������ ���������
        for (i = 0; i < sizeof(int); i++) {
            counters[256 * i + *bp++]++;
        }
    }
}

// ������� radixPass ��������� � �������� ����������
// ����� ����� Offset,
// ����� ��������� N,
// �������� ������ source,
// ������ dest, ���� ����� ������������ �����, ��������������� �� ����� Offset
// ������ ��������� count, ��������������� �������� �������.

void sorting::radixPass(short Offset, long N, int* source, int* dest, long* count) {
    // ��������� ����������
    int* sp;
    long s, c, i, * cp;
    unsigned char* bp;


    // ��� 3
    s = 0; // ��������� ����������, �������� ����� �� ������ ������
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
    // ��� 4
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

// ����������� ������ in �� N ���������
void sorting::radixSort (int* &in, long N) {
    int *out = new int[N];
    long *counters = new long[sizeof(int)*256], *count;
    createCounters(in, counters, N);
    for (unsigned int short i=0; i<sizeof(int); i++) {
        count = counters + 256*i; // count - ������ ��������� ��� i-�� �������
        if ( count[0] == N ) continue; // (*** �� ����)
        radixPass (i, N, in, out, count); // ����� ������� ���� ������� �
        swap(in, out); // �������� ������� �������� �������
    }
     // �� ��������� ��������
    delete out; // ��� ���������� �������� �� ������� �������.
    delete counters;
}

