#include <iostream>
#include <algorithm>

using namespace std;

int n, k, a[100006];

int main() {
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1, greater<int>());
    int j = 0, num = 0;
    for(int i=1; i<=n; ++i) 
       if (i == n || a[i] != a[i+1]) {
          num += i - j;
          j = i;
          if (num > k) {
              cout << -1;
              return 0;
          } else if (num == k) {
              cout << a[i] << " " << a[i];
              return 0;
          }
       }
    cout << -1;
    return 0;
}
    
