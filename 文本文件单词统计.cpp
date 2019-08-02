#include "stdio.h"
#include "stdlib.h"
#include "string.h"


#define LIST_INIT_SIZE 100    //线性表存储空间的初始分配量
#define LISTINCREMENT 10      //线性表存储空间的分配增量
#define OK 1
#define OVERFLOW -2
#define ERROR -1



typedef struct{
    char word[21];            //存储单词，不超过20个字符
    int count;                //单词出现的次数
}ElemType;

 //顺序表元素类型
typedef struct{
    ElemType *elem;           //存储空间基址
    int length;               //当前长度
	int listsize;             //当前分配的存储容量
} Sqlist;                    //顺序表类型

/*构造一个空的线性表L*/
int InitList(Sqlist &L){
	L.elem = (ElemType *) malloc (LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)
		exit(OVERFLOW);
	L.length=0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

/*插入顺序表*/
int ListInsert(Sqlist &L,int i,char *s){
	int j;
	if(L.length>=L.listsize)         //当前存储已满，增加空间
	{

		ElemType *newbase;
		newbase =(ElemType*) realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));

		if(!newbase){
			printf("exdepend fail!!");
			exit(OVERFLOW);
		}
		L.elem=newbase;
		L.listsize += LISTINCREMENT;        //增加存储容量

	}

	for(j=L.length;j>=i;j--)
      L.elem[j]=L.elem[j-1];

    strcpy(L.elem[i-1].word,s);
	L.elem[i-1].count=1;
	++L.length;
	return OK;
}

/*在顺序表中查找单词*/
int LocateElem(Sqlist &L,char *s)
{
	int end=L.length;
	int begin=0,mid;
	int j=0;
	while(begin<=end)        //折半查找
	{
		mid=(begin+end)/2;
		if(strcmp(L.elem[mid].word,s)==0)
		{
			++L.elem[mid].count;
			return 0;
		}
		else
		{
			if (strcmp(L.elem[mid].word,s)>0)
			{
				end=mid-1;
			}
			if (strcmp(L.elem[mid].word,s)<0)
			{	
				begin=mid+1;
			}
		}


	}
	return begin+1;
}

/*输出函数*/
int PrintList(Sqlist &L,int count){
	FILE *fw1;
	fw1=fopen("张利云.txt","w");
	fprintf(fw1,"总单词数量为%d\n",count);
	//int sum;
	for(int i=0;i<L.length;i++)
	{
		fprintf(fw1,"%s 的数量为:  \t",L.elem[i].word);
		fprintf(fw1,"%d \n",L.elem[i].count);
		//sum+=sum+L.elem[i].count;
	}
	//fprintf(fw1,"总单词数量为%d\n",sum);
	fclose(fw1);
	return 0;
}

int main()
{
	int i,j,count=0,m;
	char  s[21],ch;    //str

	FILE *fp1;
	fp1=fopen ("Happiness.txt","r");
	if(!fp1)
	{
		printf("can't open file\n");
		return -1;
	}
	Sqlist L;
	InitList(L);
	i=0;
	while((ch = fgetc(fp1)) != EOF)
	{
		if(ch>='A'&&ch<='Z'||ch>='a'&&ch<='z')
		{
			if(ch>='A'&&ch<='Z')
				ch=ch+32;
			s[i++]=ch;
			m=1;
		}
		else
		{
			if(m==1){

			s[i++]='\0';
			count++;
			i=0;
			j=LocateElem(L,s);
			if(j>0)
				ListInsert(L,j,s);
			m=0;
			}
		}
	}
	PrintList(L,count);
	fclose(fp1);    //关闭文件

	return 0;
}

