#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n;
string s,t;
struct node
{
	int num,pos;
};
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		cin>>s>>t;
		vector<node> vec;
		int cnt=0,p=-1;
		for(int i=0;i<n;i++)
		{
			if(s[i]!=t[i])
			{
				cnt++;
				if(p==-1)
				{
					p=i;
				}
			}
			else
			{
				if(cnt) vec.push_back({cnt,p});
				cnt=0;
				p=-1;
			}
		}
		if(cnt) vec.push_back({cnt,p});
		if(vec.size()>=3)
		{
			puts("0");
		}
		else if(vec.size()==2)
		{
			puts("6");
		}
		else if(vec.size()==1)
		{
			int l=vec[0].pos;
			int r=l+vec[0].num-1;
			int res=l-1+n-r+(vec[0].num-1);
			printf("%d\n",res*2);
		}
		else
		{
			printf("%lld\n",(ll)n*(n+1)/2ll);
		}
	}
	return 0;
}