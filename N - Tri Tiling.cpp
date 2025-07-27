#include <iostream>
#include <cstring>
using namespace std;
int f[31];

int main()
{
    memset(f, 0, sizeof(f));
    f[0] = 1;
    f[2] = 3;
    for (int i = 4; i <= 30; i += 2) {
        f[i] = 4 * f[i - 2] - f[i - 4];
    }

    int n;
    while(cin >> n && n != -1) {
        cout << f[n] << endl;
    }
    return 0;
}