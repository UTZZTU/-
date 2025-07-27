#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int n,m,d,c;
	cin>>n;
	while(n--)
	{
		cin>>m>>d>>c;
		if(m>7||m==7&&d>11)
		{
			cout<<"Too late!"<<endl;
		}
		else if(m==7||m==6&&d>20)
		{
			if(c<2000) cout<<"Need more!"<<endl;
			else if(c==2000) cout<<"Ok!"<<endl;
			else cout<<"^_^"<<endl;
		}
		else
		{
			if(c<1800) cout<<"Need more!"<<endl;
			else if(c==1800) cout<<"Ok!"<<endl;
			else cout<<"^_^"<<endl;
		}
	}
	return 0;
}
