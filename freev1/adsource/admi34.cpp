#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<graphics.h>
#include<dos.h>
#include <stdio.h>
#include<string.h>
#include<stddef.h>
#include<stdlib.h>
#define x1 100
#define y1 100
const long prog_id=12345678;
void draw();
void cmpdtls();
void staff();
void runner();
void search();
void deleted();
void drawex();
void menu();

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
int tag;
double progno;
public:
int no();
void display();
void getdata();
}pro[256],pdtbilled[20],s1;
void product:: display()
{
char txt1[20],txt2[20],txt3[20];
hidemouse();
clearviewport();
outtextxy(25,40,"                     ");
outtextxy(25,40,"name of product");
outtextxy(25,50,name);

outtextxy(25,60,"           ");
outtextxy(25,60,"price");
sprintf(txt1,"%g",price);
outtextxy(25,70,txt1);

outtextxy(25,80,"                          ");
outtextxy(25,80,"quantity");
sprintf(txt2,"%d",qty);
outtextxy(25,90,txt2);

sprintf(txt3,"%d",prno);
outtextxy(25,100,"                          ");
outtextxy(25,100,"product no");
outtextxy(25,110,txt3);
showmouse();
}
int product::no()
{
return prno;
}

void product:: getdata()
{
char txt1[20],txt2[20],txt3[20];
hidemouse();
clearviewport();
gotoxy(5,1);
cout<<"enter name of product\n";
gotoxy(5,2);
gets(name);
gotoxy(5,1);
cout<<"                                  ";
gotoxy(1,2);
cout<<"                                  ";
outtextxy(25,40,"                     ");
outtextxy(25,40,"name of product");
outtextxy(25,50,name);

gotoxy(5,1);
cout<<"enter price\n    ";
cin>>price;
gotoxy(5,1);
cout<<"                   ";
gotoxy(1,2);
cout<<"                                  ";

outtextxy(25,60,"           ");
outtextxy(25,60,"price");
sprintf(txt1,"%g",price);
outtextxy(25,70,txt1);

gotoxy(5,1);
cout<<"enter quantity present in stock\n    ";
cin>>qty;
gotoxy(5,1);
cout<<"                                     ";
gotoxy(1,2);
cout<<"                                  ";
outtextxy(25,80,"                           ");
outtextxy(25,80,"quantity");
sprintf(txt2,"%d",qty);
outtextxy(25,90,txt2);

gotoxy(5,1);
cout<<"enter product no\n    ";
cin>>prno;
gotoxy(5,1);
cout<<"                             ";
gotoxy(1,2);
cout<<"                                  ";
sprintf(txt3,"%d",prno);
outtextxy(25,100,"                      ");
outtextxy(25,100,"product no");
outtextxy(25,110,txt3);
//progno=prog_id;                            // ert  sgrgrseerh
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
   outtextxy(450,440," next ");

   setcolor(a);
   settextstyle(0,0,0);

}


class namepass
{public:
char name[20];
char pass[20];
};
char cmpname[20];
void main()
{


   int gdriver = DETECT, gmode;


   initgraph(&gdriver, &gmode, "");

   //cmpdtls();
  // staff();
     menu();



}

