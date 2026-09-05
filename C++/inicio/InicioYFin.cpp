#include <iostream>
#include <vector>
#include <string>
using namespace std;

void imprimir(const vector<string>& v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << endl;
}

int main()
{
    // Insercion al inicio
    vector<string> abecedario = {"a", "b", "c", "d"};
    imprimir(abecedario);
    // muestra normal

    abecedario.insert(abecedario.begin(), "z");
    imprimir(abecedario);

    // Insercion al final
    abecedario = {"a", "b", "c", "d"};
    imprimir(abecedario);
    // muestra normal

    abecedario.insert(abecedario.begin() + 4, "z");
    imprimir(abecedario);

    return 0;
}
