#include<iostream>
using namespace std;
class DB;
 
class DM
{
    int m;
    double cm;
    public:
        void input()
        {
            cout<<"Enter distance in meter and centimeter : ";
            cin>>m>>cm;
        }
        void show()
        {
            cout<<"\nDistance = "<<m<<" m & "<<cm<<" cm\n";
        }
         
        int getm()
        {
            return m;
        }
        double getcm()
        {
            return cm;
        }
        friend DM add(DM,DB);
};
 
class DB
{
    int ft;
    double in;
    public:
        DB()
        {
            ft = 0;
			in = 0;
        }
        DB(DM dm)
        {
            double xin;
            xin = (dm.getm()*100 + dm.getcm())*0.394;
            ft = xin/12;
            in = xin - (ft*12);
        }
        void input()
        {
            cout<<"Enter distance in feet and inches : ";
            cin>>ft>>in;
        }
        friend DM add(DM,DB);
};
 
DM add(DM mc,DB fi)
{
    DM a;
     
    double cm,in,xcm,xin;
    cm = mc.m*100 + mc.cm;
    in = fi.ft*12 + fi.in;
     
    xcm = cm + in*2.54;
    xin = in + cm*0.394;
     
    a.m = xcm/100;
    a.cm = xcm - (a.m*100);
     
    return a;
     
}
 
int main()
{
    DM a;
    DB b;
    a.input();
    b.input();
    cout<<"After adding : ";
    DM c;
    c = add(a,b);
    c.show();
	system("pause");
    return 0;
}
