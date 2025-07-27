#include<bits/stdc++.h>
using namespace std;
priority_queue < int , vector < int > , greater < int > > q;  //开一个降序的队列，这个我也不会看网上的 
int ans,a[1000005],n,x,i,j,k;
int main()
{   char ch;
    cin>>n; 
    for(int i=0;i<n;i++){
    	 cin>>ch;
    	 if(ch=='i') {   cin>>x;    //如果是i，就放到队列中 
    	 	             q.push(x);
		             }
		 if(ch=='q') {
		 	           a[j++]=q.top();  //如果是q，就将队头的值赋给a数组，并加队头移出队列 
		 	           q.pop();   
		             }
	}
 for(int i=0;i<j;i++)
  cout<<a[i]<<endl; //依次输出a数组即可 
	return 0;
	
}
