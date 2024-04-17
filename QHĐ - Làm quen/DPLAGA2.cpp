#include <iostream>
#define llong long long

using namespace std;

const llong base = 1e9+7;
llong f[1006][4];

int main() {
    int n; cin >> n;
    f[1][1] = f[1][2] = f[1][3] = 1;
    for(int i=2; i<=n; ++i) {
         f[i][1] = (f[i-1][1] + f[i-1][2] + f[i-1][3]) % base;
         f[i][2] = (f[i-1][1] + f[i-1][3]) % base;
         f[i][3] = (f[i-1][1] + f[i-1][2]) % base;
    }
    cout << (f[n][1] +f[n][2] + f[n][3]) % base;
    
    return 0;
}
    
