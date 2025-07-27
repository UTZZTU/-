#include <bits/stdc++.h>
using namespace std;
set<int> st;
int n,k,p=-1,q=-1,cnt;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		st.insert(k);
	}
	for(auto it=st.begin();it!=st.end();it++)
	{
		if(p==-1&&q==-1)
		{
			p=*it+15;
			q=p+29;
		}
		else
		{
			if(*it<p)
			{
				;
			}
			else if(*it>q)
			{
				cout<<p<<" "<<q<<endl;
				p=*it+15;
				q=p+29;
				cnt=0;
			}
			else
			{
				if(!cnt)
				{
					cnt=1;
					q+=15;
				}
				else
				{
					;
				}
			}
		}
	}
	cout<<p<<" "<<q;
	return 0;
}