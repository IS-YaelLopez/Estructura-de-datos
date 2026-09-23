#include <iostream> //puedo usar cout y cin
#include <string> // lo uso pa guardar textos
#include <cstdlib> // Para system("cls")
#include <windows.h> //lo usare para poner color
#include <fstream> //servira para guardar la partida
#include <conio.h> //lo usare para leer teclas sin tener que dar enter
#include <chrono> //lo usare para el temporizador
#include <cstdio> // lo uso para comprobar si existe un archivo
#include <limits> // lo uso para limpiar entradas del teclado
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

//Aqui guardamos como estaba el tablero despues de cada movimiento
int historial[500][8][8];
int totalMovimientos = 0;

// Estado del juego
int turno = 1; // 1 = Jugador de fichas Claras, 2 = Jugador de fichas Rojas
int selFila = -1, selCol = -1; // Guarda la posición de la ficha en captura múltiple
bool enCapturaMultiple = false; // Indica si el jugador está en medio de una racha de capturas

//tiempo que tiene cada jugador para hacer su turno
const int TIEMPO_TURNO = 30;

//esta funcion reinicia el historial cuando comenzamos una partida nueva
void limpiarHistorial(){
    totalMovimientos = 0;
    turno = 1;
    selFila = -1;
    selCol = -1;
    enCapturaMultiple = false;
}

