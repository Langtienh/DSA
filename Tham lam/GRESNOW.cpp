#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#define pii pair<int, int>
#define mk make_pair

using namespace std;

struct Data {
    int a[4];
} res[100006];

int num = 0, n, r[100006];
map<int, int> Snow_ball;
vector<pii> Sball;

struct cmp {
    bool operator () (const pii &A, const pii &B) {
        return A.second < B.second;
    }
};

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &r[i]);
        Snow_ball[r[i]]++;
    }
    for(map<int, int>::iterator i = Snow_ball.begin(); i != Snow_ball.end(); ++i)
        Sball.push_back(mk(i->first, i->second));
    if (Sball.size() < 3) {
        cout << 0;
        return 0;
    }
    priority_queue<pii, vector<pii>, cmp> PQ(Sball.begin(), Sball.end());
    while ((int) PQ.size() >= 3) {
        pii c = PQ.top(); PQ.pop();
        pii b = PQ.top(); PQ.pop();
        pii a = PQ.top(); PQ.pop();
        ++num;
        res[num].a[1] = c.first;
        res[num].a[2] = b.first;
        res[num].a[3] = a.first;
        sort(res[num].a+1, res[num].a+4);
        --c.second;
        --b.second;
        --a.second;
        if(a.second > 0) PQ.push(a);
        if(b.second > 0) PQ.push(b);
        if(c.second > 0) PQ.push(c);
    }
    cout << num << "\n";
    for(int i=1; i<=num; ++i) cout << res[i].a[3] << " " << res[i].a[2] << " " << res[i].a[1] << "\n";
    return 0;
}
    
