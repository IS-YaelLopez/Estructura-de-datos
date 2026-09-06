public class Burbuja {
    static void bubbleSort(int[] a) {
        int s = a.length;

        // Iterando por todos los elementos del array
        for (int j = 0; j < s; j++) {
            boolean isswapped = false;

            // Los últimos j elementos ya están en su lugar correspondiente
            for (int i = 0; i < s - j - 1; i++) {
                // Recorriendo el array
                // Intercambiando si el elemento encontrado es mayor
                // que el siguiente elemento
                if (a[i] > a[i + 1]) {
                    int temp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = temp;
                    isswapped = true;
                }
            }

            if (isswapped == false) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        int[] a = {15, 16, 11, 13, 14};

        System.out.print("Antes de ordenar los elementos del array son: ");
        for (int j : a) {
            System.out.print(j + " ");
        }

        bubbleSort(a);

        System.out.print("\nDespués de ordenar los elementos del array son: ");
        for (int j : a) {
            System.out.print(j + " ");
        }
    }
}