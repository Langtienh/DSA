#include <iostream>
#include <algorithm>

using namespace std;

int n, h[100006], k;
long long m;

void enter() {
    scanf("%d%I64d%d", &n, &m, &k);
    for(int i=1; i<=n; ++i) scanf("%d", &h[i]);
}

void process() {
    if (n == 1) {
        cout << "YES\n";
        return;
    }
    for(int i=1; i<n; ++i) {
        if (h[i] + m + k >= h[i+1]) {
            if (h[i] + k > h[i+1]) m += min(h[i], h[i] + k - h[i+1]); else m -= h[i+1] - h[i] - k;
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

int main(){
    int t; scanf("%d", &t);
    while (t--) {
        enter();
        process();
    }
    return 0;
}
    
