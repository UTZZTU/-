#include <bits/stdc++.h>
using namespace std;
int m,d[110],res,cnt;
int main ()
{
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>d[i];
		res+=d[i];
	}
	res=res+1>>1;
	for(int i=1;i<=m;i++)
	{
		cnt+=d[i];
		if(cnt>=res)
		{
			cout<<i<<" "<<(res-(cnt-d[i]));
			return 0;
		}
	}
	return 0;
}