public class Insertion {
    static void insertionSort(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int temp = a[i];

            // Mueve los elementos mayores que temp
            // a una posición más adelante de su posición actual
            int j = i - 1;

            while (j >= 0 && temp < a[j]) {
                a[j + 1] = a[j];
                j = j - 1;
            }

            a[j + 1] = temp;
        }
    }

    static void printArr(int[] a) { // función para imprimir el array
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
    }

    public static void main(String[] args) {
        int[] a = {70, 15, 2, 51, 60};

        System.out.print("Antes de ordenar los elementos del arreglo: ");
        printArr(a);

        insertionSort(a);

        System.out.print("\nDespués de arreglar los elementos del arreglo: ");
        printArr(a);
    }
}