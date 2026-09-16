# Implementación de QuickSort en Python

# Función para hacer la partición del arreglo
def partition(a, l, h):
    # Selecciona el elemento pivote
    pvt = a[h]
    # j es el índice de los elementos que son menores que
    # el pivote y también indica la posición correcta del pivote encontrado hasta este momento
    j = l - 1
    # Recorre a[l..h-1] y mueve todos los elementos menores
    # al lado izquierdo del pivote.
    # Los elementos de l a j son más pequeños después de cada iteración
    for k in range(l, h):  # recorre el arreglo
        # Si el elemento actual es menor que el pivote
        if a[k] < pvt:  # compara el elemento actual con el pivote
            j += 1  # incrementa el índice del elemento más pequeño
            swap(a, j, k)  # intercambia los elementos
    # Mover el pivote después de elementos más pequeños y
    # devolverlo a su posición
    swap(a, j + 1, h)  # intercambia el pivote con el elemento siguiente al último elemento más pequeño
    return j + 1  # devuelve el índice del pivote


# Función para intercambiar dos elementos en el arreglo
def swap(a, j, k):  # intercambia los elementos
    a[j], a[k] = a[k], a[j]  # intercambia los elementos


# Implementación de la función QuickSort
def qckSort(a, l, h):  # función principal de QuickSort
    if l < h:  # si el índice izquierdo es menor que el derecho
        # pi es el índice de partición, regresa el índice del pivote
        pi = partition(a, l, h)  # particiona el arreglo
        # llamadas recursivas para los elementos menores
        # y mayores o iguales a los elementos
        qckSort(a, l, pi - 1)  # llamada recursiva para los elementos menores que el pivote
        qckSort(a, pi + 1, h)  # llamada recursiva para los elementos mayores o iguales que el pivote


# Código para probar la implementación de QuickSort
if __name__ == "__main__":  # punto de entrada del programa
    a = [10, 7, 8, 9, 1, 5]  # arreglo desordenado
    size = len(a)  # tamaño del arreglo
    print("El arreglo antes de ordenarlo: ")
    for v in a:  # imprime el arreglo
        print(v, end=" ")
    print()  # salto de línea
    qckSort(a, 0, size - 1)
    print("El arreglo después de ordenarlo: ")
    for v in a:  # imprime el arreglo ordenado
        print(v, end=" ")
