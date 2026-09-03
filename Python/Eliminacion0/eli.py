#Programa para eliminar un elemento al principio de un array
inputArr = [11, 21, 31, 41, 51, 61]
print("Antes de la eliminacion, el array es: ")
for j in range(len(inputArr)):
    print(inputArr[j], end= " ")

#Eliminado el primer elemento del inputArr[0]
print("\nDespues de la eliminacion, el array es: ")
inputArr.pop(0)
for j in range(len(inputArr)):
    print(inputArr[j], end=" ")


#Eliminado el ultimo elemento del inputArr[-1]
inputArr = [11, 21, 31, 41, 51, 61]
print("\nDespues de la eliminacion, el array es: ")
inputArr.pop(-1)
for j in range(len(inputArr)):
    print(inputArr[j], end=" ")

#Eliminando el numero del medio el inputArr[2]
inputArr = [11, 21, 31, 41, 51, 61]
print("\nDespues de la eliminacion, el array es: ") 
inputArr.pop(2)
for j in range(len(inputArr)):
    print(inputArr[j], end=" ")
