#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int n, k;
map<int, int> M;
map<int, bool> avail;
vector<int> A;
vector<int> S;

int main() {
    scanf("%d%d", &n, &k);
    int ans = 0;
    for(int i=1, a; i<=n; ++i) {
        scanf("%d", &a);
        ++M[a];
        A.push_back(a);
    }
    sort(A.begin(), A.end());
    A.resize(unique(A.begin(), A.end()) - A.begin());
    if (k == 1) {
        cout << A.size();
        return 0;
    }
    for(int i=0; i<(int) A.size(); ++i)
        if (!avail[A[i]]) {
            S.clear();
            int num = 0;
            int tmp = A[i];
            while (A[i] <= 1e9) {
                avail[A[i]] = true;
                if (!S.empty()) M[A[i]] += M[S[0]];
                num = max(num, M[A[i]]);
                if (A[i] >= 1LL*k*tmp) {
                    while (!S.empty() && M[A[i]/k] >= M[S.back()]) S.pop_back();
                    S.push_back(A[i]/k);
                }
                if (1LL*A[i]*k > (int) 1e9) break;
                A[i] *= k;
            }
            ans += num;
        }
    cout << ans;
    return 0;
}
    
