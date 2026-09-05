// implementacion en JavaScript
const twoDimensionalArray = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
];

console.log("Los elementos de la matriz son:");
for (const row of twoDimensionalArray) {
    for (const element of row) {
        process.stdout.write(element + " "); // mostrando los elementos de la fila separados por espacios especiales
        console.log(); // salto de linea para mostrar los elementos de la siguiente fila
    }
}

console.log("Los elementos de la matriz en forma de lista son:");
for (const row of twoDimensionalArray) {
    console.log(row); // mostrando los elementos de la fila como una lista
}
