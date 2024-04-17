#include <iostream>
#include <algorithm>

using namespace std;

bool row[100006], colunm[100006];

int main() {
    int n, m, x, y, num_row = 0, num_colunm = 0;
    scanf("%d%d", &n, &m);
    long long res = 1LL*n*n;
    while (m--) {
        scanf("%d%d", &x, &y);
        if (row[x] && colunm[y]);
        else if (row[x]) {
            colunm[y] = true;
            res -= (n - num_row);
            ++num_colunm;
        } else if (colunm[y]) {
            row[x] = true;
            res -= (n - num_colunm);
            ++num_row;
        } else {
            row[x] = colunm[y] = true;
            res -= (2*n - num_row - num_colunm - 1);
            ++num_row; ++num_colunm;
        }
        cout << res << " ";
    }
    return 0;
}
    
