#include<iostream>
using namespace std;

int main()
{
    int a[16][10];  //在最后一横排进行置 1，防止因为最下层为0导致的穿透棋盘。
    int b[4][4]; 
    int zuo[4][2];  //用于存储四个1所在的坐标。
    int s = 0;  //用于在输入的时候提取坐标输入 4*2 数组
    int column,x;  
    for(int i=0;i<15;++i)
        for(int j=0;j<10;++j)
        {
            cin>>x;
            a[i][j]=x;
        }
    for(int i;i<10;++i)
        a[15][i]=1;
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
        {
            cin>>x;
            b[i][j]=x;
            if(x==1)  
            {
                zuo[s][0]=i;
                zuo[s][1]=j;
                ++s;
            }
        }
    cin>>column;
    bool flag=false;  //设计停止标志位。用于打断循环所用。
    int stopraw=1;
    for(int i=0;i<15;i++)
    {
        if(flag)
            break;
        else
        {
            for(int j=0 ;j<4;++j)
            {
                if(a[stopraw+zuo[j][0]][column+zuo[j][1]-1]==1)  //如果相对的位置上有1了。??，那么就退一步，并且置位flag进行循环退出。
                {
                    flag=true;
                    --stopraw;
                }
            }
            ++stopraw;
        }
    }
    --stopraw;
    for(int i=0;i<4;++i)  //置位原有的棋盘位置，刷新棋盘布局。
        a[stopraw+zuo[i][0]][column+zuo[i][1]-1]=1;
    
    for(int i=0;i<15;++i)
    {
        for(int j=0;j<10;++j)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
