#include <bits/stdc++.h>
using namespace std;
string u="female",v="male",w;
int ans,t;
double k1,k2,k3,k4,k5;
int main ()
{
	cin>>t;
	getchar();
	while(t--)
	{
	    ans=0;
		cin>>w;
		cin>>k1>>k2>>k3>>k4>>k5;
		if(w==u)
		{
			if(k1<4||k1>10)
			ans++;
			if(k2<3.5||k2>5.5)
			ans++;
			if(k3<110||k3>150)
			ans++;
			if(k4<36||k4>40)
			ans++;
			if(k5<100||k5>300)
			ans++;
		}
		else
		{
			if(k1<4||k1>10)
			ans++;
			if(k2<3.5||k2>5.5)
			ans++;
			if(k3<120||k3>160)
			ans++;
			if(k4<42||k4>48)
			ans++;
			if(k5<100||k5>300)
			ans++;
		}
		if(!ans)
		cout<<"normal"<<endl;
		else
		cout<<ans<<endl;
	}
	return 0;
}