#include<iostream>
using namespace std;
//����˵��
//atoi()��ɨ�����s�ַ���������ǰ��Ŀո��ַ���ֱ���������ֻ��������Ųſ�ʼ��ת�������� ���������ֻ��ַ�������ʱ('/0')�Ž���ת��������������ء�
//����ֵ������ת�������������
int atoi(const char *s)
{
	int i=0,flag=1,result=0;
	while(isspace(s[i]))
		i++;
	if(s[i]=='-')
	{
		flag=-1;
		i++;
	}
	while(isdigit(s[i]))
	{
		result=result*10+(s[i]-'0');
		i++;
	}
	result*=flag;
	return result;
}
int main()
{
	char s[]="    -123";
	int res=atoi(s);
	cout<<res<<endl;
	return 0;
}   