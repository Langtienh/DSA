#include <iostream>
#include <algorithm>

using namespace std;

int num[5005];
short int G[5005][5005];
short int f[5006];

void init() {
    for(short int i=2; i<=5000; ++i) {
        f[i] = i;
        for(short int j=i; j<=5000; j+=i)
        for(short int k=j; k<=5000; k+=i) G[j][k] = G[k][j] = i;
    }
}

int main() {
    init();
    short int L, R, k;
    cin >> L >> R >> k;
    long long res = 0;
    L = (L + k - 1) / k;
    R = R / k;
    for(short int i=L; i<=R; ++i)
    for(short int j=L; j<=R; ++j) ++num[G[i][j]];
    for(short int i=1; i<=5000; ++i)
    for(short int j=1; j<=5000; ++j)
        if (G[f[i]][f[j]] == 0) res += 1LL*num[f[i]]*num[f[j]];
    cout << res;
}
    
