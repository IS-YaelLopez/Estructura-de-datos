def bubbleSort(a):
    s = len(a)

    # Iterando por todos los elementos del array
    for j in range(s):
        isswapped = False

        # Los últimos j elementos ya están en su lugar correspondiente
        for j in range(0, s - j - 1):
            # Recorriendo el array de 0 a s - j - 1
            # Intercambiando si el elemento encontrado es mayor
            # que el siguiente elemento
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
                isswapped = True

        if (isswapped == False):
            break


# Código del controlador para la prueba anterior
if __name__ == "__main__":
    a = [15, 16, 11, 13, 14]

    print("Antes de ordenar los elementos del array son: ")
    for j in a:
        print(j, end=" ")

    bubbleSort(a)

    print("\nDespués de ordenar los elementos del array son: ")
    for j in range(len(a)):
        print("%d" % a[j], end=" ")
