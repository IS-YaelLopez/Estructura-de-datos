#implementacion en python
TwoDimensionalArray = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]   
]
print("Los elementos de la matriz son:")
for row in TwoDimensionalArray:
    for element in row:
        print(element, end=" ") # mostrando los elemetos de la fila separados por espacios especiales
        print() # salto de linea para mostrar los elementos de la siguiente fila

print("Los elementos de la matriz en forma de lista son:")
for row in TwoDimensionalArray:
    print(row) # mostrando los elementos de la fila como una lista        