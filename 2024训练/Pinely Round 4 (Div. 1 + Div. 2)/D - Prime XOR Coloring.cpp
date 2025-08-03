#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void solve()
{
	cin>>n;
	if(n==1)
	{
		cout<<"1"<<endl;
		cout<<"1"<<endl;
	}
	else if(n==2)
	{
		cout<<"2"<<endl;
		cout<<"1 2"<<endl;
	}
	else if(n==3)
	{
		cout<<"2"<<endl;
		cout<<"1 2 2"<<endl;
	}
	else if(n==4)
	{
		cout<<"3"<<endl;
		cout<<"1 2 2 3"<<endl;
	}
	else if(n==5)
	{
		cout<<"3"<<endl;
		cout<<"1 2 2 3 3"<<endl;
	}
	else
	{
		cout<<4<<endl;
		for(int i=1;i<=n;i++)
		{
			int j=i;
			j%=4;
			if(j==0) j=4;
			cout<<j<<" ";
		}
		cout<<endl;
	}
}
/*
1
1
2
1 2
2
1 2 2
3
1 2 2 3
3
1 2 2 3 3
4
1 2 2 3 3 4
4
1 2 2 3 3 4 4
4
1 2 22 3 33 4 4 4

5
5
6
6
7
7


*/
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}