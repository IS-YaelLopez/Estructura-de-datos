#include <iostream>
#include <cmath>
using namespace std;

// 0 = casilla vacia
// 1 = ficha Blanca
// 2 = ficha Roja
// 3 = Dama Blanca
// 4 = Dama Roja
int tablero[8][8];

// 1 = Blancas
//2 = Rojas
// Las Blancas comienzan el juego
int TurnoActual = 1; // -1 pa que no tenga nada asignado

// Aqui guardamos la posicion de una ficha
// cuando tiene que seguir comiendo
int selFila = -1;
int selCol = -1;

bool enCapturaMultiple = false;


// INICIALIZAR TABLERO
// Aqui colocamos todas las fichas en sus posiciones iniciales.
// Primero dejamos todo vacio y despues colocamos las fichas.
void InicializarTablero() {

    // Recorremos todas las filas y columnas
    for (int fila = 0; fila < 8; fila++) {
        for (int columna = 0; columna < 8; columna++) {

            // Primero dejamos todas las casillas vacias
            tablero[fila][columna] = 0;

            // Solo se pueden utilizar las casillas oscuras
            if ((fila + columna) % 2 != 0) {

                // Las Rojas empiezan arriba
                if (fila < 3)
                    tablero[fila][columna] = 2;

                // Las Blancas empiezan abajo
                else if (fila > 4)
                    tablero[fila][columna] = 1;
            }
        }
    }
}


// MOSTRAR TABLERO
// Este bloque muestra el tablero en la consola.
// Tambien muestra los numeros de fila y columna para poder
// saber que coordenadas debemos escribir al hacer una jugada.
void MostrarTablero() {

    cout << "\n       0   1   2   3   4   5   6   7\n";
    cout << "     ---------------------------------\n";

    // Recorremos las filas
    for (int fila = 0; fila < 8; fila++) {

        cout << "  " << fila << " |";

        // Recorremos las columnas
        for (int columna = 0; columna < 8; columna++) {

            // Las casillas claras no se pueden utilizar
            if ((fila + columna) % 2 == 0) {
                cout << "   |";
            }

            else {
                // Casilla oscura vacia
                if (tablero[fila][columna] == 0)
                    cout << " . |";

                // Ficha Blanca
                else if (tablero[fila][columna] == 1)
                    cout << " b |";

                // Ficha Roja
                else if (tablero[fila][columna] == 2)
                    cout << " r |";

                // Dama Blanca
                else if (tablero[fila][columna] == 3)
                    cout << " B |";

                // Dama Roja
                else if (tablero[fila][columna] == 4)
                    cout << " R |";
            }
        }

        cout << "\n     ---------------------------------\n";
    }

    // Indicamos de quien es el turno
    cout << "\nTurno actual: ";

    if (TurnoActual == 1)
        cout << "Blancas (b/B)\n";
    else
        cout << "Rojas (r/R)\n";
}


// COMPROBAR FICHAS
// Estas funciones sirven para identificar si una ficha
// es nuestra o pertenece al jugador contrario.
bool esFichaPropia(int ficha, int jugador) {
    if (jugador == 1)
        return ficha == 1 || ficha == 3;
    if (jugador == 2)
        return ficha == 2 || ficha == 4;
    return false;
}

bool esFichaEnemiga(int ficha, int jugador) {

    if (jugador == 1)
        return ficha == 2 || ficha == 4;

    if (jugador == 2)
        return ficha == 1 || ficha == 3;

    return false;
}

// CONTAR FICHAS
// Aqui contamos las fichas que tiene cada jugador.
// Esto sirve para saber si alguien se quedo sin fichas.
int contarFichas(int jugador) {
    int cantidad = 0;
    for (int fila = 0; fila < 8; fila++) {
        for (int columna = 0; columna < 8; columna++) {
            if (esFichaPropia(tablero[fila][columna], jugador))
                cantidad++;
        }
    }
    return cantidad;
}

