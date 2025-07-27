#include <bits/stdc++.h>
using namespace std;
int n,m,a[100010],d[110];
long long res;
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&d[i]);
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=d[i];j++)
		{
			int pos=0;
			vector<int> st;
			for(int k=j;k<=n;k+=d[i])
			{
				if(st.empty())
				{
					st.push_back(a[k]);
					pos++;
					res++;
				}
				else
				{
					int cnt=upper_bound(st.begin(),st.end(),a[k])-st.begin();
					vector<int>::iterator it = upper_bound(st.begin(),st.end(),a[k]);
					res+=(abs(1+(k-j)/d[i]-cnt-1)+1);
					st.insert(it,a[k]);
					pos++;
				}
			}
			for(int k=0;k<pos;k++)
			{
				a[j+k*d[i]]=st[k];
			}
		}
	}
	printf("%lld\n",res);
	for(int i=1;i<=n;i++)
	printf("%d ",a[i]);
	return 0;
}