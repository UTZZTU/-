#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    float a,s=0;
    int i;
    for(i=0;i<12;i++)
    {
        cin>>a;
        s=s+a;
    }
    s=s/12;
    cout<<"$"<<setiosflags(ios::fixed)<<setprecision(2)<<s<<endl;
    return 0;
}