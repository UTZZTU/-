#include <bits/stdc++.h>
using namespace std;
void solve()
{
	char i1,i2;
	int l1,l2;
	cin>>i1>>l1;
	cin>>i2>>l2;
	int len=max(abs(i1-i2),abs(l1-l2));
	cout<<len<<endl;
	for(int i=1;i<=len;i++)
	{
		if(i1>i2)
		{
			cout<<"L";
			i1--;
		}
		else if(i1<i2)
		{
			cout<<"R";
			i1++;
		}
		if(l1>l2)
		{
			cout<<"D";
			l1--;
		}
		else if(l1<l2)
		{
			l1++;
			cout<<"U";
		}
		cout<<endl;
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
