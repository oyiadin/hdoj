#include <iostream>
#include <string>
using namespace std;

void print(int n, double result) {
    string format;
    if(n<=2) format="%d %g\n";
    else format="%d %.9f\n";
    
    printf(format.c_str(), n, result);
}

int main() {
    cout << "n e\n- -----------\n";

    long long factorial, factorial_last=1;
    double result_last=1, result=1;
    for(int n=0; n<=9; n++) {
        if(n==0) print(n, result);
        else {
            factorial = factorial_last * n;
            result = result_last + (1.0/factorial);
            print(n, result);
            factorial_last = factorial;
            result_last = result;
        }
        
    }

}