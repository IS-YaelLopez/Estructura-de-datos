function insertionSort(a) {
    for (let i = 1; i < a.length; i++) {
        let temp = a[i];

        // Mueve los elementos mayores que temp
        // a una posición más adelante de su posición actual
        let j = i - 1;

        while (j >= 0 && temp < a[j]) {
            a[j + 1] = a[j];
            j = j - 1;
        }

        a[j + 1] = temp;
    }
}

function printArr(a) { // función para imprimir el array
    for (let i = 0; i < a.length; i++) {
        process.stdout.write(a[i] + " ");
    }
}

let a = [70, 15, 2, 51, 60];

console.log("Antes de ordenar los elementos del arreglo:");
printArr(a);

insertionSort(a);

console.log("\nDespués de arreglar los elementos del arreglo:");
printArr(a);