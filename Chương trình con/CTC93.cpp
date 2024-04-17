#include <iostream>

using namespace std;

long long f[25];

int main() {
    f[0] = 1;
    for(int i=1; i<=20; ++i) f[i] = f[i-1]*i;
    
    int n; cin >> n;
    while (n--) {
        int a; cin >> a;
        cout << f[a] << "\n";
    }
    
    return 0;
}
    
