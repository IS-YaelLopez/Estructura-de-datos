using System;

class Array2D
{
    static void Main()
    {
        int r = 3, c = 3;
        int[] arr = new int[r * c];

        // Matriz inicializada
        int[,] twoDArr =
        {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        };

        int k = 0;

        for (int x = 0; x < r; x++)
        {
            for (int y = 0; y < c; y++)
            {
                k = x * c + y;
                arr[k] = twoDArr[x, y];
                k = k + 1;
            }
        }

        Console.WriteLine("Los elementos del array bidimensional son:");

        for (int x = 0; x < r; x++)
        {
            for (int y = 0; y < c; y++)
            {
                Console.Write(twoDArr[x, y] + " ");
            }
            Console.WriteLine();
        }

        Console.WriteLine("\nLos elementos del array unidimensional son:");

        for (int x = 0; x < r; x++)
        {
            for (int y = 0; y < c; y++)
            {
                Console.Write(arr[x * c + y] + " ");
            }
        }
    }
}
