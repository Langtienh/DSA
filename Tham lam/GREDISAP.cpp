#include <iostream>
#include <algorithm>

using namespace std;

int a[100006], n;

int main() {
    scanf("%d", &n);
    int S = 0;
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+n+1);
    int num = 0;
    for(int i=1; i<=n; ++i)
        if (S <= a[i]) S += a[i], ++num;
    cout << num;
    return 0;
}
    
