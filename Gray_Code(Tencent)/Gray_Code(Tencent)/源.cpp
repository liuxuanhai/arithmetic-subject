#include<iostream>
#include<string>
using namespace std;
int GetLength(string *str)
{
	int count=0;
	while(str)
	{
		count++;
		str++;
	}
	return count;
}
string* GrayCode(int n)
{
	int length=pow(2,n);
	string *str=new string[length];//nλ��������2^n������
	//����������һλ������Ϊ��0���͡�1��
	if(n==1)
	{
		str[0]="0";
		str[1]="1";
		return str;
	}
	string* last = GrayCode(n-1);
	//��lastǰ����ӡ�0���͡�1�������ҳ������λ�⣬����λ���ϵ��¶��ǶԳƵģ�����nΪ������������n-1λ�������2��()
	for(int i=0;i<length;i++)
	{
		str[i]="0"+last[i];//�ֱ��ԭ���ĸ��������0��1���ɣ�0��ԭ����������ӣ�1��ԭ������ĶԳ�λ�����
		str[length-1]="1"+last[i];
	}

	return str;
}
int main()
{
	string *str=GrayCode(2);
	for(int i=0;i<4;i++)
	{
		cout<<str[i]<<endl;
	}
	delete str;
	str=NULL;
	return 0;
}