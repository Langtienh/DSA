#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    long long res = 0;
    if (n & 1) res -= n, ++n;
    res += ((1LL*n)*(1LL*n) >> 2);
    cout << res;
    
    return 0;
}
    
