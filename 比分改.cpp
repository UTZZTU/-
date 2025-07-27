#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

char c;
int F, A;

void same() {
    if (c == 'E' || F - A == 2 || A - F == 2) {
        cout << F << ":" << A << endl;
        F = 0;
        A = 0;
        return;
    }
    cin >> c;
    if (c == 'F')
        F++;
    if (c == 'A')
        A++;
    same();
}

int main() {
    while (c != 'E') {
        cin >> c;
        if (c == 'F')
            F++;
        if (c == 'A')
            A++;
        if (F == 10 && A == 10)
            same();
        if (F == 11 || A == 11) {
            cout << F << ":" << A << endl;
            F = 0;
            A = 0;
        }
    }
    if (F != 0 || A != 0)
        cout << F << ":" << A << endl;//зЂвт

    return 0;
}

