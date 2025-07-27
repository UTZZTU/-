#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll weishu,ans;
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
    if(ans)
    	return 1;
    else
    	return 0;
}
int main ()
{
	int g,sum=0;
	cin>>g;
	while(g--)
	{
		sum=0;
		ll a,b,x,y,i;
		cin>>a>>b;
		x=sqrt(a);
		y=sqrt(b);
		if(x*x==a)
	    i=x;
	    else
	    i=x+1;
	    for(i;i<=y;i++)
	    {
	    	if(f(i*i))
	    	{
	    		sum++;
			}
	    	
		}
		cout<<sum<<endl;
	}
	return 0;
}