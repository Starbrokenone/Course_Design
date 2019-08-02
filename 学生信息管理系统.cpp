#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef struct StuBasic{//基本信息
    int stunum;//学号
    string name;
    string sex;
    string dornum;//宿舍号码
    string tel;//电话(七位)
}StuB;
typedef struct StuResult{//成绩信息
    int stunum;//学号
    string counum;//课程号
    string cou;//课程
    float cre;//学分
    float ures;//平时成绩
    float tres;//实验成绩
    float pres;//试卷成绩
    float tolres;//总成绩
    float tolcre;//总学分
}StuR;
StuB stub[1001];
StuR stur[1001];
 
/**函数定义**/
int AddTolRes(StuR stu);//计算总成绩
int AddTolCre(StuR stu);//计算总学分
 
int InsertStuBas();//录入学生基本信息
int InsertStuRes();//录入学生成绩信息
 
int SelectAllA();//查询A.txt的内容到stub[]
int SelectAllB();//查询B.txt的内容到stur[]
int SelectStuBNum();//查询基本信息函数(按学号)
int SelectStuDro();//查询宿舍函数
int SelectStuRNum();//查询成绩(按学号)
int SelectStuRAll();//查询全部
int SelectStuBAll();//查询全部
 
StuB S2Stub(string s);//从文件中取出学生基本信息并放到Stub中
StuR S2Stur(string s);//从文件中取出学生成绩信息并放到Stur中
 
int DeleteStu();//删除一个学生信息
int DeleteDro(string dor);//删除一个寝室信息
 
int UpdateStuB();//修改基本信息(按学号)
int UpdateStuR();//修改成绩信息(按学号)
 
int compare(StuR s1,StuR s2);//排序比较函数
int SortStu();//排序函数
 
int main()
{
    cout<<endl<<endl;
 
    cout<<"     *********************************************************"<<endl<<endl
        <<"       ****************欢迎使用学生管理系统********************"<<endl<<endl;
    cout<<"     *********************************************************"<<endl<<endl; 
 
   
    int key;    char ch;
    do{
        cout<<"         **********主菜单:                   **********"<<endl
            <<"         **********      1、录入学生信息     **********"<<endl
            <<"         **********      2、查询学生信息     **********"<<endl
            <<"         **********      3、删除学生信息     **********"<<endl
            <<"         **********      4、修改学生信息     **********"<<endl
            <<"         **********      5、排序学生信息     **********"<<endl
            <<"         **********      0、退出系统         **********"<<endl<<endl;
        cout<<"输入访问序号:";
        cin>>key;
        while(key<0&&key>5){
            cout<<"输入错误,请重新输入:";
            cin>>key;
        }
        if(key==0) break;
        switch (key){
            case 1://1、录入学生信息
                do{
                    cout<<"     1.录入学生基本信息"<<endl;
                    cout<<"     2.录入学生成绩信息"<<endl;
                    int key1;
                    cout<<"请选择:";
                    cin>>key1;
                    while(key1!=1&&key1!=2){
                        cout<<"输入错误,请重新输入:";
                        cin>>key1;
                    }
                    switch (key1){
                    case 1:
                        InsertStuBas();
                        break;
                    case 2:{
                        InsertStuRes();
                        break;
                    }
                    default :
                        break;
                    }
                    cout<<"输入y继续当前操作,输入n(或其他)返回上一层:";
                    cin>>ch;
                }while(ch=='y');
            break;
            case 2:{//2、查询学生信息
                do{
                    cout<<"     1.查询学生基本信息(支持学号和寝室)"<<endl;
                    cout<<"     2.查询学生成绩信息(只支持学号查询)"<<endl;
                    int key1;
                    cout<<"请选择:";
                    cin>>key1;
                    while(key1!=1&&key1!=2){
                        cout<<"输入错误,请重新输入:";
                        cin>>key1;
                    }
                    switch (key1){
                    case 1:{
                        do{
                            cout<<"     1.按学号查询"<<endl;
                            cout<<"     2.按寝室号查询"<<endl;
                            cout<<"     3.查询全部"<<endl;
                            int key1;
                            cout<<"请选择:";
                            cin>>key1;
                            while(key1!=1&&key1!=2&&key1!=3){
                                cout<<"输入错误,请重新输入:";
                                cin>>key1;
                            }
                            switch (key1){
                            case 1:
                                SelectStuBNum();
                            break;
                            case 2:
                                SelectStuDro();
                            break;
                            case 3:
                                SelectStuBAll();
                            break;
                            default :break;
                            }
                            cout<<"输入y继续当前操作,输入n(或其他)返回上一层,0返回主菜单:";
                            cin>>ch;
                         }while(ch=='y');
                    break;
                    }
                    case 2:{
                        do{
                            cout<<"     1.按学号查询"<<endl;
                            cout<<"     2.查询全部"<<endl;
                            int key1;
                            cout<<"请选择:";
                            cin>>key1;
                            while(key1!=1&&key1!=2){
                                cout<<"输入错误,请重新输入:";
                                cin>>key1;
                            }
                            switch (key1){
                            case 1:
                                SelectStuRNum();
                            break;
                            case 2:
                                SelectStuRAll();
                            break;
                            default :break;
                            }
                            cout<<"输入y继续当前操作,输入n(或其他)返回上一层,0返回主菜单:";
                            cin>>ch;
                         }while(ch=='y');
                        break;
                    }
                    default :
                        break;
                    }
                }while(ch=='n');
            break;
        }
        case 3:{
            char c;
            do{
                DeleteStu();
                cout<<"输入y继续当前操作,输入n返回主菜单:";
                cin>>c;
            }while(c=='y');
        break;
        }
 
        case 4://1、修改学生信息
            do{
                cout<<"     1.修改学生基本信息"<<endl;
                cout<<"     2.修改学生成绩信息"<<endl;
                int key1;
                cout<<"请选择:";
                cin>>key1;
                while(key1!=1&&key1!=2){
                    cout<<"输入错误,请重新输入:";
                    cin>>key1;
                }
                switch (key1){
                    case 1:
                        UpdateStuB();
                    break;
                    case 2:{
                        UpdateStuR();
                        break;
                    }
                    default :
                        break;
                }
                cout<<"输入y继续当前操作,输入n(或其他)返回上一层:";
                cin>>ch;
            }while(ch=='y');
        break;
 
        case 5:{
            SortStu();
            getchar();
            getchar();
        break;
        }
        case 0:
            break;
        }
 
    }while(key||ch=='0');
    return 0;
}
 
