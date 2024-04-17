#include <iostream>
#define llong long long

using namespace std;

llong f[106], n;

int main() {
    f[0] = 0; cin >> n;
    for(int i=1; i<=100; ++i) {
        f[i] = f[i-1]*2 + i+2;
        if (f[i] >= n) {
            while (true) {
                if (n <= f[i-1] || n > f[i-1] + i + 2) {
                    if (n > f[i-1] + i + 2) n -= (f[i-1] + i + 2);
                    --i;
                    if (n <= 3) {
                        if (n == 1) cout << 'm';
                        else cout << 'o';
                        return 0;
                    }
                }
                else {
                    if (n == f[i-1] + 1) cout << 'm';
                    else cout << 'o';
                    return 0;
                }
            }
            return 0;
        }
    }
    return 0;
}
    
