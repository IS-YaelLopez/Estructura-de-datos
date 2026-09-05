public class Array2D {
    public static void main(String[] args) {
        int r = 3, c = 3;
        int[] arr = new int[r * c];

        // Matriz inicializada
        int[][] twoDArr = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        int k = 0;

        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                k = x * c + y;
                arr[k] = twoDArr[x][y];
                k = k + 1;
            }
        }

        System.out.println("Los elementos del array bidimensional son:");

        for (int[] row : twoDArr) {
            for (int ele : row) {
                System.out.print(ele + " ");
            }
            System.out.println();
        }

        System.out.println("\nLos elementos del array unidimensional son:");

        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                System.out.print(arr[x * c + y] + " ");
            }
        }
    }
}
