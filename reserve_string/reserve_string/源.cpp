#include<iostream>
#include<vector>
#define SPACE ' '
using namespace std;
void str_reserve(char *str)
{
	vector<char> vec;//�����洢��ת����ַ���
	char *head=str;
	char *last=str+strlen(str)-1;
	char *q=last;
	while(q!=head)//�ж��Ƿ񵽴�ͷ���
	{
		while(*q!=SPACE && q!=head)
		{
			q--;
		}
		if(q==head)
			break;
		char *temp=q+1;
		while(temp!=last)
		{
			vec.push_back(*temp++);
		}
		vec.push_back(*last);
		vec.push_back(SPACE);
		//ָ���ƶ����ո�ǰһ���ĵ���β��
		q--;
		last=q;
	}
	//Ҫ��ǰ��ĵ���Ҳ����vec��
	while(last!=q)
	{
		vec.push_back(*q++);
	}
	vec.push_back(*last);
	//��vec�д�ķ�ת�������´���ԭ�����ַ���
	vector<char>::iterator it;
	head=str;
	for(it=vec.begin();it!=vec.end();it++)
	{
		*head++ = (*it);
	}
}
int main()
{
	char str[]="tom is cat";
	str_reserve(str);
	cout<<str<<endl;
	return 0;
}