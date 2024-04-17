#include <iostream>

using namespace std;

int n;

int main() {
    (cout << fixed).precision(10);
    long double d = 1, res = 0;
    cin >> n;
    for (int i=1; i<=n; ++i) {
        d /= 1.0L*i;
        res += d;
    }
    cout << res;
    
    return 0;
}
    
