#include <iostream>
#include <algorithm>
#include <cstring>
#define fname "BTKABC"

using namespace std;

int n, minC;
char x[106], best[106];
int t[106];

bool same(int i, int l) {
    int j = i - l;
    for(int k=0; k<=l-1; ++k)
        if (x[i-k] != x[j-k]) return false;
    return true;
}

bool check(int i) {
    for (int l = 1; l * 2 <= i; ++l)
        if (same(i, l)) return false;
    return true;
}

void update() {
    minC = t[n];
    for(int i=1; i<=n; ++i) best[i] = x[i];
}

void back_track(int i) {
    for(int j = 65; j <= 67; ++j) {
        x[i] = char(j);
        if (check(i)) {
            if (j == 67) t[i] = t[i-1] + 1;
            else t[i] = t[i-1];
            if (t[i] + (n - i) / 4 < minC) {
                if (i == n) update();
                else back_track(i+1);
            }
        }
    }
}

int main() {

    scanf("%d", &n);
    t[0] = 0;
    minC = n+1;
    back_track(1);
    for(int i=1; i<=n; ++i) cout << best[i];
    return 0;
}
    
