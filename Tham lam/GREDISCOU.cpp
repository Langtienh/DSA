#include <iostream>
#include <algorithm>

using namespace std;

int a[200006], n, k;
long long S = 0;

int main() {
     scanf("%d%d", &n, &k);
     for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
     for(int i=1, b; i<=n; ++i) scanf("%d", &b), S += b, a[i] -= b;
     sort(a+1, a+n+1);
     for(int i=1; i<=k; ++i) S+= a[i];
     for(int i=k+1; i<=n; ++i)
        if (a[i] < 0) S += a[i];
     cout << S;
     return 0;
}
    