// CAPTURAS
// Aqui revisamos si una ficha puede comer a otra.
// Se revisan las cuatro diagonales para encontrar
// una ficha enemiga y una casilla vacia despues de ella.
bool fichaPuedeComer(int fila, int columna, int jugador) {
    int ficha = tablero[fila][columna];
    // Si no es nuestra ficha, no puede comer
    if (!esFichaPropia(ficha, jugador))
        return false;

    // Las Damas pueden comer hacia adelante y hacia atras
    bool esDama = (ficha == 3 || ficha == 4);

    // Estas son las cuatro diagonales
    int direccionesFila[4] = {-1, -1, 1, 1};
    int direccionesColumna[4] = {-1, 1, -1, 1};

    for (int i = 0; i < 4; i++) {

        int cambioFila = direccionesFila[i];
        int cambioColumna = direccionesColumna[i];

        // Una ficha normal solamente puede avanzar
        if (!esDama) {

            // Blancas avanzan hacia la fila 0
            if (jugador == 1 && cambioFila > 0)
                continue;

            // Rojas avanzan hacia la fila 7
            if (jugador == 2 && cambioFila < 0)
                continue;
        }

        // Esta es la posicion de la ficha enemiga
        int medioFila = fila + cambioFila;
        int medioColumna = columna + cambioColumna;

        // Esta es la posicion donde terminaria el salto
        int destinoFila = fila + cambioFila * 2;
        int destinoColumna = columna + cambioColumna * 2;

        // Revisamos que las posiciones esten dentro del tablero
        if (medioFila >= 0 && medioFila < 8 &&
            medioColumna >= 0 && medioColumna < 8 &&
            destinoFila >= 0 && destinoFila < 8 &&
            destinoColumna >= 0 && destinoColumna < 8) {

            // Debe haber enemigo en medio
            // y la casilla final debe estar vacia
            if (esFichaEnemiga(tablero[medioFila][medioColumna], jugador) &&
                tablero[destinoFila][destinoColumna] == 0) {

                return true;
            }
        }
    }

    return false;
}


// Aqui revisamos todo el tablero para saber si existe
// alguna captura disponible para el jugador.
bool hayCapturaDisponible(int jugador) {

    for (int fila = 0; fila < 8; fila++) {
        for (int columna = 0; columna < 8; columna++) {

            if (fichaPuedeComer(fila, columna, jugador))
                return true;
        }
    }

    return false;
}


// MOVIMIENTO NORMAL
// Revisamos si una ficha puede moverse una casilla
// en diagonal sin tener que capturar.
bool fichaPuedeMoverse(int fila, int columna, int jugador) {

    int ficha = tablero[fila][columna];

    // Primero comprobamos que sea nuestra ficha
    if (!esFichaPropia(ficha, jugador))
        return false;

    bool esDama = (ficha == 3 || ficha == 4);

    int direccionesFila[4] = {-1, -1, 1, 1};
    int direccionesColumna[4] = {-1, 1, -1, 1};

    for (int i = 0; i < 4; i++) {

        int cambioFila = direccionesFila[i];
        int cambioColumna = direccionesColumna[i];

        // Las fichas normales solamente avanzan
        if (!esDama) {

            if (jugador == 1 && cambioFila > 0)
                continue;

            if (jugador == 2 && cambioFila < 0)
                continue;
        }

        int destinoFila = fila + cambioFila;
        int destinoColumna = columna + cambioColumna;

        // Revisamos que no salgamos del tablero
        // y que la casilla este vacia
        if (destinoFila >= 0 && destinoFila < 8 &&
            destinoColumna >= 0 && destinoColumna < 8 &&
            tablero[destinoFila][destinoColumna] == 0) {

            return true;
        }
    }

    return false;
}


// COMPROBAR MOVIMIENTOS
// Aqui verificamos si el jugador tiene algun movimiento.
// Primero se buscan capturas porque son obligatorias.
// Si no hay capturas, se buscan movimientos normales.
bool tieneMovimientosValidos(int jugador) {

    // Si estamos en captura multiple,
    // solamente podemos utilizar esa ficha
    if (enCapturaMultiple)
        return fichaPuedeComer(selFila, selCol, jugador);

    // Primero revisamos capturas porque son obligatorias
    if (hayCapturaDisponible(jugador))
        return true;

    // Si no hay captura buscamos movimientos normales
    for (int fila = 0; fila < 8; fila++) {
        for (int columna = 0; columna < 8; columna++) {

            if (fichaPuedeMoverse(fila, columna, jugador))
                return true;
        }
    }

    return false;
}


