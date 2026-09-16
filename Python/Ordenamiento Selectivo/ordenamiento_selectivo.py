def seleccion(a):  # Funcion para implementar el algoritmo de selección
    for i in range(len(a)):  # Recorre todo el arreglo
        small = i  # Indice del elemento más pequeño

        for j in range(i + 1, len(a)):  # Encuentra el elemento más pequeño en el arreglo
            if a[small] > a[j]:  # Compara el elemento más pequeño con el siguiente elemento
                small = j  # Actualiza el indice del elemento más pequeño

        # Intercambia el elemento más pequeño con el primer elemento
        a[i], a[small] = a[small], a[i]  # Intercambia los elementos


def printArr(a):  # Funcion para imprimir el array
    for i in range(len(a)):  # Recorre todo el arreglo
        print(a[i], end=" ")  # Imprime el elemento

    print()


a = [65, 26, 13, 23, 12]  # Arreglo desordenado

print("Arreglo antes de ser ordenado:")
printArr(a)

seleccion(a)

print("\nArreglo después de ser ordenado:")
printArr(a)
