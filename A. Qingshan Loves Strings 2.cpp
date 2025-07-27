#include <bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		getchar();
		cin>>s;
		s=" "+s;
		if(n&1)
		{
			puts("-1");
		}
		else
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i]=='1') cnt++;
			}
			if(n-cnt!=cnt)
			{
				puts("-1");
				continue;
			}
			cnt=0;
			vector<int> vec;
			int i=1,j=n;
			while(1)
			{
				while(i<=j&&s[i]!=s[j])
				{
					i++,j--;
				}
				if(i>j) break;
				if(cnt>300) break;
				if(s[i]=='0')
				{
					vec.push_back(j);
					s=s.substr(0,j+1)+"01"+s.substr(j+1,s.size()-j-1);
					i++,j++;
					cnt++;
				}
				else if(s[i]=='1')
				{
					vec.push_back(i-1);
					s=s.substr(0,i)+"01"+s.substr(i,s.size()-i);
					i++,j++;
					cnt++;
				}
				else break;
			}
//			printf("%lld\n",cnt);
			if(cnt<=300)
			{
				printf("%d\n",cnt);
				if(vec.size())
				{
//					sort(vec.begin(),vec.end());
					for(int i=0;i<cnt;i++)
					{
						printf("%d ",vec[i]);
					}
				}
				printf("\n");
			}
			else puts("-1");
		}
	}
	return 0;
}