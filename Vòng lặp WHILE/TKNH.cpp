#include <iostream>
#include <algorithm>
#define fname "TKNH"

using namespace std;

double a, b;

void enter() {
    scanf("%lf%lf", &a, &b);
}

void process() {
    int res = 0;
    while (a < b) {
        ++res;
        a *= 1.*1011/1000;
    }
    cout << res;
}

int main() {

    enter();
    process();

    return 0;
}
    
