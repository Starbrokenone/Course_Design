# 太原理工大学程序设计课程设计

# 1.      学生排队

1.1【问题描述】

体育老师小明要将自己班上的学生按顺序排队。他首先让学生按学号从小到大的顺序排成一排，学号小的排在前面，然后进行多次调整。一次调整小明可能让一位同学出队，向前或者向后移动一段距离后再插入队列。

　　例如，下面给出了一组移动的例子，例子中学生的人数为8人。

　　0）初始队列中学生的学号依次为1, 2, 3, 4, 5, 6, 7, 8；

　　1）第一次调整，命令为“3号同学向后移动2”，表示3号同学出队，向后移动2名同学的距离，再插入到队列中，新队列中学生的学号依次为1, 2, 4, 5, 3, 6, 7, 8；

　　2）第二次调整，命令为“8号同学向前移动3”，表示8号同学出队，向前移动3名同学的距离，再插入到队列中，新队列中学生的学号依次为1, 2, 4, 5, 8, 3, 6, 7；

　　3）第三次调整，命令为“3号同学向前移动2”，表示3号同学出队，向前移动2名同学的距离，再插入到队列中，新队列中学生的学号依次为1, 2, 4, 3, 5, 8, 6, 7。

　　小明记录了所有调整的过程，请问，最终从前向后所有学生的学号依次是多少？

　　请特别注意，上述移动过程中所涉及的号码指的是学号，而不是在队伍中的位置。在向后移动时，移动的距离不超过对应同学后面的人数，如果向后移动的距离正好等于对应同学后面的人数则该同学会移动到队列的最后面。在向前移动时，移动的距离不超过对应同学前面的人数，如果向前移动的距离正好等于对应同学前面的人数则该同学会移动到队列的最前面。

**输入格式**

输入的第一行包含一个整数n，表示学生的数量，学生的学号由1到n编号。

　　第二行包含一个整数m，表示调整的次数。

　　接下来m行，每行两个整数p, q，如果q为正，表示学号为p的同学向后移动q，如果q为负，表示学号为p的同学向前移动-q。

**输出格式**

输出一行，包含n个整数，相邻两个整数之间由一个空格分隔，表示最终从前向后所有学生的学号。

1.2【测试数据】

| **输入：**                | **输出：**      |
| ------------------------- | --------------- |
| 8   3   3 2   8 -3   3 -2 | 1 2 4 3 5 8 6 7 |
| 7   2   3 2   5 -3        | 1 5 2 4 3 6 7   |

 

1.3【问题分析】

​    该程序采用的数据结构为数组，数组a[]用于存储各个所在的位置上的学生（学号），a[i]=s表示学生s位于位置i。查找是顺序查找，若i位置的同学向后移动q则将数组中的该同学后q位同学向前移动一位，然后再将i同学放在数组中空出来的位置.

1.4【运行结果】

