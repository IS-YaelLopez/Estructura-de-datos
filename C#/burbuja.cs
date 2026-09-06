using System;

class Program
{
    static void BubbleSort(int[] a)
    {
        int s = a.Length;

        // Iterando por todos los elementos del array
        for (int j = 0; j < s; j++)
        {
            bool isswapped = false;

            // Los últimos j elementos ya están en su lugar correspondiente
            for (int i = 0; i < s - j - 1; i++)
            {
                // Recorriendo el array
                // Intercambiando si el elemento encontrado es mayor
                // que el siguiente elemento
                if (a[i] > a[i + 1])
                {
                    int temp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = temp;
                    isswapped = true;
                }
            }

            if (isswapped == false)
            {
                break;
            }
        }
    }

    static void Main()
    {
        int[] a = { 15, 16, 11, 13, 14 };

        Console.Write("Antes de ordenar los elementos del array son: ");
        foreach (int j in a)
        {
            Console.Write(j + " ");
        }

        BubbleSort(a);

        Console.Write("\nDespués de ordenar los elementos del array son: ");
        foreach (int j in a)
        {
            Console.Write(j + " ");
        }
    }
}