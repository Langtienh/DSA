#include <iostream>
#include <algorithm>

using namespace std;

int S[106], f[106][106], n;
bool avail[106][106];

void init() {
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j) avail[i][j] = false;
}

int get_res(int l, int r) {
    if (l >= r) return 0;
    if (avail[l][r]) return f[l][r];
    avail[l][r] = true;
    f[l][r] = 1e9;
    for(int i=l; i<r; ++i)
        f[l][r] = min(f[l][r], get_res(l, i) + get_res(i+1, r)+ ((S[i] - S[l-1]) % 100) * ((S[r] - S[i]) % 100));
    return f[l][r];
}

int main() {
    while (scanf("%d", &n) != -1) {
        init();
        for(int i=1; i<=n; ++i) scanf("%d", &S[i]), S[i] += S[i-1];
        cout << get_res(1, n) << "\n";
    }
    return 0;
}
    