int InsertStuBas()
{
    fstream afile;
    int n,i;
    cout<<"请输入学生个数:";
    cin>>n;
    for(i=0;i<n;i++){
 
        cout<<"输入学号:";
        cin>>stub[i].stunum;
 
        cout<<"输入姓名:";
        cin>>stub[i].name;
 
        cout<<"输入性别:";
        cin>>stub[i].sex;
 
        cout<<"输入寝室号:";
        cin>>stub[i].dornum;
 
        cout<<"输入电话:";
        cin>>stub[i].tel;
    }
    for(i=0;i<n;i++){
        afile.open("A.txt",ios::in|ios::out|ios::app);//读写、追加的方式写入文件
        afile<<stub[i].stunum<<" "<<stub[i].name<<" "
             <<stub[i].sex<<" "<<stub[i].dornum<<" "
             <<stub[i].tel<<endl;
        afile.close();//关闭文件
        afile.clear();//清空文件流
    }
    return 0;
}
 
int InsertStuRes()
{
    fstream bfile;
    //s.c_str();
    //infile.open("B.txt",ios::in||ios::out|ios::app);
    int n,i;
    cout<<"请输入学生个数:";
    cin>>n;
    for(i=0;i<n;i++){
        cout<<"输入学号:";
        cin>>stur[i].stunum;
 
        cout<<"输入课程号:";
        //string counum;//课程号
        cin>>stur[i].counum;
 
        cout<<"输入课程:";
        //string cou;//课程
        cin>>stur[i].cou;
 
        cout<<"输入学分:";
        //int cre;//学分
        cin>>stur[i].cre;
 
        cout<<"输入平时成绩:";
        //int ures;//平时成绩
        cin>>stur[i].ures;
 
        cout<<"输入实验成绩:";
        //int tres;//实验成绩
        cin>>stur[i].tres;
 
        cout<<"试卷成绩:";
        //int pres;//试卷成绩
        cin>>stur[i].pres;
 
        float tolres;//总成绩
        float tolcre;//总学分
        if(stur[i].tres==-1){
            tolres=stur[i].pres*0.7+stur[i].ures*0.3;
        }else{
            tolres=stur[i].pres*0.7+stur[i].ures*0.15+stur[i].tres*0.15;
        }
        stur[i].tolres=tolres;
        //cout<<stur[i].tolres<<endl;
        if(tolres>=90&&tolres<=100){
            tolcre=stur[i].cre;
        }else if(tolres>=80&&tolres<90){
            tolcre=stur[i].cre*0.8;
        }else if(tolres>=70&&tolres<80){
            tolcre=stur[i].cre*0.75;
        }else if(tolres>=60&&tolres<70){
            tolcre=stur[i].cre*0.6;
        }else{
            tolcre=0;
        }
        stur[i].tolcre=tolcre;
        //cout<<stur[i].tolcre<<endl;
    }
    for(i=0;i<n;i++){
        bfile.open("B.txt",ios::in|ios::out|ios::app);//读写、追加的方式写入文件
        bfile<<stur[i].stunum<<" "<<stur[i].counum<<" "
             <<stur[i].cou<<" "<<stur[i].cre<<" "
             <<stur[i].ures<<" "<<stur[i].tres<<" "
             <<stur[i].pres<<" "<<stur[i].tolres<<" "
             <<stur[i].tolcre<<endl;
        bfile.close();
        bfile.clear();
    }
    return 0;
}
 
