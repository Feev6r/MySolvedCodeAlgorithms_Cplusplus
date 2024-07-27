#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int rows = 3;
    int cols = 4;

    // Crear el vector 2D como un vector de vectores
    vector<vector<int>> vec2D(rows, vector<int>(cols));

    // Rellenar el vector 2D con algunos valores
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            vec2D[i][j] = i * cols + j;
        }
    }

    // Imprimir el contenido del vector 2D
    cout << "Contenido del vector 2D:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << vec2D[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
