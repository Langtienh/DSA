#include <iostream>
#include <cstring>

using namespace std;

char S[1000006];

int main() {
    int n, k; scanf("%d%d", &n, &k);
    scanf("%s", S+1);
    int diff = 0;
    for(int i=1; i*2 <= n; ++i)
        if (S[i] != S[n-i+1]) ++diff;
    if (diff > k) {
        cout << "No";
        return 0;
    }
    k -= diff;
    if (k > (n/2 - diff)*2) {
        k -= (n/2 - diff)*2;
        if (k > diff) {
            k -= diff;
            if (n & 1) {
                if (k <= 1) cout << "Yes";
                else cout << "No";
            } else {
                if (k == 0) cout << "Yes";
                else cout << "No";
            }
        } else cout << "Yes";
    } else {
        if ((n & 1) == 0) {
            if (!diff && (k & 1)) cout << "No";
            else cout << "Yes";
        } else cout << "Yes";
    }
    return 0;
}
    
