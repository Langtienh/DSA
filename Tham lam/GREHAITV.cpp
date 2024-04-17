#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define fname "ROOM"

using namespace std;

const int MaxN = 100002;
typedef vector<int> TRoom;
int n, Room[2*MaxN];
TRoom r[2*MaxN];

struct Data {
    double x;
    int kind, Conference;

    bool operator < (const Data &A) const {
        return x < A.x || (x == A.x && kind > A.kind);
    }

} P[4*MaxN];

stack<int> S;

void enter() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        double start, finish; scanf("%lf%lf", &start, &finish);
        P[i].x = start; P[i].kind = 1; P[i].Conference = i;
        P[i+n].x = finish; P[i+n].kind = 0; P[i+n].Conference = i;
    }
    sort(P+1, P+2*n+1);
}

void process() {
    int res = 0, cnt = 0;
    for(int i=n; i>0; i--) S.push(i);
    for(int i=1; i<=2*n; i++)
        if (P[i].kind == 1) {
            int a = P[i].Conference;
            int b = S.top();
            Room[a] = b; r[b].push_back(a);
            S.pop();
            cnt++;
            res = max(res, cnt);
        } else {
            S.push(Room[P[i].Conference]);
            cnt--;
        }
    if (res <= 2) cout << "YES";
    else cout << "NO";
}

int main() {

    enter();
    process();

    return 0;
}
    
