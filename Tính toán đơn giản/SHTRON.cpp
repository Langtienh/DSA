#include <iostream>

using namespace std;

long long a;

int main() {
    cin >>  a;
    long double res = 3.141592653589793238462643383279502884L*a*a;
    (cout << fixed).precision(0);
    cout << res;
    return 0;
}
    
