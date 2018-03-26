/* 
 * File:   main.cpp
 * Author: Sili Guo
 * Created on May 3, 2017
 * Purpose: Sorting Comparison: Heap, merge and quick
 */
//System library
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

//Global constant

//Function Prototype
void fillAry(int [], int);
void heapSort(int [], int);
void buildMaxHeap(int [], int);
void maxHeapify(int[], int, int);
int parent(int);
int left(int);
int right(int);
void mergeSort(int [], int, int);
void merge(int [], int, int, int);
void quickSort(int [], int, int);
int partition(int [], int, int);
void swap(int &, int &);

int main(int argc, char** argv) {
    //Random number seed
    srand(static_cast<unsigned int> (time(0)));

    //Declare variables
    int *ary;
    int size;
    int beg, end;

    //Output title
    cout << "Sorting Comparison:" << endl;
    //Heapsort
    cout << "\nHeapsort (nlogn):" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < 4; i++) {
        //Initialize size and ary
        size = pow(2, i) *1e7;
        ary = new int[size];
        fillAry(ary, size);
        //Heapsort
        beg = time(0);
        heapSort(ary, size);
        end = time(0);
        //Output result
        cout << "Array size = " << size / (1e7) << "e7" << endl;
        cout << "Time = " << end - beg << " sec" << endl;
        cout << endl;
    }
   
    //Mergesort
    cout << "\nMergeSort (nlogn):" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < 4; i++) {
        //Initialize size and ary
        size = pow(2, i) * 1e7;
        ary = new int[size];
        fillAry(ary, size);
        //Heapsort
        beg = time(0);
        mergeSort(ary, 0, size - 1);
        end = time(0);
        //Output result
        cout << "Array size = " << size / (1e7) << "e7" << endl;
        cout << "Time = " << end - beg << " sec" << endl;
        cout << endl;
    }

    //Quicksort
    cout << "\nQuicksort (nlogn):" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 1; i < 5; i++) {
        //Initialize size and ary
        size = pow(2, i) * 1e5;
        ary = new int[size];
        fillAry(ary, size);
        //Heapsort
        beg = time(0);
        quickSort(ary, 0, size - 1);
        end = time(0);
        //Output result
        cout << "Array size = " << size / (1e5) << "e5" << endl;
        cout << "Time = " << end - beg << " sec" << endl;
        cout << endl;
    }

    //Exit
    delete [] ary;
    return 0;
}

void fillAry(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 90 + 10;
    }
}

//Heapsort

void heapSort(int a[], int size) {
    int heapSize = size;
    buildMaxHeap(a, size);
    for (int i = size - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapSize--;
        maxHeapify(a, heapSize, 0);
    }
}

void buildMaxHeap(int a[], int size) {
    for (int i = (size / 2); i >= 0; i--) {
        maxHeapify(a, size, i);
    }
}

void maxHeapify(int a[], int heapSize, int i) {
    int l = left(i) + 1;
    int r = right(i) + 1;
    int largest;
    if (l < heapSize && a[l] > a[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r < heapSize && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        maxHeapify(a, heapSize, largest);
    }
}

int parent(int i) {
    return (i / 2);
}

int left(int i) {
    return (2 * i);
}

int right(int i) {
    return (2 * i + 1);
}

//Mergesort

void mergeSort(int a[], int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

void merge(int a[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = new int [n1 + 1];
    int *R = new int [n2 + 1];
    int i, j, k;
    for (i = 0; i < n1; i++) {
        L[i] = a[p + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = a[q + j + 1];
    }
    L[n1] = 10000;
    R[n2] = 10000;
    i = 0;
    j = 0;
    for (k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
    }
    delete []L;
    delete []R;
}

//Quicksort

void quickSort(int a[], int p, int r) {
    int q;
    if (p < r) {
        q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}

int partition(int a[], int p, int r) {
    int x = a[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (a[j] <= x) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}