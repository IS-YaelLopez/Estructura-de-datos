using System;

class Program
{
    static void InsertionSort(int[] a)
    {
        for (int i = 1; i < a.Length; i++)
        {
            int temp = a[i];

            // Mueve los elementos mayores que temp
            // a una posición más adelante de su posición actual
            int j = i - 1;

            while (j >= 0 && temp < a[j])
            {
                a[j + 1] = a[j];
                j = j - 1;
            }

            a[j + 1] = temp;
        }
    }

    static void PrintArr(int[] a) // función para imprimir el array
    {
        for (int i = 0; i < a.Length; i++)
        {
            Console.Write(a[i] + " ");
        }
    }

    static void Main()
    {
        int[] a = { 70, 15, 2, 51, 60 };

        Console.Write("Antes de ordenar los elementos del arreglo: ");
        PrintArr(a);

        InsertionSort(a);

        Console.Write("\nDespués de arreglar los elementos del arreglo: ");
        PrintArr(a);
    }
}