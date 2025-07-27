#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll i,j,n;
string a,b,c,d;
string an[13]={"Ox","Tiger","Rabbit","Dragon","Snake","Horse","Goat","Monkey","Rooster","Dog","Pig","Rat"};
map<string,ll> year;
int main ()
{
	year["Bessie"]=0;
	cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b>>b>>b>>c>>d>>d>>d;
        if(b=="previous")
        {
            for(j=year[d]-1;;j--)   if(an[(j%12+12)%12]==c) break;
            year[a]=j;
        }
        else
        {
            for(j=year[d]+1;;j++)   if(an[(j%12+12)%12]==c) break;
            year[a]=j;
        }
    }
    cout<<abs(year["Elsie"]);
    return 0;
}