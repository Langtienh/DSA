#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <set>
#define fname "FINDIDGIFT"
#define llong long long

using namespace std;

llong S, k;
int a[100006], b[100006], n;
bool avail[100006];

void enter() {
    scanf("%d%I64d", &n, &k);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]); S += a[i];
        b[i] = i;
    }
    sort(b+1, b+n+1, [] (const int &A, const int &B) {
        return a[A] < a[B];
    });
}

void process() {
    if (S < k) cout << k - S;
    else if (S == k) cout << "OK";
    else {
        a[0] = 0;
        int m = n, l = 1;
        while (l <= n) {
            int r = l;
            while (r <= n && a[b[r]] == a[b[l]]) ++r;
            if ((1LL*a[b[l]] - a[b[l-1]]) * m > k) {
                llong mod = k % m;
                llong div = k / m;
                int pos;
                if (mod == 0) {
                    pos = 1;
                    while (avail[pos]) ++pos;
                } else {
                    for(int i=1; i<=n; ++i)
                        if (!avail[i]) {
                            if (a[b[l - 1]] + div + 1 == a[i]) avail[i] = true;
                            mod--;
                            if (mod == 0) {
                                pos = i+1;
                                while (avail[pos]) ++pos;
                                break;
                            }
                        }
                }
                for(int i=pos; i<=n; ++i)
                    if (!avail[i]) cout << i << " ";
                for(int i=1; i<pos; ++i)
                    if (!avail[i]) cout << i << " ";
                break;
            }
            k -= (1LL*a[b[l]] - a[b[l-1]]) * m;
            for(int i=l; i<r; ++i) avail[b[i]] = true;
            m -= (r - l);
            l = r;
        }
    }
}

int main() {

    enter();
    process();

    return 0;
}
    
