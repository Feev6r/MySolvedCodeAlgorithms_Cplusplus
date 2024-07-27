#include <iostream>
#include <vector>


using namespace std;

unsigned int gridTraveler(int m, int n) {

    vector<vector<unsigned int>> table(m + 1, vector<unsigned int >(n + 1, 0));
    table[1][1] = 1;

    for (int y = 0; y <= m; y++)
    {
        for (int x = 0; x <= n; x++)
        {
            unsigned int  current = table[y][x];
            if (x + 1 <= n) table[y][x + 1] += current;
            if (y + 1 <= m) table[y + 1][x] += current;
        }
    }

    return table[m][n];
}

//funciona con unasigned int : 0 to 4,294,967,295
//funciona con long long int : -(2^63) to (2^63)-1

//unasigned int no tiene signo, por lo cual sobran 31 bits que se pueden utilizar
//solamente en numeros positivos.
//por ahi vi que no era buena idea utilizarlos, 
//pero yo creo que es mas que nada en cosas mas complejas
//pero en este caso no hay nada de malo.

int main()
{
    std::cout << gridTraveler(2, 3) << endl;
    std::cout << gridTraveler(18, 18) << endl;
}
