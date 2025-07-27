#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,res,num;
int main ()
{
	cin>>n>>m;
	while(res<n)
	{
		if(res+m>=n)
		{
			cout<<num;
			return 0;
		}
		else
		{
			res+=m;
			m=(m+1)/2;
			num++;
			if(m==1)
			{
				num+=(n-res);
				cout<<num-1;
				return 0;
			}
		}
	}
	return 0;
}