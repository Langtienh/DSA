#include <iostream>

using namespace std;

int x[21], sum[2], a[21], n;
bool ok = false;

void back_track(int cnt) {
    for(int i=1; i<=2; ++i) {
        x[cnt] = i; 
        sum[i] += a[cnt];
        if (n == cnt) {
            if (sum[1] == sum[2]) {
                ok = true;
                for(int j=1; j<=n; ++j) cout << x[j];
                putchar('\n'); 
            }
        } else back_track(cnt+1);
        sum[i] -= a[cnt];
    }
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    back_track(1);
    if(!ok) cout << -1;
    
    return 0;
}
    
