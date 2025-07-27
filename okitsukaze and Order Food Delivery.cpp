#include <bits/stdc++.h>
using namespace std;
int t,n,a,b,k,x,y,z,minn;
int main ()
{
	cin>>t;
	while(t--){
		minn=0x3f3f3f3f;
		cin>>n>>a>>b;
		for(int i=1;i<=n;i++){
			cin>>k>>x>>y;
			for(int j=1;j<=k;j++){
				cin>>z;
				if(z>=x&&z>=a)
				minn=min(minn,z-y-b);
				else if(z>=x)
				minn=min(minn,z-y);
				else if(z>=a){
					minn=min(minn,z-b);
				}else 
				minn=min(minn,z);
			}
		}
		cout<<max(minn,0)<<endl;
	}
	return 0;
}