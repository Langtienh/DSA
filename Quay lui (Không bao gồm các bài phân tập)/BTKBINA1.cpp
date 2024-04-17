#include <iostream>

using namespace std;

int n;
char S[30];

void back_track(int cnt) {
    if (cnt == n+1) {
    	cout << S+1;
    	putchar('\n');
    	return;
    }
    for(int i=0; i<2; ++i) S[cnt] = char(i+48), back_track(cnt+1), S[cnt] = '\0';
}

int main() {
    scanf("%d", &n);
    back_track(1);

}
    
