#include <iostream>
using namespace std;

int main() {
    int threeDimensionalArray[2][3][3] = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {10, 11, 12},
            {13, 14, 15},
            {16, 17, 18}
        }
    };

    cout << "Los elementos del array son:" << endl;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cout << threeDimensionalArray[i][j][k] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
