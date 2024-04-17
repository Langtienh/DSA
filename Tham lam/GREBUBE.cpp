#include <bits/stdc++.h>
#define fname "DOLLS"
#define llong long long

using namespace std;

int n, k;
int a[100006];

void enter() {
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
}

void process() {
    sort(a+1, a+n+1);
    llong res = 0;
    priority_queue<int> S; S.push(a[n]);
    res += a[n];
    for(int i=n-1; i; i--)
        if (a[i] + k > S.top()) {
            S.push(a[i]);
            res += a[i];
        } else {
            S.pop();
            S.push(a[i]);
        }
    cout << res;
}

int main() {

    enter();
    process();

    return 0;
}
    
