using System;

// implementacion en C#
class Matriz
{
    static void Main(string[] args)
    {
        int[,] twoDimensionalArray = {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        };

        Console.WriteLine("Los elementos de la matriz son:");
        for (int i = 0; i < twoDimensionalArray.GetLength(0); i++)
        {
            for (int j = 0; j < twoDimensionalArray.GetLength(1); j++)
            {
                Console.Write(twoDimensionalArray[i, j] + " "); // mostrando los elementos de la fila separados por espacios especiales
                Console.WriteLine(); // salto de linea para mostrar los elementos de la siguiente fila
            }
        }

        Console.WriteLine("Los elementos de la matriz en forma de lista son:");
        for (int i = 0; i < twoDimensionalArray.GetLength(0); i++)
        {
            Console.Write("[");
            for (int j = 0; j < twoDimensionalArray.GetLength(1); j++)
            {
                Console.Write(twoDimensionalArray[i, j]);
                if (j != twoDimensionalArray.GetLength(1) - 1) Console.Write(", ");
            }
            Console.WriteLine("]"); // mostrando los elementos de la fila como una lista
        }
    }
}
