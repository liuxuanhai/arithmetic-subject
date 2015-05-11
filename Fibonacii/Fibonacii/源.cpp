#include<iostream>
using namespace std;
long long Fibonacci_xunhuan(int n)
{
	if(n<0)
		throw exception("��������");
	long long start[2]={0,1};
	if(n<2)
		return start[n];
	long long first=start[0];
	long long second=start[1];
	long long result=0;
	//�����±�֮��Ϊ����������ͬʱ�����±����
	for(unsigned int i=2;i<=n;i++)
	{
		result=first+second;
		first=second;
		second=result;
	}
	return result;
}
int main()
{
	cout<<Fibonacci_xunhuan(5);
	return 0;
}