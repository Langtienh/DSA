#pragma GCC optimize("O3")
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#define llong long long

using namespace std;

int x[16];

llong res = 0, sum[3];
int _best, num = 0, n, a[16], t[16];
set<int> S;
vector<int> V;

int upbit(int u, int pos) {
    return u | (1 << (pos - 1));
}

int downbit(int u, int pos) {
    return u ^ (1 << (pos - 1));
}

int getbit(int u, int pos) {
    return (u >> (pos - 1)) & 1;
}

void back_track1(int cnt) {
    for(int i=0; i<3; ++i) {
        if (i == 0) num = upbit(num, t[cnt]);
        else sum[i] += a[t[cnt]];
        if (cnt == n) {
            if (sum[1] == sum[2]) {
                if (sum[1] + sum[2] > res) {
                    res = sum[1] + sum[2];
                    _best = num;
                    S.clear(); S.insert(num);
                    V.clear(); V.push_back(num);
                } else if (sum[1] + sum[2] == res && !S.count(num)) {
                    S.insert(num);
                    V.push_back(num);
                }
            }
        } else back_track1(cnt+1);
        if (i == 0) num = downbit(num, t[cnt]);
        else sum[i] -= a[t[cnt]];
    }
}

bool cmp (const int &A, const int &B) {
    string A1 = to_string(A);
    string B1 = to_string(B);
    return A1 < B1;
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]), t[i] = i;
    sort(t+1, t+n+1, cmp);
    back_track1(1);
    cout << res << "\n";
    if (*(S.begin()) == 0) cout << "OK";
    else {
        for(int e: V) {
            for (int i=1; i<=n; ++i)
                if (getbit(e, i)) cout << i << " ";
            putchar('\n');
        }
    }
    return 0;
}
    
