function bubbleSort(a) {
    let s = a.length;

    // Iterando por todos los elementos del array
    for (let j = 0; j < s; j++) {
        let isswapped = false;

        // Los últimos j elementos ya están en su lugar correspondiente
        for (let i = 0; i < s - j - 1; i++) {
            // Recorriendo el array
            // Intercambiando si el elemento encontrado es mayor
            // que el siguiente elemento
            if (a[i] > a[i + 1]) {
                [a[i], a[i + 1]] = [a[i + 1], a[i]];
                isswapped = true;
            }
        }

        if (isswapped === false) {
            break;
        }
    }
}

let a = [15, 16, 11, 13, 14];

console.log("Antes de ordenar los elementos del array son:");
console.log(a.join(" "));

bubbleSort(a);

console.log("Después de ordenar los elementos del array son:");
console.log(a.join(" "));