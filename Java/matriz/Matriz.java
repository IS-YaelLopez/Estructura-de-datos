// implementacion en Java
public class Matriz {
    public static void main(String[] args) {
        int[][] twoDimensionalArray = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        System.out.println("Los elementos de la matriz son:");
        for (int[] row : twoDimensionalArray) {
            for (int element : row) {
                System.out.print(element + " "); // mostrando los elementos de la fila separados por espacios especiales
                System.out.println(); // salto de linea para mostrar los elementos de la siguiente fila
            }
        }

        System.out.println("Los elementos de la matriz en forma de lista son:");
        for (int[] row : twoDimensionalArray) {
            StringBuilder sb = new StringBuilder("[");
            for (int j = 0; j < row.length; j++) {
                sb.append(row[j]);
                if (j != row.length - 1) sb.append(", ");
            }
            sb.append("]");
            System.out.println(sb); // mostrando los elementos de la fila como una lista
        }
    }
}
