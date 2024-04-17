#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char S[12];
int n;

int main() {
    scanf("%s", S+1); n = strlen(S+1);
    int num = 0, res = n;
    for(int i=1; i<=n; ++i) num *= 10, num += S[i] - '0';
    for(int i=1; i*i <= num; ++i) {
        int tmp = i*i, tmp1 = 0, l = 0;
        if (tmp == 0) l = 1;
        while (tmp > 0) tmp /= 10, ++l;
        tmp = i*i;
        for(int j=n; j>0; --j) {
            if (tmp > 0 && S[j] - '0' == tmp%10) tmp /= 10;
            else tmp1++;
        }
        if (n - tmp1 == l) res = min(res, tmp1);
    }
    if (res == n) cout << -1;
    else cout << res;
    return 0;
}
    
