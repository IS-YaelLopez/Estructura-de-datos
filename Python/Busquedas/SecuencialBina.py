mi_lista = [3, 7, 12, 15, 22, 30, 44, 50]
#busqueda secuencial
def busqueda_secuencial(lista, objetivo):
    for i, elemento in enumerate(lista):
        if elemento == objetivo:
            return i  # Retorna la posición
    return -1  # No encontrado   

#busqueda binaria
def busqueda_binaria(lista, objetivo):
    izq, der = 0, len(lista) - 1
    while izq <= der:
        medio = (izq + der) // 2
        if lista[medio] == objetivo:
            return medio
        elif lista[medio] < objetivo:
            izq = medio + 1
        else:
            der = medio - 1  
    return -1  # No encontrado 
  
print(busqueda_secuencial(mi_lista, 22))   
print(busqueda_binaria(mi_lista, 22))      
print(busqueda_secuencial(mi_lista, 99))   
print(busqueda_binaria(mi_lista, 99))      