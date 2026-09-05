import java.util.ArrayList;
import java.util.List;

// Programa para eliminar un elemento al principio de un array
public class Eliminacion {
    public static void main(String[] args) {
        List<Integer> inputArr = new ArrayList<>(List.of(11, 21, 31, 41, 51, 61));
        System.out.println("Antes de la eliminacion, el array es: ");
        for (int j = 0; j < inputArr.size(); j++) {
            System.out.print(inputArr.get(j) + " ");
        }

        // Eliminando el primer elemento del inputArr[0]
        System.out.println("\nDespues de la eliminacion, el array es: ");
        inputArr.remove(0);
        for (int j = 0; j < inputArr.size(); j++) {
            System.out.print(inputArr.get(j) + " ");
        }

        // Eliminando el ultimo elemento del inputArr[-1]
        inputArr = new ArrayList<>(List.of(11, 21, 31, 41, 51, 61));
        System.out.println("\nDespues de la eliminacion, el array es: ");
        inputArr.remove(inputArr.size() - 1);
        for (int j = 0; j < inputArr.size(); j++) {
            System.out.print(inputArr.get(j) + " ");
        }

        // Eliminando el numero del medio el inputArr[2]
        inputArr = new ArrayList<>(List.of(11, 21, 31, 41, 51, 61));
        System.out.println("\nDespues de la eliminacion, el array es: ");
        inputArr.remove(2);
        for (int j = 0; j < inputArr.size(); j++) {
            System.out.print(inputArr.get(j) + " ");
        }
    }
}
