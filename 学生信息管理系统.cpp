#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef struct StuBasic{//������Ϣ
    int stunum;//ѧ��
    string name;
    string sex;
    string dornum;//�������
    string tel;//�绰(��λ)
}StuB;
typedef struct StuResult{//�ɼ���Ϣ
    int stunum;//ѧ��
    string counum;//�γ̺�
    string cou;//�γ�
    float cre;//ѧ��
    float ures;//ƽʱ�ɼ�
    float tres;//ʵ��ɼ�
    float pres;//�Ծ�ɼ�
    float tolres;//�ܳɼ�
    float tolcre;//��ѧ��
}StuR;
StuB stub[1001];
StuR stur[1001];
 
/**��������**/
int AddTolRes(StuR stu);//�����ܳɼ�
int AddTolCre(StuR stu);//������ѧ��
 
int InsertStuBas();//¼��ѧ��������Ϣ
int InsertStuRes();//¼��ѧ���ɼ���Ϣ
 
int SelectAllA();//��ѯA.txt�����ݵ�stub[]
int SelectAllB();//��ѯB.txt�����ݵ�stur[]
int SelectStuBNum();//��ѯ������Ϣ����(��ѧ��)
int SelectStuDro();//��ѯ���ắ��
int SelectStuRNum();//��ѯ�ɼ�(��ѧ��)
int SelectStuRAll();//��ѯȫ��
int SelectStuBAll();//��ѯȫ��
 
StuB S2Stub(string s);//���ļ���ȡ��ѧ��������Ϣ���ŵ�Stub��
StuR S2Stur(string s);//���ļ���ȡ��ѧ���ɼ���Ϣ���ŵ�Stur��
 
int DeleteStu();//ɾ��һ��ѧ����Ϣ
int DeleteDro(string dor);//ɾ��һ��������Ϣ
 
int UpdateStuB();//�޸Ļ�����Ϣ(��ѧ��)
int UpdateStuR();//�޸ĳɼ���Ϣ(��ѧ��)
 
int compare(StuR s1,StuR s2);//����ȽϺ���
int SortStu();//������
 
