#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a[200010],f[200010],k,tt[200010],flag;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		vector<int> vec1,vec2;
		cin>>n;
		flag=0;
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			if(k&1)
			{
				f[i]=1;
				vec1.push_back(k);
			}
			else
			{
				f[i]=0;
				vec2.push_back(k);
			}
		}
		sort(vec1.begin(),vec1.end());
		sort(vec2.begin(),vec2.end());
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]&1)
			{
				tt[i]=vec1[cnt1++];
			}
			else
			{
				tt[i]=vec2[cnt2++];
			}
			if(tt[i]<tt[i-1])
			{
				flag=1;
				break;
			}
		}
		if(!flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}