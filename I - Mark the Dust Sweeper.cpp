#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int T,n;
signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		int p=1,ans=0;
		while(p<=n&&!a[p]) p++;//找初始有砖头的位置 
		for(int i=p;i<n;i++)
		{
			ans+=a[i];
			if(!a[i]) ans++;//添加新砖头	
		} 	
		cout<<ans<<endl;
	}
	return 0;	
} 