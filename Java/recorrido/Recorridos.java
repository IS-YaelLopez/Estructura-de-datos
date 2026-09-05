public class Recorridos {
    public static void main(String[] args) {
        // datos
        int[] lista = {10, 20, 30, 40, 50};

        // RECORRIDO SECUENCIAL
        System.out.println("RECORRIDO SECUENCIAL:");
        for (int i = 0; i < lista.length; i++) {
            System.out.println(lista[i]);
            // muestra la lista simple como estaba en la lista
        }

        // RECORRIDO INVERSO
        System.out.println("\nRECORRIDO INVERSO:");
        // \n salto de linea
        for (int i = lista.length - 1; i >= 0; i--) {
            System.out.println(lista[i]);
            // mostrara el recorrido inverso por los -1
            // esto sucede porque inicio del ultimo indice o sea el -1, y va con pasos atras -1
            // y acaba hasta llegar al indice 0
        }
    }
}
