#include <iostream>
#include <algorithm>

using namespace std;

long long A=0, B=0;
int a[200006], b[200006], n;

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=1; i<=n; ++i) scanf("%d", &b[i]);
    sort(a+1, a+n+1, greater<int>()), sort(b+1, b+n+1, greater<int>());
    int r1 = 1, r2=1;
    for(int i=1; i<=n; ++i) {
        if (a[r1] >= b[r2]) A += a[r1++];
        else ++r2;
        if (b[r2] >= a[r1]) B += b[r2++];
        else ++r1;
    }
    cout << A - B;

    return 0;
}
    
