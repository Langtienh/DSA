#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[1000006];
vector<int> res;

int main() {
    int n; scanf("%d", &n);
    for(int i=1, x, y; i<=n; ++i) {
        scanf("%d%d", &x, &y);
        ++a[x], --a[y+1];
    }
    int num = 0;
    for(int i=1; i<=1000000; ++i) {
        a[i] += a[i-1];
        if (a[i] > num) {
            res.clear();
            res.push_back(i);
            num = a[i];
        } else if (a[i] == num) res.push_back(i);
    }
    for(int point: res) cout << point << " ";

    return 0;
}
    
