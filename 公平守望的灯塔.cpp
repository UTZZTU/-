#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x1,y1,x2,y2;
int main ()
{
	cin>>x1>>y1>>x2>>y2;
	if((x1+y1+x2-y2)%2!=0||(x2+y2+y1-x1)%2!=0)
	cout<<-1;
	else
	cout<<(x1+y1+x2-y2)/2<<" "<<(x2+y2+y1-x1)/2;
	return 0;
}