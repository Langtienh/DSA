#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int main() {
    llong a, b, c;
    int n;
    cin >> a >> b >> c >> n;
    a = a * b / __gcd(a, b);
    a = a * c / __gcd(a, c);
    llong mmax = 1, l_max;
    if (n == 0) {
        cout << -1;
        return 0;
    }

    for(int i=1; i<=n; ++i)
        mmax *= 10;
    --mmax;
    l_max = mmax / a;
    if (l_max == 0) {
        cout << -1;
        return 0;
    }
    a *= l_max;
    cout << a;

    return 0;
}
    
