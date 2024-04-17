#include <iostream>

using namespace std;

bool a[1000006];
int l, k, n;

int main() {
    scanf("%d%d%d", &k, &l, &n);
    a[1] = true; a[0] = false;
    for(int i=2; i<=1000000; ++i) {
        if (i < k) a[i] = !a[i-1];
        else if (i < l) a[i] = !(a[i-1] && a[i-k]);
        else a[i] = !(a[i-1] && a[i-k] && a[i-l]);
    }
    for(int i=1, A; i<=n; ++i) {
         scanf("%d", &A);
         if (a[A]) cout << 'A'; else cout << 'B';
    }

    return 0;
}
    
