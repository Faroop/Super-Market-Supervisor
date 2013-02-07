#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<graphics.h>
#include<dos.h>
#include <stdio.h>
#include<string.h>
#include<stddef.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip.h>
#define x1 100
#define y1 100
char mmm[100];
char m1[20],m2[20],m3[20],m4[20],m5[20],m6[20];
char n1[20],n2[20],n3[20],n4[20],n5[20],n6[20];
int blldte();
void draw();
void cmpdtls();
void staff();
void runner();
void search();
void deleted();
void drawex();
void menu();
void passw();
void cmpw();
void store(float);
float total();
void drawp();
void backbill();
void showmanager();
char managername[20];
char companyname[20];
char companyadd[80];

int srl;

int uni;
union REGS mouse;

void initmouse(void)
{
mouse.x.ax=0;
int86(0x33,&mouse,&mouse);
}

void showmouse(void)
{
mouse.x.ax=1;
int86(0x33,&mouse,&mouse);

}
void getmouse(int &btn,int&x,int&y)
{
mouse.x.ax=3;
int86(0x33,&mouse,&mouse);
btn=mouse.x.bx;
x=mouse.x.cx;
y=mouse.x.dx;
}
void hidemouse(void)
{
mouse.x.ax=2;
int86(0x33,&mouse,&mouse);
}

class product
{
char name [20];
float price;
int qty;
int prno;
int secno;
double barcodeid;
int q;
float tot;
double progno;
int tag;
public:

void billed(int,int );
int no();
void display();
void getdata();
void prnn(int,int);
float tota();
}pro[256],pdtbilled[30],s1;
void product:: billed(int a,int q1)
{
int pod;
pod=a*10;
char txt1[20],txt2[20],txt3[20],txt4[20];

q=q1;
tot=(q*price);

sprintf(txt4,"%d",a+1);
outtextxy(20,200+pod,txt4);

sprintf(txt1,"%d",prno);
outtextxy(60,200+pod,txt1);

outtextxy(100,200+pod,name);



sprintf(txt2,"%d",q);
outtextxy(280,200+pod,txt2);

sprintf(txt3,"%g",price);
outtextxy(360,200+pod,txt3);

sprintf(txt3,"%g",tot);
outtextxy(420,200+pod,txt3);
showmouse();
}
void product::prnn(int a,int q1)
{


char txt1[20],txt2[20],txt3[20],txt4[20],txt5[20],txtt[100];

q=q1;
tot=(q*price);

sprintf(txt4,"%d",a+1);


sprintf(txt1,"%d",prno);






sprintf(txt2,"%d",q);


sprintf(txt3,"%g",price);


sprintf(txt5,"%g",tot);

sprintf(
txtt,"%s  %s  %s  %s  %s  %s", txt4,name,txt1,txt2,txt3,txt5);
strcpy(mmm,txtt);
strcpy(m1,txt1);
strcpy(m2,txt2);
strcpy(m3,txt3);
strcpy(m4,txt4);
strcpy(m5,txt5);
strcpy(m6,name);

}
int product::no()
{
return prno;
}
float product::tota()
{
return  tot;//(q*price);
}


