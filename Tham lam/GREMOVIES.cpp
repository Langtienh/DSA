#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[100006], num[100006], S, n, k;
vector<pair<int, int> > K[100001];

int main() {
    int j = 0;
    scanf("%d%d", &n, &k);
    int res = 1e9, pos = 0;
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        if (i > 1) res += (a[i] != a[i-1]);
    }
    for(int i=1; i<=n; ++i)
        if (i == n || a[i] != a[i+1]) {
            K[a[i]].push_back(make_pair(j+1, i));
            j = i;
        }
    for(int i=1; i<=k; ++i) {
        int S1 = S;
        for(pair<int, int> e : K[i]) {
            if (e.first == 1 && e.second == n) {
                cout << -1;
                return 0;
            }
            if (e.first == 1) --S1;
            else if (e.second == n) --S1;
            else {
                if (a[e.first-1] == a[e.second+1]) S1 -= 2;
                else --S1;
            }
        }
        if (res > S1) {
            res = S1;
            pos = i;
        }
    }
    cout << pos;
    return 0;
}
    
