#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long ull; 
ull n, day, week;
bool check(ull week) 
{
   
    ull temp = 7*week*(week+1);
    if(temp >= n*2) return true;
    return false;
}
int binarySearch()
{
    ull left = 1, right = 1e10 + 9; 
    while(left < right)
    {
        ull mid = (left + right) >> 1; 
        if(check(mid)) right = mid; 
        else left = mid + 1; 
    }
    return left;
}
ull solve()
{
    ull day = week*7;
    ull sum = 0;
    if(week%2 == 0) sum = week*7 + week/2*(week-1)*7;
    else sum = week*7 + (week-1)/2*week*7;
    while(sum >= n)
    {
        day--;
        sum -= week;
    }
    return day+1;
}
int main()
{
    cin >> n;
    week = binarySearch(); 
    day = solve(); 
    cout << day << endl; 
    system("pause");
    return 0;
}
