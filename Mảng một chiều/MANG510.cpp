#include <iostream>
#include <algorithm>

using namespace std;

int n;
int f[10000006], p[700006], cnt=0;

void enter() {
    scanf("%d", &n);
}

void prime() {
    f[0] = -1;
    for(int i=2; i<=10000000; ++i) {
        if (f[i] == 0) p[++cnt] = f[i] = i;
        int j = 1;
        while (j <= cnt && p[j] <= f[i] && p[j] * i <= 10000000) {
            f[p[j]*i] = p[j];
            ++j;
        }
    }
}

int main() {
    prime();
    scanf("%d", &n); bool ok = false;
    for (int i=1; i<=n; ++i) {
       int a; scanf("%d", &a);
       if (f[a] == a) {cout << i << " " << a << "\n"; ok = true;}
    }
    
    if (!ok) cout << "KHONG CO SO NGUYEN TO";
    
    return 0;
}
    
