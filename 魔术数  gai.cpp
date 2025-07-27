#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll a,w,n,pin,weishu,i,ans;
ll shuzu[15];
int f(ll dai)
{
	ans=1;weishu=0;
	while(dai) 
	{
        shuzu[weishu]=dai%10;
        weishu++;
        dai/=10;
    }
    if(weishu%2!=0) 
	{
        shuzu[weishu]=10;
        for(ll i=0; i<weishu; i++)
		{
            if(i%2) 
			{
                if(shuzu[i]<=shuzu[i+1])
				{
                    ans=0;
                    break;
                }
            } else {
                if(shuzu[i]>=shuzu[i+1])
				{
                    ans=0;
                    break;
                }
            }
        }
    } 
	else 
	{
        shuzu[weishu]=11;
        for(ll i=0; i<weishu; i++) 
		{
            {
                if(i%2) 
				{
                    if(shuzu[i]>=shuzu[i+1]) 
					{
                        ans=0;
                        break;
                    }
                } 
				else
				{
                    if(shuzu[i]<=shuzu[i+1]) 
					{
                        ans=0;
                        break;
                    }
                }
            }
        }
    }
    if(ans)
    	return 1;
    else
    	return 0;
}
int main()
{
	
	cin >> n;
	while(n--)
	{
		//memset(d,0,sizeof(d));
		int count=0;
		scanf("%lld%lld",&a,&w);
		ll x=sqrt(a);
		ll y=sqrt(w);
		if(floor(sqrt(a)) == sqrt(a))
		{
			i=x;
		}
		else {
			i=x+1; 
		}
		for(;i<=y;i++)
		{
			ll weishu=0;
			//int ans=1;
			pin=i*i;
            if(f(pin))
            count++;
		}
		cout<<count<<endl;	
	} 
	return 0;		
}
