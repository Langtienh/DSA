#include <iostream>
#include <algorithm>

using namespace std;

int f[56][56];
int L, n, c[56];
bool avail[56][56];

int get_res(int i, int j) {
    if (j == i+1) return 0;
    if (avail[i][j]) return f[i][j];
    avail[i][j] = true;
    for(int k=i+1; k<j; ++k) f[i][j] = min(f[i][j], c[j] - c[i] + get_res(i, k) + get_res(k, j));
    return f[i][j];
}

void init() {
    for(int i=0; i<=n+1; ++i)
    for(int j=0; j<=n+1; ++j) f[i][j] = 1e9, avail[i][j] = false;
}

int main() {
    scanf("%d", &L);
    while (L != 0) {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i) scanf("%d", &c[i]);
        c[n+1] = L; init();
        cout << get_res(0, n+1) << "\n";
        scanf("%d", &L);
    }
    return 0;
}
    
