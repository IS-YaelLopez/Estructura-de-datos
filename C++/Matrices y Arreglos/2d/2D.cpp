#include <iostream>
using namespace std;

int main() {
    int r = 3, c = 3;
    int arr[r * c];

    // Matriz inicializada
    int twoDArr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int k = 0;

    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            k = x * c + y;
            arr[k] = twoDArr[x][y];
            k = k + 1;
        }
    }

    cout << "Los elementos del array bidimensional son:" << endl;

    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            cout << twoDArr[x][y] << " ";
        }
        cout << endl;
    }

    cout << "\nLos elementos del array unidimensional son:" << endl;

    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            cout << arr[x * c + y] << " ";
        }
    }

    return 0;
}
