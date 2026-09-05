using System;

class SecuencialBinaria
{
    // busqueda secuencial
    static int BusquedaSecuencial(int[] lista, int objetivo)
    {
        for (int i = 0; i < lista.Length; i++)
        {
            if (lista[i] == objetivo)
            {
                return i; // Retorna la posicion
            }
        }
        return -1; // No encontrado
    }

    // busqueda binaria
    static int BusquedaBinaria(int[] lista, int objetivo)
    {
        int izq = 0, der = lista.Length - 1;
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

    static void Main(string[] args)
    {
        int[] miLista = { 3, 7, 12, 15, 22, 30, 44, 50 };

        Console.WriteLine(BusquedaSecuencial(miLista, 22));
        Console.WriteLine(BusquedaBinaria(miLista, 22));
        Console.WriteLine(BusquedaSecuencial(miLista, 99));
        Console.WriteLine(BusquedaBinaria(miLista, 99));
    }
}
