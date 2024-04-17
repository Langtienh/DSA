#include <iostream>
#include <string>

using namespace std;

int n, m;
string S1, S2;
int Z[200006];

void Z_function() {
    m = S2.length();
    S1 = S2 + '#' + S1; n = S1.length();
    int l = 0, r = 0;
    for(int i=1; i < n; ++i) {
        if (i <= r) Z[i] = min(r-i+1, Z[i-l]);
        while (i + Z[i] < n && S1[Z[i]] == S1[i + Z[i]]) ++ Z[i];
        if (i + Z[i]-1 > r) l = i, r = i + Z[i] - 1;
    }
}

int main() {
    cin >> S1 >> S2;
    Z_function();
    int res = 0;
    for(int i=m-1; i < n; ++i)
        if (Z[i] == m) ++res, i += m-1;
    cout << res;
    return 0;
}
    
