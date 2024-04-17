#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int n, T, m, a[200006];
deque<int> A;

int main() {
    scanf("%d%d%d", &n, &T, &m);
    int res = 0;
    for(int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        while (!A.empty() && A.front() <= i-m) A.pop_front();
        while (!A.empty() && a[A.back()] <= a[i]) A.pop_back();
        A.push_back(i);
        if (a[A.front()] <= T && i >= m) ++res;
    }
    cout << res;
    return 0;
}
    
