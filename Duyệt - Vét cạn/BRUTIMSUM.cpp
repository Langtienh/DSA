#include <iostream>
#define llong long long

using namespace std;

llong S[100006];
int n, q;

int main() {
    scanf("%d%d", &n, &q); S[0] = 0;
    for(int i=1, a; i<=n; ++i) {
        scanf("%d", &a);
        S[i] = S[i-1] + a;
    }
    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        cout << S[y] - S[x-1] << "\n";
    }
    return 0;
}
    
