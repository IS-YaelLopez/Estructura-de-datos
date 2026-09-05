using System;
using System.Collections.Generic;

// Programa para eliminar un elemento al principio de un array
class Eliminacion
{
    static void Main(string[] args)
    {
        List<int> inputArr = new List<int> { 11, 21, 31, 41, 51, 61 };
        Console.WriteLine("Antes de la eliminacion, el array es: ");
        for (int j = 0; j < inputArr.Count; j++)
        {
            Console.Write(inputArr[j] + " ");
        }

        // Eliminando el primer elemento del inputArr[0]
        Console.WriteLine("\nDespues de la eliminacion, el array es: ");
        inputArr.RemoveAt(0);
        for (int j = 0; j < inputArr.Count; j++)
        {
            Console.Write(inputArr[j] + " ");
        }

        // Eliminando el ultimo elemento del inputArr[-1]
        inputArr = new List<int> { 11, 21, 31, 41, 51, 61 };
        Console.WriteLine("\nDespues de la eliminacion, el array es: ");
        inputArr.RemoveAt(inputArr.Count - 1);
        for (int j = 0; j < inputArr.Count; j++)
        {
            Console.Write(inputArr[j] + " ");
        }

        // Eliminando el numero del medio el inputArr[2]
        inputArr = new List<int> { 11, 21, 31, 41, 51, 61 };
        Console.WriteLine("\nDespues de la eliminacion, el array es: ");
        inputArr.RemoveAt(2);
        for (int j = 0; j < inputArr.Count; j++)
        {
            Console.Write(inputArr[j] + " ");
        }
    }
}
