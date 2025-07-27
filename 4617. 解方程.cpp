#include <iostream>
using namespace std;
int n;
int main () {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int t = 0,x = n;
        while (x) {
            x &= x - 1;
            t++;
        }
        cout << (1 << t) << endl;
    }
    return 0;
}