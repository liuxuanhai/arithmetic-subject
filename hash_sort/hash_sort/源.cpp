#include<iostream>
using namespace std;
void sortages(int ages[],int length)
{
	if(ages==NULL||length<=0)
		throw exception("��������");
	const int large=99;
	int countage[large+1];//���屣���������������
	//��ʼ��countage
	for(int i=0;i<=large;i++)
		countage[i]=0;
	//Ϊcountage����ֵ
	for(int i=0;i<length;i++)
	{
		if(ages[i]<0||ages[i]>99)
			throw exception("����������������");
		++countage[ages[i]];//����ages[i]���൱��hash����������ages���鱾�����countage����ĵ�ַ
	}
	int index=0;//ages���±�
	//ages���澭������������
	for(int i=18;i<60;i++)//18-60�������
	{
		for(int j=0;j<countage[i];j++)//�м����͸�ֵ����
		{
			ages[index]=i;
			index++;
		}
	}
}
//��ӡ����
void print(int ages[],int length)
{
	for(int i=0;i<length;i++)
	{
		cout<<" "<<ages[i];
	}
}
int main()
{
	int ages[10]={18,29,34,19,54,24,32,35,55,47};
	sortages(ages,10);
	print(ages,10);
	return 0;
}