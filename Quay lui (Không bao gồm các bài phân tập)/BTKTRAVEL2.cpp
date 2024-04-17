#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define pi pair<int, int>
#define mk make_pair
#define fname "BTKTRAVEL"
#define llong long long

using namespace std;

const llong base = 1e16;
int C[17][17], n, m;
llong f[17][150006];

inline void fs_int(int &x) {
    bool neg = false;
    register char c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    x = 0;
    for(; '0' <= c && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c - '0');
    if (neg) x = -x;
}

void enter() {
    fs_int(n);
    for(short int i=1; i<=n; i++)
        for(short int j=1; j<=n; j++) fs_int(C[i][j]);
}

int  pos_end=0;
pi  trace[17][150006];
llong res = 1e16;

void minimize(int &A, int B) {
    if (B < A) A = B;
}

int  or_bit(int u, int pos) {
    return u | (1 << (pos-1));
}

bool get_bit(int u, int pos) {
    return ((u >> (pos-1)) & 1) == 1;
}

void BFS() {
    m = (1<<n) - 1;
    for(int i=1; i<=n; ++i)
        for(int j=0; j<=m; ++j) trace[i][j].first = trace[i][j].second = 0, f[i][j] = base;
    queue<pi> Q;
    for(int i=1; i<=n; ++i) {
        Q.push(mk(i, or_bit(0, i)));
        trace[i][or_bit(0, i)].first = -1;
        f[i][or_bit(0, i)] = 0;
    }
    do {
        pi u = Q.front(); Q.pop();
        for(int i=1; i<=n; ++i)
            if (!get_bit(u.second, i)) {
                int v = or_bit(u.second, i);
                if (!trace[i][v].first) Q.push(mk(i, v));
                if (f[i][v] > f[u.first][u.second] + C[u.first][i]) {
                    f[i][v] = f[u.first][u.second] + C[u.first][i];
                    trace[i][v].first = u.first;
                    trace[i][v].second = u.second;
                }
            }
    } while (!Q.empty());
    for(int i=1; i<=n; ++i)
        if (res > f[i][m]) {
            res = f[i][m];
            pos_end = i;
        }
}

void print_trace() {
    vector<int> V;
    while (pos_end != -1) {
        V.push_back(pos_end);
        pi pre = trace[pos_end][m];
        m = pre.second;
        pos_end = pre.first;
    }
    for(vector<int>::reverse_iterator i = V.rbegin(); i != V.rend(); ++i) cout << (*i) << " ";
}

void process() {
    BFS();
    ///cout << res;
    ///putchar('\n');
    print_trace();
}

int main() {

    enter();
    process();

    return 0;
}
    
