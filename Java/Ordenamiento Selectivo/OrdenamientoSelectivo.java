public class OrdenamientoSelectivo
{
    public static void seleccion(int[] a)
    {
        // Recorre todo el arreglo
        for (int i = 0; i < a.length; i++)
        {
            int small = i; // Indice del elemento más pequeño

            // Encuentra el elemento más pequeño en el arreglo
            for (int j = i + 1; j < a.length; j++)
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

    public static void printArr(int[] a)
    {
        // Recorre todo el arreglo
        for (int i = 0; i < a.length; i++)
        {
            System.out.print(a[i] + " "); // Imprime el elemento
        }

        System.out.println();
    }

    public static void main(String[] args)
    {
        int[] a = {65, 26, 13, 23, 12}; // Arreglo desordenado

        System.out.println("Arreglo antes de ser ordenado:");
        printArr(a);

        seleccion(a);

        System.out.println("\nArreglo después de ser ordenado:");
        printArr(a);
    }
}