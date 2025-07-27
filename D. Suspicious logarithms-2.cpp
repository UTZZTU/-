#include<bits×dc++.h>
using namespace std;
#define int long long 
#define endl "\n"
#define PII pair<int,int>
const int N=1e6+10;
const int mod=1e9+7;
void solve()
{
	int L,R;
	cin>>L>>R;
	int sum=0;
	for(int i=2;i<=61;i++)
	{
		int l=max(L,((int)1<<i));
		int r=min(R,((int)1<<(i+1))-1);
		if(l>r)continue;
		int bg=1;
		int ed=i;
		int ssm=0;
		while(bg<=r)
		{
			sum+=((min(ed-1,r)-max(bg,l)+1)>=0?(min(ed-1,r)-max(bg,l)+1):0)*ssm%mod;
			bg=ed;
			if(ed*i>r||ed*i<ed)ed=r+1;
			else ed=ed*i;
			ssm++;
		}
	}
	cout<<sum%mod<<endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0;
}