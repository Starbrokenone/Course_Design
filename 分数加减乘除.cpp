#include <iostream>
#include <cmath>
#include <stdlib.h>
 
using namespace std;
 
class Rational
{
private:
    int x,y;//����
    void normalize();//��һ���������罫2/16���1/8
public:
    Rational(int a=1,int b=1);
 	Rational Add(Rational &r){
	Rational a(x,y);	
 	return a+r;
	 } //�����������ĺ�
	Rational Sub(Rational &r){
		Rational a(x,y);	
 	return a-r;
	}  //�����������Ĳ�
	Rational Mul(Rational &r){
		Rational a(x,y);	
 	return a*r;
	}
	 //�����������Ļ�
	Rational Div(Rational &r){
		Rational a(x,y);	
 	return a/r;
	} //��������������
    Rational operator+(Rational r);//���������
    Rational operator-(Rational r);
    Rational operator*(Rational r);
    Rational operator/(Rational r);
 friend ostream& operator<<(ostream &output,Rational &r){
    if(r.x%r.y==0)
        cout<<r.x/r.y;
    else
        cout<<r.x<<'/'<<r.y;
 }
  //�� x/y ����ʽ�������
    void print();

 
};
 
Rational::Rational(int a,int b)
{
    x=a;
    y=b;
 
    normalize();
}
 
void Rational::normalize()
{
   if(y<0)
   {
       x=-x;
       y=-y;
   }
//ŷ������㷨
    int a = abs(x);
    int b = abs(y);
//�������������Լ��
    while(b>0)
    {
      int t=a%b;
      a=b;
      b=t;
    }
//���ӣ���ĸ�ֱ�������Լ�����õ����ʽ��
    x/=a;
    y/=a;
 
}
//a    c   a*d+b*c
//��  + �� = ������������
//b    d     b*d
Rational Rational::operator+(Rational r)
{
 int a=x;
 int b=y;
 int c=r.x;
 int d=r.y;
 
 int e=a*d+c*b;
 int f=b*d;
 return Rational(e,f);
}
 
Rational Rational::operator-(Rational r)
{
    r.x=-r.x;//���൱�ڼӸ���
 
    return operator+(r);
}
//a    c     a*c
//��  * �� = ������������
//b    d     b*d
Rational Rational::operator*(Rational r)
{
    int a=x;
    int b=y;
    
    int c=r.x;
    int d=r.y;
 
    int e=a*c;
    int f=b*d;
 
    return Rational(e,f);
}
//a    c     a*d
//��  / �� = ������������
//b    d     b*c
Rational Rational::operator/(Rational r)
{
    int a=x;
    int b=y;
    int c=r.x;
    int d=r.y;
 
    int e=a*d;
    int f=b*c;
 
    return Rational(e,f);
}
 
void Rational::print()
{
    if(x%y==0)
        cout<<x/y;
    else
        cout<<x<<'/'<<y;
}
int main()
{
Rational a(5,15),b(1,-2),c;
cout<<"a="<<a<<endl;
cout<<"b="<<b<<endl;
c=a.Add(b); //c=a+b;
cout<<"a+b="<<c<<endl;
c=a.Sub(b); //c=a-b;
cout<<"a-b="<<c<<endl;
c=a.Mul(b); //c=a*b;
cout<<"a*b="<<c<<endl;
c=a.Div(b); //c=a/b;
cout<<"a/b="<<c<<endl;
 
    return 0;
}
