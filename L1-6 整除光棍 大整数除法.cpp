#include<iostream>
#include<algorithm>
#include<set>
#include<cmath>
#include<stack>
#include<string>
#include<queue>
using namespace std;
int main(){
	int a[1000]={0};
	int n;
	cin>>n;
	for(int i=0;;i++){
		a[i]=1;
		int fz[1000];
		int d=0;
		for(int j=0;j<=i;j++){
			d=d*10+a[j];
			fz[j]=d/n;
			d=d%n;
		}
		if(d!=0)  continue;
		int j=0;
		while(fz[j]==0&&j<=i) j++;
		for(int k=j;k<=i;k++)  {
		    cout<<fz[k];	
		}
		cout<<" "<<i+1;
		return 0;
	}
	return 0;
}