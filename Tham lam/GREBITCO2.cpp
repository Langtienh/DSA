#include <iostream>
#include <deque>

using namespace std;

int n, k, a[2000006];

int main() {
    int res = 0;
    deque<int> Q;
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        while (!Q.empty() && a[Q.front()] - (i - Q.front()) * k < a[i]) Q.pop_front();
        if (!Q.empty()) res = max(res, a[Q.front()] - (i - Q.front())*k - a[i]);
        while (!Q.empty() && a[Q.back()] - (i - Q.back()) * k < a[i]) Q.pop_back();
        Q.push_back(i);
    }
    cout << res;
    return 0;
}
    