StuB S2Stub(string s)
{
    StuB stub;
    string stemp[10];
    int k=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=' '){
            stemp[k]+=s[i];
        }else{
            ++k;
        }
    }
    stub.stunum=atoi(stemp[0].c_str());
    stub.name=stemp[1];
    stub.sex=stemp[2];
    stub.dornum=stemp[3];
    stub.tel=stemp[4];
    return stub;
}
 
StuR S2Stur(string s)
{
    StuR stur;
    string stemp[10];
    int k=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=' '){
            stemp[k]+=s[i];
        }else{
            ++k;
        }
    }
    stur.stunum=atoi(stemp[0].c_str());
    stur.counum=stemp[1];
    stur.cou=stemp[2];
    stur.cre=atof(stemp[3].c_str());
    stur.ures=atof(stemp[4].c_str());
    stur.tres=atof(stemp[5].c_str());
    stur.pres=atof(stemp[6].c_str());
    stur.tolres=atof(stemp[7].c_str());
    stur.tolcre=atof(stemp[8].c_str());
 
    return stur;
}
 
int SelectStuBNum()//查询基本信息函数(按学号)
{
    //StuB stb[50];
    int k=SelectAllA();//读A文件到内存
    int num;
    cout<<"请输入查询学号:";
    cin>>num;
    cout<<" 学号  "<<" 姓名  "<<" 性别  "<<" 寝室  "<<" 电话  "<<endl;
    //cout<<" 学号  "<<" 姓名  "<<" 性别  "<<" 寝室  "<<" 电话  "<<endl;
    int ok=0;
    for(int i=0;i<k;i++){
        if(stub[i].stunum==num){
            ok=1;
            cout<<"  "<<stub[i].stunum<<" ";
            cout<<"  "<<stub[i].name<<" ";
            cout<<"  "<<stub[i].sex<<" ";
            cout<<"  "<<stub[i].dornum<<" ";
            cout<<"  "<<stub[i].tel<<endl;
            break;
        }
    }
    if(ok==0) cout<<" 不存在这个人,请查对后在输入!"<<endl;
    return 0;
}
int SelectStuDro()//查询宿舍函数
{
    //StuB stb[50];
    int k=SelectAllA();//读A文件到内存
    string s1;
    cout<<"请输入查询寝室号:";
    cin>>s1;
    cout<<" 学号  "<<" 姓名  "<<" 性别  "<<" 寝室  "<<" 电话  "<<endl;
    //cout<<" 学号  "<<"  姓名  "<<"  性别  "<<"  寝室  "<<"  电话  "<<endl;
    int ok=0;
    for(int i=0;i<k;i++){
        if(stub[i].dornum==s1){
            ok=1;
            cout<<"  "<<stub[i].stunum<<" ";
            cout<<"  "<<stub[i].name<<" ";
            cout<<"  "<<stub[i].sex<<" ";
            cout<<"  "<<stub[i].dornum<<" ";
            cout<<"  "<<stub[i].tel<<endl;
        }
    }
    if(ok==0) cout<<" 不存在这个寝室,请查对后在输入!"<<endl;
    return 0;
}
 
