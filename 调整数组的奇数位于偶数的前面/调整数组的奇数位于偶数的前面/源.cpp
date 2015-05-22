#include<iostream>
using namespace std;
//�������ŵ�ż��ǰ���ʵ��
void tiaozheng(int *data,unsigned int length)
{
	if(data==NULL||length<=0)
		throw exception("��������");
	int *begin=data;
	int *end=data+length-1;
	//��begin�ĵ�һ��ż����end�ĵ�һ������������ֱ��begin>=end,��ʱ������������ż��ǰ��
	while(begin<end)
	{
		//beginָ�����Ϊ������begin++,��ż��������ѭ��
		while(begin<end && (*begin & 0x1)==1)
			begin++;
		//endָ�����Ϊż����end++,��������������ѭ��
		while(begin<end && (*end & 0x1)==0)
			end--;
		//���begin<end�򽻻�����������
		if(begin<end)
		{
			int temp=*begin;
			*begin=*end;
			*end=temp;
		}
	}
}
//�ж��Ƿ��������ĺ���,��������true��ż������false
bool isjishu(int x)
{
	if(x & 0x1==1)
		return true;
	else if(x & 0x1==0)
		return false;
}
//��ӡ����
void print(int *data,int length)
{
	int *begin=data;
	int count=0;
	while(count<length)
	{
		cout<<*begin<<"  ";
		begin++;
		count++;
	}
	cout<<endl;
}
//ʹ��ͨ�õ�ģ������������
void tiaozheng2(int *data,unsigned int length,bool (*func)(int))
	{
	if(data==NULL||length<=0)
		throw exception("��������");
	int *begin=data;
	int *end=data+length-1;
	//��begin�ĵ�һ��ż����end�ĵ�һ������������ֱ��begin>=end,��ʱ������������ż��ǰ��
	while(begin<end)
	{
		//beginָ�����Ϊ������begin++,��ż��������ѭ��
		while(begin<end && func(*begin))
			begin++;
		//endָ�����Ϊż����end++,��������������ѭ��
		while(begin<end && !func(*end))
			end--;
		//���begin<end�򽻻�����������
		if(begin<end)
		{
			int temp=*begin;
			*begin=*end;
			*end=temp;
		}
	}
}
int main()
{
	int data[5]={1,2,3,4,5};
	print(data,5);
	tiaozheng2(data,5,isjishu);
    print(data,5);
	return 0;
}