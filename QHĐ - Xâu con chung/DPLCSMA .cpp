#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string A, B;
int f[1006][1006], n, m;
bool avail[10];

char process1(int u, int v, char c, int res) {
    char block = '#';
    while (c <= '9') {
        avail[c-'0'] = true;
        ++c;
    }
    for(int i=u; i<=n; ++i)
        if (avail[A[i-1]-'0']) {
            avail[A[i-1]-'0'] = false;
            for(int j=v; j<=m; ++j)
                if (A[i-1] == B[j-1] && f[i][j] == res) {
                    block = max(block, A[i-1]);
                    break;
                }
        }
    return block;
}

void update(int &u, int &v, char &c, string &ans, int &res) {
    if (c == '#') {
        u = n+1;
        v = m+1;
        return;
    }
    --res;
    for(int i=u; i <= n && u<=n; ++i)
        if (A[i-1] == c) {
            u = i+1;
            break;
        }
    for(int i=v; i <= m && v<=m; ++i)
        if (B[i-1] == c) {
            v = i+1;
            break;
        }
    ans.push_back(c);
}

void process() {
    int res = 0; n = A.length(), m = B.length();
    for(int i=n; i>0; --i)
    for(int j=m; j>0; --j)
    if (A[i-1] == B[j-1]) {
        f[i][j] = f[i+1][j+1] + 1;
        if (A[i-1] != '0') res = max(res, f[i][j]);
    } else f[i][j] = max(f[i+1][j], f[i][j+1]);
    int u=1, v = 1;
    string ans = "";
    char x = process1(u, v, '1', res);
    if (x != '#') update(u, v, x, ans, res); else res = 1;
    while (u <= n && v <= m) {
        x = process1(u, v, '0', res);
        update(u, v, x, ans, res);
    }
    cout << ans.length() << "\n";
    cout << "LCS MAX NUMBER is ";
    if ((int) ans.length() == 0) cout << "NULL"; else cout << ans;
}

int main() {
    cin >> A >> B;
    process();
}
    
