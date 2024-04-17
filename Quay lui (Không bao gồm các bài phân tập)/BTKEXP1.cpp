#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int n, a[23], x[23];
llong S;

void check() {
    llong S1 = a[1];
    for(int i=2; i<=n; ++i)
        if  (x[i] == 0) S1 += a[i];
        else S1 -= a[i];
    if (S1 == S) {
        cout << a[1];
        for(int i=2; i<=n; ++i) {
            if (x[i] == 1) cout << '-';
            else cout << '+';
            cout << a[i];
        }
        putchar('\n');
    }
}

void back_track(int cnt) {
    if (cnt == n+1){
        check();
        return;
    }
    for(int i=0; i<2; ++i) {
        x[cnt] = i;
        back_track(cnt+1);
    }
}

int main() {
    scanf("%d%I64d", &n, &S);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=2; i<=n; ++i) a[i] = abs(a[i]);
    back_track(2);
    return 0;
}
    
