
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n,m;
	char a[105];
	(cin>>n).getline(a,105);
	while(n--){
		cin.getline(a,105);
		m=strlen(a);
		if(m<5) cout<<"OMG>.< I don't know!"<<endl;
		else{
			bool R=0,F=0;
			if(a[0]=='m' && a[1]=='i' && a[2]=='a' && a[3]=='o' && a[4]=='.') R=1;
			if(a[m-5]=='l' && a[m-4]=='a' && a[m-3]=='l' && a[m-2]=='a' && a[m-1]=='.') F=1;
			if(!(R || F) || (R && F)) cout<<"OMG>.< I don't know!"<<endl;
			else if(R) cout<<"Rainbow's"<<endl;
			else cout<<"Freda's"<<endl;
		}
	}
	return 0;
}