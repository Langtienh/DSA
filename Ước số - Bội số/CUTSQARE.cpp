#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong a, b;

int main() {
    scanf("%I64d%I64d", &a, &b);
    llong res = __gcd(a, b);
    a /= res, b /= res;
    res = a*b;
    cout << res;
    
    return 0;
}
    
