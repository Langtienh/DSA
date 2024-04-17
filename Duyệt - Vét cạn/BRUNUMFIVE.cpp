#include <iostream>
#include <algorithm>

using namespace std;

int num[10], n;

int main() {
    scanf("%d", &n);
    for(int i = 1, a; i<=n; ++i) {
        scanf("%d", &a);
        num[a]++;
    }
    if (!num[0]) cout << -1;
    else {
        for(int i=1; i<=num[5]/9*9; ++i) cout << 5;
        if(num[5]/9 == 0) {
            cout << 0;
            return 0;
        }
        for(int i=1; i<=num[0]; ++i) cout << 0;
    }
    return 0;
}
    
