#include <iostream>

using namespace std;

int n, x[26];
long long num = 0;
bool a[41];

void init() {
    a[2] = a[3] = a[5] = a[7] = a[11] = a[13] = true;
    a[17] = a[19] = a[23] = a[29] = a[31] = a[37] = true;
}

bool d[21];

void back_track(int cnt) {
    for(int i=2; i<=n; ++i)
        if (!d[i]) {
            d[i] = true;
            x[cnt] = i;
            if (cnt == n) {
                if (a[x[cnt] + x[cnt-1]] && a[x[cnt] + x[1]]) {
                    for(int i=1; i<n; ++i) cout << x[i] << " ";
                    cout << x[n] << "\n";
                }
            } else if(cnt == 1 || a[x[cnt] + x[cnt-1]]) back_track(cnt+1);
            d[i] = false;
        }
}

int main() {
    cin >> n; n *= 2;
    init();
    x[1] = 1;
    back_track(2);
    return 0;
}
    