int main()
{
    cout<<endl<<endl;
 
    cout<<"     *********************************************************"<<endl<<endl
        <<"       ****************��ӭʹ��ѧ������ϵͳ********************"<<endl<<endl;
    cout<<"     *********************************************************"<<endl<<endl; 
 
   
    int key;    char ch;
    do{
        cout<<"         **********���˵�:                   **********"<<endl
            <<"         **********      1��¼��ѧ����Ϣ     **********"<<endl
            <<"         **********      2����ѯѧ����Ϣ     **********"<<endl
            <<"         **********      3��ɾ��ѧ����Ϣ     **********"<<endl
            <<"         **********      4���޸�ѧ����Ϣ     **********"<<endl
            <<"         **********      5������ѧ����Ϣ     **********"<<endl
            <<"         **********      0���˳�ϵͳ         **********"<<endl<<endl;
        cout<<"����������:";
        cin>>key;
        while(key<0&&key>5){
            cout<<"�������,����������:";
            cin>>key;
        }
        if(key==0) break;
        switch (key){
            case 1://1��¼��ѧ����Ϣ
                do{
                    cout<<"     1.¼��ѧ��������Ϣ"<<endl;
                    cout<<"     2.¼��ѧ���ɼ���Ϣ"<<endl;
                    int key1;
                    cout<<"��ѡ��:";
                    cin>>key1;
                    while(key1!=1&&key1!=2){
                        cout<<"�������,����������:";
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
                    cout<<"����y������ǰ����,����n(������)������һ��:";
                    cin>>ch;
                }while(ch=='y');
            break;
            case 2:{//2����ѯѧ����Ϣ
                do{
                    cout<<"     1.��ѯѧ��������Ϣ(֧��ѧ�ź�����)"<<endl;
                    cout<<"     2.��ѯѧ���ɼ���Ϣ(ֻ֧��ѧ�Ų�ѯ)"<<endl;
                    int key1;
                    cout<<"��ѡ��:";
                    cin>>key1;
                    while(key1!=1&&key1!=2){
                        cout<<"�������,����������:";
                        cin>>key1;
                    }
                    switch (key1){
                    case 1:{
                        do{
                            cout<<"     1.��ѧ�Ų�ѯ"<<endl;
                            cout<<"     2.�����ҺŲ�ѯ"<<endl;
                            cout<<"     3.��ѯȫ��"<<endl;
                            int key1;
                            cout<<"��ѡ��:";
                            cin>>key1;
                            while(key1!=1&&key1!=2&&key1!=3){
                                cout<<"�������,����������:";
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
                            cout<<"����y������ǰ����,����n(������)������һ��,0�������˵�:";
                            cin>>ch;
                         }while(ch=='y');
                    break;
                    }
                    case 2:{
                        do{
                            cout<<"     1.��ѧ�Ų�ѯ"<<endl;
                            cout<<"     2.��ѯȫ��"<<endl;
                            int key1;
                            cout<<"��ѡ��:";
                            cin>>key1;
                            while(key1!=1&&key1!=2){
                                cout<<"�������,����������:";
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
                            cout<<"����y������ǰ����,����n(������)������һ��,0�������˵�:";
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
                cout<<"����y������ǰ����,����n�������˵�:";
                cin>>c;
            }while(c=='y');
        break;
        }
 
        case 4://1���޸�ѧ����Ϣ
            do{
                cout<<"     1.�޸�ѧ��������Ϣ"<<endl;
                cout<<"     2.�޸�ѧ���ɼ���Ϣ"<<endl;
                int key1;
                cout<<"��ѡ��:";
                cin>>key1;
                while(key1!=1&&key1!=2){
                    cout<<"�������,����������:";
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
                cout<<"����y������ǰ����,����n(������)������һ��:";
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
    cout<<"������ѧ������:";
    cin>>n;
    for(i=0;i<n;i++){
 
        cout<<"����ѧ��:";
        cin>>stub[i].stunum;
 
        cout<<"��������:";
        cin>>stub[i].name;
 
        cout<<"�����Ա�:";
        cin>>stub[i].sex;
 
        cout<<"�������Һ�:";
        cin>>stub[i].dornum;
 
        cout<<"����绰:";
        cin>>stub[i].tel;
    }
    for(i=0;i<n;i++){
        afile.open("A.txt",ios::in|ios::out|ios::app);//��д��׷�ӵķ�ʽд���ļ�
        afile<<stub[i].stunum<<" "<<stub[i].name<<" "
             <<stub[i].sex<<" "<<stub[i].dornum<<" "
             <<stub[i].tel<<endl;
        afile.close();//�ر��ļ�
        afile.clear();//����ļ���
    }
    return 0;
}
 
int InsertStuRes()
{
    fstream bfile;
    //s.c_str();
    //infile.open("B.txt",ios::in||ios::out|ios::app);
    int n,i;
    cout<<"������ѧ������:";
    cin>>n;
    for(i=0;i<n;i++){
        cout<<"����ѧ��:";
        cin>>stur[i].stunum;
 
        cout<<"����γ̺�:";
        //string counum;//�γ̺�
        cin>>stur[i].counum;
 
        cout<<"����γ�:";
        //string cou;//�γ�
        cin>>stur[i].cou;
 
        cout<<"����ѧ��:";
        //int cre;//ѧ��
        cin>>stur[i].cre;
 
        cout<<"����ƽʱ�ɼ�:";
        //int ures;//ƽʱ�ɼ�
        cin>>stur[i].ures;
 
        cout<<"����ʵ��ɼ�:";
        //int tres;//ʵ��ɼ�
        cin>>stur[i].tres;
 
        cout<<"�Ծ�ɼ�:";
        //int pres;//�Ծ�ɼ�
        cin>>stur[i].pres;
 
        float tolres;//�ܳɼ�
        float tolcre;//��ѧ��
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
        bfile.open("B.txt",ios::in|ios::out|ios::app);//��д��׷�ӵķ�ʽд���ļ�
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
 
int SelectStuBNum()//��ѯ������Ϣ����(��ѧ��)
{
    //StuB stb[50];
    int k=SelectAllA();//��A�ļ����ڴ�
    int num;
    cout<<"�������ѯѧ��:";
    cin>>num;
    cout<<" ѧ��  "<<" ����  "<<" �Ա�  "<<" ����  "<<" �绰  "<<endl;
    //cout<<" ѧ��  "<<" ����  "<<" �Ա�  "<<" ����  "<<" �绰  "<<endl;
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
    if(ok==0) cout<<" �����������,���Ժ�������!"<<endl;
    return 0;
}
int SelectStuDro()//��ѯ���ắ��
{
    //StuB stb[50];
    int k=SelectAllA();//��A�ļ����ڴ�
    string s1;
    cout<<"�������ѯ���Һ�:";
    cin>>s1;
    cout<<" ѧ��  "<<" ����  "<<" �Ա�  "<<" ����  "<<" �绰  "<<endl;
    //cout<<" ѧ��  "<<"  ����  "<<"  �Ա�  "<<"  ����  "<<"  �绰  "<<endl;
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
    if(ok==0) cout<<" �������������,���Ժ�������!"<<endl;
    return 0;
}
 
int SelectStuBAll()//��ѯ���л�����Ϣ
{
    //StuB stb[50];
    int k=SelectAllA();//��A�ļ����ڴ�
    cout<<" ѧ��  "<<" ����  "<<" �Ա�  "<<" ����  "<<" �绰  "<<endl;
    for(int i=0;i<k;i++){
        cout<<"  "<<stub[i].stunum<<" ";
        cout<<"  "<<stub[i].name<<" ";
        cout<<"  "<<stub[i].sex<<" ";
        cout<<"  "<<stub[i].dornum<<" ";
        cout<<"  "<<stub[i].tel<<endl;
    }
    return 0;
}
int SelectStuRNum()//��ѯ�ɼ�(��ѧ��)
{
    //StuR str[50];
    int k=SelectAllB();
    int num;
    cout<<"�������ѯѧ��:";
    cin>>num;
    cout<<" ѧ��"<<" �γ̺�"<<" �γ�"<<" ѧ��"
        <<" ƽʱ�ɼ�"<<" ʵ��ɼ�"<<" �Ծ�ɼ�"
        <<" �ܳɼ�"<<" ��ѧ��"<<endl;
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
    if(ok==0) cout<<" �����������,���Ժ�������!"<<endl;
    return 0;
}
 
int SelectStuRAll()//��ѯ����
{
    //StuR str[50];
    int k=SelectAllB();
    cout<<" ѧ��"<<" �γ̺�"<<" �γ�"<<" ѧ��"
        <<" ƽʱ�ɼ�"<<" ʵ��ɼ�"<<" �Ծ�ɼ�"
        <<" �ܳɼ�"<<" ��ѧ��"<<endl;
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
    cout<<"������ɾ����ѧ��:";
    cin>>num;
    int k1=SelectAllA();
    int k2=SelectAllB();
    fstream afile;
    fstream bfile;
    afile.open("A.txt",ios::out);//д�ķ�ʽд���ļ�
    for(int i=0;i<k1;i++){
        //cout<<stub[i].stunum<<endl;
        if(stub[i].stunum!=num){
            afile<<stub[i].stunum<<" "<<stub[i].name<<" "
                <<stub[i].sex<<" "<<stub[i].dornum<<" "
                <<stub[i].tel<<endl;
            }
    }
    afile.close();//�ر��ļ�
    afile.clear();//����ļ���
 
    bfile.open("B.txt",ios::out);//��д�ķ�ʽд���ļ�
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
    cout<<"ɾ���ɹ�!"<<endl;
    return 0;
}
 
int compare(StuR s1,StuR s2)//����ȽϺ���
{
    if(s1.tolres>s2.tolres) return 1;
    else return 0;
}
int SortStu()//������(�ܳɼ�))
{
    int k2=SelectAllB();
    fstream bfile;
    sort(stur,stur+k2,compare);
    bfile.open("B.txt");//��д��׷�ӵķ�ʽд���ļ�
    for(int i=0;i<k2;i++){
       bfile<<stur[i].stunum<<" "<<stur[i].counum<<" "
             <<stur[i].cou<<" "<<stur[i].cre<<" "
             <<stur[i].ures<<" "<<stur[i].tres<<" "
             <<stur[i].pres<<" "<<stur[i].tolres<<" "
             <<stur[i].tolcre<<endl;
    }
    bfile.close();
    bfile.clear();
    cout<<"�������,���س��������˵�!";
    return 0;
}
 
int UpdateStuB()
{
    int num;
    cout<<"�������޸ĵ�ѧ��:";
    cin>>num;
    int k1=SelectAllA();
    //int k2=SelectAllB();
    fstream afile;
    //fstream bfile;
    afile.open("A.txt",ios::out);//��д�ķ�ʽд���ļ�
    for(int i=0;i<k1;i++){
        //cout<<stub[i].stunum<<endl;
        if(stub[i].stunum==num){
            /**
            cout<<"����ѧ��:";
            cin>>stub[i].stunum;
            **/
            cout<<"��������:";
            string name;
            cin>>name;
            stub[i].name=name;
 
            cout<<"�����Ա�:";
            string sex;
            cin>>sex;
            stub[i].sex=sex;
 
            cout<<"�������Һ�:";
            string dornum;
            cin>>dornum;
            stub[i].dornum=num;
 
            cout<<"����绰:";
            string tel;
            cin>>tel;
            stub[i].tel=tel;
        }
        afile<<stub[i].stunum<<" "<<stub[i].name<<" "
             <<stub[i].sex<<" "<<stub[i].dornum<<" "
             <<stub[i].tel<<endl;
    }
    cout<<"�޸ĳɹ���"<<endl;
    afile.close();//�ر��ļ�
    afile.clear();//����ļ���
    return 0;
}
 
int UpdateStuR()
{
    int num;
    cout<<"�������޸ĵ�ѧ��:";
    cin>>num;
    //int k1=SelectAllA();
    int k2=SelectAllB();
    //fstream afile;
    fstream bfile;
    bfile.open("B.txt",ios::out);//��д�ķ�ʽд���ļ�
    for(int i=0;i<k2;i++){
        //cout<<stur[i].stunum<<endl;
        if(stur[i].stunum==num){
            /**
            cout<<"����ѧ��:";
            cin>>stur[i].stunum;
            **/
            cout<<"����γ̺�:";
            string counum;//�γ̺�
            cin>>counum;
            stur[i].counum=counum;
 
            cout<<"����γ�:";
            string cou;//�γ�
            cin>>cou;
            stur[i].cou=cou;
 
            cout<<"����ѧ��:";
            float cre;//ѧ��
            cin>>cre;
            stur[i].cre=cre;
 
            cout<<"����ƽʱ�ɼ�:";
            float ures;//ƽʱ�ɼ�
            cin>>ures;
            stur[i].ures=ures;
 
            cout<<"����ʵ��ɼ�:";
            float tres;//ʵ��ɼ�
            cin>>tres;
            stur[i].tres=tres;
 
            cout<<"�Ծ�ɼ�:";
            float pres;//�Ծ�ɼ�
            cin>>pres;
            stur[i].pres=pres;
 
            float tolres;//�ܳɼ�
            float tolcre;//��ѧ��
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
    cout<<"�޸ĳɹ���"<<endl;
    bfile.close();
    bfile.clear();
 
    return 0;
}


