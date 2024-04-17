#include <iostream>
#include <algorithm>

using namespace std;

long long n, f[3300006];

int main() {
    cin >> n;
    if (n <= 1) {
         cout << -1;
         return 0;
    }
    
    f[0] = 0;
    int l = 1, r = 1;
    
    for(int &i=r; i<=3300000; ++i) {
       f[i] = f[i-1] + i;
       if (f[i] + i + 1 > n) break;
    }
    
    while (l <= r) {
       while (f[r] + f[l] > n) --r;
       if (f[r] + f[l] == n) {
           cout << f[l] << " " << f[r];
           return 0;
       }
       ++l;
    }
    cout << -1;
    return 0;
}
    
