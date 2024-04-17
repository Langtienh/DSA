#include <iostream>

using namespace std;

int n, P[1003];
bool avail[1003];

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%d", &P[i]);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) avail[j] = false;
        avail[i] = true;
        int tmp = P[i];
        while (!avail[tmp]) {
            avail[tmp] = true;
            tmp = P[tmp];
        }
        cout << tmp << " ";
    }
    
    return 0;
}
    
