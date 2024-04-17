#include <bits/stdc++.h>
#define ll long long

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pi> pii;

priority_queue<pii, vector<pii>, greater<pii> > Q;
struct P {
    int s, t, pos;
} e[300006];

int n, t, start=0, finish=0, s;
int res = 1e9;
int trace[300006];

void enter() {
    scanf("%d%d%d", &n, &s, &t);
    for(int i=1; i<=n; i++) scanf("%d%d", &e[i].s, &e[i].t), e[i].pos = i;
    sort(e+1, e+n+1, [] (const P &a, const P &b){return a.s<b.s;});
    start = n+1;
    for(int i=1; i<=n; i++)
        if(e[i].s<=s) {
            if (e[i].t>=t) {
                if (res>1) res = 1, finish = i;
            } else Q.push(pii(1, pi(e[i].t, i)));
        } else {
            start = i;
            break;
        }
}

void process() {
    for(int i=start; i<=n; i++) {
        while (!Q.empty() && Q.top().second.first<e[i].s) Q.pop();
        if (Q.empty()) break;
        int tt = Q.top().first + 1;
        trace[i] = Q.top().second.second;
        if (e[i].t >= t) {
            if (res>tt) {
                res = tt;
                finish = i;
            }
        } else Q.push(pii(tt, pi(e[i].t, i)));
    }
    if (finish==0) res = -1;
    cout << res << "\n";
    vector<int> res1; res1.clear();
    while (finish!=0) {
        res1.push_back(finish);
        finish = trace[finish];
    }
    for(vector<int>::reverse_iterator i=res1.rbegin(); i!=res1.rend(); i++) cout << e[*i].pos << " ";
}

int main() {

    enter();
    process();

    return 0;
}
    
