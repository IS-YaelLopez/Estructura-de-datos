// datos
const lista = [10, 20, 30, 40, 50];

// RECORRIDO SECUENCIAL
console.log("RECORRIDO SECUENCIAL:");
for (let i = 0; i < lista.length; i++) {
    console.log(lista[i]);
    // muestra la lista simple como estaba en la lista
}

// RECORRIDO INVERSO
console.log("\nRECORRIDO INVERSO:");
// \n salto de linea
for (let i = lista.length - 1; i >= 0; i--) {
    console.log(lista[i]);
    // mostrara el recorrido inverso por los -1
    // esto sucede porque inicio del ultimo indice o sea el -1, y va con pasos atras -1
    // y acaba hasta llegar al indice 0
}
