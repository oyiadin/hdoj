// AC
#include <iostream>
#include <string>
using namespace std;

int main() {
    string data;
    int value;
    while (getline(cin, data)) {
        value = 0;
        int i = 0;
        while (data[i] !='\0') {
            if ((data[i]) >= 65 && (data[i]) <= 90) value += ((data[i]) - 'A')+1;
            else if (data[i] >= 97 && data[i] <= 122) value += ((data[i]) - 'a')+1;
            ++i;
        }
        cout << value << endl;
    }
}

/****
    # The value of poetry

    # Problem Description
    "When I was down beside the sea, 
    A wooden spade they gave to me
    To dig the sandy shore
    The holes were empty like a cup ... "

    Bob is a little boy who began to study english. Every day, his teacher will guide them read one or more poetries loudly though they don't understand the meaning of the poetries. But it seems that it doesn't affect Bob enthusiasm of learning english. Because he has his own standard to evaluate a poetry. A letter's order in alphabet is his value no matter lowercase or uppercase and punctuations, digits and spaces' value will be ignored.

    Now, can you calculate the value of the poetry after Bob read it over?

    # Input
    The input contains multiple test cases(No more than 100). 
    Each case contains a poetry only with letters, spaces and punctuations in one line.
    The length of one poetry will not bigger than 10000.

    # Output
    You should output one line with the value of poetry Bob read.

    # Sample Input
    HDOJ
    A C M
    "acm"

    # Sample Output
    37
    17
    17
****/