#include <iostream>

using namespace std;

long long a, b;

int main() {
    cin >> a >> b;
    long double res = (1.L*a * b) / 2.0L;
    (cout << fixed).precision(2);
    cout << res;
    return 0;
}
    
