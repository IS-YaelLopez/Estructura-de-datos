#include <iostream> //puedo usar cout y cin
#include <string> // lo uso pa guardar textos
#include <cstdlib> // Para system("cls")
#include <windows.h> //lo usare para poner color
#include <fstream> //servira para guardar la partida
using namespace std;

// funcion llamada color que recibe un numero y ese numero se lo 
//manda a windows para cambiar el color de consola
void color(int codigo){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), codigo);
}

// Matriz principal 8x8 (Representación del Tablero)
// 0 Casilla vacía
// 1 Ficha Clara (b), 2 Ficha Roja (r)
// 3 Dama Clara (B), 4 Dama Roja (R)
int tablero[8][8];

int historial[500][8][8];
int totalMovimientos;
// Estado del juego
int turno = 1; // 1 = Jugador de fichas Claras, 2 = Jugador de fichas Rojas
int selFila = -1, selCol = -1; // Guarda la posición de la ficha en captura múltiple
bool enCapturaMultiple = false; // Indica si el jugador está en medio de una racha de capturas


//INICIALIZACIÓN DEL TABLERO
//for anidado para  hacer el tablero 8x8 desde 0 a 7
void inicializarTablero() {
    for (int f = 0; f < 8; f++) {
        for (int c = 0; c < 8; c++) {
            tablero[f][c] = 0; // Limpia la casilla
            
            // Solo las casillas oscuras son jugables: (fila + columna) es impar
            if ((f + c) % 2 != 0) { //si se obtiene de resto 1 la casilla es jugable
                if (f < 3) tablero[f][c] = 2;      // Filas 0, 1, 2: Rojas (arriba)
                else if (f > 4) tablero[f][c] = 1; // Filas 5, 6, 7: Claras (abajo)
            }
        }
    }
}

//VISUALIZACIÓN DEL TABLERO EN CONSOLA
void mostrarTablero() {

    cout << "\n       0   1   2   3   4   5   6   7\n     ---------------------------------\n";

    for (int f = 0; f < 8; f++) {
        cout << "  " << f << " |";
        for (int c = 0; c < 8; c++) {
            // Imprime casilla no jugable
            if ((f + c) % 2 == 0) {
                cout << "   |";

            } else {

                // Imprime el contenido de la casilla oscura o sea jugable
                int p = tablero[f][c];
                //Aqui verificamos que pieza hay en la casilla
                //Con los else if vamos revisando cada caso y dependiendo
                //del numero mostramos la pieza correspondiente y le ponemos color.
                if (p == 0){cout << " . |"; }
                else if (p == 1){color(112); cout << " b "; color(7); cout << "|";}
                else if (p == 2){color(12); cout << " r "; color(7); cout << "|";}
                else if (p == 3){color(112); cout << " B "; color(7); cout << "|";}
                else if (p == 4){color(12); cout << " R "; color(7); cout << "|";}
            }
        }

        cout << "\n     ---------------------------------\n";
    }

    cout << "Turno actual: " << (turno == 1 ? "Claras (b/B)\n" : "Rojas (r/R)\n");
}


//FUNCIONES DE IDENTIFICACIÓN
// este nos permite saber si es pieza(p) de nosotros con un true o false
bool esPropia(int p) { //si turno es =1 entonces usa las piezas 1 y 3 normal y dama 
                       //y si es turno = 2 usa pieza 2 y dama 4
    return (turno == 1 && (p == 1 || p == 3)) || (turno == 2 && (p == 2 || p == 4)); 
}

// hace casi lo mismo, pero verifica el enemigo 
bool esEnemiga(int p) { 
    return (turno == 1 && (p == 2 || p == 4)) || (turno == 2 && (p == 1 || p == 3)); 
}

//EVALUACIÓN DE MOVIMIENTOS Y CAPTURAS

//Evaluamos la direccion(evalDir) usando fila(f)
//columna(c) direccion fila(df) direcccion columna(dc)
//captura,  fila destino (&fDest), columna destino (&cDest)
//& modifica la funciones
bool evalDir(int f, int c, int df, int dc, bool captura, int &fDest, int &cDest) {
    int p = tablero[f][c];//obtiene la pieza
    bool esDama = (p == 3 || p == 4);//verifica si es una dama

    // Fichas normales solo avanzan
    if (!esDama && ((turno == 1 && df > 0) || 
    (turno == 2 && df < 0))) //si no es dama e intenta moverse hacia atras no dejara hacerlo
        return false;//si la pieza no es dama entonces solo puede avanzar normal 

    //Movimiento simple de 1 casilla
    if (!captura) {
        fDest = f + df; 
        cDest = c + dc;//con esto calcula donde terminara la pieza 
         //aqui comprobamos que todo sea valido
        return (
            fDest >= 0 && //no puede ser >= 0
            fDest < 8 && //no puede ser < 8
            cDest >= 0 && //no puede ser >= 0
            cDest < 8 && //no puede ser < 8
            tablero[fDest][cDest] == 0 //el destino tiene que estar vacio
        );

    }

    //Captura de ficha enemiga (salto de 2 casillas)
    int fMed = f + df, cMed = c + dc; //fMed y cMed fila y columna del medio      
    fDest = f + df * 2; //calculamos destino de fila
    cDest = c + dc * 2; //calculamos destino de columna

    return (
        fDest >= 0 &&
        fDest < 8 &&
        cDest >= 0 &&
        cDest < 8 &&
        esEnemiga(tablero[fMed][cMed]) //con esto checo que la ficha que esta entre medio sea enemiga
                                    //si lo es podre comer
        && tablero[fDest][cDest] == 0);// tambien vemos si la casilla esta libre 
}