int SelectStuBAll()//查询所有基本信息
{
    //StuB stb[50];
    int k=SelectAllA();//读A文件到内存
    cout<<" 学号  "<<" 姓名  "<<" 性别  "<<" 寝室  "<<" 电话  "<<endl;
    for(int i=0;i<k;i++){
        cout<<"  "<<stub[i].stunum<<" ";
        cout<<"  "<<stub[i].name<<" ";
        cout<<"  "<<stub[i].sex<<" ";
        cout<<"  "<<stub[i].dornum<<" ";
        cout<<"  "<<stub[i].tel<<endl;
    }
    return 0;
}
int SelectStuRNum()//查询成绩(按学号)
{
    //StuR str[50];
    int k=SelectAllB();
    int num;
    cout<<"请输入查询学号:";
    cin>>num;
    cout<<" 学号"<<" 课程号"<<" 课程"<<" 学分"
        <<" 平时成绩"<<" 实验成绩"<<" 试卷成绩"
        <<" 总成绩"<<" 总学分"<<endl;
    int ok=0;
    for(int i=0;i<k;i++){
        if(num==stur[i].stunum){
            ok=1;
            cout<<"  "<<stur[i].stunum<<"   ";
            cout<<" "<<stur[i].counum<<" ";
            cout<<" "<<stur[i].cou<<"  ";
            cout<<" "<<stur[i].cre<<"    ";
            cout<<" "<<stur[i].ures<<"    ";
            cout<<"    "<<stur[i].tres<<"      ";
            cout<<" "<<stur[i].pres<<"    ";
            cout<<" "<<stur[i].tolres<<"    ";
            cout<<" "<<stur[i].tolcre<<endl;
        }
        //break;
    }
    if(ok==0) cout<<" 不存在这个人,请查对后在输入!"<<endl;
    return 0;
}
 
int SelectStuRAll()//查询所有
{
    //StuR str[50];
    int k=SelectAllB();
    cout<<" 学号"<<" 课程号"<<" 课程"<<" 学分"
        <<" 平时成绩"<<" 实验成绩"<<" 试卷成绩"
        <<" 总成绩"<<" 总学分"<<endl;
    for(int i=0;i<k;i++){
        cout<<"  "<<stur[i].stunum<<"   ";
        cout<<" "<<stur[i].counum<<" ";
        cout<<" "<<stur[i].cou<<"  ";
        cout<<" "<<stur[i].cre<<"    ";
        cout<<" "<<stur[i].ures<<"    ";
        cout<<"    "<<stur[i].tres<<"      ";
        cout<<" "<<stur[i].pres<<"    ";
        cout<<" "<<stur[i].tolres<<"    ";
        cout<<" "<<stur[i].tolcre<<endl;
        //break;
    }
    return 0;
}
 
int SelectAllA()
{
    fstream afile("A.txt");
    int k=0;    string s;
    while(getline(afile,s)){
        stub[k++]=S2Stub(s);
        //cout<<S2Stub(s).stunum<<endl;
        //cout<<stb[k-1].stunum<<endl;
    }
    return k;
}
 
int SelectAllB()
{
    fstream bfile("B.txt");
    int k=0;
    string s;
    while(getline(bfile,s)){
        stur[k++]=S2Stur(s);
        //cout<<str[k-1].stunum<<endl;
    }
    return k;
}
 
int DeleteStu()
{
    int num;
    cout<<"请输入删除的学号:";
    cin>>num;
    int k1=SelectAllA();
    int k2=SelectAllB();
    fstream afile;
    fstream bfile;
    afile.open("A.txt",ios::out);//写的方式写入文件
    for(int i=0;i<k1;i++){
        //cout<<stub[i].stunum<<endl;
        if(stub[i].stunum!=num){
            afile<<stub[i].stunum<<" "<<stub[i].name<<" "
                <<stub[i].sex<<" "<<stub[i].dornum<<" "
                <<stub[i].tel<<endl;
            }
    }
    afile.close();//关闭文件
    afile.clear();//清空文件流
 
    bfile.open("B.txt",ios::out);//读写的方式写入文件
    for(int i=0;i<k2;i++){
        //cout<<stur[i].stunum<<endl;
        if(stur[i].stunum!=num){
            bfile<<stur[i].stunum<<" "<<stur[i].counum<<" "
                <<stur[i].cou<<" "<<stur[i].cre<<" "
                <<stur[i].ures<<" "<<stur[i].tres<<" "
                <<stur[i].pres<<" "<<stur[i].tolres<<" "
                <<stur[i].tolcre<<endl;
        }
    }
    bfile.close();
    bfile.clear();
    cout<<"删除成功!"<<endl;
    return 0;
}
 
