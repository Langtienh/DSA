/// Code by Ha Van Hoang T6 THPT Chuyen Binh Long
#include <iostream>
#include <algorithm>
#define pii pair<int, int>
#define mk make_pair

using namespace std;

struct Data {
    int l, d;

    bool operator < (const Data &other) const {
        return l < other.l;
    }
} a[100006];

int S[100006], n;
pii bit[20006];

void operator += (pii &A, const pii B) {
    A.first += B.first;
    A.second += B.second;
}

void update(int p, int val) {
    for(; p <= 20000; p += (p & (-p))) bit[p] += mk(val, 1);
}

pii query(int p) {
    pii ans = {0, 0};
    for(; p>0; p -= (p & (-p))) ans += bit[p];
    return ans;
}

int b_search(int num) {
    int l = 0, r = 20000, ans = 20001;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (query(mid).second >= num) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i].l);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i].d);
    sort(a+1, a+n+1); S[n+1] = 0;
    for(int i=n; i>0; --i) S[i] = S[i+1] + a[i].d;
    int j = 0, res = 2e9;
    for(int i=1; i<=n; ++i)
        if (i == n || a[i].l < a[i+1].l) {
            int p = b_search(j - (i - j - 1));
            pii cost = query(p);
            if (p < 20001) cost.first -= p * (cost.second - (j - (i - j - 1)));
            res = min(res, cost.first + S[i+1]);
            while (j < i) {
                update(a[j+1].d, a[j+1].d);
                ++j;
            }
        }
    cout << res;
    return 0;
}
    
