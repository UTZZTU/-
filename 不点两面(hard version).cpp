#include <bits/stdc++.h>
using namespace std;
int m,q,op,num,f[100010],res;
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>m>>q;
	while(q--){
		cin>>op>>num;
		if(op==1){
			f[num+3]++;
			if(f[num+3]==1&&num+3<=m)
			res++;
			if(num-3>=1){
				f[num-3]++;
				if(f[num-3]==1&&num-3<=m)
				res++;
			}
			
		} else{
			f[num+3]--;
			if(f[num+3]==0&&num+3<=m)
			res--;
			if(num-3>=1){
				f[num-3]--;
				if(f[num-3]==0&&num-3<=m)
				res--;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}