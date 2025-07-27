#include<iostream>
#include<string.h>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    char a,b;
    float c,t,d,e,h,hh,z;
    while(cin>>a&&a!='E')
    {
    if(a=='E')
        return 0;
    else
    {
        cin>>c>>b>>d;
        if((a=='T'&&b=='D')||(b=='T'&&a=='D'))
        {
            if((b=='T'&&a=='D'))
            {
                z=c;
                c=d;
                d=z;
            }
            e=6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))));
            h=(0.5555)*(e-10.0);
            hh=h+c;
            cout<<setiosflags(ios::fixed)<<setprecision(1)<<"T "<<c<<" D "<<d<<" H "<<hh<<endl;
        }
        else if((a=='T'&&b=='H')||(b=='T'&&a=='H'))
        {
            if((b=='T'&&a=='H'))
            {
                z=c;
                c=d;
                d=z;
            }
            h=d-c;
            e=h/(0.5555)+10.0;
            t=1/(-(log(e/6.11)/5417.7530)+(1/273.16))-273.16;
            cout<<setiosflags(ios::fixed)<<setprecision(1)<<"T "<<c<<" D "<<t<<" H "<<d<<endl;
        }
        else if((a=='D'&&b=='H')||(b=='D'&&a=='H'))
        {
            if((b=='D'&&a=='H'))
            {
                z=c;
                c=d;
                d=z;
            }
            e= 6.11*exp((5417.7530)*((1/273.16)-(1/(c+273.16))));
            h=(0.5555)*(e-10.0);
            t=d-h;
            cout<<setiosflags(ios::fixed)<<setprecision(1)<<"T "<<t<<" D "<<c<<" H "<<d<<endl;
        }
    }
    }
    return 0;
}