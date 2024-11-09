#include <iostream>
#include <string>


class Solution2 {
public:
    bool isPalindrome(int x) {

        if (x < 0) return false;

        long s = 0, t = x;

        while (t) {

            s = (s * 10) + (t % 10);
            t = t / 10;
        }
        return (x == s);
    }
};


//a t se le saca lo que queda de su divicion por 10, entonces por ejemplo si el numero es 121, sobra 1, 
//s obtiene ese 1 y en la siguiente iteracion lo multiplica por 10, para correr un digito a la derecha, y sumar t % 10
//t es ahora 12, por lo cual va a sobrar 2, entonces s se queda con 12.
//t ahora es 1
//s se multiplica por 10 para correr un digito, ahora es 120, pero se le suma t % 10, sobra 1, ahora s = 121, 
//se repite lo mismo hasta que t no sea 0


class Solution {
public:
    bool isPalindrome(int x) {

        std::string num = std::to_string(x);

        int numLenght = num.length();

        for (int low = 0, high = numLenght - 1; low < high; low++, high--) {

            if (num[low] != num[high]) {
                return false;
            }

        }
        return true;
    }
};




int main()
{

    Solution2 a;
    a.isPalindrome(121);

}
