#include <iostream>
#include <algorithm>

using namespace std;

int a[100006], n;

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    int i = 1, res = 1;
    while (i <= n) {
        while (i <= n && a[i] < res) ++i;
        if (i >= n+1) break;
        ++i;
        ++res;
    }
    cout << --res;
}
    
