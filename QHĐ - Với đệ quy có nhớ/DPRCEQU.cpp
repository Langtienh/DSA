#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string S;
int dp[5006][5006], n = 0;
bool avail[5006][5006];

int get_res(int cnt, int sum) {
    if (cnt == (int) S.size()) {
        if (sum) return 1e9;
        else return 0;
    }
    if (avail[cnt][sum]) return dp[cnt][sum];
    avail[cnt][sum] =true; dp[cnt][sum] = 1e9;
    int num = 0;
    for(int i=cnt; i<(int) S.size(); ++i) {
        num = num * 10 + (S[i] - '0');
        if (num > sum) break;
        dp[cnt][sum] = min(dp[cnt][sum], get_res(i+1, sum - num) + 1);
    }
    return dp[cnt][sum];
}

int main() {
    string S1; cin >> S1; int num = 0; bool a = true;
    for(int i=0; i<(int) S1.size(); ++i) {
        if (S1[i] == '=') {
            a = false;
            continue;
        }
        if (!a) n = n * 10 + (S1[i] - '0');
        else {
            if (S1[i] != '0') num = 0, S.push_back(S1[i]);
            else if (num <= 3) S.push_back(S1[i]), ++num;
        }
    }
    cout << get_res(0, n) - 1;
    return 0;
}
    