int compare(StuR s1,StuR s2)//排序比较函数
{
    if(s1.tolres>s2.tolres) return 1;
    else return 0;
}
int SortStu()//排序函数(总成绩))
{
    int k2=SelectAllB();
    fstream bfile;
    sort(stur,stur+k2,compare);
    bfile.open("B.txt");//读写、追加的方式写入文件
    for(int i=0;i<k2;i++){
       bfile<<stur[i].stunum<<" "<<stur[i].counum<<" "
             <<stur[i].cou<<" "<<stur[i].cre<<" "
             <<stur[i].ures<<" "<<stur[i].tres<<" "
             <<stur[i].pres<<" "<<stur[i].tolres<<" "
             <<stur[i].tolcre<<endl;
    }
    bfile.close();
    bfile.clear();
    cout<<"排序完成,按回车返回主菜单!";
    return 0;
}
 
int UpdateStuB()
{
    int num;
    cout<<"请输入修改的学号:";
    cin>>num;
    int k1=SelectAllA();
    //int k2=SelectAllB();
    fstream afile;
    //fstream bfile;
    afile.open("A.txt",ios::out);//读写的方式写入文件
    for(int i=0;i<k1;i++){
        //cout<<stub[i].stunum<<endl;
        if(stub[i].stunum==num){
            /**
            cout<<"输入学号:";
            cin>>stub[i].stunum;
            **/
            cout<<"输入姓名:";
            string name;
            cin>>name;
            stub[i].name=name;
 
            cout<<"输入性别:";
            string sex;
            cin>>sex;
            stub[i].sex=sex;
 
            cout<<"输入寝室号:";
            string dornum;
            cin>>dornum;
            stub[i].dornum=num;
 
            cout<<"输入电话:";
            string tel;
            cin>>tel;
            stub[i].tel=tel;
        }
        afile<<stub[i].stunum<<" "<<stub[i].name<<" "
             <<stub[i].sex<<" "<<stub[i].dornum<<" "
             <<stub[i].tel<<endl;
    }
    cout<<"修改成功！"<<endl;
    afile.close();//关闭文件
    afile.clear();//清空文件流
    return 0;
}
 
int UpdateStuR()
{
    int num;
    cout<<"请输入修改的学号:";
    cin>>num;
    //int k1=SelectAllA();
    int k2=SelectAllB();
    //fstream afile;
    fstream bfile;
    bfile.open("B.txt",ios::out);//读写的方式写入文件
    for(int i=0;i<k2;i++){
        //cout<<stur[i].stunum<<endl;
        if(stur[i].stunum==num){
            /**
            cout<<"输入学号:";
            cin>>stur[i].stunum;
            **/
            cout<<"输入课程号:";
            string counum;//课程号
            cin>>counum;
            stur[i].counum=counum;
 
            cout<<"输入课程:";
            string cou;//课程
            cin>>cou;
            stur[i].cou=cou;
 
            cout<<"输入学分:";
            float cre;//学分
            cin>>cre;
            stur[i].cre=cre;
 
            cout<<"输入平时成绩:";
            float ures;//平时成绩
            cin>>ures;
            stur[i].ures=ures;
 
            cout<<"输入实验成绩:";
            float tres;//实验成绩
            cin>>tres;
            stur[i].tres=tres;
 
            cout<<"试卷成绩:";
            float pres;//试卷成绩
            cin>>pres;
            stur[i].pres=pres;
 
            float tolres;//总成绩
            float tolcre;//总学分
            if(stur[i].tres==-1){
                tolres=stur[i].pres*0.7+stur[i].ures*0.3;
            }else{
                tolres=stur[i].pres*0.7+stur[i].ures*0.15+stur[i].tres*0.15;
            }
            stur[i].tolres=tolres;
            //cout<<stur[i].tolres<<endl;
            if(tolres>=90&&tolres<=100){
                tolcre=stur[i].cre;
            }else if(tolres>=80&&tolres<90){
                tolcre=stur[i].cre*0.8;
            }else if(tolres>=70&&tolres<80){
                tolcre=stur[i].cre*0.75;
            }else if(tolres>=60&&tolres<70){
                tolcre=stur[i].cre*0.6;
            }else{
                tolcre=0;
            }
            stur[i].tolcre=tolcre;
 
            }
        bfile<<stur[i].stunum<<" "<<stur[i].counum<<" "
            <<stur[i].cou<<" "<<stur[i].cre<<" "
            <<stur[i].ures<<" "<<stur[i].tres<<" "
            <<stur[i].pres<<" "<<stur[i].tolres<<" "
            <<stur[i].tolcre<<endl;
    }
    cout<<"修改成功！"<<endl;
    bfile.close();
    bfile.clear();
 
    return 0;
}


