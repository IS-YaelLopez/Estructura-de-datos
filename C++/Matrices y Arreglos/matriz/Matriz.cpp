#include <iostream>
using namespace std;

// implementacion en C++
int main()
{
    int twoDimensionalArray[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Los elementos de la matriz son:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << twoDimensionalArray[i][j] << " "; // mostrando los elementos de la fila separados por espacios especiales
            cout << endl; // salto de linea para mostrar los elementos de la siguiente fila
        }
    }

    cout << "Los elementos de la matriz en forma de lista son:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "[";
        for (int j = 0; j < 3; j++)
        {
            cout << twoDimensionalArray[i][j];
            if (j != 2) cout << ", ";
        }
        cout << "]" << endl; // mostrando los elementos de la fila como una lista
    }

    return 0;
}
