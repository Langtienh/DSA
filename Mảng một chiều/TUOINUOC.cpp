#include <iostream>

using namespace std;

int k, n;
int mmax = 0;

int main() {
    scanf("%d%d", &n, &k);
    int pre = 0;
    for(int i=1, a; i <= k; ++i) {
        scanf("%d", &a);
        if(i==1) mmax = max(mmax, a);
        else mmax = max(mmax, (a - pre + 2) >> 1);
        pre = a;
    }
    mmax = max(mmax, n - pre + 1);
    cout << mmax;

    return 0;
}
    
