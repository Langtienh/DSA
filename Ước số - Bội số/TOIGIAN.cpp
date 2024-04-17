#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int main() {
    llong a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        llong e = __gcd(a, b); a /= e, b /= e;
        e = __gcd(c, d); c /= e, d /= e;
        e = b / __gcd(b, d) * d;
        a = e/b*a + e/d*c;
        b = __gcd(a, e);
        cout << a/b << "/" << e/b;
        putchar('\n');
    }
    return 0;
}
    
