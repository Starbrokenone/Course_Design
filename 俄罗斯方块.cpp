#include<iostream>
using namespace std;

int main()
{
    int a[16][10];  //�����һ���Ž����� 1����ֹ��Ϊ���²�Ϊ0���µĴ�͸���̡�
    int b[4][4]; 
    int zuo[4][2];  //���ڴ洢�ĸ�1���ڵ����ꡣ
    int s = 0;  //�����������ʱ����ȡ�������� 4*2 ����
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
    bool flag=false;  //���ֹͣ��־λ�����ڴ��ѭ�����á�
    int stopraw=1;
    for(int i=0;i<15;i++)
    {
        if(flag)
            break;
        else
        {
            for(int j=0 ;j<4;++j)
            {
                if(a[stopraw+zuo[j][0]][column+zuo[j][1]-1]==1)  //�����Ե�λ������1�ˡ�??����ô����һ����������λflag����ѭ���˳���
                {
                    flag=true;
                    --stopraw;
                }
            }
            ++stopraw;
        }
    }
    --stopraw;
    for(int i=0;i<4;++i)  //��λԭ�е�����λ�ã�ˢ�����̲��֡�
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
