#include<iostream>
using namespace std;
//��Ϊһ��intռ4���ֽڣ�32λ���������λ��ʼѭ��32����ͳ��1�ĸ���
int find(int n)
{
	int count=0;
	unsigned int temp=1;
	while(temp)
	{
		if(temp & n)
			count++;
		temp=temp<<1;//temp����һλ�������Ʊ��10���жϵڶ�λ�Ƿ�Ϊ1
	}
	return count;
}
//һ������һ�ٺͱ����� �����㣬�൱�ڽ�����������Ƶ����ұߵ�1��Ϊ0���ж��ٸ�1��ѭ������
int find2(int n)
{
	int count=0;
	while(n)
	{
		count++;
		n=(n-1) & n;//���ұߵ�1��Ϊ0��1�ĸ���count++
	}
	return count;
}
int main()
{
	cout<<find(2)<<endl;
	cout<<find(-2)<<endl;//�����ڼ���������Բ������ʽ��ʾ����-2��ʾΪ��2��ԭ��ȡ��+1�����λΪ1
	cout<<find2(2)<<endl;
	cout<<find2(-2)<<endl;
	return 0;
}