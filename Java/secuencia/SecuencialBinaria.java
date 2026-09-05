public class SecuencialBinaria {

    // busqueda secuencial
    static int busquedaSecuencial(int[] lista, int objetivo) {
        for (int i = 0; i < lista.length; i++) {
            if (lista[i] == objetivo) {
                return i; // Retorna la posicion
            }
        }
        return -1; // No encontrado
    }

    // busqueda binaria
    static int busquedaBinaria(int[] lista, int objetivo) {
        int izq = 0, der = lista.length - 1;
        while (izq <= der) {
            int medio = (izq + der) / 2;
            if (lista[medio] == objetivo) {
                return medio;
            } else if (lista[medio] < objetivo) {
                izq = medio + 1;
            } else {
                der = medio - 1;
            }
        }
        return -1; // No encontrado
    }

    public static void main(String[] args) {
        int[] miLista = {3, 7, 12, 15, 22, 30, 44, 50};

        System.out.println(busquedaSecuencial(miLista, 22));
        System.out.println(busquedaBinaria(miLista, 22));
        System.out.println(busquedaSecuencial(miLista, 99));
        System.out.println(busquedaBinaria(miLista, 99));
    }
}
