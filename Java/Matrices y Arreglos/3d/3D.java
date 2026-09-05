public class Array3D {
    public static void main(String[] args) {
        int[][][] threeDimensionalArray = {
            {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            },
            {
                {10, 11, 12},
                {13, 14, 15},
                {16, 17, 18}
            }
        };

        System.out.println("Los elementos del array son:");

        for (int[][] twoDimensionalArray : threeDimensionalArray) {
            for (int[] row : twoDimensionalArray) {
                for (int element : row) {
                    System.out.print(element + " ");
                }
                System.out.println();
            }
        }
    }
}
