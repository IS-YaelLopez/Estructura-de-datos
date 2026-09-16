#include <iostream>
using namespace std;

void seleccion(int a[], int n)
{
    // Recorre todo el arreglo
    for (int i = 0; i < n; i++)
    {
        int small = i; // Indice del elemento más pequeño

        // Encuentra el elemento más pequeño en el arreglo
        for (int j = i + 1; j < n; j++)
        {
            // Compara el elemento más pequeño con el siguiente elemento
            if (a[small] > a[j])
            {
                small = j; // Actualiza el indice del elemento más pequeño
            }
        }

        // Intercambia el elemento más pequeño con el primer elemento
        int temp = a[i];
        a[i] = a[small];
        a[small] = temp;
    }
}

void printArr(int a[], int n)
{
    // Recorre todo el arreglo
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " "; // Imprime el elemento
    }

    cout << endl;
}

int main()
{
    int a[] = {65, 26, 13, 23, 12}; // Arreglo desordenado
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Arreglo antes de ser ordenado: " << endl;
    printArr(a, n);

    seleccion(a, n);

    cout << "\nArreglo después de ser ordenado: " << endl;
    printArr(a, n);

    return 0;
}