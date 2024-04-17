#include <iostream>

using namespace std;

typedef long long llong;
llong a[5006], b[5006];
int n, m;
int table[5006];

void process() {
    for(int i=1; i<=m; ++i) {
        int cur = 0;
        for(int j=1; j<=n; ++j) {
            if (a[i] == b[j]) table[j] = max(table[j], cur + 1);
            if (a[i] > b[j]) cur = max(cur, table[j]);
        }
    }
    int res = 0;
    for(int i=1; i<=n; ++i) res = max(res, table[i]);
    cout << res;
}

int main() {
    scanf("%d", &m);
    for(int i=1; i<=m; ++i) scanf("%I64d", &a[i]);
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%I64d", &b[i]);
    process();
    return 0;
}
    
