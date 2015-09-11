#include<iostream>
#include<stack>
using namespace std;
void ChangeNumber(int sum,int N)
{
	if(N>16||N<0)
	{
		cout<<"进制输入有误！";
		return;
	}
	char flag=NULL;
	if(sum<0)
	{
		flag='-';
		sum=abs(sum);
	}
	stack<int> s;
	int yu=sum%N;
	int x=sum/N;
	while(x>0)
	{
		sum=x;
		s.push(yu);
		yu=sum%N;
		x=sum/N;
	}
	s.push(yu);
	//打印N进制元素
	if(flag=='-')
		cout<<flag;
	while(!s.empty())
	{
		int temp=s.top();
		s.pop();
		cout<<temp;
	}
	cout<<endl;
}
int main()
{
	ChangeNumber(-17,8);
	return 0;
}