#include <iostream>
#include <algorithm>

using namespace std;

long long a, b, c, d;

int main() {
    scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &d);
    cout << __gcd(__gcd(__gcd(a, b), c), d);
}
    
