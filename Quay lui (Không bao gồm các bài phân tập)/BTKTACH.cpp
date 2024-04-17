#include <iostream>
#include <cstring>

using namespace std;

bool avail[46];
int n, _b[46], _e[46], len;
char S[106];

void print(int cnt) {
    for(int i=1; i<=cnt; ++i) {
        for(int j=_b[i]; j<=_e[i]; ++j) cout << S[j];
        if (i < cnt) cout << " ";
        else cout << "\n";
    }
}

void back_track(int cnt, int b) {
     if (b > len) {
         print(cnt - 1);
         return;
     }
     if ('1' <= S[b] && S[b] <= '9')
     if (!avail[S[b] - '0']) {
         avail[S[b] - '0'] = true;
     	 _b[cnt] = b;
     	 _e[cnt] = b;
     	 back_track(cnt+1, b+1);
     	 avail[S[b] - '0'] = false;
     }
     if (b < len) {
         int num = (S[b] - '0') * 10 + (S[b+1] - '0');
         if (10 <= num && num <= n)
         if (!avail[num]) {
             avail[num] = true;
      	     _b[cnt] = b;
      	     _e[cnt] = b+1;
      	     back_track(cnt+1, b+2);
      	     avail[num] = false;
         }
     }
}

int main() {
     scanf("%d", &n);
     scanf("%s", S+1); len = strlen(S+1);
     back_track(1, 1);

     return 0;
}
    
