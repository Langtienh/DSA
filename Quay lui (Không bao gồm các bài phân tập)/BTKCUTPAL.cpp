#include <iostream>
#include <cstring>

using namespace std;

bool a[36][36];
char S[36];
int n, _b[36], _e[36];

void init() {
    for(int i=1; i<=n; ++i) a[i][i] = true;
    for(int i=2; i<=n; ++i) a[i-1][i] = (S[i-1] == S[i]);
    for(int i=3; i<=n; ++i)
        for(int j=1; j<=n-i+1; ++j) 
            a[j][j+i-1] = (S[j] == S[j+i-1] && a[j+1][j+i-2]);
}

void print(int cnt) {
    for(int i=1; i<=cnt; ++i) {
        for(int j=_b[i]; j<=_e[i]; ++j) cout << S[j];
        if (i < cnt) cout << " ";
        else cout << "\n";
    }
}

void back_track(int cnt, int b) {
    if(b == n+1) {
        print(cnt-1);
        return;
    }
    for(int i=b; i<=n; ++i)
        if (a[b][i]) {
            _b[cnt] = b;
            _e[cnt] = i;
            back_track(cnt+1, i+1);
        }
}

int main() {
    scanf("%s", S+1); n = strlen(S+1);
    init();
    back_track(1, 1);
    
    return 0;
}
    
