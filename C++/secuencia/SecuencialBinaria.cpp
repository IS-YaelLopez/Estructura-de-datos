#include <iostream>
#include <vector>
using namespace std;

// busqueda secuencial
int busquedaSecuencial(const vector<int>& lista, int objetivo)
{
    for (size_t i = 0; i < lista.size(); i++)
    {
        if (lista[i] == objetivo)
        {
            return i; // Retorna la posicion
        }
    }
    return -1; // No encontrado
}

// busqueda binaria
int busquedaBinaria(const vector<int>& lista, int objetivo)
{
    int izq = 0, der = lista.size() - 1;
    while (izq <= der)
    {
        int medio = (izq + der) / 2;
        if (lista[medio] == objetivo)
        {
            return medio;
        }
        else if (lista[medio] < objetivo)
        {
            izq = medio + 1;
        }
        else
        {
            der = medio - 1;
        }
    }
    return -1; // No encontrado
}

int main()
{
    vector<int> miLista = {3, 7, 12, 15, 22, 30, 44, 50};

    cout << busquedaSecuencial(miLista, 22) << endl;
    cout << busquedaBinaria(miLista, 22) << endl;
    cout << busquedaSecuencial(miLista, 99) << endl;
    cout << busquedaBinaria(miLista, 99) << endl;

    return 0;
}
