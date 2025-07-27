#include <bits/stdc++.h>
 
using namespace std;
 
const int N=4e6+10;
const int bias=2e6;
int n,k;
int nums[N],add[N],a[N];
int main(){
	scanf("%d%d",&n,&k);
	int tt,ma=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		nums[a[i]+bias]++;
		if(nums[a[i]+bias]>ma)
			ma=nums[a[i]+bias];
	}
	if(k==0){
		printf("%d",ma);
		return 0;
	}
	for(int i=1;i<=n;i++){
		add[a[i]+bias]--;
		if(add[a[i]+bias]<0)
			add[a[i]+bias]=0;
		add[a[i]+k+bias]++;
		ma=max(ma,nums[a[i]+bias+k]+add[a[i]+k+bias]);
	}
	printf("%d",ma);
}