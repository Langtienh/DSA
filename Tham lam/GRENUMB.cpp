#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char A[21], B[21];
int n, m;

void check(int i) {
    if (A[i] < B[i] || i == n) {
        sort(A+i+1, A+n+1, greater<char>());
        cout << A+1;
        exit(0);
    }
    sort(A+i+1, A+n+1);
    for(int j=i+1; j<=n; ++j)
        if (A[j] > B[j]) {
            for (int k = i+1; k<=n; ++k)
                if (k == n || A[k+1] >= B[i]) {
                    swap(A[k], A[i]);
                    sort(A+i+1, A+n+1, greater<char>());
                    if (A[i] == '0' && i == 1) cout << -1;
                    else cout << A+1;
                    exit(0);
                }
        } else if (A[j] < B[j]) break;
}

int main() {
    scanf("%s", A+1); n = strlen(A+1);
    scanf("%s", B+1); m = strlen(B+1);
    sort(A+1, A+n+1);
    if (m > n) {
        sort(A+1, A+n+1, greater<char>());
        cout << A+1;
    } else if (m < n) cout << -1;
    else {
        for(int i=1; i<=n; ++i)
            if (A[i] > B[i]) {
                cout << -1;
                return 0;
            } else if (A[i] < B[i]) break;
        for(int i=1; i<=m; ++i) {
            int j = upper_bound(A+i, A+n+1, B[i]) - A;
            --j;
            swap(A[i], A[j]);
            check(i);
        }
    }
}
    
