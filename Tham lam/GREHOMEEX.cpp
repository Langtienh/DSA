#include <iostream>

using namespace std;

int num[10], s = 0, n;

int main() {
    scanf("%d", &n);
    for(int i=1, c; i<=n; ++i) {
        scanf("%d", &c); ++num[c];
        s += c;
    }
    if (!num[0]) cout << -1;
    else {
        bool ok = false;
        s %= 3;
        switch (s) {
            case 1: {
                int cnt = 0;
                for(int i=1; i<=7; i += 3)
                    if (num[i]) {
                        --num[i];
                        ok = true;
                        break;
                    }
                if (!ok) {
                    cnt = 0;
                    for(int i=2; i<=8; i += 3)
                        if (num[i] + cnt >= 2) {
                            num[i] -= 2 - cnt;
                            ok = true;
                            break;
                        } else cnt += num[i], num[i] = 0;
                }
                break;
            }
            case 2: {
                int cnt = 0;
                for(int i=2; i<=8; i += 3)
                    if (num[i]) {
                        --num[i];
                        ok = true;
                        break;
                    }
                if (!ok) {
                    cnt = 0;
                    for(int i=1; i<=7; i += 3)
                        if (num[i] + cnt >= 2) {
                            num[i] -= 2 - cnt;
                            ok = true;
                            break;
                        } else cnt += num[i], num[i] = 0;
                }
                break;
            }
            default: ok = true;
        }
        if (ok) {
            for(int i=9; i>=0; --i)
                while (num[i]--) cout << i;
        } else cout << -1;
    }
    return 0;
}
    
