#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

char S[1001][1006];

int main() {
    int n; cin >> n; scanf("\n");
    double mmax = 0;
    int pos = 0;
    for(int i=1; i<=n; ++i) {
        gets(S[i]+1);
        int m = strlen(S[i]+1);
        string S1 = "";
        for(int j=m; j>1; --j) if (S[i][j] == '.' || ('0' <= S[i][j] && S[i][j] <= '9'))
             S1 = S[i][j]+S1; else break;
        double po = (double) atof(S1.c_str());
        if (mmax < po) {
            mmax = po;
            pos = i;
        }
    }
    for(int i=1; i<=(int) strlen(S[pos]+1) && (S[pos][i+1] < '0' || '9' < S[pos][i+1]); ++i)
        cout << S[pos][i];

    return 0;
}
    
