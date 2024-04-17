#include <iostream>
#define llong long long

using namespace std;

llong power(llong a, llong b) {
    if (b == 0) return 1LL;
    llong z = power(a, b>>1);
    z = (z * z);
    if (b & 1) z = (z * a);
    return z;
}

int main() {
    llong a, b; cin >> a >> b;
    cout << power(a, b); 
}
    
