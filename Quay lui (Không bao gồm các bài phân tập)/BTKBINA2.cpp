#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> V;
string tmp = "";
int x[27], n, num = 0;

void back_track(int cnt) {
     if (cnt == n+1) {
         V.push_back(tmp);
         return;
     }
     x[cnt] = 0;
     tmp = tmp + '0';
     back_track(cnt+1);
     if (x[cnt-1] == 1 || (x[cnt-1] == 0 &&  !num)) { 
         if (x[cnt-1] == 0) ++num;
         x[cnt] = 1;
         tmp[cnt-1] = '1';
         back_track(cnt+1);
         if (x[cnt-1] == 0) --num;
     }
     tmp.erase(tmp.size()-1, 1);
}

int main() {
     cin >> n; x[0] = 1;
     back_track(1);
     cout << V.size() << "\n";
     for(string e: V) cout << e << "\n";
     return 0;
}
    
