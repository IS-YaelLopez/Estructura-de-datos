using System;

// implementacion en C#
class ArrayPrograma
{
    static void Main(string[] args)
    {
        int[] arr = { 1, 2, 3, 4, 5 };
        Console.WriteLine("Los elementos del array son:");
        foreach (int element in arr)
        {
            Console.Write(element + " "); // mostrando los elementos del array separados por espacios especiales
        }
    }
}
