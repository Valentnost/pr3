#include <iostream>
#include <fstream>
#include <ctime>
#include <math.h>
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
void sorting:: reverse_array (){
    int temp;
    for (int i=0; i < N/2; i++){
        temp = arr[i];
        arr[i] = arr[N-1-i];
        arr[N-1-i] = temp;
    }
}
void sorting:: print_array (){
    for (int i=0; i<N; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void sorting:: sort_on (){

    cout << "\t��������������� ������" << endl;
    cout << "���������� ���������" << endl;
    bubble(arr);
    create_array();

    cout << "���������� ������� �����" << endl;
    ShellSort (arr);
    create_array();

    cout << "���������� ������� ����� (��� ����� ������� ���������)" << endl;
    ShellSortFibonachi (arr);
    //create_array();

    //cout << "����������� ����������" << endl;

    cout << "\t������������� ������" << endl;
    cout << "���������� ���������" << endl;
    bubble(arr);

    cout << "���������� ������� �����" << endl;
    ShellSort (arr);

    cout << "���������� ������� ����� (��� ����� ������� ���������)" << endl;
    ShellSortFibonachi (arr);

    //cout << "����������� ����������" << endl;

    cout << "\t������� ������������� ������" << endl;
    cout << "���������� ���������" << endl;
    reverse_array();
    print_array();
    bubble(arr);

    cout << "���������� ������� �����" << endl;
    reverse_array();
    ShellSort (arr);

    cout << "���������� ������� ����� (��� ����� ������� ���������)" << endl;
    reverse_array();
    ShellSortFibonachi (arr);

    //cout << "����������� ����������" << endl;
}
void sorting:: bubble(int *a)      //���������� ���������
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
void sorting:: ShellSort (int *a)     //���������� �����
{
    long long main_count =0, extra_count = 0;
    clock_t t0, t1;
    t0 = clock();

    const int t=(int)(log(N)/log(2)-1);extra_count++;
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
	cout << "����� ������ ���������: " << double(t1-t0)/CLOCKS_PER_SEC << endl;
}
void sorting:: ShellSortFibonachi (int *a)     //���������� ����� (��� �������� ������� ���������)
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
    cout << "����� ������ ���������: " << double (t1-t0)/CLOCKS_PER_SEC << endl;
}
/* ����������� ����������

typedef unsigned char uchar;
typedef unsigned short int ushort;

long long main_count =0, extra_count = 0;

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
    extra_count += 3;
}

// ������� ��������.
// data-����������� ������, counters-������ ��� ���������, N-����� ��������� � data

void createCounters(int* data, long* counters, long N) {
    // i-� ������ count ����������, ������� � ������ counters+256*i
    memset(counters, 0, 256 * sizeof(int) * sizeof(long));

    uchar* bp = (uchar*)data;
    uchar* dataEnd = (uchar*)(data + N);
    ushort i;

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

void radixPass(short Offset, long N, int* source, int* dest, long* count) {
    // ��������� ����������
    int* sp;
    long s, c, i, * cp;
    uchar* bp;


    // ��� 3
    s = 0, extra_count++; 	// ��������� ����������, �������� ����� �� ������ ������
    cp = count, extra_count++;
    int cou = 0;
    for (++extra_count, i = 256; i > 0; extra_count += 2, --i, ++cp) {
        c = *cp;
        *cp = s;
        s += c;
        ++main_count;
        extra_count += 2;
        cou++;
    }

    cou = 0;
    // ��� 4
    bp = (uchar*)source + Offset;
    extra_count += 1;
    sp = source;
    extra_count += 1;
    for (extra_count++, i = N; i > 0; --i, bp += sizeof(int), ++sp, extra_count += 3) {
        cp = count + *bp;
        dest[*cp] = *sp;
        ++(*cp);
        main_count++;
        extra_count += 2;

        cou++;
    }
}

// ����������� ������ in �� N ���������
// T - ����� ����������� ����� ���

// ������ ����������� ���������� �� ������� ������,
// ��� ����� ����� �� ������ Offset = sizeof(T)-1.

void signedRadixLastPass(short Offset, long N, int* source, int* dest, long* count) {
    int* sp;
    long s, c, i, * cp;
    uchar* bp;

    // ������� ���������� ������������� �����
    long numNeg = 0;
    for (i = 128, extra_count += 1; i < 256; i++, extra_count+= 1) {
        extra_count += 1;
        numNeg += count[i];
    }

    // ������ 128 ��������� count ��������� � ������������� ������.
    // ����������� ����� ������� �����, ������� �� numNeg
    s = numNeg;
    cp = count;
    extra_count += 2;
    for (extra_count+= 1,i = 0; i < 128; extra_count += 1, ++i, extra_count += 1, ++cp) {
        c = *cp;
        *cp = s;
        s += c;
       main_count += 1;
        extra_count += 2;
    }

    // ������ ��� ������������� ����� ����������� �� ������ �������
    s = 0;
    cp = count + 128;
    extra_count += 2;
    for (extra_count += 1, i = 0; i < 128; extra_count += 1, ++i, extra_count += 1, ++cp) {
        c = *cp;
        *cp = s;
        s += c;
        main_count += 1;
        extra_count += 2;
    }


    bp = (uchar*)source + Offset;
    sp = source;
    extra_count += 2;
    for (extra_count += 1, i = N; i > 0; --i, extra_count += 1, bp += sizeof(int), extra_count += 1, ++sp) {
        cp = count + *bp;
        dest[*cp] = *sp;
        ++(*cp);
        main_count += 1;
        extra_count += 2;
    }
}

void signedRadixSort(int* a) {
    clock_t t0, t;
    t0 = clock();
    int* out = new int[N];
    ushort i;

    long* counters = new long[sizeof(int) * 256], * count;

    createCounters(a, counters, N);

    for (++extra_count, i = 0; i < sizeof(int) - 1; ++extra_count, i++) {
        count = counters + 256 * i, ++extra_count;
        if (count[0] == N) continue;
        radixPass(i, N, a, out, count);
        swap(a, out);
    }
    count = counters + 256 * i;
    extra_count += 1;
    signedRadixLastPass(i, N, a, out, count);
    swap(a, out);

    a = out;
    delete[] counters;

    t = clock();
	cout << "���������� �������� ������������: " << main_count << endl;
	cout << "���������� ��������������� ������������: "<< extra_count << endl;
    cout << "����� ������ ���������: " << double (t-t0)/CLOCKS_PER_SEC << endl;
}*/


