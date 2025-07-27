#include <bits/stdc++.h>
using namespace std;
int t,n,c,a[200010],res,num;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			a[i]+=i;
		}
		sort(a+1,a+1+n);
		res=num=0;
		for(int i=1;i<=n;i++)
		{
			res+=a[i];
			if(res>c)
			{
				break;
			}
			num++;
		}
		cout<<num<<endl;
	}
	return 0;
}