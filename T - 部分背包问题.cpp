#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;
struct albb{
	int m;
	int v;
	double avg;
}al[101];
bool cmp(albb a,albb b){
	return a.avg>b.avg;
}
int main(){
	int n,t;
	cin>>n>>t;
	for(int i=0;i<n;i++){
		scanf("%d%d",&al[i].m,&al[i].v);
		al[i].avg = 1.0 * al[i].v/al[i].m;
	}
	sort(al,al+n,cmp);
	double ans,weight=0;
	for(int i=0;i<n;i++){
		if(weight + al[i].m <= t){
			weight += al[i].m;
			ans += al[i].v;
		}else{
			ans += al[i].avg * (t-weight);
			break;
		}
	}
	printf("%.2lf\n",ans);
	return 0;
}