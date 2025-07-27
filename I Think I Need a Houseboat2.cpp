#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    float*x=new float[n];
    float*y=new float[n];
    for(i=1;i<=n;i++)
    {
        float s;
        int z=0;
        cin>>x[i-1]>>y[i-1];
        s=3.1415926*(x[i-1]*x[i-1]+y[i-1]*y[i-1])/2;
        z=s/50+1;
        cout<<"Property "<<i<<": This property will begin eroding in year "<<z<<"."<<endl;
    }
    delete[]x;
    delete[]y;
    cout<<"END OF OUTPUT."<<endl;
    return 0;
}