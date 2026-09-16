using System;

class Program
{
    static void Seleccion(int[] a)
    {
        // Recorre todo el arreglo
        for (int i = 0; i < a.Length; i++)
        {
            int small = i; // Indice del elemento más pequeño

            // Encuentra el elemento más pequeño en el arreglo
            for (int j = i + 1; j < a.Length; j++)
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

    static void PrintArr(int[] a)
    {
        // Recorre todo el arreglo
        for (int i = 0; i < a.Length; i++)
        {
            Console.Write(a[i] + " "); // Imprime el elemento
        }

        Console.WriteLine();
    }

    static void Main()
    {
        int[] a = { 65, 26, 13, 23, 12 }; // Arreglo desordenado

        Console.WriteLine("Arreglo antes de ser ordenado:");
        PrintArr(a);

        Seleccion(a);

        Console.WriteLine("\nArreglo después de ser ordenado:");
        PrintArr(a);
    }
}