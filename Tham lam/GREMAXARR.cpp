#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Data {
    long long val;
    int pos;
} a[200006];

struct cmp1 {
    bool operator () (const Data &A, const Data &B) {
        return A.val > B.val;
    }
};

struct cmp2 {
    bool operator () (const Data &A, const Data &B) {
        return A.val < B.val;
    }
};

template<typename T>
bool fast_scan(T &num) {
    num = 0;
    register char c = getchar();
    while (c != '-' && (c < '0' || '9' < c)) {
        if (feof(stdin)) return false;
        c = getchar();
    }
    bool neg = false;
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    for(; '0' <= c && c <= '9'; c = getchar()) num = (num << 1) + (num << 3) + (c - '0');
    if (neg) num = -num;
    return true;
}

priority_queue<Data, vector<Data>, cmp1> Q1;
priority_queue<Data, vector<Data>, cmp2> Q2;

int main() {
    int n, k, x;
    fast_scan(n), fast_scan(k), fast_scan(x);
    for(int i=1; i<=n; ++i) {
        fast_scan(a[i].val);
        a[i].pos = i;
        if (a[i].val >= 0) Q1.push(a[i]);
        else Q2.push(a[i]);
    }
    while ((int) Q2.size() % 2 == 0 && k > 0) {
        Data tmp1, tmp2;
        if (!Q1.empty()) tmp1 = Q1.top(); else tmp1.val = 1e18;
        if (!Q2.empty()) tmp2 = Q2.top(); else tmp2.val = -1e18;
        if (tmp1.val > -tmp2.val) {
            Q2.pop();
            tmp2.val += x;
            if (tmp2.val < 0) Q2.push(tmp2);
            else Q1.push(tmp2);
        } else {
            Q1.pop();
            tmp1.val -= x;
            if (tmp1.val < 0) Q2.push(tmp1);
            else Q1.push(tmp1);
        }
        --k;
    }
    while (k > 0) {
        Data tmp1, tmp2;
        if (!Q1.empty()) tmp1 = Q1.top(); else tmp1.val = 1e18;
        if (!Q2.empty()) tmp2 = Q2.top(); else tmp2.val = -1e18;
        if (tmp1.val > -tmp2.val) {
            Q2.pop();
            tmp2.val -= x;
            Q2.push(tmp2);
        } else {
            Q1.pop();
            tmp1.val += x;
            Q1.push(tmp1);
        }
        --k;
    }
    while (!Q1.empty()) {
        a[Q1.top().pos] = Q1.top();
        Q1.pop();
    }
    while (!Q2.empty()) {
        a[Q2.top().pos] = Q2.top();
        Q2.pop();
    }
    for(int i=1; i<=n; ++i) cout << a[i].val << " ";
    return 0;
}
    
