#include <bits/stdc++.h>
using namespace std;
const int N = 4e6+10;
vector<int> vec[N];
vector<int> alls;
int n,k,t,maxx,res;
int main ()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		vec[t+2000001].push_back(i);
		alls.push_back(t+2000001);
	}
	sort(alls.begin(),alls.end());
	alls.erase(unique(alls.begin(),alls.end()),alls.end());
	for(int i=0;i<alls.size();i++)
	{
		maxx=max(maxx,(int)vec[alls[i]].size());
		if(k==0) continue;
		if(vec[alls[i]+k].size()==0) continue;
		int l1=0,l2=0,len1=vec[alls[i]].size(),len2=vec[alls[i]+k].size();
		int f=0;
		int numf=0;
		while(l1<len1&&l2<len2)
		{
			if(vec[alls[i]][l1]<vec[alls[i]+k][l2])
			{
				numf++;
				f=max(f,numf);
				l1++;
			}
			else
			{
				numf--;
				if(numf<0) numf=0;
				l2++;
			}
		}
		if(l1<len1)
		{
			numf+=len1-l1;
			f=max(f,numf);
		}
		maxx=max(maxx,len2+f);
	}
	printf("%d",maxx);
	return 0;
}