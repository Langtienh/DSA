#include <iostream>
#define llong long long
#define pii pair<llong, int>
#define mk make_pair

using namespace std;

int n, a[10006];
pii nf[10006], f[10006], res;

pii max(pii A, pii B) {
    if (A.first > B.first || (A.first == B.first && A.second < B.second))
         return A;
    return B;
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    res = nf[0] = nf[1] = mk(0LL, 0); f[1] = mk(1LL*a[1], 1);
    if (n == 1) {
        cout << 1 << " " << a[1];
        return 0;
    }
    for(int i=2; i<=n; ++i) {
        nf[i] = max(nf[i-1], f[i-1]);
        pii tmp = mk(nf[i-2].first + a[i-1], nf[i-2].second + 1);
        f[i] = max(nf[i-1], tmp);
        f[i].first += a[i], f[i].second += 1;
        res = max(res, f[i]);
    }
    cout << res.second << " " << res.first;
    
    return 0;
}
    
