#include <iostream>
#include <algorithm>

using namespace std;

long long n, f[101], cnt = 0;

int main() {
    f[0] = 0, f[1] = 1; cnt = 1;
    for(int i=2; f[i-1]+f[i-2] <= 1e15; ++i) {
        ++cnt;
        f[i] = f[i-1] + f[i-2];
    }
    int t = 0; cin >> t;
    while (t--) {
        cin >> n;
        int ok = 0;
        for (int i=1; f[i] <= n && ok == 0; ++i)
        for(int j=1; f[i]*f[j] <=n && ok == 0; ++j)
            if (f[i] * f[j] == n) ok = 1;
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
    
