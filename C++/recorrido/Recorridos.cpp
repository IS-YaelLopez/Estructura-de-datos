#include <iostream>
using namespace std;

int main()
{
    // datos
    int lista[] = {10, 20, 30, 40, 50};
    int n = 5;

    // RECORRIDO SECUENCIAL
    cout << "RECORRIDO SECUENCIAL:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << lista[i] << endl;
        // muestra la lista simple como estaba en la lista
    }

    // RECORRIDO INVERSO
    cout << "\nRECORRIDO INVERSO:" << endl;
    // \n salto de linea
    for (int i = n - 1; i >= 0; i--)
    {
        cout << lista[i] << endl;
        // mostrara el recorrido inverso por los -1
        // esto sucede porque inicio del ultimo indice o sea el -1, y va con pasos atras -1
        // y acaba hasta llegar al indice 0
    }

    return 0;
}