int main() {

    // INICIO DEL JUEGO
    // Primero preparamos el tablero y las variables
    // que utilizaremos para recibir las jugadas.
    InicializarTablero();

    int origenFila;
    int origenColumna;
    int destinoFila;
    int destinoColumna;

    cout << "--- JUEGO DE DAMAS CHINAS ---\n";
    cout << "\nFila = de arriba hacia abajo (0 a 7)\n";
    cout << "Columna = de izquierda a derecha (0 a 7)\n";
    cout << "Ejemplo: 5 0 significa fila 5, columna 0\n";
    cout << "\nPara terminar, escribe -1 en el origen.\n";


    // CICLO PRINCIPAL
    // Este ciclo mantiene el juego funcionando hasta que
    // alguien gane, quede bloqueado o los jugadores salgan.
    while (true) {

        system("cls"); // limpio la pantalla
        MostrarTablero(); // muestro el tablero


        // COMPROBAR GANADOR
        // Contamos las fichas para saber si algun jugador
        // ya se quedo sin ninguna.
        int fichasBlancas = contarFichas(1);
        int fichasRojas = contarFichas(2);

        if (fichasBlancas == 0) {

            cout << "\nLas Blancas se han quedado sin fichas\n";
            cout << "GANA EL JUGADOR ROJO (r)\n";

            break;
        }

        if (fichasRojas == 0) {

            cout << "\nLas Rojas se han quedado sin fichas\n";
            cout << "GANA EL JUGADOR BLANCO (b)\n";

            break;
        }


        // COMPROBAR BLOQUEO
        // Si el jugador no puede mover ninguna ficha,
        // se considera que esta acorralado.
        if (!tieneMovimientosValidos(TurnoActual)) {

            cout << "\nEl jugador ";

            if (TurnoActual == 1)
                cout << "Blancas";
            else
                cout << "Rojas";

            cout << " esta acorralado\n";

            cout << "GANA EL JUGADOR ";

            if (TurnoActual == 1)
                cout << "ROJAS (r)\n";
            else
                cout << "BLANCAS (b)\n";

            break;
        }


        // PEDIR JUGADA
        // Aqui le pedimos al jugador la posicion de origen
        // y despues la posicion a donde quiere mover.
        if (enCapturaMultiple) {

            // En una captura consecutiva no podemos escoger
            // otra ficha porque debemos seguir con la misma.
            origenFila = selFila;
            origenColumna = selCol;

            cout << "\nCaptura consecutiva con la ficha en ("
                 << origenFila << ", "
                 << origenColumna << ")\n";
        }

        else {

            cout << "\nOrigen [Fila Columna] (o -1 para salir): ";

            if (!(cin >> origenFila))
                break;

            // -1 permite terminar la partida
            if (origenFila == -1) {

                cout << "\nPartida finalizada por acuerdo de los jugadores\n";

                break;
            }

            if (!(cin >> origenColumna))
                break;
        }

        cout << "Destino [Fila Columna]: ";

        if (!(cin >> destinoFila >> destinoColumna))
            break;


        // COMPROBAR COORDENADAS
        // Revisamos que las posiciones introducidas
        // existan dentro del tablero.
        if (origenFila < 0 || origenFila > 7 ||
            origenColumna < 0 || origenColumna > 7 ||
            destinoFila < 0 || destinoFila > 7 ||
            destinoColumna < 0 || destinoColumna > 7) {

            cout << "Coordenadas fuera del tablero\n";

            continue;
        }


        // COMPROBAR FICHA
        // Aqui verificamos que la ficha seleccionada
        // realmente pertenezca al jugador actual.
        int pieza = tablero[origenFila][origenColumna];

        if (!esFichaPropia(pieza, TurnoActual)) {

            cout << "Esa casilla no contiene una ficha tuya\n";

            continue;
        }


        // COMPROBAR DESTINO
        // No podemos mover una ficha a una casilla
        // que ya esta ocupada.
        if (tablero[destinoFila][destinoColumna] != 0) {

            cout << "La casilla de destino esta ocupada\n";

            continue;
        }


        // PREPARAR MOVIMIENTO
        // Aqui guardamos algunos datos que necesitamos
        // para saber si sera captura o movimiento normal.
        bool esDama = (pieza == 3 || pieza == 4);

        bool obligacionComer = hayCapturaDisponible(TurnoActual);

        bool realizoMovimiento = false;
        bool fueCaptura = false;

        // Calculamos cuanto cambio la fila y la columna
        int cambioFila = destinoFila - origenFila;
        int cambioColumna = destinoColumna - origenColumna;


        // CAPTURA
        // Para capturar debemos saltar dos casillas en diagonal.
        if (abs(cambioFila) == 2 &&
            abs(cambioColumna) == 2) {

            // Esta es la ficha que esta en medio
            int medioFila = origenFila + cambioFila / 2;
            int medioColumna = origenColumna + cambioColumna / 2;


            // Las fichas normales no pueden comer hacia atras
            if (!esDama) {

                if (TurnoActual == 1 && cambioFila > 0) {

                    cout << "Las Blancas no pueden comer hacia atras\n";

                    continue;
                }

                if (TurnoActual == 2 && cambioFila < 0) {

                    cout << "Las Rojas no pueden comer hacia atras\n";

                    continue;
                }
            }


            // Revisamos que en medio haya una ficha enemiga
            if (esFichaEnemiga(
                    tablero[medioFila][medioColumna],
                    TurnoActual)) {

                // Movemos nuestra ficha al destino
                tablero[destinoFila][destinoColumna] = pieza;

                // Dejamos vacia la posicion anterior
                tablero[origenFila][origenColumna] = 0;

                // Eliminamos la ficha enemiga
                tablero[medioFila][medioColumna] = 0;

                realizoMovimiento = true;
                fueCaptura = true;
            }

            else {

                cout << "No hay una ficha enemiga para capturar\n";
            }
        }


        // MOVIMIENTO NORMAL
        // Si no hay captura obligatoria, la ficha puede avanzar
        // una casilla en diagonal.
        else if (!enCapturaMultiple &&
                 !obligacionComer &&
                 abs(cambioFila) == 1 &&
                 abs(cambioColumna) == 1) {

            // Las Damas pueden moverse en cualquier direccion.
            // Las fichas normales solamente avanzan.
            bool direccionValida =
                esDama ||
                (TurnoActual == 1 && cambioFila == -1) ||
                (TurnoActual == 2 && cambioFila == 1);


            if (direccionValida) {

                // Colocamos la ficha en la nueva posicion
                tablero[destinoFila][destinoColumna] = pieza;

                // Quitamos la ficha de la posicion anterior
                tablero[origenFila][origenColumna] = 0;

                realizoMovimiento = true;
            }

            else {

                cout << "Las fichas normales solo avanzan\n";
            }
        }

        else {

            // Si existe una captura, estamos obligados a realizarla
            if (obligacionComer)
                cout << "Tienes la obligacion de comer una pieza\n";

            else
                cout << "Movimiento no permitido\n";
        }


        // DESPUES DEL MOVIMIENTO
        // Si el movimiento fue valido, aqui revisamos si la ficha
        // debe convertirse en Dama o si debe seguir capturando.
        if (realizoMovimiento) {


            // CORONACION
            // Las Blancas llegan a la fila 0 para convertirse en Dama.
            if (TurnoActual == 1 && destinoFila == 0 && tablero[destinoFila][destinoColumna] == 1) {
                tablero[destinoFila][destinoColumna] = 3;

                cout << "Tu ficha se ha coronado como Dama (B)\n";
            }

            // Las Rojas llegan a la fila 7 para convertirse en Dama.
            else if (TurnoActual == 2 && destinoFila == 7 && tablero[destinoFila][destinoColumna] == 2) {
                tablero[destinoFila][destinoColumna] = 4;

                cout << "Tu ficha se ha coronado como Dama (R)\n";
            }


            // CAPTURA CONSECUTIVA
            // Despues de comer revisamos si la misma ficha
            // puede volver a comer.
            if (fueCaptura && fichaPuedeComer( destinoFila,destinoColumna, TurnoActual)) {

                // Guardamos la nueva posicion de la ficha
                selFila = destinoFila;
                selCol = destinoColumna;

                enCapturaMultiple = true;

                cout << "Puedes seguir comiendo con la misma ficha\n";
            }


            // CAMBIAR TURNO
            // Si ya no puede seguir comiendo, termina el turno
            // y le toca jugar al otro jugador.
            else {

                selFila = -1;
                selCol = -1;

                enCapturaMultiple = false;

                // Cambiamos de Blancas a Rojas
                // o de Rojas a Blancas.
                if (TurnoActual == 1)
                    TurnoActual = 2;
                else
                    TurnoActual = 1;
            }
        }
    }

    // Aqui termina el programa
    return 0;
}