#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <cstring>
#define pii pair<int, int>
#define mk make_pair

using namespace std;

int a[100006], b[100006];
int c[100006], len, cnt = 0;
pii V[300006];
char S[100006];

int main() {
    scanf("%s", S+1); len = strlen(S+1);
    for(int i=1, s1 = 0, s2 = 0; i<=len; ++i) {
        if (S[i] == 'S') c[i] = 1, ++s1;
        else c[i] = 2, ++s2;
        a[i] = s1, b[i] = s2;
    }
    for(int m=1; m<=len; ++m) {
        int n1, n2, last1, last2; n1 = n2 = last1 = last2 = 0;
        while (true) {
            int pos1 = lower_bound(a+1, a+len+1, last1 + m) - a;
            int pos2 = lower_bound(b+1, b+len+1, last2 + m) - b;
            if (pos1 > len && pos2 > len) break;
            int pos;
            if (pos1 > pos2) pos = pos2, ++n2; else pos = pos1, ++n1;
            if (pos == len) {
                if ((n1 > n2 && c[len] == 1) || (n1 < n2 && c[len] == 2)) V[++cnt] = mk(max(n1, n2), m);
                break;
            }
            last1 = a[pos];
            last2 = b[pos];
        }
    }
    if (cnt == 0) {
        cout << "ERROR";
        return 0;
    }
    sort(V+1, V+cnt+1);
    for(int i=1; i<=cnt; ++i) cout << V[i].first << " " << V[i].second << "\n";

    return 0;
}
    
