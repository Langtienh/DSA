#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int a[100006], b[100006], c[200006], n, m, n1;
bool avail[200006];

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int j=1; j<=m; ++j) scanf("%d", &b[j]);
    sort(a+1, a+n+1); sort(b+1, b+m+1);
    int i=1, j = 1; n1 = 0;
    if (b[m] <= a[1]) {
        cout << 0;
        return 0;
    }
    while (i <= n && j <= m) {
        if (a[i] > b[j]) c[++n1] = b[j++];
        else if (a[i] < b[j]) c[++n1] = a[i++], avail[n1] = true;
        else c[++n1] = b[j++], c[++n1] = a[i++], avail[n1] = true;
    }
    while (j <= m) c[++n1] = b[j++];
    llong cost1 = 0, cost2 = 0; int num1 = 0, num2 = 0;
    for(i=1; i < n1; ++i)
        if (avail[i]) cost1 += c[n1] - c[i], ++num1;
    llong res = cost1;
    for(int i=n1-1; i; --i) {
        if (avail[i+1] == 0) ++num2;
        cost2 += 1LL*num2*(c[i+1] - c[i]);
        cost1 -= 1LL*num1*(c[i+1] - c[i]);
        res = min(res, cost1 + cost2);
        if (avail[i] == 1) --num1;
    }
    cout << res;
    return 0;
}
    
