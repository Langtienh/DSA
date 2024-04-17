#include <iostream>
#include <algorithm>

using namespace std;

int main() {
   int n; scanf("%d", &n);
   long long G; scanf("%I64d", &G);
   for (int i=1; i<n; ++i) {
   	int a; scanf("%d", &a);
   	G = __gcd(G, 1LL*a);
   }
   cout << G * n;
   return 0;
}
    
