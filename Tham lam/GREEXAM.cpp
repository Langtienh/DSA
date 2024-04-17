#include <iostream>
#include <algorithm>
#define fname "GREEXAM"

using namespace std;

struct Data {
    int val, num;
} bit[106];

void update(Data &p, int val) {
    p.val += val;
    p.num++;
}

void update(int p, int val) {
    for(; p <= 100; p += (p & (-p))) update(bit[p], val);
}

Data query(int p) {
    Data ans = {0, 0};
    for(; p>0; p -= (p & (-p))) ans.val += bit[p].val, ans.num += bit[p].num;
    return ans;
}

int  binary_s(int x) {
    int l = 1, r = 100, ans = 101;
    while (l <= r) {
        int mid = (l+r) >> 1;
        if (query(mid).val >= x) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ans;
}

int main() {

    int n = 0, m = 0;
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) {
        int a; scanf("%d", &a);
        int p = binary_s(m - a);
        if (p == 101) {
            cout << 0 << " ";
            update(a, a);
            continue;
        }
        Data l = query(p-1);
        int add = (m - a - l.val) / p;
        cout << (i - l.num - add - 1) << " ";
        update(a, a);
    }

    return 0;
}
    
