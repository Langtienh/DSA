#include <iostream>
#include <algorithm>

using namespace std;

int n, a, b, x, y;
long long res;

int main() {
    cin >> n >> a >> b >> x >> y;
    long long c = 1LL*a*b / __gcd(a, b);
    cout << 1LL*n / (1LL*a) *x + 1LL*n / (1LL*b) * y - 1LL*n / c *min(x, y);
}
    
