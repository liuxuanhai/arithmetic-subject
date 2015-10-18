#include<iostream>
using namespace std;
int main()
{
	int n,t,c;
	do{
		cin>>n>>t>>c;
	}while(c>n);
	int a[200000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int count=0;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			sum=sum+a[j];
			if(sum<t)
			{
				if(j!=i)
				{
					count++;		
				}
			}
			else
			{
				break;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}