void runner()
{
clearviewport();
fstream f3;
f3.open("product",ios::app|ios::nocreate);
f3.seekg(0);
if(f3.fail())
{
cmpdtls();
staff();
//outtextxy(40,40,"This is a deault file");
}

int val;
int x,y,btn;
int cnr;

showmouse();


int whcnt=0;
do
{
pro[whcnt].getdata();

rep:
showmouse();
   draw();
   getmouse(btn,x,y);
   draw();
   while(!(btn&1)==1)
   {
   getmouse(btn,x,y);
   if(cnr==0)
   draw();
   cnr++;
   }
   while((btn&1)==1)
   getmouse(btn,x,y);

   f3.write((char*)&pro[whcnt],sizeof(product));
   whcnt++;

 if(!((x>450&&x<500&&y>450&&y<460)||(x>550&&x<600&&y>450&&y<460)))
 goto rep;
}while((x>450&&x<500&&y>450&&y<460));




f3.close();
clearviewport();
}
void cmpdtls()
{
clearviewport();
fstream f1;
//remove("cmp name");                     //               k;sdlkfklkjl
f1.open("cmp name",ios::app|ios::nocreate);
if(f1.fail())
{
f1.close();
//cout<<"open failed";
fstream q1;
q1.open("cmp name",ios::app);
cout<<"enter company name\n";
cin.getline(cmpname,20);
q1<<cmpname<<"\n";
q1.close();
}
else
{
clrscr();
f1.close();
}
fstream ff;
ff.open("cmp add",ios::app,ios::nocreate);
if(ff.fail())
{
char add[80];
ff.close();
fstream fg("cmp add",ios::app);
cout<<"enter your address\n";
cin.getline(add,80,'$');
fg<<add;
fg.close();
}
else
{
ff.close();
}
}
void staff()
{
clearviewport();
fstream f2;
//remove("name of");
f2.open("name of",ios::app|ios::nocreate);
if(f2.fail())
{
fstream j;
j.open("name of",ios::app);
//cout<<"open failed";
int i,lt;
cout<<"enter no of staffs( max 100 only..)\n";
cin>>lt;
namepass stf[100];
for(i=0;i<lt;i++)
{
cout<<"enter staff "<<i+1<<"'s name\n";
cin>>stf[i].name;
cout<<"enter staff"<<i+1<<"password\n";
cin>>stf[i].pass;
j.write((char*)&stf[i],sizeof(namepass));
//j<<stf[i].name<<"\n"<<stf[i].pass<<"\n";
j.close();
}
}
else
f2.close();
clrscr();
}
void menu()
{
hidemouse();
clrscr();
clearviewport();

initmouse();
showmouse();

dummy:
{
int x,y,btn,cnr=0,i=0;
do
   {


   drawex();
   getmouse(btn,x,y);
   drawex();
   while(!(btn&1)==1)
   {
   getmouse(btn,x,y);
   if(cnr==0)
   drawex();
   cnr++;
   }
   clearviewport();
   while((btn&1)==1)
   getmouse(btn,x,y);

   int  a=getmaxcolor();
  setcolor(5);
   settextstyle(3,0,1);
   bar(10,0,100,20);
   outtextxy(10,0,"search");
   bar(10,40,100,60);
   outtextxy(10,40,"delete");
   bar(10,80,100,100);
   outtextxy(10,80,"append");

   setcolor(a);
   settextstyle(0,0,0);
   setfillstyle(0,0);


   if(x>10&&x<100&&y>0&&y<20)
   {//cout<<"circle";
   hidemouse();
   clrscr();
   clearviewport();
   showmouse();
    search();




   }
   else if(x>10&&x<100&&y>40&&y<60)
   { //cout<<"box";
   hidemouse();
   clrscr();
   clearviewport();
   showmouse();
   deleted();

   }
   else if(x>10&&x<100&&y>80&&y<100)
   {
    hidemouse();
   clrscr();
   clearviewport();
   cmpdtls();
   staff();
   runner();
   showmouse();

   }
   i++;

   showmouse();


   }while(!(x>550&&x<600&&y>450&&y<460));




}
}
void drawex()
{   setfillstyle(1,getmaxcolor());
   int a=getmaxcolor();
   bar(550,450,600,460);
   //a=getcolor();
   a=1;
   setcolor(5);
   settextstyle(3,0,1);
   outtextxy(550,440," exit ");
   setcolor(a);
   settextstyle(0,0,0);

}
void search()
{
clearviewport();
int rn;
char found='n';
ifstream fi("product",ios::app);
if(fi.fail())
{
cout<<"open failed";
goto last;
}
fi.seekg(0);
cout<<"prno";
cin>>rn;
while(!fi.eof())
{
fi.read((char*)&s1,sizeof(product));
if(s1.no()==rn)
{
cout<<"all your data\n";
s1.display();//data
found='y';
break;
}

}
if (found=='n')
{
cout<<"product not found\n";
}
last:
fi.close();

}
void deleted()
{
clearviewport();
ifstream fio("product",ios::app);
ofstream file("temp",ios::out);
fio.seekg(0);
int rno;
char found='f';
char confirm='n';
cout<<"enter prno to be deleted";
cin>>rno;
while(!fio.eof())
{
fio.read((char*)&s1,sizeof(product));
if(s1.no()==rno)
{
found='t';
delay(1000);
s1.display();
cout<<"   want to del this file(y/n)   ";
cin>>confirm;


if(confirm=='n')
{ file.write((char*)&s1,sizeof(product));}

}
else
file.write((char*)&s1,sizeof(product));

}//eow
if(found=='f')
cout<<"record not found\n";
fio.close();
file.close();
remove("product");
rename("temp","product");

}