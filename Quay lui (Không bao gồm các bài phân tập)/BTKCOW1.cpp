#include <iostream>

using namespace std;

int x[21], sum = 0, a[21], S, _best = 21, num = 0, p = 0, n;

void back_track(int cnt) {
    for(int i=0; i<2; ++i) {
        x[cnt] = i; p += i;
        sum += a[cnt] * i;
        if (n == cnt) {
            if (sum == S) ++num, _best = min(_best, p);
        } else if (sum <= S) back_track(cnt+1);
        sum -= a[cnt] * i;
        p -= i;
    }
}

int main() {
    scanf("%d%d", &n, &S);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    back_track(1);
    cout << num << " " << _best;
}
    
