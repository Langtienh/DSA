#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string bit(int p) {
    string ans = "";
    if (p == 0) return "0";
    while (p > 0) {
        ans = char((p & 1) + 48) + ans;
        p >>= 1;
    }
    return ans;
}

string S;
int n, k;
int V[1000006], cnt = 0;
int avail[1000006];

int main() {
    scanf("%d%d", &n, &k);
    for(int i=1, a; i<=n; ++i) {
        scanf("%d", &a);
        S = S + bit(a);
    }
    int l = -1, res = 0; n = S.length();
    for(int i=0; i<n; ++i)  {
        if(i == n-1 || S[i] != S[i+1]) {
            V[++cnt] = i-l;
            l = i;
            if (S[i] == '0') avail[cnt] = 1;
            else avail[cnt] = 0;
        }
    }
    l = 0; V[0] = 0; avail[0] = 0;
    for (int i=1; i<=cnt; ++i) {
         V[i]+=V[i-1];
         avail[i] += avail[i-1];
         while (l < i && avail[i]>avail[l]+k) ++l;
         res = max(res, V[i] - V[l]);    
    }
    cout << res;
    
    return 0;
}
    
