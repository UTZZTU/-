#include <bits/stdc++.h>
using namespace std;
int t,l,r,cnt,res,flag;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		res=0;flag=0;
		cin>>l>>r>>cnt;
		while(l<=r)
		{
			res++;
			int mid=l+r>>1;
			if(cnt==res)
			{
				cout<<mid<<endl;
				flag=1;
				break;	
			}
			l=mid+1;
		}
		if(!flag) cout<<-1<<endl;
	}
	return 0;
}