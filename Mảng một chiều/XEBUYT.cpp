#include <iostream>

using namespace std;

int n, mmax = 0;

int main() {
     scanf("%d", &n); int seat = 0;
     for(int i=1, a, b; i<=n; ++i) {
         scanf("%d%d", &a, &b);
         seat += b-a;
         mmax = max(mmax, seat);
     }
     cout << mmax;
     
     return 0; 
}
    
