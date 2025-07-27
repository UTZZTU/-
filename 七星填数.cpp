#include<iostream>
#include<algorithm>
using namespace std;
int a[12]={0,1,2,3,4,5,7,8,9,10,12,13};
int main()
{
    do
    {
        int x1=a[1]+a[2]+a[3]+a[4];
        int x2=a[4]+a[5]+a[6]+a[7];
        int x3=a[7]+a[8]+a[10]+14;
        int x4=14+a[11]+a[2]+6;
        int x5=6+a[3]+a[5]+11;
        int x6=11+a[6]+a[8]+a[9];
        int x7=a[9]+a[10]+a[11]+a[1];
        if(x1==x2&&x2==x3&&x3==x4&&x4==x5&&x5==x6&&x6==x7)
        {
            cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
            return 0;
        }
    }while(next_permutation(a+1,a+12));
    return 0;
}