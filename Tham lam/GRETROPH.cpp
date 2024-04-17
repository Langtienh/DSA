#include <iostream>
#include <vector>
#define pii pair<int, int>

using namespace std;

vector<pii> G;
char S[100006];

int main() {
    int n; scanf("%d", &n);
    scanf("%s", S+1);
    int j = 0;
    for(int i=1; i<=n; ++i)
        if (i == n || S[i] != S[i+1]) {
            if (S[i] == 'G') G.push_back(make_pair(j+1, i));
            j = i;
        }
    if ((int) G.size() == 0) cout << 0;
    else if ((int) G.size() == 1) cout << G[0].second - G[0].first + 1;
    else if ((int) G.size() == 2) {
        if (G[1].first - G[0].second == 2) cout << G[1].second - G[0].first;
        else cout << max(G[1].second - G[1].first + 1, G[0].second - G[0].first + 1) + 1;
    } else {
        int mmax = 0;
        for(int i=0; i<(int) G.size(); ++i) {
            mmax = max(G[i].second - G[i].first + 2, mmax);
            if (i > 0 && G[i].first - G[i-1].second == 2)
                mmax = max(mmax, G[i].second - G[i-1].first + 1);
        }
        cout << mmax;
    }
    return 0;
}
    
