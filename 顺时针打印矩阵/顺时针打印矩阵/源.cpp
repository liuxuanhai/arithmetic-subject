#include<iostream>
using namespace std;
//ִ��һ��˳ʱ���ӡ�ĺ�������Ҫ�ĸ����裬��ÿһ�������Ǳ���ģ��п���ֻ��Ҫ����
void subprint(int **data,int rows,int columns,int start)
{
	int endx=columns-1-start;
	int endy=rows-1-start;
	//��һ���������Ҵ�ӡ,��һ������ִ��
	for(int i=start;i<=endx;i++)
	{
		int number=data[start][i];
		cout<<"	"<<number;
	}
	//�ڶ��������ϵ��´�ӡ�����������ٰ�������
	for(int i=start+1;i<=endy;i++)
	{
		cout<<"	"<<data[i][endx];
	}
	//�����������������ӡ�����������ٰ�����������
	for(int i=endx-1;i>=start;--i)
	{
		cout<<"	"<<data[endy][i];
	}
	//���Ĳ������µ��ϴ�ӡ�����������ٰ�����������
	for(int i=endy-1;i>=start+1;--i)
	{
		cout<<"	"<<data[i][start];
	}
}
//����ʵ��
void print(int **data,int rows,int columns)
{
	try
	{
		if(data==NULL||rows<=0||columns<=0)
			throw new exception("��������");
		int start=0;
		//һ��˳ʱ���ӡ��������rows>2*start && columns>2*start
		while(rows>2*start && columns>2*start)
		{
			subprint(data,rows,columns,start);
			start++;
		}
	}
	catch(exception e)
	{
		cerr<<e.what()<<endl;
	}
}
int main()
{
	int data[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int *p[4];//ָ�����飬ʵ����һ�����飬������ÿһ��Ԫ����һ��ָ��
	//��ָ�����鸳ֵ
	for(int i=0;i<4;i++)
	{
		p[i]=data[i];
	}
	print(p,4,4);

	////����ָ�룬ʵ����ָ�������ָ�룬��һ��ָ��
	//int (*p2)[4];//p2��ָ�� ��4��Ԫ�ص����� ��ָ��
	////����ָ��ĳ�ʼ��
	//p2=data;//dataΪ0�з�����ĵ�ַ��������ֵ��p2ָ�룬����data==&data[0]��������&data[0]��ֵ��p2Ҳ��һ����
	//p2=&data[0];

	return 0;
}