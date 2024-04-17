#pragma GCC optimize("O2")
#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
#define mk make_pair

using namespace std;

vector<pii> P[100006], res;
vector<int> A;
int n, a[100006];

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        A.push_back(a[i]);
    }
    sort(A.begin(), A.end());
    A.resize(unique(A.begin(), A.end()) - A.begin());
    for(int i=1, j = 1; i<=n; ++i)
        if (i == n || a[i] != a[i+1]) {
            P[a[i]].push_back(mk(j, i));
            j = i+1;
        }
    vector<pii> tmp;
    for(int i = A.size()-1; i>=0; --i)
        if (i == 0) {
            for(pii e : P[A[i]])
            for(int j=A[i]; j>0; --j) res.push_back(e);
        } else {
            tmp.clear();
            for(pii e : P[A[i]])
            for(int j=A[i]; j>A[i-1]; --j) res.push_back(e);
            int l = 0, r = 0;
            while (l < (int) P[A[i]].size() && r < (int) P[A[i-1]].size()) {
                if (P[A[i]][l].second < P[A[i-1]][r].first) tmp.push_back(P[A[i]][l++]);
                else tmp.push_back(P[A[i-1]][r++]);
            }
            while (l < (int) P[A[i]].size()) tmp.push_back(P[A[i]][l++]);
            while (r < (int) P[A[i-1]].size()) tmp.push_back(P[A[i-1]][r++]);
            P[A[i]].clear(); P[A[i-1]].clear(); P[A[i-1]].push_back(tmp[0]);
            r = 0;
            for(int j = 1; j < (int) tmp.size(); ++j)
                if (tmp[j].first == P[A[i-1]][r].second + 1) P[A[i-1]][r].second = tmp[j].second;
                else P[A[i-1]].push_back(tmp[j]), ++r;
        }
    cout << res.size() << "\n";
    for(pii e : res) cout << e.first << " " << e.second << "\n";
    return 0;
}
    
