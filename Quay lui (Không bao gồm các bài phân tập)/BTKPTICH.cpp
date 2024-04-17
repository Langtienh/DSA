#include <iostream>

using namespace std;

int x[36], m = 0, n;

void print(int cnt) {
    cout << n << " = ";
    for(int i=1; i<cnt; ++i) cout << x[i] << "+";
    cout << x[cnt] << "\n";
}

void back_track(int cnt) {
    for(int i=x[cnt-1]; i*2<=n-m; ++i) {
        x[cnt] = i;
        m += i;
        back_track(cnt+1);
        m -= i;
        x[cnt] = 0;
    }
    x[cnt] = n - m;
    print(cnt);
}

int main() {
    cin >> n;
    x[0] = 1;
    back_track(1);
}
    
