#include <iostream>
#include <cstring>

using namespace std;

bool avail[256];
char S[106];

int main() {
    int t; cin >> t;
    while (t--) {
        for(int i=0; i<256; ++i) avail[i] = false;
        scanf("%s", S+1); int n = strlen(S+1);
        for(int i=1; i<=n; ++i) avail[(int) S[i]] = true;
        scanf("%s", S+1); bool ok = false;
        for(int i=1; i<=n; ++i)
            if (avail[(int) S[i]]) {
                ok = true;
                break;
            }
        if (ok) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}
    
