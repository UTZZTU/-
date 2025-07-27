#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> div(vector<int>& A, int b, int& r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i -- )
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

vector<int> mul(vector<int>& A, int b)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size() || t; i ++ )
    {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

vector<int> add(vector<int>& A, int b)
{
    vector<int> C;
    for (int i = 0, t = b; i < A.size() || t; i ++ )
    {
        if (i < A.size()) t += A[i];
        C.push_back(t % 10);
        t /= 10;
    }
    return C;
}

void print(vector<int>& A)
{
    for (int i = A.size() - 1; i >= 0; i -- )
        cout << A[i];
    cout << endl;
}

int main()
{
    string a;
    cin >> a;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');

    vector<int> B;
    while (A.size() > 1 || A[0] > 0)
    {
        int r;
        A = div(A, 2, r);
        B.push_back(r);
    }

    vector<int> C;
    for (int x: B)
    {
        C = mul(C, 2);
        C = add(C, x);
    }

    print(C);

    return 0;
}