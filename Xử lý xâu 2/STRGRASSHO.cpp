#include <iostream>

using namespace std;

char S[100006];
int n, k;

int main() {
    int f = -1;
    scanf("%d%d", &n, &k);
    scanf("%s", S+1);
    for(int i=1; i<=n; ++i)
        if (S[i] == 'G' || S[i] == 'T') {
            f = i+k;
            while (f <= n) {
                if (S[f] == '#') break;
                if (S[f] == 'G' || S[f] == 'T') {
                    cout << "YES";
                    return 0;
                }
                f += k;
            }
            break;
        }
    cout << "NO";
    return 0;
}
    
