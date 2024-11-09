#include <iostream>
#include <unordered_map>
#include <string>
#include <map>

using namespace std;

string intToRoman(int num) {
    vector<int>val = { 1000, 900, 500, 400, 100,   90,  50,  40,   10,   9,   5,    4,    1 };
    vector<string>ch = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
  
    string roman_num = "";
    
    int times = 0;
    
    for (int i = 0; i < 13; i++) {

        if (num == 0) {
            break;
        }

        times = num / val[i];

        //cant use string(times,val[i]), bcz 'ch' is a string vector not char vector
        //and this fun is limited to char vector or inserting characters only
        while (times--) {
            roman_num += ch[i];
        }
        // no need to create a temp and sub it,just modulo
        num %= val[i];
    }
    return roman_num;
}

//O(1) woa
string intToRoman2(int num) {
    string ones[] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };
    string tens[] = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
    string hrns[] = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
    string ths[] = { "","M","MM","MMM" };

    return ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
}

int main()
{
    intToRoman(58);
}
