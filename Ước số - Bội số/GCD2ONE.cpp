#include <iostream>
#include <algorithm>

using namespace std;

int main() {
   int n; scanf("%d", &n);
   int G; scanf("%d", &G);
   for (int i=1; i<n; ++i) {
   	int a; scanf("%d", &a);
   	G = __gcd(G, a);
   }
   if (G == 1) cout << 0;
   else cout << -1;
   return 0;
}
    
