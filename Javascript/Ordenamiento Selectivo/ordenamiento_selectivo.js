function seleccion(a) {
    // Recorre todo el arreglo
    for (let i = 0; i < a.length; i++) {
        let small = i; // Indice del elemento más pequeño

        // Encuentra el elemento más pequeño en el arreglo
        for (let j = i + 1; j < a.length; j++) {
            // Compara el elemento más pequeño con el siguiente elemento
            if (a[small] > a[j]) {
                small = j; // Actualiza el indice del elemento más pequeño
            }
        }

        // Intercambia el elemento más pequeño con el primer elemento
        let temp = a[i];
        a[i] = a[small];
        a[small] = temp;
    }
}

function printArr(a) {
    // Recorre todo el arreglo
    for (let i = 0; i < a.length; i++) {
        process.stdout.write(a[i] + " "); // Imprime el elemento
    }

    console.log();
}

let a = [65, 26, 13, 23, 12]; // Arreglo desordenado

console.log("Arreglo antes de ser ordenado:");
printArr(a);

seleccion(a);

console.log("\nArreglo después de ser ordenado:");
printArr(a);