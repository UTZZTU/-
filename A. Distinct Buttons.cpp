#include <bits/stdc++.h>
using namespace std;
int t,n,x,y;
int main ()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		set<char> st;
		for(int i=1;i<=n;i++)
		{
			cin>>x>>y;
			if(x<0) st.insert('L');
			else if(x>0) st.insert('R');
			if(y<0) st.insert('D');
			else if(y>0) st.insert('U');
		}
		if(st.size()==4)
		{
			puts("NO");
		}
		else puts("YES");
	}
	return 0;
}