#include<iostream>
#include<cstring>
using namespace std;
const int max = 1000005;
bool prime[1000005]={false};
int main()
{
    int        i,a,d,n,j;
    memset(prime,true,sizeof(prime));
    for(i = 3 ; i <= 1000 ; i += 2 )
    {
        for(j = 3 ; j <= ::max / i ; j += 2)
        {
            if(prime[i])
            {
                prime[i * j] = false;    
            }    
        }    
    }
    for(i = 4 ; i <= ::max; i += 2 )
    {
        prime[i] = false;    
    }
    prime[1] = prime[0] = false;
    
    while(cin >> a >> d >> n,a != 0 && d != 0 && n != 0)
    {
        j = 0;
        for (i = a; j < n; i += d)
        {
            if (prime[i])
            {
                j++;
            }
        }
        cout << i - d << endl;
    }
    return 0;
}