#include<iostream>
using namespace std;
bool isorder(int *data,int length)
{
	//�жϱ߽�����
	if(data==NULL||length<=0)
	{
		return false;
	}
	//������ڵ�ֵ
	int root=data[length-1];
	//�ҵ���һ�����ڸ��ڵ��ֵ�������ֵ�����ڸ��ڵ㣬���򷵻�false
	int i=0;
	for(;i<length-1;i++)
	{
		if(root<data[i])
			break;
	}
	for(int j=i+1;j<length-1;j++)
	{
		//���i֮���������һ��С�ڸ��ڵ㣬������������������false
		if(data[j]<root)
			return false;
	}
	//�����������������ݹ��ж�������
	bool left=true;
	if(i>0)
	{
		left=isorder(data,i);
	}
	//����������������ݹ��ж�������
	bool right=true;
	if(i<length-1)
	{
		right=isorder(data+i,length-i-1);
	}
	return left&&right;
}
int main()
{
	int data[]={5,7,6,9,11,10,8};
	cout<<"�Ƿ��Ƕ����������ĺ��������"<<(isorder(data,7)?"true":"false")<<endl;
	return 0;
}