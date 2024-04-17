#include <iostream>
#include <algorithm>

using namespace std;

int f[506][506], S[506][506], a[506];
int n, k, t;
bool avail[506][506];

void init() {
    for(int i=1; i<=n; ++i) {
        int mmin = 1e9;
        for(int j=i; j>=max(1, i-t+1); --j) {
            mmin = min(mmin, a[j]);
            S[i-j+1][i] = max(S[i-j][i], (i-j+1) * mmin);
        }
    }
}

int get_res(int cnt, int pos) {
    if (avail[cnt][pos]) return f[cnt][pos];
    avail[cnt][pos] = true;
    if (cnt == 1) return f[cnt][pos] = S[min(pos, t)][pos];
    for(int i=1; i<pos; ++i) f[cnt][pos] = max(f[cnt][pos], get_res(cnt-1, i) + S[min(pos-i, t)][pos]);
    return f[cnt][pos];
}

int main() {
    scanf("%d%d%d", &n, &k, &t);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    init(); int res = 0;
    for(int i=k; i<=n; ++i) res = max(res, get_res(k, i));
    cout << res;
    return 0;
}
    
