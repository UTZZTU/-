#include <iostream>
#include <set>
using namespace std;
int main()
{
  set<int> p;
  int a,b;
  int ans=0;
  for(a=23;a<45;a++)
  {
    for(b=10000;b>45;b--)
    {
      if(a==b||2*a*b!=45*(a+b))
      continue;
      if(p.find(a)==p.end())
      {
      	ans++;
      	p.insert(a);
      	p.insert(b);
	  }
    }
  }
  cout<<ans;
  return 0;
}