class namepass
{public:
char name[20];
char pass[20];
};
char cmpname[20];
void biller()
{
clearviewport();
fstream f3;
f3.open("product",ios::app);
f3.seekg(0);
if(f3.fail())
{

outtextxy(40,40,"This is a deault file");
}
int t;
for(t=0;t<256;t++)
{
f3.read((char*)&pro[t],sizeof(product));
}
int val;
int x,y,btn;
int cnr;

 double no1;
 char at[20],ti[40];
 srl=blldte();
 sprintf(at,"%d",srl);
  time_t tm;
 char nm[100];
 time(&tm);
showmouse();
backbill();
int no,ro,q;
int whcnt=0;
 fstream b,b1;
 b.open("blprn.txt",ios::app);
 b1.open("blprn1.txt",ios::out);


 b1<<"\n\nBill no:  ";
 b1<<at<<"\t";

 b1<<"Date:";
 b1<<ctime(&tm)<<"\n";

 b<<"\n\nBill no:  ";
 b<<at<<"\t";

 b<<"Date:";
 b<<ctime(&tm)<<"\n";


b<<n1<<setw(20-strlen(n1))<<n2<<setw(20-strlen(n2))<<n3<<setw(20-strlen(n3))
<<n4<<setw(20-strlen(n4))<<n5<<setw(20-strlen(n5))<<n6<<setw(20-strlen(n6))<<"\n";

b1<<n1<<setw(20-strlen(n1))<<n2<<setw(20-strlen(n2))<<n3<<setw(20-strlen(n3))
<<n4<<setw(20-strlen(n4))<<n5<<setw(20-strlen(n5))<<n6<<setw(20-strlen(n6))<<"\n";

do
{
q=1;
beg:
gotoxy(5,1);
cout<<"prno\n";
gotoxy(5,2);
cin>>ro;
gotoxy(1,1);
cout<<"                                                                   ";
gotoxy(1,2);
cout<<"                                                                   ";
gotoxy(5,1);
//cout<<"qty";
gotoxy(5,2);
//cin>>q;
gotoxy(1,1);
cout<<"                                                                   ";
gotoxy(1,2);
cout<<"                                                                   ";
gotoxy(1,3);
cout<<"                                                                   ";
gotoxy(1,4);
cout<<"                                                                   ";

char found='n';
ifstream fi("product",ios::app);
if(fi.fail())
{
cout<<"open failed";
goto last;
}
fi.seekg(0);
t=0;
while(!fi.eof())
{
fi.read((char*)&pro[t],sizeof(product));
if(pro[t].no()==ro)
{
no=t;
found='y';
break;
}
t++;
}
if (found=='n')
{
gotoxy(5,1);
cout<<"                                                  ";
gotoxy(5,1);
cout<<"product not found\n";

goto last;
}

fi.close();



pro[no].billed(whcnt,q);
pdtbilled[whcnt]=pro[no];
pro[no].prnn(whcnt,q);
//b<<mmm<<"\n";                  //m1-m2   m4-m1  m5-m3

b<<m4<<setw(20-strlen(m1))<<m1<<setw(20-strlen(m2))<<m6<<setw(20-strlen(m3))
<<m2<<setw(20-strlen(m4))<<m5<<setw(20-strlen(m5))<<m3<<setw(20-strlen(m6))<<"\n";
b1<<m4<<setw(20-strlen(m1))<<m1
<<setw(20-strlen(m2))<<m6<<setw(20-strlen(m3))
<<m2<<setw(20-strlen(m4))<<m5<<setw(20-strlen(m5))<<m3<<setw(20-strlen(m6))<<"\n";

rep:
showmouse();
   draw();

   getmouse(btn,x,y);
   draw();

   while(!((btn&1)==1))
   {
   if(kbhit())
   goto wer;
   getmouse(btn,x,y);
   if(cnr==0)
   draw();
   cnr++;
   }
   while((btn&1)==1)
   getmouse(btn,x,y);
   wer:
  // f3.write((char*)&pro[whcnt],sizeof(product));
   whcnt++;
   uni=whcnt;
   last:
   if(whcnt>19)
 { //to be filled
   //prn();

   goto eee;
 }

 if(!((x>450&&x<500&&y>450&&y<460)||(x>550&&x<600&&y>450&&y<460)))
 continue;

 if((x>450&&x<500&&y>450&&y<460))
 {eee:
 float ttl;char txt8[20];
 ttl=total();
 //goto beg;
 backbill();
 outtextxy(50,410,"the total billed amt=");
 sprintf(txt8,"%g",ttl);
 outtextxy(415,410,txt8);                   //dipfjio[dod
 store(ttl);


 outtextxy(10,150,"bill no:");
 outtextxy(100,150,at);

 outtextxy(350,150,"date:");
 outtextxy(400,150,ctime(&tm));
 //showmanager();
 b<<"\nthe total billed amt=";
 b1<<"\nthe total billed amt=";
 b<<txt8<<"\n";
 b1<<txt8<<"\n";
 b1<<"\nthankyou visit again..\n";
 b<<"\nthankyou visit again..\n";
delay(3000);
 //prn();

 b.close();
 b1.close();
// remove("blprn");
 break;
 }

}while(!(x>550&&x<600&&y>450&&y<460));



fool:
f3.close();
clearviewport();
}
void  draw()
{
 setfillstyle(1,getmaxcolor());
   int a=getmaxcolor();
   bar(550,450,600,460);
   bar(450,450,500,460);
   setcolor(5);
   settextstyle(3,0,1);
   outtextxy(550,440," exit ");
   outtextxy(450,440," bill ");

   setcolor(a);
   settextstyle(0,0,0);
  // showmanager();

}
void main()
{
   initmouse();
   showmouse();
   int gdriver = DETECT, gmode;
   // passw();                                //   akshfkj;ksdhhj;sdjjk
   // cmpw();
   // cout<<companyname;
   // cout<<companyadd;
   // getch();
   initgraph(&gdriver, &gmode, "");

   menu();
  // getch();
    closegraph();
}
float total()
{
float tot=0;
for(int in=0;in<uni;in++)
{
tot+=pdtbilled[in].tota();
}
return tot;
}




 void menu()
 {
 int cnr=0;
 int btn,x,y;
 do
 {
 showmouse();
   drawp();

   getmouse(btn,x,y);
   drawp();

   while(!((btn&1)==1))
   {
   if(kbhit())
   goto wer;
   getmouse(btn,x,y);
   if(cnr==0)
   drawp();
   cnr++;
   }
   while((btn&1)==1)
   getmouse(btn,x,y);
   //
    biller();


   while(!((btn&1)==1))
   {
   if(kbhit())
   goto wer;
   getmouse(btn,x,y);
   if(cnr==0)
   drawp();
   cnr++;
   }
   while((btn&1)==1)
   getmouse(btn,x,y);


    if(!((x>450&&x<500&&y>450&&y<460)))//||(x>550&&x<600&&y>450&&y<460)))
  continue;
  wer:
  if((x>550&&x<600&&y>450&&y<460))
  exit(0);

  }while(!(x>550&&x<600&&y>450&&y<460));

 }
 void drawp()
 {
 setfillstyle(1,getmaxcolor());
   int a=getmaxcolor();
   bar(550,450,600,460);
   setcolor(5);
   settextstyle(3,0,1);
   outtextxy(550,440," exit ");

   setcolor(a);
   settextstyle(0,0,0);

 }
 void backbill()
 {
 hidemouse();
line(15,180,15,400);
line(55,180,55,400);
line(95,180,95,400);
line(275,180,275,400);
line(355,180,355,400);
line(415,180,415,400);
line(465,180,465,400);
line(15,180,465,180);        //top
line(15,400,465,400);        //bottom
line(15,190,465,190);        //sl line

outtextxy(20,180,"slno");
strcpy(n1,"slno");

outtextxy(60,180,"pdno");

strcpy(n2,"pdno");

outtextxy(100,180,"  item");
strcpy(n3,"item");



outtextxy(280,180,"quantity");
strcpy(n4,"quantity");

outtextxy(360,180,"price");
strcpy(n5,"price");

outtextxy(420,180,"tot");
strcpy(n6,"tot");
showmanager();
showmouse();

}



  void showmanager()
 {
 outtextxy(450,300,companyname);
 outtextxy(450,350,companyadd);
 }
 void passw()
 {
 namepass n;
 int flag=0;
 char passi[20];
 fstream a;
 a.open("name of",ios::app|ios::nocreate);
 if(a.fail())
 {
 cout<<"open failed";
 exit(0);
 }
 cout<<"enter password\n";
 cin>>passi;
 a.seekg(0);
// while(!a.eof())
for(int y=0;y<10;y++)
 { char ch;
 //a.read((char*)&n,sizeof(namepass));
 //a.get();
 a.get(n.name,30);
 a.get(ch);
 a.get(n.pass,30);
 cout<<n.name<<" "<<n.pass;
 if(!(strcmpi(n.pass,passi)))
 {
  strcpy(managername,n.name);
 flag=1;
 break;
 }

 }
 if(flag==0)
 {
 cout<<"\nwrong password\n";
 exit(0);
 }
 a.close();
 }


 void cmpw()
 {


 fstream a;
 a.open("cmp name",ios::app|ios::nocreate);
 if(a.fail())
 {
 cout<<"open failed";
 }
 a.seekg(0);
 while(!a.eof())
 {
 a.getline(companyname,20);
 }
 a.close();

 fstream p;
 p.open("cmp add",ios::app|ios::nocreate);
 if(p.fail())
 {
 cout<<"open failed";
 }
 p.seekg(0);
 while(!p.eof())
 {
 p.getline(companyadd,80,'$');
 }
 p.close();
 }

void store(float ttl)
{

time_t t;
fstream b;
b.open("datetxt",ios::app);
if(b.fail())
 {
 cout<<"open failed";
 }
time(&t);
b<<"Today's date and time:"<< ctime(&t)<<"\t" <<ttl<<"\n";
b.close();
}
int blldte()
{
int nos;
int i=0;
fstream s;
s.open("billno.txt",ios::app|ios::nocreate);
if(s.fail())
{
i=1;
ofstream q1;
q1.open("billno.txt",ios::app);
q1.write((char*)&i,sizeof(i));
q1.close();
//s.write((char*)&i,sizeof(i));
s.close();
return i;
}

else
{
s.close();
ifstream q2;
q2.open("billno.txt",ios::app);
q2.seekg(0);
q2.read((char*)&i,sizeof(i));
q2.close();
remove("billno.txt");
i+=1;
ofstream q1;
q1.open("billno.txt",ios::app);
q1.write((char*)&i,sizeof(i));
q1.close();
nos=(i);

return nos;
}

}