#include <iostream>

using namespace std;

int a[150006], n;
bool avail[150006];

int main() {
    scanf("%d", &n);  avail[0] = true; int num = 0;
    for(int i=1, b; i<=n; ++i) scanf("%d", &b), ++a[b];
    for(int i=1; i<=150000; ++i) {
        bool ok = false;
        while (true) {
            if (avail[i] && avail[i-1] && ok) break;
            ok = true;
            if (a[i] == 0) break;
            if (!avail[i-1]) avail[i-1] = true, --a[i], ++num;
            if (a[i] == 0) break;
            if (!avail[i]) avail[i] = true, --a[i], ++num;
            if (a[i] == 0) break;
            if (!avail[i+1] && (a[i+2] < 3 && a[i+1] < 2)) avail[i+1] = true, --a[i], ++num;
        }
    }
    cout << num;
    return 0;
}
    
