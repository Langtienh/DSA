#include <iostream>
#include <algorithm>

using namespace std;

int bit[1003][1003];
int n;

void update(int x, int y, int val) {
    for(; x<=1000; x += (x & (-x))) {
        int yy = y;
        for(; yy <= 1000; yy += (yy & (-yy))) bit[x][yy] = max(bit[x][yy], val);
    }
}

int query(int x, int y) {
    int ans = 0;
    for(; x > 0; x -= (x & (-x))) {
        int yy = y;
        for(; yy > 0; yy -= (yy & (-yy))) ans = max(bit[x][yy], ans);
    }
    return ans;
}

int main() {
    scanf("%d", &n); int res = 0;
    for (int i=1; i<=n; ++i) {
    	int x, y; scanf("%d%d", &x, &y);
    	int best = query(x-1, y-1) + 1;
    	res = max(res, best);
    	update(x, y, best);
    }
    cout << res;
    return 0;
}
    
