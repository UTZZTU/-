#include<iostream>
using namespace std;
int main(){
	int a,b,c,d,e,f;
	int sum = 0;
	int space_1,space_2;
	int arr[4]={0,5,3,1};
	while(cin>>a>>b>>c>>d>>e>>f&&(a+b+c+d+e+f!=0))
	{
		sum =d+e+f+(c+3)/4;
	    space_2 = 5*d+arr[c%4]; 
        if(b>space_2){
			sum+=((b-space_2)+8)/9;
		}
		space_1 =36*sum-b*4-c*9-d*16-e*25-f*36;
		if(a>space_1){
			sum+=((a-space_1)+35)/36;
		}
		cout<<sum<<endl;
	}
	return 0;
}
