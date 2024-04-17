#include <iostream>
#define llong long long

using namespace std;

const llong base = 1e9+7;

llong power(llong a, llong b) {
    if (b == 0) return 1LL;
    llong z   = power(a, b>>1);
    z = (z * z) % base;
    if (b & 1) z = (z * a) % base;
    return z;
}

int main() {
    llong a, b; cin >> a >> b;
    cout << power(a, b); 
}
    
