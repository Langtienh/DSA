#include <iostream>
#include <algorithm>

using namespace std;

int a[100006], n;
long long sum = 0;

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    for(int i=2; i<=n; i+=2) sum += a[i] - a[i-1];
    cout << sum;
    return 0;
}
    
