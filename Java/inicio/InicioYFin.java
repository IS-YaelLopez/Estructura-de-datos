import java.util.ArrayList;
import java.util.List;

public class InicioYFin {
    public static void main(String[] args) {
        // Insercion al inicio
        List<String> abecedario = new ArrayList<>(List.of("a", "b", "c", "d"));
        System.out.println(abecedario);
        // muestra normal

        abecedario.add(0, "z");
        System.out.println(abecedario);

        // Insercion al final
        abecedario = new ArrayList<>(List.of("a", "b", "c", "d"));
        System.out.println(abecedario);
        // muestra normal

        abecedario.add(4, "z");
        System.out.println(abecedario);
    }
}
