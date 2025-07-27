#include <bits/stdc++.h>
using namespace std;
int t,n,q,a[100010],op,s,idx,v,res;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		set<int> st;
		res=0;
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			res+=a[i];
			if(a[i]==1)
			{
				st.insert(i);
			}
		}
		while(q--)
		{
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d",&s);
				if(s>res) puts("NO");
				else
				{
					if(st.size()==0)
					{
						if(s&1) puts("NO");
						else puts("YES");
					}
					else
					{
						int value1=res-2*(*(st.begin())-1);
						int value2=res-2*(n-*(st.rbegin()));
						if(s<=value1||s<=value2)
						{
							puts("YES");
						}
						else
						{
							if((s-value1)%2==0||(s-value2)%2==0)
							{
								puts("YES");
							}
							else puts("NO");
						}
					}
				}
			}
			else
			{
				scanf("%d%d",&idx,&v);
				if(a[idx]==1)
				{
					st.erase(idx);
				}
				res-=a[idx];
				a[idx]=v;
				res+=v;
				if(v==1)
				{
					st.insert(idx);
				}
			}
		}
	}
	return 0;
}