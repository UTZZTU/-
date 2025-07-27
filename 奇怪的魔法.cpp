#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9+7;
ll f[1000010],ans,n,k,res=1;
int main ()
{
   cin>>n>>k;
   for(int i=1;i<=k;i++)
   {
   	  res=res*(n-1+i);
      res/=i;
      res%=INF;
      ans+=res*i%INF;
      ans%=INF;
   }
	cout<<ans;
	return 0;
}