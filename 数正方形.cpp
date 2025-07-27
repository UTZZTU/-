#include <iostream>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int main()
{
  int n;
  cin>>n;
  ll ans=0;
  for(int i=2;i<=n;i++){
      ans=(ans+(i-1)*(ll)(n-i+1)*(n-i+1))%mod;
  }
  cout<<ans<<endl;
  return 0;
}