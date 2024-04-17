#include <iostream>

using namespace std;

int n, a[100006], b[100006];
int f[100006], trace[100006];
int cnt = 0, V[100006];

int main() {
     scanf("%d", &n);
     for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
     for(int i=2; i<=n; ++i) scanf("%d", &b[i]);
     f[1] = f[0] + a[1]; f[0] = 0;
     for(int i=2; i<=n; ++i)
         if (f[i-1] + a[i] < f[i-2] + b[i]) {
              f[i] = f[i-1] + a[i];
              trace[i] = i-1;
         } else {
              f[i] = f[i-2] + b[i];
              trace[i] = i-2;
         }
     while (n != 0) {
         ++cnt;
         if (n - trace[n] == 1) V[cnt] = n;
         else V[cnt] = n-1;
         n = trace[n];
     }
     cout << cnt << "\n";
     for(int i=cnt; i; --i) cout << V[i] << " ";

     return 0;
}
    
