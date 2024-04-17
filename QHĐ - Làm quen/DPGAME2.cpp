#include <iostream>
#include <deque>
#define llong long long

using namespace std;

deque<int> Q;
llong f[100006];

int main() {
    int n, k; scanf("%d%d", &n, &k);
    llong res = 0; Q.push_back(0); f[0] = 0LL;
    for(int i=1, a; i<=n; ++i) {
        scanf("%d", &a);
        while (!Q.empty() && Q.front() < i-k) Q.pop_front();
        f[i] = f[Q.front()] + a; res = max(res,f[i]);
        while (!Q.empty() && f[Q.back()] <= f[i]) Q.pop_back();
        Q.push_back(i);
    }
    cout << res;
    
    return 0;
}
    
