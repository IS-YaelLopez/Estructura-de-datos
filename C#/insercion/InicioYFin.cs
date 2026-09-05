using System;
using System.Collections.Generic;

class InicioYFin
{
    static void Main(string[] args)
    {
        // Insercion al inicio
        List<string> abecedario = new List<string> { "a", "b", "c", "d" };
        Console.WriteLine(string.Join(", ", abecedario));
        // muestra normal

        abecedario.Insert(0, "z");
        Console.WriteLine(string.Join(", ", abecedario));

        // Insercion al final
        abecedario = new List<string> { "a", "b", "c", "d" };
        Console.WriteLine(string.Join(", ", abecedario));
        // muestra normal

        abecedario.Insert(4, "z");
        Console.WriteLine(string.Join(", ", abecedario));
    }
}
