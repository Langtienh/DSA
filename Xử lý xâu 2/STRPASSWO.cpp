#include <iostream>
#include <cstring>

using namespace std;

int num[4], n;
char S[1000006];

int  kind(int pos) {
    if ('a' <= S[pos] && S[pos] <= 'z') return 1;
    if ('A' <= S[pos] && S[pos] <= 'Z') return 2;
    return 3;
}

int main() {
    scanf("%s", S+1); n = strlen(S+1);
    int l = 1; long long res = 0;
    for(int i=1; i<=n; ++i) {
        ++num[kind(i)];
        while (num[kind(l)] > 1) --num[kind(l++)];
        if (num[1] >= 1 && num[2] >= 1 && num[3] >= 1) res += max(0, min(i-6+1, l));
    }
    cout << res;
    return 0;
}
    
