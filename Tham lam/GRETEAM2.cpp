#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
#define pii pair<int, pair<int, int> >
#define mk make_pair

using namespace std;

int L[100006], R[100006], a[100006], n;
char s[100006];
set<pii> Q;
pair<int, int> res[100006];
int num = 0;

void process() {
    pii T;
    int tmp1, tmp2;
    while (!Q.empty()) {
        T = (*Q.begin());
        Q.erase(Q.find(T));
        res[++num] = T.second;
        tmp1 = L[T.second.first], tmp2 = T.second.first;
        if (tmp1 > 0 && s[tmp1] != s[tmp2]) Q.erase(Q.find(mk(abs(a[tmp2] - a[tmp1]), mk(tmp1, tmp2))));
        tmp2 = R[T.second.second], tmp1 = T.second.second;
        if (tmp2 <= n && s[tmp1] != s[tmp2]) Q.erase(Q.find(mk(abs(a[tmp2] - a[tmp1]), mk(tmp1, tmp2))));
        R[L[T.second.first]] = R[T.second.second];
        L[R[T.second.second]] = L[T.second.first];
        tmp1 = L[T.second.first], tmp2 = R[T.second.second];
        if (0 < tmp1 && tmp2 <= n && s[tmp1] != s[tmp2]) Q.insert(mk(abs(a[tmp2] - a[tmp1]), mk(tmp1, tmp2)));
    }
}

int main() {
    scanf("%d", &n);
    scanf("%s", s+1);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        L[i] = i-1, R[i] = i+1;
        if (i > 1 && s[i] != s[i-1]) Q.insert(mk(abs(a[i] - a[i-1]), mk(i-1, i)));
    }
    s[0] = s[1]; s[n+1] = s[n];
    process();
    cout << num << "\n";
    for(int i=1; i<=num; ++i)
        cout << res[i].first << " " << res[i].second << "\n";
    return 0;
}
    
