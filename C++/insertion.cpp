#include <iostream>
using namespace std;

void insertionSort(int a[], int s) {
    for (int i = 1; i < s; i++) {
        int temp = a[i];

        // Mueve los elementos mayores que temp
        // a una posición más adelante de su posición actual
        int j = i - 1;

        while (j >= 0 && temp < a[j]) {
            a[j + 1] = a[j];
            j = j - 1;
        }

        a[j + 1] = temp;
    }
}

void printArr(int a[], int s) { // función para imprimir el array
    for (int i = 0; i < s; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int a[] = {70, 15, 2, 51, 60};
    int s = sizeof(a) / sizeof(a[0]);

    cout << "Antes de ordenar los elementos del arreglo: ";
    printArr(a, s);

    insertionSort(a, s);

    cout << "\nDespués de arreglar los elementos del arreglo: ";
    printArr(a, s);

    return 0;
}