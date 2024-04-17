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
    ++sum;
}

bool d[10];

void back_track(int cnt) {
    for(int i=1; i<=n; ++i) 
        if (!d[i]) {
             d[i] = true;
             x[cnt] = i;
             if (cnt == k) print(); else back_track(cnt+1);
             d[i] = false;
         }
}

int main() {
    cin >> k >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    back_track(1);
    cout << sum << "\n";
    return 0;
}
    
