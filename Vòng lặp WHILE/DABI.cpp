#include <iostream>

using namespace std;

int main() {
    int res = 0;
    long long n, m;
    cin >> n; m = n;
    while (n > 0) res += n%10, n/=10;
    if (m % res == 0) cout << 1;
    else cout << 0;
    
    return 0;
}
    
