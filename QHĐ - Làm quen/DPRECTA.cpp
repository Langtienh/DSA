#include <iostream>
#define llong long long

using namespace std;

llong f[100006][2];
int n;
int pre_a, pre_b;

int main() {
    scanf("%d", &n);
    scanf("%d%d", &pre_a, &pre_b);
    f[1][0] = pre_b; f[1][1] = pre_a;
    for(int i=2, a, b; i<=n; ++i) {
        scanf("%d%d", &a, &b);
        f[i][0] = max(f[i-1][0] + abs(a - pre_a), f[i-1][1] + abs(a - pre_b)) + b;
        f[i][1] = max(f[i-1][0] + abs(b - pre_a), f[i-1][1] + abs(b - pre_b)) + a;
        pre_a = a, pre_b = b;
    }
    cout << max(f[n][0], f[n][1]);
    
    return 0;
}
    
