#include <bits/stdc++.h>
using namespace std;
int t,f[30],k;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		for(int i=1;i<=4;i++)
		{
			cin>>k;
			int num=0;
			while(k)
			{
				if(k&1) f[num]=1;
				k>>=1;
				num++;
			}
		}
		int res=0;
		k=1;
		for(int i=0;i<30;i++)
		{
			if(f[i])
			res+=k;
			k*=2;
			f[i]=0;
		}
		cout<<res*4<<endl;
	}
	return 0;
}