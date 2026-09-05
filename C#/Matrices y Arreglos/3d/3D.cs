using System;

class Array3D
{
    static void Main()
    {
        int[,,] threeDimensionalArray =
        {
            {
                { 1, 2, 3 },
                { 4, 5, 6 },
                { 7, 8, 9 }
            },
            {
                { 10, 11, 12 },
                { 13, 14, 15 },
                { 16, 17, 18 }
            }
        };

        Console.WriteLine("Los elementos del array son:");

        for (int i = 0; i < threeDimensionalArray.GetLength(0); i++)
        {
            for (int j = 0; j < threeDimensionalArray.GetLength(1); j++)
            {
                for (int k = 0; k < threeDimensionalArray.GetLength(2); k++)
                {
                    Console.Write(threeDimensionalArray[i, j, k] + " ");
                }
                Console.WriteLine();
            }
        }
    }
}
