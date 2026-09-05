using System;

class Recorridos
{
    static void Main(string[] args)
    {
        // datos
        int[] lista = { 10, 20, 30, 40, 50 };

        // RECORRIDO SECUENCIAL
        Console.WriteLine("RECORRIDO SECUENCIAL:");
        for (int i = 0; i < lista.Length; i++)
        {
            Console.WriteLine(lista[i]);
            // muestra la lista simple como estaba en la lista
        }

        // RECORRIDO INVERSO
        Console.WriteLine("\nRECORRIDO INVERSO:");
        // \n salto de linea
        for (int i = lista.Length - 1; i >= 0; i--)
        {
            Console.WriteLine(lista[i]);
            // mostrara el recorrido inverso por los -1
            // esto sucede porque inicio del ultimo indice o sea el -1, y va con pasos atras -1
            // y acaba hasta llegar al indice 0
        }
    }
}
