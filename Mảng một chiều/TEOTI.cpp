#include <iostream>
#include <algorithm>

using namespace std;

int a[1000006];

int main() {
   int n; scanf("%d", &n);
   for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
   sort(a+1, a+n+1);
   int l = 1, r = n;
   while (l < r) {
       --r;
       if (l == r) break;
       ++l;
   }
   cout << a[l];
   return 0;
}
    
