#include <iostream>

using namespace std;

int n, a[100006], k;

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    scanf("%d", &k);
    for(int i=1; i<=n; ++i)
        if (a[i] == k) {
            cout << i;
            return 0;
        }
    return 0;
}
    
