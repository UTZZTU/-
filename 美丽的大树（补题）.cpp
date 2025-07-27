#include <iostream>
using namespace std;
int tree_1[1000],tree_2[1000];
int hide[1000];
int main()
{
	int los;
	cin>>los;
	for(int i=1;i<=50;i++)
	{
		tree_1[i]=1;
		tree_2[i]=1;
	}
	for(int i=0;i<los;i++)
	{
		int a;
		cin>>a;
		int change;
		if(a%2==0)
		{
			change=a/2;
			tree_2[change]=0;
		}
		else if(a%2!=0)
		{
			change=(a+1)/2;
			tree_1[change]=0;
		}
		
	}
	int number=1;
	if(tree_1[number]==1)//hide[] hide the number of the lose tree.
	{
		hide[number]=0;	//the number of one is repesent the tree's sum.
	}
	if(tree_1[number]==0)
	{
		number+=2;
		hide[number]=0;
	}
	for(int i=1;i<=50;i++)
	{
		if(tree_1[i]!=0)
		{
			hide[number]++;
		}
		else if(tree_1[i]==0)
		{
			number=2*(i+1)-1;
			hide[number]=0;
		}
	}
	number=2;
	if(tree_2[number]==1)
	{
		hide[number]=0;
	}
	if(tree_2[number]==0)
	{
		number+=2;
		hide[number]=0;
	}
	for(int i=1;i<=50;i++)
	{
		if(tree_2[i]!=0)
		{
			hide[number]++;
		}
		else if(tree_2[i]==0)
		{
			number=2*(i+1);
			hide[number]=0;
		}
	}
	int max=hide[1];
	int i;
	for(i=1;i<=100;i++)
	{
		if(max<hide[i])max=hide[i];
	}
	for(int j=1;j<=100;j++)
	{
		if(max==hide[j])
		{
		cout<<j<<" ";break;	
		}
	}
	cout<<max;
	
} 