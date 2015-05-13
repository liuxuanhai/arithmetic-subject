#include<iostream>
using namespace std;
double GetPower(double base,double exp);
bool equals(double number1,double number2);
double  Power(double base,int exponent)
{
	try
	{
		//0�ĸ�ָ���˻����Ϸ�
		if(equals(base,0.0)&&exponent<0)
		{
			throw exception("��������ȷ��");
		}
		unsigned int exp=(unsigned int)exponent;
		//���ָ���Ǹ���������ת��nΪ�������ڼ���a^n,�������
		if(exponent<0)
			exp=(unsigned int)(-exponent);
		//��base^exp,expΪ������
		double result=GetPower(base,exp);
		//���ָ��Ϊ����������
		if(exponent<0)
			result=1/result;
		return result;
	}
	catch(exception e)
	{
		cerr<<e.what()<<endl;
	}
}
//�ݹ�ʵ��
double Power2(double base,int exponent)
{
	try
	{
		//0�ĸ�ָ���˻����Ϸ�
		if(equals(base,0.0)&&exponent<=0)
		{
			throw exception("��������ȷ��");
		}
		//�ݹ鷵������
		if(exponent==0)
			return 1;
		if(exponent==1)
			return base;
		if(exponent==-1)
			return 1/base;
		double result=Power2(base,exponent>>1);//�ݹ����n/2�η�
		result*=result;//base��exponent�η�=��base��exponent/2�η���*��base��exponent/2�η���
		if(exponent&1==1)//ָ��Ϊ����ʱ
			result*=base;//base��exponent�η�=��base��exponent/2�η���*��base��exponent/2�η���*base
		return result;
	}
	catch(exception e)
	{
		cerr<<e.what()<<endl;
	}
}
//a^n��ʵ��
double GetPower(double base,double exp)
{
	double result=1.0;
	for(int i=0;i<exp;i++)
		result*=base;
	return result;
}
//�ж�����double�����Ƿ���ȣ�������==�жϣ���Ϊ�������ʾС����float��double���������
bool equals(double number1,double number2)
{
	if(number1-number2>-0.00000001&&number1-number2<0.0000001)
		return true;
	else
		return false;
}
int main()
{ 
	cout<<"ʹ�õ�һ�ַ�����"<<endl;
	cout<<"2^3="<<Power(2,3)<<endl;
	cout<<"0^-3="<<Power(0,-3)<<endl;
	cout<<"2^-3="<<Power(2,-3)<<endl;
	cout<<"ʹ�õڶ��ַ�����"<<endl;
	cout<<"-2^3="<<Power2(-2,3)<<endl;
	cout<<"-2^-3="<<Power2(-2,-3)<<endl;
	return 0;
}