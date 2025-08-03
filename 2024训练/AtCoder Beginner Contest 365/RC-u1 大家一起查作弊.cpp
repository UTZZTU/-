#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int sum,cnt,len;
void solve()
{
	while(getline(cin,s))
	{
		int aa=0,bb=0,cc=0;
		for(auto c:s)
		{
			if(c>='0'&&c<='9')
			{
				aa++;
			}
			else if(c>='a'&&c<='z')
			{
				bb++;
			}
			else if(c>='A'&&c<='Z')
			{
				cc++;
			}
			else
			{
				if(aa+bb+cc==0) continue;
				cnt++;
				len+=aa+bb+cc;
				if(aa&&bb&&cc)
				{
					sum+=5;
				}
				else if(aa&&(bb||cc))
				{
					sum+=3;
				}
				else if(bb&&cc)
				{
					sum++;
				}
				aa=bb=cc=0;
			}
		}
		if(aa+bb+cc!=0)
		{
			cnt++;
			len+=aa+bb+cc;
			if(aa&&bb&&cc)
			{
				sum+=5;
			}
			else if(aa&&(bb||cc))
			{
				sum+=3;
			}
			else if(bb&&cc)
			{
				sum++;
			}
			aa=bb=cc=0;
		}
	}
	cout<<sum<<endl;
	cout<<len<<" "<<cnt;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
