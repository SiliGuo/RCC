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
int ceq, ccal, crel; //equal, calculate, relation

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

    //Output title
    cout << "Sorting Comparison:" << endl;

    //Heapsort
    cout << "\nHeapsort (nlogn):" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < 4; i++) {
        //Initialize size and ary
        size = pow(2, i) * 10;
        ary = new int[size];
        fillAry(ary, size);
        //Set counters to 0
        ceq = ccal = crel = 0;
        //Heapsort
        heapSort(ary, size);
        //Output result
        cout << "Array size = " << size << endl;
        cout << "Equality = " << ceq << endl;
        cout << "Calculation = " << ccal << endl;
        cout << "Relation = " << crel << endl;
        cout << "Composite = " << ceq + ccal + crel << endl;
        cout << endl;
    }

    //Mergesort
    cout << "\nMergeSort (nlogn):" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < 4; i++) {
        //Initialize size and ary
        size = pow(2, i) * 10;
        ary = new int[size];
        fillAry(ary, size);
        //Set counters to 0
        ceq = ccal = crel = 0;
        //Heapsort
        mergeSort(ary, 0, size - 1);
        //Output result
        cout << "Array size = " << size << endl;
        cout << "Equality = " << ceq << endl;
        cout << "Calculation = " << ccal << endl;
        cout << "Relation = " << crel << endl;
        cout << "Composite = " << ceq + ccal + crel << endl;
        cout << endl;
    }

    //Quicksort
    cout << "\nQuicksort (nlogn):" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < 4; i++) {
        //Initialize size and ary
        size = pow(2, i) * 10;
        ary = new int[size];
        fillAry(ary, size);
        //Set counters to 0
        ceq = ccal = crel = 0;
        //Heapsort
        quickSort(ary, 0, size - 1);
        //Output result
        cout << "Array size = " << size << endl;
        cout << "Equality = " << ceq << endl;
        cout << "Calculation = " << ccal << endl;
        cout << "Relation = " << crel << endl;
        cout << "Composite = " << ceq + ccal + crel << endl;
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
    ceq++;
    buildMaxHeap(a, size);
    ceq++;
    ccal++;
    for (int i = size - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapSize--;
        maxHeapify(a, heapSize, 0);
        crel++;
        ccal += 2;
    }
}

void buildMaxHeap(int a[], int size) {
    ceq++;
    ccal++;
    for (int i = (size / 2); i >= 0; i--) {
        maxHeapify(a, size, i);
        crel++;
        ccal++;
    }
}

void maxHeapify(int a[], int heapSize, int i) {
    int l = left(i) + 1;
    int r = right(i) + 1;
    int largest;
    ceq += 2;
    ccal += 2;
    crel += 2;
    if (l < heapSize && a[l] > a[i]) {
        largest = l;
        ceq++;
    } else {
        largest = i;
        ceq++;
    }
    crel += 2;
    if (r < heapSize && a[r] > a[largest]) {
        largest = r;
        ceq++;
    }
    crel++;
    if (largest != i) {
        swap(a[i], a[largest]);
        maxHeapify(a, heapSize, largest);
    }
}

int parent(int i) {
    ccal++;
    return (i / 2);
}

int left(int i) {
    ccal++;
    return (2 * i);
}

int right(int i) {
    ccal += 2;
    return (2 * i + 1);
}

//Mergesort

void mergeSort(int a[], int p, int r) {
    int q;
    crel++;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q + 1, r);
        merge(a, p, q, r);
        ceq++;
        ccal += 2;
    }
}

void merge(int a[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = new int [n1 + 1];
    int *R = new int [n2 + 1];
    int i, j, k;
    ceq += 5;
    ccal += 5;
    for (i = 0; i < n1; i++) {
        L[i] = a[p + i];
        crel++;
        ccal += 2;
        ceq++;

    }
    ceq++;
    for (j = 0; j < n2; j++) {
        R[j] = a[q + j + 1];
        crel++;
        ccal += 3;
        ceq++;
    }
    L[n1] = 10000;
    R[n2] = 10000;
    i = 0;
    j = 0;
    ceq += 5;
    for (k = p; k <= r; k++) {
        crel += 2;
        ccal++;
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
            ceq++;
            ccal++;
        } else {
            a[k] = R[j];
            j++;
            ceq++;
            ccal++;
        }
    }
    delete []L;
    delete []R;
}

//Quicksort

void quickSort(int a[], int p, int r) {
    int q;
    crel++;
    if (p < r) {
        q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
        ceq++;
        ccal++;
    }
}

int partition(int a[], int p, int r) {
    int x = a[r];
    int i = p - 1;
    ceq += 3;
    ccal++;
    for (int j = p; j < r; j++) {
        crel += 2;
        ccal++;
        if (a[j] <= x) {
            i++;
            swap(a[i], a[j]);
            ccal++;
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    ceq += 3;
}

