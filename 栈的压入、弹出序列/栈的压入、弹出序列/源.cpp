#include<iostream>
#include<stack>
using namespace std;
bool isorder(const int *push,const int * pop,int length)
{
	if(push!=NULL && pop!=NULL && length>0)
	{
		bool result=false;
		const int *newpush=push;
		const int *newpop=pop;
		stack<int> data;
		while(newpop-pop<length)
		{
			//���ջΪ�ջ���ջ�������治����Ҫ��������������ջ
			if(data.size()==0||*newpop!=data.top())
			{
				data.push(*newpush);
				newpush++;
				//���һ�����Ѿ���ջ
				if(newpush-push>=length)
				{
					//���ջ�������治����Ҫ��������������ʱ���һ�����Ѿ���ջ,֤�����ǳ�ջ����
					if(*newpop!=data.top())
						break;
				}
			}
			else{
				//���Ҫ���������ֺ�ջ��Ԫ��һ�£���ջ����
				data.pop();
				newpop++;
			}
		}
		//���ջΪ�ղ��ҵ������е���ĩβ����֤���ǳ�ջ����
		if(newpop-pop==length && data.size()==0)
			result=true;
		return result;
	}
}
int main()
{
	int a[5]={1,2,3,4,5};
	int b[5]={4,5,3,2,1};
	int c[5]={4,3,5,1,2};
	cout<<isorder(a,b,5)<<endl;
	cout<<isorder(a,c,5)<<endl;
	return 0;
}