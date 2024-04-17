#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong a[10];
int k, n, x[10];
int sum = 0;

void print() {
    for(int i=1; i<k; ++i) cout << a[x[i]] << " ";
    cout << a[x[k]] << "\n";
}

void back_track(int cnt) {
    for(int i=1; i<=n; ++i) {
        x[cnt] = i;
        if (cnt == k) print(); else back_track(cnt+1);
    }
}

int main() {
    cin >> k >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    sum = pow(n, k);
    cout << sum << "\n";
    back_track(1);
    return 0;
}
    
