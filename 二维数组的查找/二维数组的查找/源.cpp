#include<iostream>
using namespace std;
bool find(int *data,int rows,int columns,int key)//int *data����ά����ת��Ϊһά���飬ָ���ά�����һ�����ĵ�ַ
{
	bool result=false;
	if(data!=NULL&&rows>0&&columns>0)//�жϲ����Ƿ�Ϸ�
	{
		int row=0,column=columns-1;//�����ұ߿�ʼ�Ƚ�
		while(row<rows&&column>=0)
		{
			if(data[row*columns+column]==key)//�ҵ�
			{
				result=true;
				break;
			}
			else if(data[row*columns+column]>key)//Ҫ���ҵ�ֵС�����ұߵ�������ȥ���ұߵ���
			{
				column--;
			}
			else//Ҫ���ҵ�ֵ�������ұߵ�������ȥ���ϱߵ�һ��
				row++;
		}
	}
	return result;
}
int main()
{
	int a[4][4]={1,2,8,9,2,4,8,12,4,7,10,13,6,8,11,15};
	//int (*p)[4]=a;
	cout<<find(*a,4,4,7)<<endl;//a[4][4]��һ����ά���飬��a����ָ���һ���������ָ�룬�����ֽ�Ϊ4��int��ռ�ֽ�����*4����������Ԫ�صĸ�����=16���ֽڣ���˲��ܸ�ֵ��int *��4���ֽڣ�����*a,a[0],&a[0][0]�������ά�����һ�����ĵ�ַ��4���ֽڣ�
	return 0;
}