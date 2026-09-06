#include <iostream>
using namespace std;

void bubbleSort(int a[], int s) {
    // Iterando por todos los elementos del array
    for (int j = 0; j < s; j++) {
        bool isswapped = false;

        // Los últimos j elementos ya están en su lugar correspondiente
        for (int i = 0; i < s - j - 1; i++) {
            // Recorriendo el array
            // Intercambiando si el elemento encontrado es mayor
            // que el siguiente elemento
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                isswapped = true;
            }
        }

        if (isswapped == false) {
            break;
        }
    }
}

int main() {
    int a[] = {15, 16, 11, 13, 14};
    int s = sizeof(a) / sizeof(a[0]);

    cout << "Antes de ordenar los elementos del array son: ";
    for (int j = 0; j < s; j++) {
        cout << a[j] << " ";
    }

    bubbleSort(a, s);

    cout << "\nDespués de ordenar los elementos del array son: ";
    for (int j = 0; j < s; j++) {
        cout << a[j] << " ";
    }

    return 0;
}