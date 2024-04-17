#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct Data {
    int val, pos;

    bool operator < (const Data &other) {
        return val < other.val;
    }
} a[100006], b[100006];

bool c[100006], d[100006];
int match[100006];
int n;
stack<int> S;

void enter() {
    scanf("%d", &n);
    for(int i=1; i<=n ;i++) scanf("%d", &b[i].val), b[i].pos = i;
    for(int i=1; i<=n ;i++) scanf("%d", &a[i].val), a[i].pos = i;
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
}

void process() {
    int j = 1, res = 0;
    for(int i=1; i<=n; i++) {
        while (j <= n && b[j].val < a[i].val) S.push(j++);
        if (!S.empty()) {
            c[i] = d[S.top()] = true;
            match[b[S.top()].pos] = a[i].pos;
            S.pop(); ++res;
        }
    }
    cout << res;
}

int main() {

    enter();
    process();

    return 0;
}
    
