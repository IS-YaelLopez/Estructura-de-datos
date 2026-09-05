// Programa para eliminar un elemento al principio de un array
let inputArr = [11, 21, 31, 41, 51, 61];
console.log("Antes de la eliminacion, el array es: ");
process.stdout.write(inputArr.join(" "));

// Eliminando el primer elemento del inputArr[0]
console.log("\nDespues de la eliminacion, el array es: ");
inputArr.shift();
process.stdout.write(inputArr.join(" "));

// Eliminando el ultimo elemento del inputArr[-1]
inputArr = [11, 21, 31, 41, 51, 61];
console.log("\nDespues de la eliminacion, el array es: ");
inputArr.pop();
process.stdout.write(inputArr.join(" "));

// Eliminando el numero del medio el inputArr[2]
inputArr = [11, 21, 31, 41, 51, 61];
console.log("\nDespues de la eliminacion, el array es: ");
inputArr.splice(2, 1);
process.stdout.write(inputArr.join(" "));
console.log();
