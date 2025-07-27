#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,k,c[200010];
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>c[i];
		}
		int pos1,pos2,cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==c[1])
			{
				cnt1++;
				pos1=i;
				if(cnt1>=k) break;
			}
		}
		for(int i=n;i>=1;i--)
		{
			if(c[i]==c[n])
			{
				cnt2++;
				pos2=i;
				if(cnt2>=k) break;
			}
		}
		if((pos1<pos2&&cnt1==k&&cnt2==k)||(pos1>=pos2&&c[1]==c[n]&&cnt1==k)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}