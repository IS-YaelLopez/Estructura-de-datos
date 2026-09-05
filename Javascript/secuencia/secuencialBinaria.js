const miLista = [3, 7, 12, 15, 22, 30, 44, 50];

// busqueda secuencial
function busquedaSecuencial(lista, objetivo) {
    for (let i = 0; i < lista.length; i++) {
        if (lista[i] === objetivo) {
            return i; // Retorna la posicion
        }
    }
    return -1; // No encontrado
}

// busqueda binaria
function busquedaBinaria(lista, objetivo) {
    let izq = 0, der = lista.length - 1;
    while (izq <= der) {
        const medio = Math.floor((izq + der) / 2);
        if (lista[medio] === objetivo) {
            return medio;
        } else if (lista[medio] < objetivo) {
            izq = medio + 1;
        } else {
            der = medio - 1;
        }
    }
    return -1; // No encontrado
}

console.log(busquedaSecuencial(miLista, 22));
console.log(busquedaBinaria(miLista, 22));
console.log(busquedaSecuencial(miLista, 99));
console.log(busquedaBinaria(miLista, 99));