![img](file:///C:/Users/张利云/AppData/Local/Temp/msohtmlclip1/01/clip_image004.jpg)

# 2.      俄罗斯方块

2.1【问题描述】

　俄罗斯方块是俄罗斯人阿列克谢·帕基特诺夫发明的一款休闲游戏。

　　游戏在一个15行10列的方格图上进行，方格图上的每一个格子可能已经放置了方块，或者没有放置方块。每一轮，都会有一个新的由4个小方块组成的板块从方格图的上方落下，玩家可以操作板块左右移动放到合适的位置，当板块中某一个方块的下边缘与方格图上的方块上边缘重合或者达到下边界时，板块不再移动，如果此时方格图的某一行全放满了方块，则该行被消除并得分。

　　在这个问题中，你需要写一个程序来模拟板块下落，你不需要处理玩家的操作，也不需要处理消行和得分。

　　具体的，给定一个初始的方格图，以及一个板块的形状和它下落的初始位置，你要给出最终的方格图。

2.2【基本要求】

**输入数据格式：**

输入的前15行包含初始的方格图，每行包含10个数字，相邻的数字用空格分隔。如果一个数字是0，表示对应的方格中没有方块，如果数字是1，则表示初始的时候有方块。输入保证前4行中的数字都是0。

　　输入的第16至第19行包含新加入的板块的形状，每行包含4个数字，组成了板块图案，同样0表示没方块，1表示有方块。输入保证板块的图案中正好包含4个方块，且4个方块是连在一起的（准确的说，4个方块是四连通的，即给定的板块是俄罗斯方块的标准板块）。

　　第20行包含一个1到7之间的整数，表示板块图案最左边开始的时候是在方格图的哪一列中。注意，这里的板块图案指的是16至19行所输入的板块图案，如果板块图案的最左边一列全是0，则它的左边和实际所表示的板块的左边是不一致的（见样例）

**输出数据格式：**

输出15行，每行10个数字，相邻的数字之间用一个空格分隔，表示板块下落后的方格图。注意，你不需要处理最终的消行。

2.3【问题分析】

该程序采用数组数据结构，输入4 * 4的矩阵后，因为系统限定只要四个格子是1，故提取出来四个1所在的位置，组成一个4 * 2的二维数组，在模拟下落过程中，只需要对4 * 2数组中所存储的坐标进行四点排查，如果四个点所在的棋盘坐标都没有1，那么就继续下落，如果有一个地方是1，就代表着已经碰到了。接触到了原先棋盘中的1，所以此时就需要退一步，--stopraw就是这一步，然后既然知道了stopraw，那么就可以把原来的存储在4 * 2数组中的相对坐标位置进行置1，完成本次下落。

2.4【测试数据】

| **输入：**                                                   | **输出：**                                                   |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| 0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 1 0 0   0 0 0 0 0 0 1 0 0 0   0 0 0 0 0 0 1 0 0 0   1 1 1 0 0 0 1 1 1 1   0 0 0 0 1 0 0 0 0 0   0 0 0 0   0 1 1 1   0 0 0 1   0 0 0 0   3 | 0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 1 0 0   0 0 0 0 0 0 1 0 0 0   0 0 0 0 0 0 1 0 0 0   1 1 1 1 1 1 1 1 1 1   0 0 0 0 1 1 0 0 0 0 |

2.5【运行结果】

![img](file:///C:/Users/张利云/AppData/Local/Temp/msohtmlclip1/01/clip_image006.jpg)



# 3.      文本文件单词统计

3.1【问题描述】

假设有如下的英文文本文档：（文件名是：Happiness.txt）

What Is Happiness

Most of us probably don’t believe we need a formal definition of happiness; we know it

when we feel it, and we often use the term to describe a range of positive emotions,

including joy, pride, contentment, and gratitude.

But to understand the causes and effects of happiness, researchers first need to define

it. Many of them use the term interchangeably with “subjective well-being,” which they

measure by simply asking people to report how satisfied they feel with their own lives and

how much positive and negative emotion they’re experiencing. In her 2007 book The How

of Happiness, positive psychology researcher Sonja Lyubomirsky elaborates, describing

happiness as “the experience of joy, contentment, or positive well being, combined with a

sense that one’s life is good, meaningful, and worthwhile.”

That definition resonates with us here at Greater Good: It captures the fleeting positive

emotions that come with happiness, along with a deeper sense of meaning and purpose in

life and suggests how these emotions and sense of meaning reinforce one another.

设计 C 或 C++程序，统计在这样的英文文本文件中，出现了多少个单词（不区分大小写），每个单词

出现了几次。连续的英文字符都认为是单词(不包括数字)，单词之间用空格或标点符号分隔。

3.2【设计需求及分析】

要统计英文文本文件中出现了哪些单词，就要从文件中读取字符，读取出来的连续英文字符认为是一个单词，遇空格或标点符号单词结束。

使用线性表记录单词以及每个单词出现的次数。线性表中的单词按字典顺序存储。

**线性表的顺序存储结构如下：（必须使用如下定义的存储结构，否则无效）**

\#define LIST_INIT_SIZE 100    //线性表存储空间的初始分配量

\#define LISTINCREMENT 10      //线性表存储空间的分配增量

typedef struct{

​    char word[21]             //存储单词，不超过20个字符

​    int count;                //单词出现的次数

} ElemType;                   //顺序表元素类型

typedef struct{

​    ElemType *elem;           //存储空间基址

​    int length;               //当前长度

int listsize;             //当前分配的存储容量

​    } Seqlist;                    //顺序表类型

**/\*****插入顺序表\*/**

**int ListInsert(Sqlist &L,int i,char \*s){**

​    **int j;**

​    **if(L.length>=L.listsize)         //****当前存储已满，增加空间**

​    **{**

 

​       **ElemType \*newbase;**

​       **newbase =(ElemType\*) realloc(L.elem,(L.listsize+LISTINCREMENT)\*sizeof(ElemType));**

 

​       **if(!newbase){**

​           **printf("exdepend fail!!");**

​           **exit(OVERFLOW);**

​       **}**

​       **L.elem=newbase;**

​       **L.listsize += LISTINCREMENT;        //****增加存储容量**

​    **}**

 

​    **for(j=L.length;j>=i;j--)**

​      **L.elem[j]=L.elem[j-1];**

 

​    **strcpy(L.elem[i-1].word,s);**

​    **L.elem[i-1].count=1;**

​    **++L.length;**

​    **return OK;**

**}**

**/\*****在顺序表中查找单词\*/**

**int LocateElem(Sqlist &L,char \*s)**

**{**

​    **int end=L.length;**

​    **int begin=0,mid;**

​    **int j=0;**

​    **while(begin<=end)        //****折半查找**

​    **{**

​       **mid=(begin+end)/2;**

​       **if(strcmp(L.elem[mid].word,s)==0)**

​       **{**

​           **++L.elem[mid].count;**

​           **return 0;**

​       **}**

​       **else**

​       **{**

​           **if (strcmp(L.elem[mid].word,s)>0)**

​           **{**

​              **end=mid-1;**

​           **}**

​           **if (strcmp(L.elem[mid].word,s)<0)**

​           **{**   

​              **begin=mid+1;**

​           **}**

​       **}**

 

​    **}**

​    **return begin+1;**

**}**

**/\*****输出函数\*/**

**int PrintList(Sqlist &L,int count){**

​    **FILE \*fw1;**

​    **fw1=fopen("****张利云.txt","w");**

​    **fprintf(fw1,"****总单词数量为%d\n",count);**

​    **//int sum;**

​    **for(int i=0;i<L.length;i++)**

​    **{**

​       **fprintf(fw1,"%s** **的数量为:  \t",L.elem[i].word);**

​       **fprintf(fw1,"%d \n",L.elem[i].count);**

​       **//sum+=sum+L.elem[i].count;**

​    **}**

​    **//fprintf(fw1,"****总单词数量为%d\n",sum);**

​    **fclose(fw1);**

​    **return 0;**

**}**

3.3【用例及结果】

![img](file:///C:/Users/张利云/AppData/Local/Temp/msohtmlclip1/01/clip_image008.jpg)

![img](file:///C:/Users/张利云/AppData/Local/Temp/msohtmlclip1/01/clip_image010.jpg)

# 4.      分数的加减乘除

4.1【问题描述】

用分数形式表示的有理数类如下：

class Rational{

private:

int x,y; //成员变量 x 和 y，分别存放分子和分母

public:

Rational(int a=1,int b=1);  //具有默认参数的构造函数，默认值为 1

Rational Add(Rational &r); //求两个分数的和

Rational Sub(Rational &r);  //求两个分数的差

Rational Mul(Rational &r); //求两个分数的积

Rational Div(Rational &r); //求两个分数的商

Rational operator+(Rational &r); //重载“+”运算符，求两个分数的和

Rational operator-(Rational &r); //重载“-”运算符，求两个分数的差

Rational operator*(Rational &r); //重载“*”运算符，求两个分数的积

Rational operator/(Rational &r); //重载“/”运算符，求两个分数的商

int Divisor(int a,int b); //求最大公约数

friend ostream& operator<<(ostream &output,Rational &r); //以 x/y 的形式输出分数

};

4.2【基本要求】

1.成员变量 x 和 y，分别存放分子和分母, 要求分数以最简形式存放。例如：分数 2/4 应简化为 1/2。

2.定义成员函数 Add、Sub、Mul 和 Div，求两个分数的和差积商。计算结果仍以最简形式存放。

3.重载运算符“+、-、*、/”，求两个分数的和差积商。计算结果仍以最简形式存放。

4.定义友元函数，重载“<<”运算符，以 x/y 的形式输出分数。例如，有如下的主函数：

int main(){

Rational a(5,15),b(1,-2),c;

![img](file:///C:/Users/张利云/AppData/Local/Temp/msohtmlclip1/01/clip_image012.jpg)cout<<"a="<<a<<endl;

cout<<"b="<<b<<endl;

c=a.Add(b); //c=a+b;

cout<<"a+b="<<c<<endl;

c=a.Sub(b); //c=a-b;

cout<<"a-b="<<c<<endl; 

c=a.Mul(b); //c=a*b;

cout<<"a*b="<<c<<endl;

c=a.Div(b); //c=a/b;

cout<<"a/b="<<c<<endl;

}

运行结果如图 4-1 所示： 

 

5.5【运行结果】

![img](file:///C:/Users/张利云/AppData/Local/Temp/msohtmlclip1/01/clip_image014.jpg)

# 5.      送货

5.1【问题描述】

为了增加公司收入，F 公司新开设了物流业务。由于 F 公司在业界的良好口碑，物流业务一开通即受到了消费者的欢迎，物流业务马上遍及了城市的每条街道。然而，F 公司现在只安排了小明一个人负责所有街道的服务。任务虽然繁重，但是小明有足够的信心，他拿到了城市的地图，准备研究最好的方案。城市中有 n 个交叉路口，m 条街道连接在这些交叉路口之间，每条街道的首尾都正好连接着一个交叉路口。除开街道的首尾端点，街道不会在其他位置与其他街道相交。每个交叉路口都至少连接着一条街道，有的交叉路口可能只连接着一条或两条街道。

5.2【基本要求】

小明希望设计一个方案，从编号为 1 的交叉路口出发，每次必须沿街道去往街道另一端的路口，再从新的路口出发去往下一个路口，直到所有的街道都经过了正好一次。

**输入格式**

输入的第一行包含两个整数 n, m(1≤n≤10, n-1≤m≤20)，表示交叉路口的数量和街道的数量，交叉路口从 1 到 n 标号。

接下来 m 行，每行两个整数 a, b，表示和标号为 a 的交叉路口和标号为 b 的交叉路口之间有一条街道，街道是双向的，小明可以从任意一端走向另一端。两个路口之间最多有一条街道。

**输出格式**

如果小明可以经过每条街道正好一次，则输出一行包含 m+1 个整数 p1, p2, p3, ..., pm+1，表示小明经过的路口的顺序，相邻两个整数之间用一个空格分隔。如果有多种方案满足条件，则输出字典序最小的一种方案，即首先保证 p1 最小，p1 最小的前提下再保证 p2 最小，依此类推。

如果不存在方案使得小明经过每条街道正好一次，则输出一个整数-1。

5.3【测试数据】

**测试数据一：**

| **输入：**                        | **输出：**  |
| --------------------------------- | ----------- |
| 4 5   1 2   1 3   1 4   2 4   3 4 | 1 2 4 1 3 4 |

输出说明 ：城市的地图和小明的路径如图 5-1 所示。

![img](file:///C:/Users/张利云/AppData/Local/Temp/msohtmlclip1/01/clip_image016.jpg)

**测试数据二：**

| **输入：**                              | **输出：** |
| --------------------------------------- | ---------- |
| 4 6   1 2   1 3   1 4   2 4   3 4   2 3 | -1         |

输出说明 ：城市的地图如图 5-2 所示，不存在满足条件的路径。

5.4【问题分析】

​    一笔画问题， 也就是求欧拉通路。根据欧拉定理， 对于这样一个无向连通图， 如果所有节点的度数都是偶数（情况1），那么这个图从任意点出发都一笔画； 如果有两个节点的度数是奇数（情况2）， 其它节点度数为偶数， 那么从任一奇点出发能一笔画， 且终点为另一奇点。其余情况都不能一笔画。因此， 首先要判断图是不是连通的， 然后判断是不是这两种情况中的1个，不是得话直接输出-1返回。如果从1出发一定能一笔画的话， 除非遇到走不通的情况， 否则无论你怎么画都跳不出情况1和情况2。情况1画一条边，就会变成情况2， 情况2画一条边可能还是情况2，或者就是变成情况1。只有一种情况会发生改变， 那就是接下来要画的边的另一端度数是1的时候， 这样画下去会使得新的起点变成与图的其它部分分隔的单点， 就再也走不通了。这时候， 我们不能画这条边， 但根据欧拉定理，图明明又是能够一笔画的， 这就说明这条边只能最后画。 于是我们可以直接把这条边去掉， 把另一端的顶点压栈， 作为一笔画的最后一点。如此类推， 当出现这种情况时就把点压栈。最后，再弹出来， 就可以得到一个一笔画的顶点序列。而且， 我们发现这个过程其实就是dfs的过程。即dfs的逆后序列就是一个一笔画的序列。至于要字典序最小，只需要事先对邻接表按升序排序即可。

5.5【**运行结果**】

![img](file:///C:/Users/张利云/AppData/Local/Temp/msohtmlclip1/01/clip_image018.jpg)

![img](file:///C:/Users/张利云/AppData/Local/Temp/msohtmlclip1/01/clip_image020.jpg)

# 6.      学生信息管理系统

1.1【问题描述】

大学里有各种类型的学生，校方需要对这些学生的信息进行计算机管理。所开发的软件应包括各类

学生的添加、修改、删除和查找等功能。考虑到软件的可重用性、可扩展性和可维护性，校方决定采用面向对象的程序设计方法来开发系统。学生信息需要以文件方式保存到计算机硬盘中。另外，系统的用户界面应该尽可能友好，方便用户使用。

1.2【设计及需求分析】

(1) 使用 C++语言开发，充分利用面向对象程序设计的类、对象、继承、封装和多态性等概念来设计和实现该管理系统。

(2) 设计一个 Person（人员）类，考虑到通用性，只抽象出所有类型人员都具有的属性：name（姓名）,id（身份证号），gender（性别），birthday（出生日期）等等。其中“出生日期”为内嵌子对象，是一个 Date（日期）类型，Date 类具有属性: year(年)，month（月），day（日）。用成员函数实现对人员信息的录入和显示等必要功能操作。

(3) 从 Person 类派生出 Student（学生）类，添加属性： studentNo（学号），schoolName（学校），classIn(班级)。从 Person 类派生出 Teacher（教师）类，添加属性：teacherNo（教师编号），schoolName（学校），department（部门）。

(4) 从 Student 类中派生出 UnderGraduate（本科生）类，添加属性：major（专业）。从 Student 类中派生出 Graduate（研究生）类，添加属性：direction（研究方向），adviserName（导师姓名）。

(5) 从 Graduate 类和 Teacher 类派生出 TＡ（助教博士生）类。

(6) 写程序测试上述各类，看能否正常运行。

(7) 构建必要的辅助类，实现对本科生、研究生和助教博士生的添加、修改、删除、查询管理。

(8) 根据需要定义类的构造函数、析构函数、拷贝构造函数、成员函数。必要时重载函数。

(9) 要求将 Person 类设置为虚基类，以消除其派生类成员访问的二义性问题（注意在虚基类各级派生类的构造函数实现时调用虚基类的构造函数）。

(10) 要求在 Person 类中定义虚函数 displayDetails（），用于显示当前对象的信息；同时定义虚函数inputData( )，用于从键盘获取当前对象的信息。Person 类所有派生类也要定义同名虚函数，使程序可以实现动态多态性。

(11) 用菜单方式设计主控模块程序。

(12) 对程序源代码要给出各部分的详细注释，这也是该题目的考核重点之一。

(13) 用 UML 语言描述系统用到的类及其关系。

1.3【运行结果】

![img](file:///C:/Users/张利云/AppData/Local/Temp/msohtmlclip1/01/clip_image022.jpg)
