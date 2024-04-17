#include <iostream>
#include <string>

using namespace std;

int Z[4000006], n, m;
string S;

void Z_function() {
    S = S  + '#' + S; n = S.length();
    int l = 0, r = 0;
    for(int i=1; i<n; ++i) {
        if (i <= r) Z[i] = min(r-i+1, Z[i-l]);
        while (i + Z[i] < n && S[Z[i]] == S[Z[i]+i]) ++Z[i];
        if (i + Z[i] - 1 > r) l = i, r = i + Z[i] - 1;
    }
}

int main() {
    cin >> m;
    cin >> S;
    Z_function();
    int r = m;
    for(int i=n-1; i > m; --i, --r)
        if (Z[i] >= r - 1 && r > 1) {
            cout << r  + (m - 2*(r-1));
            return 0;
        }
    cout << m;
    return 0;
}
    
