#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

string s1, s2, s3;
const int base = 1e9+7;
int dp[66][66][66];
bool avail[66][66][66];

int get_res(int i, int j, int k) {
    if (k == (int) s3.size()) return 1;
    if (avail[i][j][k]) return dp[i][j][k];
    dp[i][j][k] = 0; avail[i][j][k] = true;
    for(int l=i; l<(int) s1.size(); ++l)
        if (s1[l] == s3[k]) dp[i][j][k] = (dp[i][j][k] + get_res(l+1, j, k+1)) % base;
    for(int l=j; l<(int) s2.size(); ++l)
        if (s2[l] == s3[k]) dp[i][j][k] = (dp[i][j][k] + get_res(i, l+1, k+1)) % base;
    return dp[i][j][k];
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        cin >> s1 >> s2 >> s3;
        memset(avail, false, sizeof(avail));
        cout << get_res(0, 0, 0) << "\n";
    }
    return 0;
}
    
