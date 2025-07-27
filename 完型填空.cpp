#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,f[101][101][101][101];
struct node{
	int a,b,c,d;
}s[1010];
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b>>s[i].c>>s[i].d;
	}
	m=n/4;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=m;k++){
				for(int l=0;l<=m;l++){
					int sum=(i+j+k+l);
					if(i){
						f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l]+s[sum].a);
					}
					if(j){
						f[i][j][k][l]=max(f[i][j][k][l],f[i][j-1][k][l]+s[sum].b);
					}
					if(k){
						f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k-1][l]+s[sum].c);
					}
					if(l){
						f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k][l-1]+s[sum].d);
					}
				}
			}
		}
	}
	cout<<f[m][m][m][m];
	return 0;
}