#include <iostream>

using namespace std;

bool colunm[9], c[18], p[18];
int x, y, num = 0, _x[9], _y[9];

void back_track(int cnt) {
    if(cnt == 9) {
        for(int i=1; i<=7; ++i)
            cout << _x[i] << " " << _y[i] << "\n";
        exit(0);
    }
    if (x == cnt) back_track(cnt+1);
    for(int i=1; i<=8; ++i)
        if(!colunm[i] && !c[cnt - i + 8] && !p[cnt + i]) {
            colunm[i] = c[cnt - i + 8] = p[cnt + i] = true;
            _x[++num] = cnt, _y[num] = i;
            back_track(cnt+1); --num;
            colunm[i] = c[cnt - i + 8] = p[cnt + i] = false;
        }
}

int main() {
    cin >> x >> y;
    colunm[y] = c[x - y + 8] = p[x + y] = true;
    back_track(1);
}
    
