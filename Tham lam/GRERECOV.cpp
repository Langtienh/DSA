#include <iostream>

using namespace std;

int a[200006], n;

int main() {
    scanf("%d", &n);
    for(int i=1, b; i*2<=n; ++i) {
         scanf("%d", &b);
         if(i == 1) {
             a[i] = 0;
             a[n] = b;
             continue;
         }
         if (b - a[i-1] > a[n-i+2]) {
             a[n-i+1] = a[n-i+2];
             a[i] = b - a[n-i+1];
         } else {
             a[i] = a[i-1];
             a[n-i+1] = b - a[i];
         }
    }
    for(int i=1; i<=n; ++i) cout << a[i] << " ";
    return 0;
}
    
