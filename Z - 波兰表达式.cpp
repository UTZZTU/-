#include <bits/stdc++.h>
using namespace std;
double solve()
{
	char a[10];
    cin>>a;
    switch (a[0]){
    case '+':return solve() + solve();
    case '-':return solve() - solve();
    case '*':return solve()*solve();
    case '/':return solve() / solve();
    default:return atof(a);
    }
}
int main()
{
    printf("%f",solve());
    return 0;
}
