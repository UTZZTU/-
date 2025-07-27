#include<cstring>
#include<iostream>
using namespace std;
int num[1001],mod[1001];
int m; 
int main(){
    int x,y;
    while(scanf("%d,%d",&x,&y)!=EOF){
        memset(num,0,sizeof(num));
        memset(mod,0,sizeof(mod));
        num[0]=x/y;
        m=x%y;
        int flag=0;
        int i=1,circle;
        while(!flag){
            mod[m]=i;
            num[i]=m*10/y;
            m=m*10%y;
            if(mod[m]){
                flag=2;
                circle=m;
            }
            if(m==0){
                flag=1;
            }
            i++;
        }
        cout<<num[0]<<'.';
        for(int j=1;j<i;j++){
            if(flag==2&&mod[circle]==j)cout<<'[';
            cout<<num[j];
        }
        if(flag==2)cout<<']';
        cout<<endl;
        printf("%.13f",1.0/7);
    }
    return 0;
}