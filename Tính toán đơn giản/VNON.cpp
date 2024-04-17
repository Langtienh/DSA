#include <iostream>

using namespace std;

long long R, h;

int main() {
    cin >> h >> R;
    long double res = 3.141592653589793238462643383279502884L*R*R*h/3.0L;
    (cout << fixed).precision(8);
    cout << res;
    return 0;
}
    
