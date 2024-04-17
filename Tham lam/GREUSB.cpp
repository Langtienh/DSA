#include <iostream>
#include <algorithm>

using namespace std;

int a[100006], n, m;

int main() {
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1, greater<int>());
    for(int i=1; i<=n; ++i)
       if (m > a[i]) m -= a[i];
       else {
           cout << i;
           break;
       }
    return 0; 
}
    
