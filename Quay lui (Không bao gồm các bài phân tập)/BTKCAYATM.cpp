#include <iostream>
#define llong long long

using namespace std;

int a[26], n, x[26];
llong m, s = 0, num = 0;

void back_track(int cnt) {
    for(int i=0; i<=1; ++i) {
        x[cnt] = i; num += i;
        s += a[cnt] * i;
        if (s == m) {
            cout << num << "\n";
            for(int j=1; j<=cnt; ++j)
                if (x[j] == 1) cout << j << " ";
            exit(0);
        }
        if (n > cnt && s < m) back_track(cnt+1);
        s -= a[cnt] * i; num -= i;
    }
}

int main() {
    scanf("%d%I64d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    back_track(1);

    cout << "khongtherut";
    return 0;
}
    
