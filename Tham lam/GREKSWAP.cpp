#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char a[20];
int n, k;

int main() {
    while (scanf("%s", a+1) != -1) {
        scanf("%d", &k);
        n = strlen(a+1);
        for(int i=1; i<=n; ++i) {
            int mmax = a[i]-'0', pos = i;
            for(int j=i+1; j<=n && j - i <= k; ++j)
                if (mmax < a[j]-'0') {
                    mmax = a[j]-'0';
                    pos = j;
                }
            k -= pos - i;
            for (int j=pos; j>i; --j) a[j] = a[j-1];
            a[i] = char(mmax + '0');
        }
        cout << a+1 << "\n";
    }
}
    
