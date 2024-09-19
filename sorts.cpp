#include <iostream>

#include "sorts.h"

using namespace std;

void swap(ListaSimple arr, int i1, int i2) {
    int t = arr.get(i1);
    arr.set(i1, arr.get(i2));
    arr.set(i2, t);
}
void selectionSort(ListaSimple arr, int n) {

    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr.get(j) < arr.get(min_idx))
                min_idx = j;
        }

        // Swap the found minimum element with the first element
        if (min_idx != i) {
            int temp = arr.get(min_idx);
            arr.set(min_idx, arr.get(i));
            arr.set(i, temp);
        }
    }
}

void bubbleSort(ListaSimple arr, int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr.get(j) > arr.get(j + 1)) {
                swap(arr, j, j + 1);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}
