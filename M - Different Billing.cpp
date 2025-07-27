#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y;
int main ()
{
	cin>>x>>y;
	for(int i=0;i*2500<=y;i++)
	{
		if((y-i*2500)%1000==0&&(y-i*2500)/1000>=0)
		{
			int j=(y-i*2500)/1000;
			if(x-i-j>=0)
			{
				cout<<x-i-j<<" "<<j<<" "<<i;
				return 0;
			}
		}
	}
	cout<<-1;
	return 0;
}