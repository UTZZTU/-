#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 mrand(random_device{}()); 
double r1,r2;
const double pi = 3.141592;
void solve()
{
	cin>>r1>>r2;
	printf("%.6f",pi*(r2*r2-r1*r1));
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}