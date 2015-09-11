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
	string *str=new string[length];//n位格雷码有2^n个数据
	//返回条件，一位格雷码为“0”和“1”
	if(n==1)
	{
		str[0]="0";
		str[1]="1";
		return str;
	}
	string* last = GrayCode(n-1);
	//给last前面添加“0”和“1”，并且除了最高位外，其余位从上到下都是对称的，并且n为格雷码数据是n-1位格雷码的2倍()
	for(int i=0;i<length;i++)
	{
		str[i]="0"+last[i];//分别给原来的格雷码添加0和1即可，0在原格雷码上添加，1在原格雷码的对称位上添加
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