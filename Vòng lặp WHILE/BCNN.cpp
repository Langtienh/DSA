#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong a, b;

int main() {
    scanf("%I64d%I64d", &a, &b);
    cout << a / __gcd(a, b) * b;
    
    return 0;
}
    