//INICIALIZACIÓN DEL TABLERO
//for anidado para  hacer el tablero 8x8 desde 0 a 7
void inicializarTablero() {
    limpiarHistorial();

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
void mostrarTablero(int cursorFila = -1, int cursorCol = -1, int piezaFila = -1, int piezaCol = -1) {

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

                //Aqui verificamos si el cursor esta sobre esta casilla
                //Si esta seleccionado lo mostramos entre corchetes para saber donde estamos
                if (f == cursorFila && c == cursorCol){
                    if (p == 0) cout << "[.]|";
                    else if (p == 1) cout << "[b]|";
                    else if (p == 2) cout << "[r]|";
                    else if (p == 3) cout << "[B]|";
                    else if (p == 4) cout << "[R]|";
                }
                else if (p == 0){cout << " . |"; }
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

//guardamos el tablero de este movimiento en el historial
void guardarEnHistorial(){
    if (totalMovimientos >= 500) return;

    for (int fila = 0; fila < 8; fila++){
        for (int columna = 0; columna < 8; columna++){
            historial[totalMovimientos][fila][columna] = tablero[fila][columna];
        }
    }

    totalMovimientos++; //incrementa en 1 los movimientos hechos
}

//guardamos todos los movimientos de la partida en un archivo
void guardarPartida(){
    int numeroPartida = 1;

    //buscamos el siguiente numero disponible
    while (numeroPartida <= 99){
        string nombre = "Partida" + to_string(numeroPartida) + ".txt";
        ifstream prueba(nombre);
        if (!prueba) break;
        prueba.close();
        numeroPartida++;
    }

    if (numeroPartida > 99){
        cout << "\nYa existen demasiadas partidas guardadas.\n";
        system("Pause");
        return;
    }

    string nombreArchivo = "Partida" + to_string(numeroPartida) + ".txt";
    ofstream archivo(nombreArchivo);

    if (!archivo){
        cout << "\nNo se pudo guardar la partida.\n";
        system("Pause");
        return;
    }

    archivo << totalMovimientos << endl;

    //guardamos cada tablero del historial
    for (int movimiento = 0; movimiento < totalMovimientos; movimiento++){
        for (int fila = 0; fila < 8; fila++){
            for (int columna = 0; columna < 8; columna++){
                archivo << historial[movimiento][fila][columna] << " ";
            }
            archivo << endl;
        }
    }

    archivo.close();

    cout << "\nPartida guardada como " << nombreArchivo << ".\n";
}

//mostramos una lista con las partidas que existen
void mostrarPartidasGuardadas(){
    cout << "\n========================================\n";
    cout << "       HISTORIAL DE PARTIDAS\n";
    cout << "========================================\n";

    bool hayPartidas = false;

    for (int numero = 1; numero <= 99; numero++){
        string nombre = "Partida" + to_string(numero) + ".txt";
        ifstream archivo(nombre);

        if (archivo){
            hayPartidas = true;
            int movimientos = 0;
            archivo >> movimientos;

            cout << " " << numero << ". " << nombre
                 << " - " << movimientos << " movimientos\n";

            archivo.close();
        }
    }

    if (!hayPartidas){
        cout << "\nNo hay partidas guardadas.\n";
    }
}

//cargamos una partida seleccionada
void cargarPartida(){
    mostrarPartidasGuardadas();

    cout << "\nEscribe el numero de la partida que quieres ver: ";
    int numero;
    cin >> numero;

    if (numero < 1 || numero > 99){
        cout << "\nNumero no valido.\n";
        system("Pause");
        return;
    }

    string nombre = "Partida" + to_string(numero) + ".txt";
    ifstream archivo(nombre);

    if (!archivo){
        cout << "\nNo se encontro esa partida.\n";
        system("Pause");
        return;
    }

    archivo >> totalMovimientos;

    if (totalMovimientos > 500)
        totalMovimientos = 500;

    //leemos todos los tableros guardados
    for (int movimiento = 0; movimiento < totalMovimientos; movimiento++){
        for (int fila = 0; fila < 8; fila++){
            for (int columna = 0; columna < 8; columna++){
                archivo >> historial[movimiento][fila][columna];
            }
        }
    }

    archivo.close();

    //limpiamos el ENTER que quedo despues de escribir el numero de partida
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //mostramos los movimientos uno por uno
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

        cin.ignore();
        cin.get();
    }

    system("cls");

    cout << "================================\n";
    cout << "       FIN DE LA PARTIDA        \n";
    cout << "================================\n";

    system("Pause");
}

//movemos el cursor usando el teclado y esperamos una tecla
//ENTER selecciona la ficha o confirma el destino
//0 = ESC, 1 = ENTER, -1 = se acabo el tiempo, -2 = regresar al menu con 0
int seleccionarConTeclado(int &fila, int &columna, chrono::steady_clock::time_point limite, int piezaFila = -1, int piezaCol = -1){
    while (true){
        system("cls");

        mostrarTablero(fila, columna, piezaFila, piezaCol);

        cout << "\nControles: W/A/S/D o flechas = mover | ENTER = seleccionar";
        cout << "\nESC = cancelar | 0 = regresar al menu";

        auto ahora = chrono::steady_clock::now();
        int restantes = (int)chrono::duration_cast<chrono::seconds>(limite - ahora).count();

        cout << "\nTiempo restante del turno: " << (restantes > 0 ? restantes : 0) << " segundos\n";

        //si se acabo el tiempo ya no puede hacer el movimiento
        if (restantes <= 0){
            return -1;
        }

        if (_kbhit()){
            int tecla = _getch();

            //las flechas mandan primero un codigo especial y despues otro
            if (tecla == 224 || tecla == 0){
                tecla = _getch();

                if (tecla == 72 && fila > 0) fila--;       //flecha arriba
                else if (tecla == 80 && fila < 7) fila++; //flecha abajo
                else if (tecla == 75 && columna > 0) columna--; //flecha izquierda
                else if (tecla == 77 && columna < 7) columna++; //flecha derecha
            }
            else if (tecla == 'w' || tecla == 'W'){
                if (fila > 0) fila--;
            }
            else if (tecla == 's' || tecla == 'S'){
                if (fila < 7) fila++;
            }
            else if (tecla == 'a' || tecla == 'A'){
                if (columna > 0) columna--;
            }
            else if (tecla == 'd' || tecla == 'D'){
                if (columna < 7) columna++;
            }
            else if (tecla == 13){
                return 1;
            }
            else if (tecla == 27){
                return 0;
            }
            else if (tecla == '0'){
                return -2;
            }
        }

        Sleep(50);
    }
}

//funcion para el juego principal
void jugarPartida() {

    //el temporizador empieza una sola vez y se reinicia cuando cambia el turno
    int turnoAnterior = turno;
    auto limiteTurno = chrono::steady_clock::now() + chrono::seconds(TIEMPO_TURNO);

    while (true) {

        //si cambio el turno volvemos a poner los 30 segundos
        if (turno != turnoAnterior){
            turnoAnterior = turno;
            limiteTurno = chrono::steady_clock::now() + chrono::seconds(TIEMPO_TURNO);
        }

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
            return;
        }

        //SELECCION DE FICHA
        int sel = 1;
        int fOrig, cOrig;

        //si no estamos haciendo captura multiple podemos escoger una ficha
        if (!enCapturaMultiple) {

            cout << "\nSelecciona una ficha con W/A/S/D y ENTER.";
            cout << "\nPresiona 0 no aplica aqui; ESC regresa al menu.\n";

            int cursorFila = filas[0];
            int cursorCol = cols[0];

            int seleccionada = seleccionarConTeclado(
                cursorFila, cursorCol, limiteTurno);

            if (seleccionada == -2){
                //si ponen 0 regresamos al menu principal
                return;
            }

            if (seleccionada == 0){
                //si presiona ESC regresamos al menu principal
                return;
            }

            if (seleccionada == -1){
                //si se acaba el tiempo el turno pasa al otro jugador
                cout << "\nSe acabo el tiempo del turno.\n";
                turno = (turno == 1) ? 2 : 1;
                enCapturaMultiple = false;
                selFila = -1;
                selCol = -1;
                system("Pause");
                continue;
            }

            //verificamos que el cursor este sobre una ficha que el jugador pueda mover
            bool encontrada = false;

            for (int i = 0; i < total; i++){
                if (filas[i] == cursorFila && cols[i] == cursorCol){
                    fOrig = cursorFila;
                    cOrig = cursorCol;
                    encontrada = true;
                    break;
                }
            }

            if (!encontrada){
                cout << "\nEsa ficha no se puede seleccionar.\n";
                system("Pause");
                continue;
            }
        }
        else {
            //en captura multiple usamos la ficha que ya habiamos seleccionado
            fOrig = selFila;
            cOrig = selCol;
        }

        //SELECCION DEL DESTINO
        int fDestCursor = fOrig;
        int cDestCursor = cOrig;

        cout << "\nAhora mueve el cursor al destino y presiona ENTER.";
        cout << "\nTiempo para este movimiento: " << TIEMPO_TURNO << " segundos.\n";

        int destinoConfirmado = seleccionarConTeclado(
            fDestCursor, cDestCursor, limiteTurno, fOrig, cOrig);

        if (destinoConfirmado == -2 || destinoConfirmado == 0){
            //si ponen 0 o ESC regresamos al menu principal
            return;
        }

        if (destinoConfirmado == -1){
            //si se acaba el tiempo el turno pasa al otro jugador
            cout << "\nSe acabo el tiempo del turno.\n";
            turno = (turno == 1) ? 2 : 1;
            enCapturaMultiple = false;
            selFila = -1;
            selCol = -1;
            system("Pause");
            continue;
        }

        //calculamos cuanto se movio la ficha
        int df = fDestCursor - fOrig;
        int dc = cDestCursor - cOrig;

        //solo permitimos diagonales de 1 o 2 casillas
        if (abs(df) != abs(dc) || (abs(df) != 1 && abs(df) != 2)){
            cout << "\nMovimiento invalido.\n";
            system("Pause");
            continue;
        }

        //si es captura debe avanzar 2 casillas
        if (obligaCaptura && abs(df) != 2){
            cout << "\nDebes realizar una captura.\n";
            system("Pause");
            continue;
        }

        //si no es captura debe avanzar 1 casilla
        if (!obligaCaptura && abs(df) != 1){
            cout << "\nEse movimiento debe ser de una casilla.\n";
            system("Pause");
            continue;
        }

        int fDest = -1, cDest = -1;

        //guardamos que tipo de pieza es
        int p = tablero[fOrig][cOrig];

        //nos dice si el movimiento se pudo realizar
        bool ejecuto = false;

        //calculamos la direccion usando el movimiento elegido con teclado
        int dFil = df / abs(df);
        int dCol = dc / abs(dc);

        //checamos si el movimiento es valido
        if (evalDir(
            fOrig,
            cOrig,
            dFil,
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
        }

        //si el movimiento no fue valido volvemos a empezar
        if (!ejecuto){
            cout << "\nMovimiento invalido para esa ficha.\n";
            system("Pause");
            continue;
        }

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
        }

        //guardo el tablero para el movimiento
        guardarEnHistorial();

        system("cls"); // limpiamos
        mostrarTablero(); //mostramos el tablero actualizadito
        cout << "\n Movimiento realizado \n";
        system("Pause");
    }
}

//regresamos al menu principal
void volverMenu(){
    cout << "\nPresiona ENTER para regresar al menu principal...";
    cin.ignore();
    cin.get();
}

int main(){

    char op;

    while (true){

        system("cls");

        cout << "===============================\n";
        cout << "       DAMAS \"CHINAS\"        \n";
        cout << "===============================\n";
        cout << "     (1) Iniciar juego         \n";
        cout << "      (2) Cargar partida       \n";
        cout << "      (3) Guardar partida      \n";
        cout << "         (4) Salir             \n";
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
            if (totalMovimientos == 0){
                cout << "\nNo hay movimientos para guardar.\n";
                system("Pause");
            }
            else {
                guardarPartida();
                system("Pause");
            }
        }

        if (op == '4') {
            break;
        }
    }

    return 0;
}