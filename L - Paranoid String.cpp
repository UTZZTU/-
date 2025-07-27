 
#include <iostream>
 
typedef long long int ll;
using namespace std;
 
 
 
int main()
{
    int t;
 
    cin>>t;
 
    while(t--)
    {
        int n;
        cin>>n;
 
        string s;
 
        cin>>s;
 
        ll ans=0;
        s=" "+s;
        s[0]=s[1];
 
        for(int i=1;i<=n;i++)
        {
            if(s[i]!=s[i-1])
                ans+=i-1;
        }
        cout<<ans+n<<endl;
    }
 
    return 0;
}