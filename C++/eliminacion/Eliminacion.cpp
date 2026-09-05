#include <iostream>
#include <vector>
using namespace std;

// Programa para eliminar un elemento al principio de un array
int main()
{
    vector<int> inputArr = {11, 21, 31, 41, 51, 61};
    cout << "Antes de la eliminacion, el array es: " << endl;
    for (size_t j = 0; j < inputArr.size(); j++)
    {
        cout << inputArr[j] << " ";
    }

    // Eliminando el primer elemento del inputArr[0]
    cout << "\nDespues de la eliminacion, el array es: " << endl;
    inputArr.erase(inputArr.begin());
    for (size_t j = 0; j < inputArr.size(); j++)
    {
        cout << inputArr[j] << " ";
    }

    // Eliminando el ultimo elemento del inputArr[-1]
    inputArr = {11, 21, 31, 41, 51, 61};
    cout << "\nDespues de la eliminacion, el array es: " << endl;
    inputArr.erase(inputArr.end() - 1);
    for (size_t j = 0; j < inputArr.size(); j++)
    {
        cout << inputArr[j] << " ";
    }

    // Eliminando el numero del medio el inputArr[2]
    inputArr = {11, 21, 31, 41, 51, 61};
    cout << "\nDespues de la eliminacion, el array es: " << endl;
    inputArr.erase(inputArr.begin() + 2);
    for (size_t j = 0; j < inputArr.size(); j++)
    {
        cout << inputArr[j] << " ";
    }

    return 0;
}
