#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int f[2006][2006], n, k;
bool avail[2006][2006];
const int base = 1e9+7;
vector<int> G[2006];

void init() {
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=i; ++j)
        if (i % j == 0) G[i].push_back(j);
}

int get_res(int cnt, int num) {
    if (cnt == 1) return 1;
    if (avail[cnt][num]) return f[cnt][num];
    avail[cnt][num] = true;
    for(int i: G[num]) f[cnt][num] = (f[cnt][num] + get_res(cnt-1, i)) % base;
    return f[cnt][num];
}

int main() {
    cin >> n >> k;
    int res = 0; init();
    for(int i=1; i<=n; ++i)
        res = (res + get_res(k, i)) % base;
    cout << res;
    return 0;
}
    
