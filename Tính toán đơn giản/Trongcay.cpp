#include <iostream>

using namespace std;

long long a, b, c;

int main() {
    cin >> a >> b >> c;
    a *= 1000;
    long long res = a / (b+c);
    if (a % (b+c) < c) res--;
    cout << res;
    
    return 0;
}
    
