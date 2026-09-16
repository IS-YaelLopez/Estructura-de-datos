// Implementación de QuickSort en C++

#include <iostream>
using namespace std;

// Función para intercambiar dos elementos en el arreglo
void swap(int a[], int j, int k) { // intercambia los elementos
    int temp = a[j]; // guarda el valor temporalmente
    a[j] = a[k]; // intercambia los elementos
    a[k] = temp; // intercambia los elementos
}

// Función para hacer la partición del arreglo
int partition(int a[], int l, int h) {
    // Selecciona el elemento pivote
    int pvt = a[h];
    // j es el índice de los elementos que son menores que
    // el pivote y también indica la posición correcta del pivote encontrado hasta este momento
    int j = l - 1;
    // Recorre a[l..h-1] y mueve todos los elementos menores
    // al lado izquierdo del pivote.
    // Los elementos de l a j son más pequeños después de cada iteración
    for (int k = l; k < h; k++) { // recorre el arreglo
        // Si el elemento actual es menor que el pivote
        if (a[k] < pvt) { // compara el elemento actual con el pivote
            j++; // incrementa el índice del elemento más pequeño
            swap(a, j, k); // intercambia los elementos
        }
    }
    // Mover el pivote después de elementos más pequeños y
    // devolverlo a su posición
    swap(a, j + 1, h); // intercambia el pivote con el elemento siguiente al último elemento más pequeño
    return j + 1; // devuelve el índice del pivote
}

// Implementación de la función QuickSort
void qckSort(int a[], int l, int h) { // función principal de QuickSort
    if (l < h) { // si el índice izquierdo es menor que el derecho
        // pi es el índice de partición, regresa el índice del pivote
        int pi = partition(a, l, h); // particiona el arreglo
        // llamadas recursivas para los elementos menores
        // y mayores o iguales a los elementos
        qckSort(a, l, pi - 1); // llamada recursiva para los elementos menores que el pivote
        qckSort(a, pi + 1, h); // llamada recursiva para los elementos mayores o iguales que el pivote
    }
}

// Código para probar la implementación de QuickSort
int main() { // punto de entrada del programa
    int a[] = {10, 7, 8, 9, 1, 5}; // arreglo desordenado
    int size = sizeof(a) / sizeof(a[0]); // tamaño del arreglo
    cout << "El arreglo antes de ordenarlo: " << endl;
    for (int v : a) { // imprime el arreglo
        cout << v << " ";
    }
    cout << endl; // salto de línea
    qckSort(a, 0, size - 1);
    cout << "El arreglo después de ordenarlo: " << endl;
    for (int v : a) { // imprime el arreglo ordenado
        cout << v << " ";
    }
    return 0;
}
