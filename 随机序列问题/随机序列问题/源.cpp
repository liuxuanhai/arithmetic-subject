#include<iostream>
#include<ctime>
using namespace std;
//���彻������Ԫ�غ���
void ss(int a[],int x,int len)
{
	if(x!=len)
	{
		int temp=a[x];
		a[x]=a[len];
		a[len]=temp;
	}
}
//����������е�ʵ��
int* Rfan(int a[],int length)
{
	int len=length-1;
	while(len>0)
	{
		srand((int)time(NULL));//ʱ������
		int x=rand()%(len+1);//���������
		ss(a,x,len);
		len--;
	}
	return a;
}

int main()
{
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	int *b=Rfan(a,10);
	for(int i=0;i<10;i++)
	{
		cout<<b[i]<<endl;
	}
}