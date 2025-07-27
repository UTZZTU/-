#include <bits/stdc++.h>
using namespace std;
int n,x[500],y[500],res;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i==j||i==k||j==k) continue;
				double r1=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])),
				r2=sqrt((x[i]-x[k])*(x[i]-x[k])+(y[i]-y[k])*(y[i]-y[k])),
				r3=sqrt((x[k]-x[j])*(x[k]-x[j])+(y[k]-y[j])*(y[k]-y[j]));
				if(r1+r2!=r3&&r1+r3!=r2&&r2+r3!=r1)
				{
					if(r1==r2||r1==r3||r2==r3)
					res++;
				}
			}
		}
	}
	cout<<res;
	return 0;
}