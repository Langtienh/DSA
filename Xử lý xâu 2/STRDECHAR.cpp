#include <iostream>
#include <cstring>

using namespace std;

int n;
char S1[1000001];
char S2[1000001];

int main() {
    scanf("%s", S1+1); n = strlen(S1+1);
    scanf("%s", S2+1);
    int i = 1;
    int diff = 0;
    for(int i=1, j=1; i<=n && j < n; ++i)
        if (S1[i] != S2[j]) ++diff;
        else ++j;
    if (diff > 1) {
        cout << 0;
        return 0;
    }
    while (i <= n) {
        if (i == n || S1[i] != S2[i]) {
            int j = i;
            while (j > 1 && S1[j-1] == S1[i]) --j;
            cout << i - j + 1 << "\n";
            while (j <= i) {
                cout << j << " ";
                ++j;
            }
            return 0;
        }
        ++i;
    }
    return 0;
}
    
