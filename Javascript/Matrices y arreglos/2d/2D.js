// Implementación en JavaScript
let r = 3;
let c = 3;
let arr = new Array(r * c).fill(0);

// Matriz inicializada
let twoDArr = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
];

let k = 0;

for (let x = 0; x < r; x++) {
    for (let y = 0; y < c; y++) {
        k = x * c + y;
        arr[k] = twoDArr[x][y];
        k = k + 1;
    }
}

console.log("Los elementos del array bidimensional son:");

for (let row of twoDArr) {
    for (let ele of row) {
        process.stdout.write(ele + " ");
    }
    console.log();
}

console.log("\nLos elementos del array unidimensional son:");

for (let x = 0; x < r; x++) {
    for (let y = 0; y < c; y++) {
        process.stdout.write(arr[x * c + y] + " ");
    }
}