bool puedeAccion(int f, int c, bool captura) //con este checamos si las fichas pueden hacer una accion
{
    if (!esPropia(tablero[f][c])) return false; //comprobamos que sea del jugador actual
    int fd, cd;
    //aqui checa todas las posibles acciones en cada diagonal
    //si hay alguna posible accion entonces devolvera true
    return 
    evalDir(f, c, -1, -1, captura, fd, cd)|| 
    evalDir(f, c, -1, 1, captura, fd, cd) ||
    evalDir(f, c, 1, -1, captura, fd, cd) || 
    evalDir(f, c, 1, 1, captura, fd, cd);
}

//checo si hay alguan captura posible en todo el tablero
bool hayCapturaGeneral() 
{ //recorro todas las casillas que hay y si hay captura posible devuelve true
    //si no lo hay entonces devuelve false y termina el
    for (int f = 0; f < 8; f++) {
        for (int c = 0; c < 8; c++) {
            if (puedeAccion(f, c, true)) return true;
        }
    }
    return false;
}

//funcion para el juego principal
void jugarPartida() {
   

    while (true) {
        //limpiamos la pantalla para que se vea solamente el turno actual
        system("cls");

        //mostramos el tablero
        mostrarTablero();

        //checamos si hay alguna captura obligatoria
        bool obligaCaptura = hayCapturaGeneral();

        //guardamos las posiciones de las fichas que se pueden mover
        int filas[12], cols[12], total = 0;

        //CAPTURA MULTIPLE
        //si estamos haciendo una captura seguida no podemos escoger otra ficha
        if (enCapturaMultiple) {
            filas[0] = selFila;
            cols[0] = selCol;
            total = 1;

            cout << "\n Captura consecutiva Debes continuar con ["
                 << selFila << "][" << selCol << "]\n";
        }
        else {
            //mostramos las fichas que puede mover el jugador
            cout << "\nFICHAS DISPONIBLES"
                 << (obligaCaptura ? " (OBLIGADO A COMER):\n\n" : ":\n\n");

            //recorremos todo el tablero para buscar las fichas que se pueden mover
            for (int f = 0; f < 8; f++) {
                for (int c = 0; c < 8; c++) {

                    //checamos si esta ficha puede hacer el movimiento
                    if (puedeAccion(f, c, obligaCaptura)) {

                        //guardamos la posicion de la ficha
                        filas[total] = f;
                        cols[total] = c;

                        int p = tablero[f][c];

                        //mostramos si es ficha normal o dama y su posicion
                        cout << total + 1 << ". "
                             << (p >= 3 ? "Dama " : "Ficha ")
                             << (turno == 1 ? "clara" : "roja")
                             << " en [" << f << "][" << c << "]\n";

                        total++;
                    }
                }
            }
        }

        //si no hay fichas que puedan moverse significa que el jugador perdio
        if (total == 0) {
            cout << "\nEl jugador "
                 << (turno == 1 ? "Claras" : "Rojas")
                 << " se ha quedado sin movimientos/fichas.\n";

            //el jugador contrario gana
            cout << "GANA EL JUGADOR "
                 << (turno == 1 ? "ROJO (r)" : "BLANCO (b)")
                 << "\n";
                 system("Pause");

            break;
        }

        //SELECCION DE FICHA
        int sel = 1;

        //si no estamos haciendo captura multiple podemos escoger una ficha
        if (!enCapturaMultiple) {

            cout << "\nSelecciona una ficha(0 para acordar fin): ";
            cin >> sel;

            //si ponen 0 se termina la partida
            if (sel == 0) {
                cout << "\nPartida finalizada por acuerdo de los jugadores.\n";
                break;
            }

            //si ponen un numero que no existe volvemos a empezar el turno
            if (sel < 1 || sel > total)
                continue;
        }

        //sacamos la fila y columna de la ficha que seleccionamos
        int fOrig = filas[sel - 1];
        int cOrig = cols[sel - 1];

        //guardamos la direccion que quiere hacer el jugador
        string dir;

        cout << "Mueve la ficha hacia izquierda o derecha (D o I): ";
        cin >> dir;

        //convertimos las letras a minusculas para evitar problemas
        //por ejemplo Izquierda e IZQUIERDA
        for (char &c : dir)
            c = tolower(c);

        //decidimos si la ficha va a la izquierda o a la derecha
        int dCol = (dir == "i") ? -1 :
                   (dir == "d") ? 1 : 0;

        //si escribio otra cosa volvemos a empezar
        if (dCol == 0)
            continue;

        //PROCESAMOS EL MOVIMIENTO
        int fDest = -1, cDest = -1;

        //guardamos que tipo de pieza es
        int p = tablero[fOrig][cOrig];

        //nos dice si el movimiento se pudo realizar
        bool ejecuto = false;

        //guardamos las direcciones que puede tomar la pieza
        //una ficha normal solamente puede avanzar
        //una dama puede avanzar y regresar
        int dFilas[2] = {
            (turno == 1 ? -1 : 1),
            (p >= 3 ? (turno == 1 ? 1 : -1) : 0)
        };

        //revisamos las direcciones posibles
        for (int i = 0; i < (p >= 3 ? 2 : 1); i++) {

            //checamos si el movimiento es valido
            if (evalDir(
                fOrig,
                cOrig,
                dFilas[i],
                dCol,
                obligaCaptura,
                fDest,
                cDest
            )) {

                //movemos la pieza a la nueva posicion
                tablero[fDest][cDest] = p;

                //dejamos vacia la posicion anterior
                tablero[fOrig][cOrig] = 0;

                //si era una captura eliminamos la pieza enemiga
                if (obligaCaptura) {
                    tablero[(fOrig + fDest) / 2]
                           [(cOrig + cDest) / 2] = 0;
                }

                //decimos que el movimiento si se hizo
                ejecuto = true;

                //ya no necesitamos revisar la otra direccion
                break;
            }
        }

        //si el movimiento no fue valido volvemos a empezar
        if (!ejecuto)
            continue;

        //CORONACION
        //si una ficha normal llega al otro extremo se convierte en dama
        if ((turno == 1 && fDest == 0 && p == 1) ||
            (turno == 2 && fDest == 7 && p == 2)) {

            //sumamos 2 para convertir:
            //1 pasa a 3 y 2 pasa a 4
            tablero[fDest][cDest] += 2;
        }

        //CAPTURA MULTIPLE
        //despues de comer revisamos si puede volver a comer otra ficha
        if (obligaCaptura && puedeAccion(fDest, cDest, true)) {

            //guardamos la nueva posicion de la ficha
            //para que sea la misma la que continue comiendo
            selFila = fDest;
            selCol = cDest;

            //activamos la captura multiple
            enCapturaMultiple = true;
        }
        else {

            //si ya no puede seguir comiendo quitamos la captura multiple
            selFila = -1;
            selCol = -1;
            enCapturaMultiple = false;
            //cambiamos el turno al otro jugador
            turno = (turno == 1) ? 2 : 1;

            system("cls");
            mostrarTablero();
            cout << "\n Movimiento realizado \n";
            system("Pause");
        }
           //guardo el tablero para el movimiento
            for (int fila =0; fila < 8; fila++){
                for (int columna =0; columna < 8; columna++){
                    historial[totalMovimientos][fila][columna] = tablero[fila][columna];
                }
            }
            totalMovimientos++; //incrementa en 1 los movimientos hechos

            system("cls"); // limpiamos
            mostrarTablero(); //mostramos el tablero actualizadito
            cout << "\n Movimiento realizado \n";
            system("Pause");
        
    }
}
//cargo partida
void cargarPartida(){

    if (totalMovimientos == 0){
        cout << "\nNo hay movimientos guardados.\n";
        system("Pause");
        return;
    }

    for (int movimiento = 0; movimiento < totalMovimientos; movimiento++){

        system("cls");

        //copiamos el movimiento al tablero
        for (int fila = 0; fila < 8; fila++){
            for (int columna = 0; columna < 8; columna++){
                tablero[fila][columna] =
                    historial[movimiento][fila][columna];
            }
        }

        cout << "================================\n";
        cout << " Movimiento: " << movimiento + 1;
        cout << " de: " << totalMovimientos << "\n";
        cout << "================================\n\n";

        mostrarTablero();

        cout << "\n Enter para el proximo movimiento";

        cin.ignore(); //limpia el buffer
        cin.get();//lee caulquier letra
    }

    system("cls");

    cout << "================================\n";
    cout << "       FIN DE LA PARTIDA        \n";
    cout << "================================\n";

    system("Pause");
}
int main(){

    char op;

    while (true){

        system("cls");

        cout << "===============================\n";
        cout << "       DAMAS ""CHINAS""        \n";
        cout << "===============================\n";
        cout << "     (1) Iniciar juego         \n";
        cout << "      (2) Cargar partida       \n";
        cout << "         (3) Salir             \n";
        cout << "===============================\n";

        cin >> op;

        if (op == '1') {
            inicializarTablero();
            jugarPartida();
        }

        if (op == '2') {
            cargarPartida();
        }

        if (op == '3') {
            break;
        }
    }
    return 0;
}