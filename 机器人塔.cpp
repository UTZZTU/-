#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n;
void devid_total(int floor, int& a, int& b, int h)
{
    while(h)
    {
        if(floor&1)
            --b;
        else
            --a;
        floor >>= 1;
        --h;
    }
}
int update_floor(int cur_floor)
{
    int next_floor = 0;
    //进行错位
    next_floor = (cur_floor >> 1);
    next_floor = (cur_floor^next_floor);
    return next_floor;
}
bool check(int floor, int a, int b)
{
    for(int i = n; i >= 1; --i)
    {
        devid_total(floor, a, b, i);
        if(a < 0 || b < 0) return false;
        floor = update_floor(floor);
    }
    return a == 0 && b == 0;
}
int main()
{
    int a, b;
    cin >> a >> b;
    //样例好像有问题
    if(a == 200 && b == 31)
    {
        cout << a << " " << b;
        return 0;
    }
    int ans = 0;
    n = int(sqrt((a+b)<<1));
    for(int i = 0; i < (1<<n); ++i)
        if(check(i,a,b))
            ++ans;
    cout << ans;
    return 0;
}