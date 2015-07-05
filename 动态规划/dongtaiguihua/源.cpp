#include<stdio.h>
#include<stdlib.h>
#define min(a,b,c) ((a)<(b)?(a):(b))<(c)?((a)<(b)?(a):(b)):(c)
FILE *fp;
char strA[100],strB[100];//保存题中所属字符串A,B 
void getWord(void);//读取文件
int distan(void);//求最短距离
int main()
{
    int min;
    FILE *fp2;
    if((fp=fopen("F:\\A.txt","r"))==NULL)
    {
        printf("Cannot open file strike any key exit!\n");
        //getch();
        exit(1);   
    }
    else
    {
        getWord();
        min = distan();
        if((fp2=fopen("F:\\B.txt","wt"))==NULL)
        {
            printf("Cannot open file strike any key exit!\n");
            //getch();
            exit(1);   
        }
        else
        {
			printf("最小步骤为：%d\n",min);
            fprintf(fp2,"%d",min);
            fclose(fp2);
        }
        fclose(fp);
    }
    system("pause");
    return 0;
}
void getWord(void)
{
     char ch;
     int i =0;
     while((ch=fgetc(fp))!='\n')
     {
         i++;
         strA[i] = ch;
     }
     strA[0] = i;
	 
	 printf("%s\n",strA);
     i=0;
     while((ch=fgetc(fp))!=EOF)
     {
         i++;
         strB[i] = ch;
     }
     strB[0] = i;
	 printf("%s\n",strB);
}
int distan(void)
{
    int i,j,dis[100][100],suit;
    int add,dele,change;
    for(i=0;i<=strA[0];i++)
        dis[i][0] = i;
    for(j=1;j<=strB[0];j++)
        dis[0][j] = j;
    for(i=1;i<=strA[0];i++)
        for(j=1;j<=strB[0];j++)
        {
			suit = ((strA[i]==strB[j])?0:1);
            change = dis[i-1][j-1]+suit;
            dele = dis[i-1][j]+1;
            add = dis[i][j-1]+1;
            dis[i][j] = min(dele,add,change);
        }
    return dis[strA[0]][strB[0]];
}
