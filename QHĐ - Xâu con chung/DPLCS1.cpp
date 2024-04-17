#pragma GCC optimize("O2")
#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
ull f[256][50006], l[50001];
int n, m;;
char a[50006], b[50006];

int main() {
    scanf("%s", a); m = strlen(a);
    scanf("%s", b); n = strlen(b);
    int bl = (m+63)>>6;
    ull s = 1;
    for(int i=0, j = 0; i<m; ++i) {
        f[(int) a[i]][j] |= s;
        s <<= 1;
        if (!s) ++s, ++j;
    }
    ull b1, b2, c;
    for(int i=0; i<n; ++i) {
        b1 = 1, b2 = 0;
        for(int j=0; j<bl; ++j) {
            ull u = l[j] | f[(int) b[i]][j];
            c = l[j] >> 63;
            ull v = u - ((l[j] << 1) | (b1 + b2));
            b1 = c, b2 = (v > u);
            l[j] = u & (~v);
        }
    }
    int res = 0;
    for(int i=0; i<bl; ++i)
       for(; l[i]; ++res) l[i] &= (l[i] - 1);
    cout << res;
    return 0;
}
    
