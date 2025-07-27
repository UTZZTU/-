#include <bits/stdc++.h>
using namespace std;
int m,q,op,num,f[110];
int sum(){
	int res=0;
	for(int i=1;i<=m;i++){
		if(f[i])
		res++;
	}
	return res;
}
int main ()
{
	cin>>m>>q;
	while(q--){
		cin>>op>>num;
		if(op==1){
			f[num+3]++;
			if(num-3>=1)
			f[num-3]++;
		} else{
			f[num+3]--;
			if(num-3>=1)
			f[num-3]--;
		}
		cout<<sum()<<endl;
	}
	return 0;
}