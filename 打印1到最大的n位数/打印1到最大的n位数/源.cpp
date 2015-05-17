#include<iostream>
using namespace std;
void printnumber(char *number,int n,int index);
//���м�1�������ж��Ƿ����
bool Increment(char * number)
{
	bool isoverflow=false;//�ж��Ƿ����
	int overstack=0;//��λ��־
	int length=strlen(number);//�ַ����ĳ���
	for(int i=length-1;i>=0;i--)
	{
		int digit=number[i]-'0'+overstack;//��õ�ǰλ�ϵ�����
		//����ڸ�λ�Ļ��ͽ��м�һ
		if(i==length-1)
		{
			digit++;
		}
		//�жϼ�һ֮���Ƿ���Ҫ��λ
		if(digit>=10)
		{
			//�����ǰλ�����λ�Ļ������
			if(i==0)
			{
				isoverflow=true;
				break;
			}
			//û�����ʱ�򣬽�λ��־��ֵ1����ǰλ-=10
			else
			{
				overstack=1;
				digit-=10;
				number[i]='0'+digit;
				continue;
			}
		}
		//��1֮����Ҫ��λ����ֱ������ѭ��
		else
		{
			number[i]='0'+digit;
			break;
		}

	}
	return isoverflow;
}
//��ӡnumber�д������
void Print(char * number)
{
	bool beginprint=false;//������ǰ���0���������е�0��Ϊtrue�Ļ���һֱ��ӡ��ȥ
	int length=strlen(number);
	for(int i=0;i<length;i++)
	{
		if(number[i]!='0'&&(beginprint==false))//���������һ����0��������beginprintΪtrue����ʼ��ӡ
			beginprint=true;
		if(beginprint)
			cout<<number[i];
	}
	cout<<"  ";
}
void printtomax(int n)
{
	try
	{
		if(n<=0)
			throw exception("�������Ϸ���n>0");
		char *number=new char[n+1];

		memset(number,'0',n*sizeof(char));//�ȳ�ʼ���ڸ����һλ��ֵ��\0��
		number[n]='\0';
		while(!Increment(number))//���number��1֮��û��������ӡ������
		{
			Print(number);
		}
		delete[] number;
	}
	catch(exception e)
	{
		cerr<<e.what()<<endl;
	}
}
//�ڶ��ַ���ʵ�֣�ʹ�õݹ飩
void printtomax2(int n)
{
	try
	{
		if(n<=0)
			throw exception("�������Ϸ�");
		char *number=new char[n+1];
		number[n]='\0';
		printnumber(number,n,-1);//���õݹ鷽��
	}
	catch(exception e)
	{
		cerr<<e.what()<<endl;
	}
}
void printnumber(char *number,int n,int index)
{
	//�ж����һλ�����Ƿ��Ѿ���ֵ�������ӡ
	if(index==n-1)
	{
		Print(number);
		return;
	}
	//����ݹ鸳ֵ��ֱ���������һλ
	else
	{
		//����һλ��ʼ��0-9���θ�ֵ
		for(int i=0;i<10;i++)
		{
			number[index+1]='0'+i;
			
			printnumber(number,n,index+1);
		}
	}
}
int main()
{
	printtomax2(2);
	return 0;
}