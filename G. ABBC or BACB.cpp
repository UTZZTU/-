#include <bits/stdc++.h>
using namespace std;
int t,res,cnt;
string s;
int main ()
{
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		cin>>s;
		cnt=res=0;
		vector<int> vec;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='A') res++;
			else
			{
				vec.push_back(res);
				cnt++;
				res=0;
			}
		}
		vec.push_back(res);
		if(!cnt)
		{
			puts("0");
		}
		else
		{
			sort(vec.begin(),vec.end());
			int l=vec.size(),sum=0;
			for(int i=l-1;i>=0&&i>=l-cnt;i--)
			{
				sum+=vec[i];
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}