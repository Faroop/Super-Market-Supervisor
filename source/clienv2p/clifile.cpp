#include<fstream.h>
#include <graphics.h>
#include <io.h>
#include <fcntl.h>
#include <process.h>
#include <alloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<dos.h>
#include<gui.h>
#include<mouse.h>
#include<time.h>
#include<iomanip.h>
char decrypt(char [],char []);
void cfc(char);
void help1();
void globals();
int globe=0;
int pr_id_1=12345;
int qty_tag=0;
int br_flag=0;
int but_flag=0;
int t2_flag=0;
int esc=0;
char cmpany_name[80]={NULL};
char manager_name[80]={NULL};
char add_name1[80]={NULL};
char add_name2[80]={NULL};
char add_name3[80]={NULL};
char add_name4[80]={NULL};
char add_name5[80]={NULL};
float taxp;
float taxs;
char taxnm1[80];
char taxnm2[80];
char mmm[100];
char m1[20],m2[20],m3[20],m4[20],m5[20],m6[20];
char n1[20],n2[20],n3[20],n4[20],n5[20],n6[20];
char globx=NULL;
int globy=0;
void taxperc(float& ttl,float tax);
void taxrder();
void cmpnarder();
void cmpadrder();
int grapic();
void check12();
int blldte(int=1);
void draw();
void store(float);
float total();
void final();
void final2();
void writ();
void  opener();
int srl;

int uni;
int selc9(Button &b1,Button &b2,Button &b3,Button &b4,Button &b5,Button &b6,Button &b7,Button &b8,Button &b9,Button &b0,Button &b11,int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9,int a0,int a11);					    //;
union REGS mouse;
void getmouse(int &btn,int&x,int&y)
{
mouse.x.ax=3;
int86(0x33,&mouse,&mouse);
btn=mouse.x.bx;
x=mouse.x.cx;
y=mouse.x.dx;
}

void sett();

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
int pr_id;
product()
{
}

void billed(int,int );
int no();
void display();
void getdata();
void prnn(int,int);
float tota();
}pro[256],pdtbilled[30],s1;

void tdelete(product sd,int rno);

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
//char txt9[10]={NULL};
//sprintf(txt9,"%d",qty);
//outtextxy(600,200+pod,txt9);

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
float product::tota()
{
return  tot;
}


void backbill();

void refresh();
void bill();
void runner();
void tdelete();
void tsearch();
void data(int=228,int=175);
void data2(int=228,int=175);

void wrkng(int choice);
void file();
void extra();
void settime();
void about();
void help();
void exitg();

void biller();

void add();void _delete();void modify();void about();void exitg();void search();

int selc(Button &b1,Button &b2,Button &b3,Button &b4,Button &b5,Button &b6,int a1,int a2,int a3,int a4,int a5,int a6);
int selc(Button &b1,Button &b2,int n,int o);
int selc3(Button &b1,Button &b2,Button &b3,int n,int o,int p);
int selc1(Button &b1,int n);
void sscreen( );
void _3D_char(char* txt,int x,int y,int size=7,int col1=7,int col2=6,int col3=8,int col4=12)
 {
   int len=strlen(txt);
   len*=17;

	  setfillstyle(1,0);
	 bar(130,60,627,465);

       setfillstyle(1,col1);
	 bar(x-1,y+36,x+len,y+37);

       setfillstyle(1,col2);
	 bar(x-1,y+35,x+len,y+36);

       settextstyle(size,0,4);
	 setcolor(col3);
	   outtextxy(x,y,txt);
	   outtextxy(x+1,y,txt);

	 setcolor(col4);
	   outtextxy(x+2,y-1,txt);
	   outtextxy(x+3,y-1,txt);
 }



 void search_box(char*txt,int x,int y,int d=10,int col1=8,int col2=15,int col3=2,int col4=1)
{
	setcolor(col1);
	 rectangle(x+8,y+13,x+273,y+23);

       setcolor(col2);
	 rectangle(x+9,y+14,x+274,y+24);

       setcolor(col3);
       settextstyle(0,0,1);
	 outtextxy(x,y,txt);

       delay(1000);

       for(int count=0;count<261;count++)
	  {
	     setfillstyle(1,col4);
	       bar(x+12,y+16,((x+11)+count),y+21);

	     delay(d);
	  }

}



void txt_box(char ast[],int x=50,int y=50,int size=20,int col1=11,int col2=0,int col3=7)
{
  get_current_settings( );
  char s[40]={NULL};
	  int x_1=x,y_1=y,x_2=x+(size*10),y_2=y+10;
	  int count_=0;
	    setfillstyle(1,8);
	 bar(x_1,y_1,x_2,y_2);

       setcolor(col3);
	 rectangle((x_1-1),(y_1-1),(x_2+1),(y_2+1));

       setcolor(col2);
	 rectangle((x_1-2),(y_1-2),(x_2+2),(y_2+2));

	   int key_code=0;

	     char key=NULL;


	  do{


	     if(kbhit( ))
		{
		   key=getch( );

		   key_code=int(key);

		   if(key_code==0)
		      getch( );
		}

	     if(key_code==13)
	     {

		break;
	     }
	     else if(key_code==27)
	     {
		br_flag=1;
		break;
	     }
	     else if(key_code==8 && count_>0)
		{
		   setfillstyle(1,8);
		     bar(x_1,y_1,x_2,y_2);

		   count_--;

		   s[count_]=NULL;
		   count_--;

		}
	  else
	  {
	  char* d=NULL;
	  *d=(char)key;
	  strcat(s,d);
	  }
	      if(count_<3)
	      {
	       setfillstyle(1,8);
	       bar(x_1,y_1,x_2,y_2);
	      }

	     setcolor(col1);
	     settextstyle(0,0,1);
	       moveto((x_1+5),(y_1+4));
		 outtext(s);

	     int x=getx( );
	     int y=gety( );

	     while(!kbhit( ))
		{
		   settextstyle(0,0,1);
		     setcolor(15);
		       moveto((x+2),y);
			 outtext("_");

		   delay(250);

		     setcolor(col1);
		       moveto((x+2),y);
			 outtext("_");

		   delay(200);
	       }

	       count_++;

	       }while(count_<size-1);

strcpy(ast,s);
restore_previous_settings( );
}
void boxx(float& a,int x1,int y1)
{  int size=20;
   int col1=11;
   int col2=0;
   int col3=7;
get_current_settings( );
  char s[40]={NULL};
	  int x_1=x1,y_1=y1,x_2=x1+(size*10),y_2=y1+10;
	  int count_=0;
	    setfillstyle(1,8);
	 bar(x_1,y_1,x_2,y_2);

       setcolor(col3);
	 rectangle((x_1-1),(y_1-1),(x_2+1),(y_2+1));

       setcolor(col2);
	 rectangle((x_1-2),(y_1-2),(x_2+2),(y_2+2));

	   int key_code=0;

	     char key=NULL;


	  do{


	     if(kbhit( ))
		{
		   key=getch( );

		   key_code=int(key);

		   if(key_code==0)
		      getch( );
		}

	     if(key_code==13)
	     {

		break;
	     }
	     else if(key_code==27)
	     {
		br_flag=1;
		break;
	     }
	     else if(key_code==8 && count_>0)
		{
		   setfillstyle(1,8);
		     bar(x_1,y_1,x_2,y_2);

		   count_--;

		   s[count_]=NULL;
		   count_--;

		}
	  else
	  {
	  char* d=NULL;
	  *d=(char)key;
	  strcat(s,d);
	  }
	      if(count_<3)
	      {
	       setfillstyle(1,8);
	       bar(x_1,y_1,x_2,y_2);
	      }

	     setcolor(col1);
	     settextstyle(0,0,1);
	       moveto((x_1+5),(y_1+4));
		 outtext(s);

	     int x=getx( );
	     int y=gety( );

	     while(!kbhit( ))
		{
		   settextstyle(0,0,1);
		     setcolor(15);
		       moveto((x+2),y);
			 outtext("_");

		   delay(250);

		     setcolor(col1);
		       moveto((x+2),y);
			 outtext("_");

		   delay(200);
	       }

	       count_++;

	       }while(count_<size-1);

a=atof(s);
restore_previous_settings( );
}
void boxx(int& a,int x1,int y1,int size=20)
{
esc=0;
   int col1=11;
   int col2=0;
   int col3=7;
get_current_settings( );
  char s[40]={NULL};
	  int x_1=x1,y_1=y1,x_2=x1+(size*10),y_2=y1+10;
	  int count_=0;
	    setfillstyle(1,8);
	 bar(x_1,y_1,x_2,y_2);

       setcolor(col3);
	 rectangle((x_1-1),(y_1-1),(x_2+1),(y_2+1));

       setcolor(col2);
	 rectangle((x_1-2),(y_1-2),(x_2+2),(y_2+2));

	   int key_code=0;

	     char key=NULL;


	  do{


	  if(but_flag==1)
	{
	showmouse();
	key=grapic();
	if(key<0)
	{break;
	}
	if(key==12)
	{key=0;
	}
	but_flag=1;
	 char d[10]={NULL};
	 itoa(key,d,10);
	 strcat(s,d);
	 setcolor(col1);
	     settextstyle(0,0,1);
	       moveto((x_1+5),(y_1+4));
		 outtext(s);



	}



	  else
	    {
	     if(kbhit( ))
		{
		   key=getch( );

		   key_code=int(key);

		   if(key_code==0)
		      getch( );
		}


	     if(key_code==13)
	     {

		break;
	     }
	     else if(key_code==27)
	     {  esc=1;
		br_flag=1;
		break;
	     }
	     else if(key_code==8 && count_>0)
		{
		   setfillstyle(1,8);
		     bar(x_1,y_1,x_2,y_2);

		   count_--;

		   s[count_]=NULL;
		   count_--;

		}
	  else
	  {
	  if(globy==1)
	  {
	  char* d=NULL;
	  *d=globx;
	  strcat(s,d);
	  globy=0;
	  }
	  else
	  {


	  char* d=NULL;
	  *d=(char)key;
	  strcat(s,d);
	  }
	  }
	      if(count_<3)
	      {
	       setfillstyle(1,8);
	       bar(x_1,y_1,x_2,y_2);
	      }

	     setcolor(col1);
	     settextstyle(0,0,1);
	       moveto((x_1+5),(y_1+4));
		 outtext(s);

	     int x=getx( );
	     int y=gety( );

	     while(!kbhit( ))
		{
		   settextstyle(0,0,1);
		     setcolor(15);
		       moveto((x+2),y);
			 outtext("_");

		   delay(250);

		     setcolor(col1);
		       moveto((x+2),y);
			 outtext("_");

		   delay(200);
	       }

		 }


	       count_++;

	       }while(count_<size-1);


	       a=atoi(s);
	       restore_previous_settings( );

}


int main(void)
{

void    *gothic_fontp;    /* points to font bufferin memory */
int      handle;          /* file handle used for I/O */
unsigned fsize;           /* size of file (andbuffer) */

int errorcode;
int graphdriver;
int graphmode;

/* open font file */
handle = open("LCOM.CHR", O_RDONLY|O_BINARY);
if (handle == -1)
{
printf("unable to open font file 'LCOM.CHR'\n");
exit(1);
}
/* find out size of the file */
fsize = filelength(handle);
/* allocate buffer */
gothic_fontp = malloc(fsize);
if (gothic_fontp == NULL)
{
printf("unable to allocate memory for font file'LCOM.CHR'\n");
exit(1);
}
/* read font into memory */
if (read(handle, gothic_fontp, fsize) != fsize)
{
printf("unable to read font file 'LCOM.CHR'\n");
exit(1);
}
/* close font file */
close(handle);
/* register font */
if (registerfarbgifont(gothic_fontp) != 8)     //
{
printf("unable to register font file 'LCOM.CHR'\n");
exit(1);
}
/* detect and initialize graphix */
graphdriver = DETECT;
initgraph(&graphdriver, &graphmode, "..");
errorcode = graphresult();
if (errorcode != grOk)
{
printf("graphics error:%s\n",grapherrormsg(errorcode));
exit(1);
}
settextstyle(8, HORIZ_DIR, 4);

   opener();
   cmpnarder();
   cmpadrder();
   taxrder();
   globals();
   hidemouse();
   sscreen( );
   getch();
   closegraph();

   return 0;
}
int selc(Button &b1,Button &b2,int n,int o)
{    showmouse();

       int selected=0;

       do
	  {
	     if(leftmousekeypressed( ) && b1.hit( ))
		{
		   b1.press_and_release(LEFT_MOUSE_KEY);

		   selected=1;
		}

	     else if(leftmousekeypressed( ) && b2.hit( ))
		{
		   b2.press_and_release(LEFT_MOUSE_KEY);

		   selected=2;
		}
	    else if(leftmousekeypressed() &&!b1.hit( ) &&!b2.hit( ))
		{
		break;
		}

	     else if(kbhit( ))
		{
		   int key_code_1=0;
		   int key_code_2=0;

		   char key_1=NULL;
		   char key_2=NULL;

		   key_1=getch( );
		   key_code_1=int(key_1);

		   if(key_code_1==0)
		      {
			 key_2=getch( );
			 key_code_2=int(key_2);
		      }
		   if(key_code_1!=0)
		      {
		      break;
		      }

		   if(key_code_1==0)
		      {
			 if(key_code_2==n)
			    {
			       b1.press_and_release(KEY_BOARD);

			       selected=1;
			    }

			 else if(key_code_2==o)
			    {
			       b2.press_and_release(KEY_BOARD);

			       selected=2;
			    }
			 else if(key_code_2!=n||key_code_2!=o)
			    {
			      break;
			    }
		      }
		}
	  }
       while(!selected);
hidemouse();
return selected;
}
int selc3(Button &b1,Button &b2,Button &b3,int n,int o,int p)
{    showmouse();

       int selected=0;

       do
	  {
	     if(leftmousekeypressed( ) && b1.hit( ))
		{
		   b1.press_and_release(LEFT_MOUSE_KEY);

		   selected=1;
		}

	     else if(leftmousekeypressed( ) && b2.hit( ))
		{
		   b2.press_and_release(LEFT_MOUSE_KEY);

		   selected=2;
		}
		else if(leftmousekeypressed( ) && b3.hit( ))
		{
		   b3.press_and_release(LEFT_MOUSE_KEY);

		   selected=3;
		}
	    else if(leftmousekeypressed() &&!b1.hit( ) &&!b2.hit( )&&!b3.hit( ))
		{
		break;
		}

	     else if(kbhit( ))
		{
		   int key_code_1=0;
		   int key_code_2=0;

		   char key_1=NULL;
		   char key_2=NULL;

		   key_1=getch( );
		   key_code_1=int(key_1);

		   if(key_code_1==0)
		      {
			 key_2=getch( );
			 key_code_2=int(key_2);
		      }
		   if(key_code_1!=0)
		      {
		      break;
		      }

		   if(key_code_1==0)
		      {
			 if(key_code_2==n)
			    {
			       b1.press_and_release(KEY_BOARD);

			       selected=1;
			    }


			 else if(key_code_2==o)
			    {
			       b2.press_and_release(KEY_BOARD);

			       selected=2;
			    }
			    else if(key_code_2==p)
			    {
			       b3.press_and_release(KEY_BOARD);

			       selected=3;
			    }
			 else if(key_code_2!=n||key_code_2!=o||key_code_2!=p)
			    {
			      break;
			    }
		      }
		}
	  }
       while(!selected);
hidemouse();
return selected;
}

int selc(Button &b1,int n)
{    showmouse();

       int selected=0;

       do
	  {
	     if(leftmousekeypressed( ) && b1.hit( ))
		{
		   b1.press_and_release(LEFT_MOUSE_KEY);

		   selected=1;
		}


	    else if(leftmousekeypressed() &&!b1.hit( ))
		{
		break;
		}

	     else if(kbhit( ))
		{
		   int key_code_1=0;
		   int key_code_2=0;

		   char key_1=NULL;
		   char key_2=NULL;

		   key_1=getch( );
		   key_code_1=int(key_1);

		   if(key_code_1==0)
		      {
			 key_2=getch( );
			 key_code_2=int(key_2);
		      }
		   if(key_code_1!=0)
		      {
		      break;
		      }

		   if(key_code_1==0)
		      {
			 if(key_code_2==n)
			    {
			       b1.press_and_release(KEY_BOARD);

			       selected=1;
			    }


			 else if(key_code_2!=n)
			    {
			      break;
			    }
		      }
		}
	  }
       while(!selected);
hidemouse();
return selected;
}

void shape1(char*txt,int x,int y)
{

     setcolor(8);
	 rectangle(x-9,y+5,x+287,y+41);
	 rectangle(x-9,y+48,x+287,y+331);

       setcolor(15);
	 rectangle(x-8,y+6,x+288,y+42);
	 rectangle(x-8,y+49,x+288,y+332);

       setfillstyle(1,1);
	 bar(x-5,y+9,x+284,y+38);
     settextstyle(8,0,4);
	 setcolor(0);
	   outtextxy(x,y,txt);
	   outtextxy(x+1,y,txt);

	 setcolor(14);
	   outtextxy(x+2,y-1,txt);
	   outtextxy(x+3,y-1,txt);
	   outtextxy(x+4,y-1,txt);
}
void sscreen( )
    {
       cleardevice( );

       Panel main_bar,Screen,tool;

       main_bar.init(0,0,getmaxx( ),getmaxy( ),IN,THIN);
       main_bar.show();

      char*txt="SUPER MARKET SUPERVISOR..ver-2r";
 {  int x1=0;
    int y1=0;
    int x2=getmaxx( );
    int y2=getmaxy( );
    int x=x1+13;
    int y=y1-1;


     setcolor(8);
	 rectangle(x1+4,y1+4,x2-5,y+41);
	 rectangle(x1+4,y+48,x2-5,y2-5);

       setcolor(15);
	 rectangle(x1+5,y+6,x2-4,y+42);
	 rectangle(x1+5,y+
	 49,x2-4,y2-4);

       setfillstyle(1,9);
	 bar(x1+8,y1+8,x2-8,y+38);
     settextstyle(8,0,4);
	 setcolor(0);
	   outtextxy(x,y,txt);
	   outtextxy(x+1,y,txt);

	 setcolor(14);
	   outtextxy(x+2,y-1,txt);
	   outtextxy(x+3,y-1,txt);
	   outtextxy(x+4,y-1,txt);
}
       tool.init(0,35,getmaxx(),55,IN,THIN);
       tool.show();

       Button File,Extra,Settime,About,Exit,Help;
       File.init(6,35,"File        ",FLAT);
       File.show( );

       Extra.init(111,35,"Extra       ",FLAT,0,0,7,1);
       Extra.show( );

       Settime.init(221,35,"Settime     ",FLAT);
       Settime.show( );

       About.init(331,35,"About       ",FLAT);
       About.show( );


       Help.init(441,35,"Help        ",FLAT);
       Help.show( );

       Exit.init(551,35,"Exit     ",FLAT);
       Exit.show( );

       Screen.init(5,53,632,467,IN,THICK);

       Screen.show( );

       setcolor(8);
	 rectangle(4,53,633,471);

       setcolor(15);
	 rectangle(5,54,634,472);
	 initmouse();

	while(1)
	{
	showmouse();
	 int ch=selc(File,Extra,Settime,About,Help,Exit,33,45,31,30,35,18);

	 hidemouse();
	 wrkng(ch);

	}
    }
    void wrkng(int choice)
    {
    switch(choice)
    {
    case 1: file();   break;
    case 2: extra();   break;
    case 3: settime();   break;
    case 4: about();   break;
    case 5: help();   break;
    case 6: exitg();   break;
    default: exit(0);   break;
    }
    }
int selc(Button &b1,Button &b2,Button &b3,Button &b4,Button &b5,Button &b6,int a1,int a2,int a3,int a4,int a5,int a6)
{

       int selected=0;

       do
	  {
	     if(leftmousekeypressed( ) && b1.hit( ))
		{
		   b1.press_and_release(LEFT_MOUSE_KEY);

		   selected=1;
		}

	     else if(leftmousekeypressed( ) && b2.hit( ))
		{
		   b2.press_and_release(LEFT_MOUSE_KEY);

		   selected=2;
		}
		 else if(leftmousekeypressed( ) && b3.hit( ))
		{
		   b3.press_and_release(LEFT_MOUSE_KEY);

		   selected=3;
		}
		 else if(leftmousekeypressed( ) && b4.hit( ))
		{
		   b4.press_and_release(LEFT_MOUSE_KEY);

		   selected=4;
		}
		 else if(leftmousekeypressed( ) && b5.hit( ))
		{
		   b5.press_and_release(LEFT_MOUSE_KEY);

		   selected=5;
		}
		 else if(leftmousekeypressed( ) && b6.hit( ))
		{
		   b6.press_and_release(LEFT_MOUSE_KEY);

		   selected=6;
		}





	     else if(kbhit( ))
		{
		   int key_code_1=0;
		   int key_code_2=0;

		   char key_1=NULL;
		   char key_2=NULL;

		   key_1=getch( );
		   key_code_1=int(key_1);

		   if(key_code_1==0)
		      {
			 key_2=getch( );
			 key_code_2=int(key_2);
		      }

		   if(key_code_1==0)
		      {
			 if(key_code_2==a1)
			    {
			       b1.press_and_release(KEY_BOARD);

			       selected=1;
			    }

			 else if(key_code_2==a2)
			    {
			       b2.press_and_release(KEY_BOARD);

			       selected=2;
			    }
			    else if(key_code_2==a3)
			    {
			       b3.press_and_release(KEY_BOARD);

			       selected=3;
			    }
			    else if(key_code_2==a4)
			    {
			       b4.press_and_release(KEY_BOARD);

			       selected=4;
			    }
			    else if(key_code_2==a5)
			    {
			       b5.press_and_release(KEY_BOARD);

			       selected=5;
			    }
			    else if(key_code_2==a6)
			    {
			       b6.press_and_release(KEY_BOARD);

			       selected=6;
			    }
			    else if(key_code_2==48)
			    {
			       bill();
			       refresh();
			    }
			    else if(key_code_2==50)
			    {
			    if(but_flag==1)
			    but_flag=0;
			    else
			    but_flag=1;

			    }
			    else if(key_code_2==16)
			    {
			    if(qty_tag==1)
			    qty_tag=0;
			    else
			    qty_tag=1;

			    }
		      }
		}
	  }
       while(!selected);
       Panel scribble;
       scribble.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);
       scribble.show();
return selected;
}

void file()
{
       Panel Screen;
       Screen.init(5,53,632,467,IN,THICK);
       Screen.show( );


get_current_settings( );

      runner();


Panel scribble;
       scribble.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);
       scribble.show();


}
void extra()
{
final();

Panel scribble;
       scribble.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);
       scribble.show();

}
void settime()
{
Panel settime;
settime.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);;
settime.show();
settime.shape("Settime");


Panel move;

       move.init(220,120,525,455,OUT,THIN);
       move.show( );
       move.shape("SETTIME");
showmouse();



      settextstyle(1,0,1);

       sett();

showmouse();
int cnt=0;
if(br_flag==1)
{
br_flag=0;
goto d;
}
while((!kbhit())&&(!(leftmousekeypressed())))
cnt++;
d:
Panel scribble;

       scribble.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);
       scribble.show();

}
void exitg()
{
Panel move;

       move.init(220,120,525,455,OUT,THIN);
       move.show( );
       move.shape("EXIT");
       data2();
       delay(1000);

exit(0);
}
void about()
{
Panel about ;
about.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);;
about.show();
about.shape("About");

get_current_settings( );
Panel move;



       move.init(220,120,525,455,OUT,THIN);
       move.show( );
       move.shape("About");
       data();
showmouse();
int cnt=0;
while((!kbhit())&&(!(leftmousekeypressed())))
cnt++;
Panel scribble;
       scribble.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);
       scribble.show();

}
void help()
{
Panel help;
help.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);;
help.show();
help.shape("Help");

       settextstyle(1,0,1);
help1();




showmouse();
int cnt=0;
while((!kbhit())&&(!(leftmousekeypressed())))
cnt++;
Panel scribble;
       scribble.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);
       scribble.show();


}


void product::display()
{ char*t1,*t2,*t3;
sprintf(t1,"%f",price);
sprintf(t2,"%f",prno);
sprintf(t3,"%f",qty);

outtextxy(240,222,name);
outtextxy(240,242,t1);
outtextxy(240,162,t2);
outtextxy(240,282,t3);
}
int product::no()
{
return prno;
}
void product::getdata()
{
get_current_settings( );
settextstyle(1,0,1);
outtextxy(240,202,"Name");
restore_previous_settings( );
txt_box(name,260,222);
settextstyle(1,0,1);
outtextxy(240,242,"Price");
restore_previous_settings( );
boxx(price,260,262);
settextstyle(1,0,1);
outtextxy(240,282,"Prno");
restore_previous_settings( );
boxx(prno,260,302);
settextstyle(1,0,1);
outtextxy(240,322,"Qty");
restore_previous_settings( );
boxx(qty,260,342);
restore_previous_settings( );


}
void runner()
{     showmouse();
       Button Bill,Exit;
       Bill.init(6,57,"Bill        ",FLAT);
       Bill.show( );
       if(qty_tag==1)
       {
       Exit.init(6,77,"Qty disp  * ",FLAT);
       Exit.show( );
       }
       else
       {
       Exit.init(6,77,"Qty disp    ",FLAT);
       Exit.show( );
       }
       int i= selc(Bill,Exit,48,16);
       if(i==2)
     {

     if(qty_tag==0)
     {
     qty_tag=1;
     }
     else if(qty_tag==1)
     {
     qty_tag=0;
     }
     }
      else if(i==1)
     {

     bill();
     }

}
  void data(int a,int b)
  {
       setcolor(4);
       settextstyle(1,0,1);
       outtextxy(a,b,    "    A COMPLETE SOLUTION TO    ");
       outtextxy(a,b+20, "    BILLING AND MANAGEMENT    ");
       outtextxy(a,b+40, "    OF LARGE OR SMALL SCALE   ");
       outtextxy(a,b+60, "    DEPTARTMENTAL STORE...    ");
       outtextxy(a,b+80, "");
       outtextxy(a,b+100,"");
       setcolor(14);
       outtextxy(a,b+120,"     SUPER  MARKET SUPERVISOR");
       outtextxy(a,b+140,"          --version--2-r     ");
       outtextxy(a,b+160,"              CLIENT         ");
       outtextxy(a,b+180,"");

       moveto(a,b+240);
       setcolor(4);
       outtext("By Sadanandh");
       outtextxy(a,b+260,"PROFITZ SOLUTIONS");
       Button F1,F2;
	F1.init(a+100,b+200,"  OK  ",NORMAL,0,-2);
	F1.show( );

	selc(F1,F2,24,8);
       restore_previous_settings( );

  }
  void data2(int a,int b)
  {
  setcolor(4);
       settextstyle(1,0,1);
       outtextxy(a,b,"visit us at");
       outtextxy(a,b+20,"");
       outtextxy(a,b+40,"www.profitzsoftwares.com ");
       outtextxy(a,b+60,"");
       outtextxy(a,b+80,"Or email us at");
       outtextxy(a,b+100,"");
       outtextxy(a,b+120,"profitzsoftwares@hotmail.com");
       outtextxy(a,b+140,"");
       outtextxy(a,b+160,"Happy Computing     ");
       outtextxy(a,b+180,"Get your licence soon..");

       moveto(a,b+240);
       setcolor(11);
       outtext("Thank you......");
       restore_previous_settings( );


}
void backbill()
 {
 char*n1,*n2,*n3,*n4,*n5,*n6,*n7;
 n1=NULL;
 n2=NULL;
 n3=NULL;
 n4=NULL;
 n5=NULL;
 n6=NULL;
 n7=NULL;
 hidemouse();
line(15,180,15,400);
line(55,180,55,400);
line(95,180,95,400);
line(275,180,275,400);
line(355,180,355,400);
line(415,180,415,400);
line(465,180,465,400);
line(15,180,465,180);
line(15,400,465,400);
line(15,190,465,190);

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



strcpy(n7," ");



}

void refresh()
{
    cleardevice( );
       hidemouse();
       Panel main_bar,Screen,tool;

       main_bar.init(0,0,getmaxx( ),getmaxy( ),IN,THIN);
       main_bar.show();

      char*txt="SUPER MARKET SUPERVISOR..ver-2r";
 {  int x1=0;
    int y1=0;
    int x2=getmaxx( );
    int y2=getmaxy( );
    int x=x1+13;
    int y=y1-1;


     setcolor(8);
	 rectangle(x1+4,y1+4,x2-5,y+41);
	 rectangle(x1+4,y+48,x2-5,y2-5);

       setcolor(15);
	 rectangle(x1+5,y+6,x2-4,y+42);
	 rectangle(x1+5,y+
	 49,x2-4,y2-4);

       setfillstyle(1,9);
	 bar(x1+8,y1+8,x2-8,y+38);
     settextstyle(8,0,4);
	 setcolor(0);
	   outtextxy(x,y,txt);
	   outtextxy(x+1,y,txt);

	 setcolor(14);
	   outtextxy(x+2,y-1,txt);
	   outtextxy(x+3,y-1,txt);
	   outtextxy(x+4,y-1,txt);
}
       tool.init(0,35,getmaxx(),55,IN,THIN);
       tool.show();

       Button File,Extra,Settime,About,Exit,Help;
       File.init(6,35,"File        ",FLAT);
       File.show( );

       Extra.init(111,35,"Extra       ",FLAT,0,0,7,1);
       Extra.show( );

       Settime.init(221,35,"Settime     ",FLAT);
       Settime.show( );

       About.init(331,35,"About       ",FLAT);
       About.show( );


       Help.init(441,35,"Help        ",FLAT);
       Help.show( );

       Exit.init(551,35,"Exit     ",FLAT);
       Exit.show( );

       Screen.init(5,53,632,467,IN,THICK);

       Screen.show( );

       setcolor(8);
	 rectangle(4,53,633,471);

       setcolor(15);
	 rectangle(5,54,634,472);
	 initmouse();
	 showmouse();


}
void bill()
{
refresh();
biller();

}
void biller()
{
Button b11,b22;
int yo;
char txt9[80];
char txt10[80];
char txt11[80];

fstream f3;
f3.open("pro//product",ios::app|ios::nocreate);
f3.seekg(0);
if(f3.fail())
{

outtextxy(40,40,"This is a deault file");
f3.close();
f3.open("pro//default",ios::app);
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
char xl1;
fstream j,k;
 j.open("data//billprn.txt",ios::app|ios::in);
 k.open("data//tmp.txt",ios::app|ios::out);
 while(!j.eof())
 {
 j.get(xl1);
 k.put(xl1);
 }
 j.close();
 k.close();

 fstream b,b1;
 b.open("data//billprn.txt",ios::app);
 b1.open("data//billprn1.txt",ios::out);



b<<"\n\t"<<cmpany_name<<"\n\t";
b<<add_name1<<"\n\t";
b<<add_name2<<"\n\t";
b<<add_name3<<"\n\t";
b<<add_name4<<"\n\t";
b<<add_name5<<"\n";

b1<<"\n\t"<<cmpany_name<<"\n\t";
b1<<add_name1<<"\n\t";
b1<<add_name2<<"\n\t";
b1<<add_name3<<"\n\t";
b1<<add_name4<<"\n\t";
b1<<add_name5<<"\n";

 b<<"\n"<<manager_name<<"\n";
 b1<<"\n"<<manager_name<<"\n";

 b1<<"\n\nBill no:  ";
 b1<<at<<"\t";

 b1<<"Date:";
 b1<<ctime(&tm)<<"\n";

 b<<"\n\nBill no:  ";
 b<<at<<"\t";

 b<<"Date:";
 b<<ctime(&tm)<<"\n";

b<<"----------------------------------------------------";
b<<"----------------------------------------------------\n";

b<<n1<<setw(20-strlen(n1))<<n2<<setw(23-strlen(n2))<<n3<<setw(27-strlen(n3))
<<n4<<setw(26-strlen(n4))<<n5<<setw(24-strlen(n5))<<n6<<setw(20-strlen(n6))<<"\n";
b<<"----------------------------------------------------";
b<<"----------------------------------------------------\n";


b1<<"----------------------------------------------------";
b1<<"----------------------------------------------------\n";

b1<<n1<<setw(20-strlen(n1))<<n2<<setw(23-strlen(n2))<<n3<<setw(27-strlen(n3))
<<n4<<setw(26-strlen(n4))<<n5<<setw(24-strlen(n5))<<n6<<setw(20-strlen(n6))<<"\n";
b1<<"----------------------------------------------------";
b1<<"----------------------------------------------------\n";

int er=0;
do
{
if(whcnt!=0)
{
setfillstyle(1,7);
bar(8,100,108,110);

}
if(er!=1)
{
setfillstyle(1,7);
bar(210,120,350,130);
er=0;
}

q=1;
beg:
outtextxy(10,100,"prno");
boxx(ro,10,120);
if(br_flag==1&&globe!=0||esc==1)
{

br_flag=0;
     blldte(-1);
     remove("data//billprn.txt");
     rename("data//tmp.txt","data//billprn.txt");

goto fool;
}
globe=0;
if(qty_tag==1)
{
outtextxy(10,140,"qty");
boxx(q,10,155);
}
if(er==1)
{
setfillstyle(1,7);
bar(210,120,370,130);
er=0;
}


setfillstyle(1,7);
bar(8,140,228,150);

setfillstyle(1,7);
bar(8,115,228,135);

setfillstyle(1,7);
bar(8,150,228,175);


char found='n';
ifstream fi("pro//product",ios::app|ios::nocreate);
if(fi.fail())
{
cout<<"open failed";
goto fool;
}
fi.seekg(0);
t=0;
while(!fi.eof())
{
fi.read((char*)&pro[t],sizeof(product));
if(pro[t].no()==ro&&(ro!=0))
{
no=t;
found='y';
if(pro[t].pr_id!=pr_id_1)                  //security
{
cout<<"security breeched";
exit(0);
}
break;
}
t++;
}
if (found=='n')
{
gotoxy(5,1);

gotoxy(5,1);

outtextxy(210,120,"  product not found");
er=1;
goto last;
}
 er=0;

fi.close();



pro[no].billed(whcnt,q);
pdtbilled[whcnt]=pro[no];
pro[no].prnn(whcnt,q);


b<<m4<<setw(20-strlen(m4))<<m1<<setw(20-strlen(m1))<<m6<<setw(20)
<<m2<<setw(20)<<m5<<setw(20)<<m3<<setw(20-strlen(m3))<<"\n";

b1<<m4<<setw(20-strlen(m4))<<m1<<setw(20-strlen(m1))<<m6<<setw(20)
<<m2<<setw(20)<<m5<<setw(20)<<m3<<setw(20-strlen(m3))<<"\n";

rep:
showmouse();
   draw();
   getmouse(btn,x,y);
   draw();

 b11.init(450,450," Bill    ",FLAT);
 b11.show();
 b22.init(550,450," Exit    ",FLAT);
 b22.show();


   while(!((btn&1)==1))
   {


   if(kbhit())
   {

		   int key_code_1=0;
		   int key_code_2=0;

		   char key_1=NULL;
		   char key_2=NULL;

		   key_1=getch( );
		   key_code_1=int(key_1);
		   globx=key_1;
		   globy=1;
		   if(key_code_1==0)
		      {
			 key_2=getch( );
			 key_code_2=int(key_2);
		      }
		      else
		      {
		      goto wer;
		      }

		   if(key_code_1==0)
		      {
			 if(key_code_2==48)
			    {
			       b11.press_and_release(KEY_BOARD);
			    remove("data//tmp.txt");
			      goto go1;
			     }
		       else if(key_code_2==18)
			    {
			       b22.press_and_release(KEY_BOARD);
			       blldte(-1);
			       remove("data//billprn.txt");
			      rename("data//tmp.txt","data//billprn.txt");

			       goto go2;
			    }

		       }
		      else
		   {
		   goto wer;
		   }
   }



   getmouse(btn,x,y);

   if(cnr==0)
   draw();
   cnr++;
   }

   while((btn&1)==1)
   {

   if(leftmousekeypressed( ) && b11.hit( ))
		{
		   b11.press_and_release(LEFT_MOUSE_KEY);

		   remove("data//tmp.txt");
		   goto go1;

		}

    else if(leftmousekeypressed( ) && b22.hit( ))
		{
		   b22.press_and_release(LEFT_MOUSE_KEY);
		   blldte(-1);
		   remove("data//billprn.txt");
		   rename("data//tmp.txt","data//billprn.txt");

		   goto go2;
		}
   getmouse(btn,x,y);
   }
   wer:

   whcnt++;
   uni=whcnt;
   last:
   if(whcnt>19)
 {
   goto eee;
 }

 if(!((x>450&&x<500&&y>450&&y<460)||(x>550&&x<600&&y>450&&y<460)))
 continue;

 if((x>450&&x<500&&y>450&&y<460))
 {go1:
 eee:
 float ttl;char txt8[20];
 ttl=total();
 ttl+=pro[no].tota();

 backbill();
 int hb=200;
 int vb=70;
 outtextxy(hb,vb,cmpany_name);
 outtextxy(hb,vb+20,add_name1);
 outtextxy(hb,vb+40,add_name2);
 outtextxy(hb,vb+60,add_name3);
 outtextxy(hb,vb+80,add_name4);
 outtextxy(hb,vb+100,add_name5);

  outtextxy(10,vb+100,manager_name);

 outtextxy(50,410,"the total billed amt=");
 sprintf(txt8,"%g",ttl);
 outtextxy(415,410,txt8);
 outtextxy(50,422,taxnm1);
 taxperc(ttl,taxp);
 sprintf(txt11,"%g",taxp);
 outtextxy(200,422,txt11);
 sprintf(txt9,"%g",ttl);
 outtextxy(415,422,txt9);
 if(t2_flag==1)
 { outtextxy(50,434,taxnm2);
   taxperc(ttl,taxs);
   sprintf(txt11,"%g",taxs);
   outtextxy(200,434,txt11);
   sprintf(txt10,"%g",ttl);
   outtextxy(415,434,txt10);
 }

 store(ttl);



 outtextxy(10,150,"bill no:");
 outtextxy(100,150,at);

 outtextxy(350,150,"date:");
 outtextxy(400,150,ctime(&tm));
 //showmanager();
 b<<"----------------------------------------------------";
 b<<"----------------------------------------------------\n";

 b1<<"----------------------------------------------------";
 b1<<"----------------------------------------------------\n";


 b<<"\nthe total billed amt=";
 b1<<"\nthe total billed amt=";
 b<<txt8<<"\n";
 b1<<txt8<<"\n";
 b<<"\nthe ";
 b1<<"\nthe ";
 b<<taxnm1<<"=";
 b1<<taxnm1<<"=";
 b<<taxp<<"%"<<"\n";
 b1<<taxp<<"%"<<"\n";
 if(t2_flag==1)
 {
 b<<"\nthe ";
 b1<<"\nthe ";
 b<<taxnm2<<"=";
 b1<<taxnm2<<"=";
 b<<taxs<<"%"<<"\n";
 b1<<taxs<<"%"<<"\n";

 }
 b<<"\nthe total amt+tax=";
 b1<<"\nthe total amt+tax=";
 b<<txt10<<"\n";
 b1<<txt10<<"\n";

 b1<<"\nthankyou visit again..\n";
 b<<"\nthankyou visit again..\n";

 //prn();
 ofstream fout;
 fout.open("PRN",ios::nocreate);
 if(fout.fail())
 {
 outtextxy(210,120,"printer not detected");

 }
 char ch;
 while(b1.get(ch)!=0)
 fout.put(ch);
 showmouse();
 while((!kbhit())&&(!(leftmousekeypressed())))
 {
 }

 b.close();
 b1.close();
 break;
 }

}while(!(x>550&&x<600&&y>450&&y<460));


go2:
fool:
f3.close();

}
void store(float ttl)
{

time_t t;
fstream b;
b.open("data//date",ios::app);
if(b.fail())
 {
 cout<<"open failed";
 }
time(&t);
b<<"Today's date and time:"<< ctime(&t)<<"\t" <<ttl<<"\n";
b.close();
}
int blldte(int p)
{
int nos;
int i=0;
fstream s;
s.open("data//billno.txt",ios::app|ios::nocreate);
if(s.fail())
{
i=1;
ofstream q1;
q1.open("data//billno.txt",ios::app);
q1.write((char*)&i,sizeof(i));
q1.close();

s.close();
return i;
}

else
{
s.close();
ifstream q2;
q2.open("data//billno.txt",ios::app);
q2.seekg(0);
q2.read((char*)&i,sizeof(i));
q2.close();
remove("data//billno.txt");
i+=p;
ofstream q1;
q1.open("data//billno.txt",ios::app);
q1.write((char*)&i,sizeof(i));
q1.close();
nos=(i);

return nos;
}

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
void  draw()
{

}
void sett()
{
settextstyle(1,0,1);
outtextxy(240,200,"Current time & date");

struct  time t;

gettime(&t);
Button br,be;
int a,b,c;
int i;
char t66[30],t55[30];
sprintf(t66,"%d::%d::%d", t.ti_hour,t.ti_min,t.ti_sec);
outtextxy(240,220,t66);
br_flag=0;
outtextxy(240,260,"Set current time [hh]::[mm]::[ss]");
outtextxy(240,280,"       ::        ::");
boxx(a,240,280,5);
if(br_flag==1)
{
goto g;
}

boxx(b,320,280,5);
boxx(c,400,280,5);
setfillstyle(1,7);
bar(235,275,460,295);
sprintf(t55,"%d::%d::%d", a,b,c);
outtextxy(240,280,t55);
t.ti_hour=a;
t.ti_min=b;
t.ti_sec=c;
outtextxy(240,300,"want to set this time?");

 br.init(244,372," Yes     ",FLAT);
 br.show();
 be.init(384,372,"  No     ",FLAT);
 be.show();
 i= selc(br,be,21,49);
 bar(235,295,420,315);

 if(i==1)
 {
   search_box("setting time..",240,300);
 settime(&t);
  outtextxy(240,342,"time set");

 }
g:

}

void check12()
  { hidemouse();
  char*txt="SUPER MARKET SUPERVISOR ver..2l";
  int x=220;
  int y=240;
  int d=20;
  int col1=8;
  int col2=15;
  int col3=2;
  int col4=1;

	setcolor(col1);
	 rectangle(x+8,y+13,x+273,y+23);

       setcolor(col2);
	 rectangle(x+9,y+14,x+274,y+24);

       setcolor(col3);
       settextstyle(0,0,1);
	 outtextxy(x,y,txt);

       delay(1000);

       for(int count=0;count<261;count++)
	  {
	       setfillstyle(1,col4);
		bar(x+12,y+16,((x+11)+count),y+21);
		if(count==0)
		{
		ifstream fi("pro//product",ios::app|ios::nocreate);
		if(fi.fail())
		{
		outtextxy(240,300,"product failed");
		break;

		}
		else
		{
		outtextxy(240,300,"product sucess");
		}
		fi.close();
		}
		else if(count==50)
		{
		setfillstyle(1,7);
		bar(235,295,420,315);
		ifstream fi("data//date",ios::app|ios::nocreate);
		if(fi.fail())
		{
		outtextxy(240,300,"date failed");
		break;

		}
		else
		{
		outtextxy(240,300,"date sucess");
		}
		fi.close();
		}
		else if(count==100)
		{
		setfillstyle(1,7);
		bar(235,295,420,315);
		ifstream fi("data//billprn.txt",ios::app|ios::nocreate);
		if(fi.fail())
		{
		outtextxy(240,300,"billprn.txt failed");
		break;

		}
		else
		{
		outtextxy(240,300,"billlprn.txt sucess");
		}
		fi.close();
		}
		else if(count==150)
		{
		setfillstyle(1,7);
		bar(235,295,420,315);
		ifstream fi("data//billprn1.txt",ios::app|ios::nocreate);
		if(fi.fail())
		{
		outtextxy(240,300,"billprn1.txt failed");
		break;

		}
		else
		{
		outtextxy(240,300,"billprn1.txt sucess");
		}
		fi.close();
		}
		else if(count==200)
		{
		setfillstyle(1,7);
		bar(235,295,420,315);
		ifstream fi("data//billno.txt",ios::app|ios::nocreate);
		if(fi.fail())
		{
		outtextxy(240,300,"billno failed");
		break;

		}
		else
		{
		outtextxy(240,300,"billno success");
		}
		fi.close();
		}
		else if(count==250)
		{
		setfillstyle(1,7);
		bar(235,295,420,315);
		ifstream fi("LCOM.CHR",ios::app|ios::nocreate);
		if(fi.fail())
		{
		outtextxy(240,300,"LCOM.CHR failed");
		break;

		}
		else
		{
		outtextxy(240,300,"LCOM.CHR success");
		}
		fi.close();
		}
		else if(count==260)
		{
		setfillstyle(1,7);
		bar(235,295,420,315);
		outtextxy(240,300,"complete success");
		}

	     delay(d);
	  }
       showmouse();
      while((!kbhit())&&(!(leftmousekeypressed())))
      {

     setcolor(14);
      outtextxy(240,320,"press any key!");
      delay(300);
      if(!(!kbhit())&&(!(leftmousekeypressed())))
      {goto la;
      }
      bar(235,315,420,335);
      if(!(!kbhit())&&(!(leftmousekeypressed())))
      {goto la;
      }
      delay(300);

     }
     la:
     showmouse();
  }
void final()
{
       Button Bill,Exit;
       Bill.init(111,57,"Check       ",FLAT);
       Bill.show( );
       if(but_flag==1)
       {
       Exit.init(111,77,"Mouse but * ",FLAT);
       Exit.show( );
       }
       else
       {
       Exit.init(111,77,"Mouse but   ",FLAT);
       Exit.show( );
       }
       int i= selc(Bill,Exit,46,50);
       if(i==2)
     {

     refresh();
     if(but_flag==1)
     but_flag=0;
     else
     but_flag=1;
     }
      else if(i==1)
     {

     final2();
     }

}
void final2()
{
refresh();
Panel extra;
extra.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);;
extra.show();
extra.shape("Extra");
check12();
  while((!kbhit())&&(!(leftmousekeypressed())))
  {
  }
refresh();
}
void writ()
{ int a=228,b=175;
 setcolor(8);
       settextstyle(1,0,1);
       outtextxy(a,b,"This file is not included in");
       outtextxy(a,b+20," this packadge and this needs");
       outtextxy(a,b+40," to be downloaded along with");
       outtextxy(a,b+60," your licence key.Please register");
       outtextxy(a,b+80," this software in--");
       outtextxy(a,b+100,"");
       outtextxy(a,b+120," www.cppprogramming.com");
       outtextxy(a,b+140,"");
       outtextxy(a,b+160,"");
       outtextxy(a,b+180,"");

       moveto(a,b+240);
       setcolor(8);
       outtext("Freeware valid till  31/12/2009");
       restore_previous_settings( );

}
void tdelete(product sd,int rno)
{
product s1;
ifstream fio("pro//product",ios::app);
ofstream file("pro//temp_asd",ios::out);
fio.seekg(0);
char found='f';
char confirm='y';
while(!fio.eof())
{
fio.read((char*)&s1,sizeof(product));
if(s1.no()==rno)
{
found='t';
s1.display();


if(confirm=='n')
{ file.write((char*)&sd,sizeof(product));}

}
else
file.write((char*)&s1,sizeof(product));

}//eow
fio.close();
file.close();
remove("pro//product");
rename("pro//temp_asd","product");
if(found!='t')
{
cout<<"error...............";
}
}
int grapic()
{
       int x1=480;
       int y1=170;
       int dx=45;
       int dy=20;
       Button F1,F2,F3,F4,F5,F6,F7,F8,F9,F0,F11;
       F1.init(x1,y1,"1   ",FLAT);
       F1.show( );

       F2.init(x1+dx,y1,"2   ",FLAT);
       F2.show( );

       F3.init(x1+(2*(dx)),y1,"3   ",FLAT);
       F3.show( );

       F4.init(x1,y1+dy,"4   ",FLAT);
       F4.show( );

       F5.init(x1+dx,y1+dy,"5   ",FLAT);
       F5.show( );

       F6.init(x1+(2*(dx)),y1+dy,"6   ",FLAT);
       F6.show( );

       F7.init(x1,y1+(2*(dy)),"7   ",FLAT);
       F7.show( );

       F8.init(x1+dx,y1+(2*(dy)),"8   ",FLAT);
       F8.show( );

       F9.init(x1+(2*(dx)),y1+(2*(dy)),"9   ",FLAT);
       F9.show( );

       F0.init(x1,y1+(3*(dy)),"0   ",FLAT);
       F0.show( );

       F11.init(x1+dx,y1+(3*(dy)),"ENTER     ",FLAT);
       F11.show( );

int key= selc9(F1,F2,F3,F4,F5,F6,F7,F8,F9,F0,F11,120,121,122,123,124,125,126,127,128,129,18);

return key;
}
int selc9(Button &b1,Button &b2,Button &b3,Button &b4,Button &b5,Button &b6,Button &b7,Button &b8,Button &b9,Button &b0,Button &b11,int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9,int a0,int a11)
{

       int selected=0;

       do
	  {
	     if(leftmousekeypressed( ) && b1.hit( ))
		{
		   b1.press_and_release(LEFT_MOUSE_KEY);

		   selected=1;
		}

	     else if(leftmousekeypressed( ) && b2.hit( ))
		{
		   b2.press_and_release(LEFT_MOUSE_KEY);

		   selected=2;
		}
		 else if(leftmousekeypressed( ) && b3.hit( ))
		{
		   b3.press_and_release(LEFT_MOUSE_KEY);

		   selected=3;
		}
		 else if(leftmousekeypressed( ) && b4.hit( ))
		{
		   b4.press_and_release(LEFT_MOUSE_KEY);

		   selected=4;
		}
		 else if(leftmousekeypressed( ) && b5.hit( ))
		{
		   b5.press_and_release(LEFT_MOUSE_KEY);

		   selected=5;
		}
		 else if(leftmousekeypressed( ) && b6.hit( ))
		{
		   b6.press_and_release(LEFT_MOUSE_KEY);

		   selected=6;
		}
		 else if(leftmousekeypressed( ) && b7.hit( ))
		{
		   b7.press_and_release(LEFT_MOUSE_KEY);

		   selected=7;
		}
		 else if(leftmousekeypressed( ) && b8.hit( ))
		{
		   b8.press_and_release(LEFT_MOUSE_KEY);

		   selected=8;
		}
		 else if(leftmousekeypressed( ) && b9.hit( ))
		{
		   b9.press_and_release(LEFT_MOUSE_KEY);

		   selected=9;
		}
		 else if(leftmousekeypressed( ) && b0.hit( ))
		{
		   b0.press_and_release(LEFT_MOUSE_KEY);

		   selected=12;
		}
		else if(leftmousekeypressed( ) && b11.hit( ))
		{
		   b11.press_and_release(LEFT_MOUSE_KEY);

		   selected=-1;
		}

		else if(rightmousekeypressed( ))
		{
		selected=-1;
		}




	     else if(kbhit( ))
		{
		   int key_code_1=0;
		   int key_code_2=0;

		   char key_1=NULL;
		   char key_2=NULL;

		   key_1=getch( );
		   key_code_1=int(key_1);



		   if(key_code_1==0)
		      {
			 key_2=getch( );
			 key_code_2=int(key_2);
		      }

		   if(key_code_1==0)
		      {

			 if(key_code_2==a1)
			    {
			       b1.press_and_release(KEY_BOARD);

			       selected=1;
			    }

			 else if(key_code_2==a2)
			    {
			       b2.press_and_release(KEY_BOARD);

			       selected=2;
			    }
			    else if(key_code_2==a3)
			    {
			       b3.press_and_release(KEY_BOARD);

			       selected=3;
			    }
			    else if(key_code_2==a4)
			    {
			       b4.press_and_release(KEY_BOARD);

			       selected=4;
			    }
			    else if(key_code_2==a5)
			    {
			       b5.press_and_release(KEY_BOARD);

			       selected=5;
			    }
			    else if(key_code_2==a6)
			    {
			       b6.press_and_release(KEY_BOARD);

			       selected=6;
			    }
			    else if(key_code_2==a7)
			    {
			       b7.press_and_release(KEY_BOARD);

			       selected=7;
			    }
			    else if(key_code_2==a8)
			    {
			       b8.press_and_release(KEY_BOARD);

			       selected=8;
			    }
			    else if(key_code_2==a9)
			    {
			       b9.press_and_release(KEY_BOARD);

			       selected=9;
			    }
			    else if(key_code_2==a0)
			    {
			       b0.press_and_release(KEY_BOARD);

			       selected=12;
			    }
			    else if(key_code_2==a11)
			    {
			       b11.press_and_release(KEY_BOARD);

			       selected=-1;
			    }

		      }
		       else if(key_code_1==27)
			    {


			       selected=-1;
			    }
		}
	  }
       while(!selected);

return selected;
}
void passrder()
{
char name1[80];
char pass1[80];
char inpt[80];
int cnt=0;
int sd=9;
int flag=0;
fstream op;


int x2=240;
int y2=180;
int d=1;
	{
	     while(cnt<3)
	      {

	      d=(cnt*60);
	      outtextxy(x2,y2-40+d,"password..");
	      txt_box(inpt,x2,y2-20+d);

		 op.open("pro//passwrd.txt",ios::app|ios::nocreate|ios::in);
	if(op.fail())
	{
	cout<<"    open failed        ";
	}
	else
	      {
		 op.seekg(ios::beg);
		while(!op.eof())
		{
		 op.getline(name1,80);
		 op.getline(pass1,80);
	     char c=decrypt(name1,pass1);
		 sd=strcmpi(pass1,inpt);
			if(sd==0)
			{
			 cfc(c);
			 cout<<name1;
			 flag=1;
			 strcpy(manager_name,name1);
			 break;
			}

		}
		cnt++;
		if(flag==1)
		{
		break;
		}
		else
		{
		outtextxy(x2,y2-60+d,"wrong password");

		}
		op.close();
	      } }
	      if(flag==0)
	      {
	      outtextxy(x2,y2+d,"failed thrice aborting....");
	      int cnt=0;
	      while((!kbhit())&&(!(leftmousekeypressed())))
	      cnt++;

	      exit(0);

	      }
	}


}
 void cmpnarder()
{
int cnt=1;
int num;
char name1[80];

char txt1[40];
char txt2[40];
fstream op;
int x2=240;
int y2=150;
int dy=10;
Panel add ;
fstream n;
n.open("pro//compname.txt",ios::app|ios::nocreate);
if(n.fail())
{
n.close();
goto lar;
}
n.close();

settextstyle(1,0,1);


		 op.open("pro//compname.txt",ios::app|ios::in);
	if(op.fail())
		{
		settextstyle(1,0,1);
	outtextxy(x2,y2+((6*dy)*cnt),"    open failed        ");
		}
	else
	      {
		 op.getline(name1,80);
		 strcpy(cmpany_name,name1);


	      }
	      op.close();
	      cnt++;


lar:

       }
void cmpadrder()
{
int cnt=1;
int num;
char name1[80];
char name2[80];
char name3[80];
char name4[80];
char name5[80];
char txt1[40];
char txt2[40];
fstream op;
int x2=240;
int y2=150;
int dy=10;
Panel add ;
fstream n;
n.open("pro//compadd.txt",ios::app|ios::nocreate);
if(n.fail())
{
n.close();
goto lar;
}
n.close();

settextstyle(1,0,1);

 {
		 op.open("pro//compadd.txt",ios::app|ios::in);
	if(op.fail())
		{
		settextstyle(1,0,1);
	outtextxy(x2,y2+((6*dy)*cnt),"    open failed        ");
		}
	else
	      {

		 op.getline(name1,80);
		 op.getline(name2,80);
		 op.getline(name3,80);
		 op.getline(name4,80);
		 op.getline(name5,80);


		strcpy(add_name1,name1);
		strcpy(add_name2,name2);
		strcpy(add_name3,name3);
		strcpy(add_name4,name4);
		strcpy(add_name5,name5);

	      }
	      op.close();
	      cnt++;
	}

lar:

       }
     void  opener()
       {
       refresh();
       passrder();
       }
    void dsp()
     {

     cout<<cmpany_name<<"\n";
     cout<<manager_name<<"\n";
     cout<<add_name1<<"\n";
     cout<<add_name2<<"\n";
     cout<<add_name3<<"\n";
     cout<<add_name4<<"\n";
     cout<<taxp<<"\n";
     cout<<taxnm1<<"\n";
     cout<<taxs<<"\n";
     cout<<taxnm2<<"\n";
     cout<<t2_flag;
     }
 void taxrder()
 {
 int cnt=1;
int num;
char name1[80],name2[80];

char txt1[40];
char txt2[40];
fstream op;
int x2=240;
int y2=150;
int dy=10;
int tax1=0,tax2=0;
char ch;
Panel add ;
fstream n;
n.open("pro//tax.txt",ios::app|ios::nocreate);
if(n.fail())
{
n.close();
goto lar;
}
n.close();

settextstyle(1,0,1);


       {
	      settextstyle(1,0,1);

		 op.open("pro//tax.txt",ios::app|ios::in);
		 op.seekp(0);
	if(op.fail())
		{
		settextstyle(1,0,1);
	outtextxy(x2,y2+((6*dy)*cnt),"    open failed        ");
		}
	else
	      {

		 op.getline(name1,80);
		 op>>tax1;
		 strcpy(taxnm1,name1);
		 taxp=tax1;
		 op.getline(txt1,80);
		  if(!op.eof())
		 {
		 op.getline(name2,80);
		 op>>tax2;
		 taxs=tax2;
		 strcpy(taxnm2,name2);
		 t2_flag=1;
		 }
		 else
		 {
		 t2_flag=0;
		 }

	      }
	      op.close();
	      cnt++;
	}

lar:

      }
  void globals()
  {

strcpy(n1,"slno");



strcpy(n2,"pdno");


strcpy(n3,"item");




strcpy(n4,"quantity");



strcpy(n5,"price");


strcpy(n6,"tot");



}

 void taxperc(float& ttl,float tax)
 {
  float temp=0;
  temp=ttl*tax;
  temp/=100;
  ttl+=temp;

 }
char decrypt(char in1[],char in2[])
{
char out[80];
char out1[80];
char out2[80];
int l1=strlen(in1);
int l2=strlen(in2);
for(int i=0,j=0;i<l1;i++,j+=2)
{
in1[i]-=1;
out[j]=in1[i];
}
for( i=0,j=1;i<l2-2;i++,j+=2)
{
in2[i]+=1;
out[j]=in2[i];
}
char a=in2[l2-2];
int n=(int)a;
n-=65;
for(i=0;i<n;i++)
{
in1[i]=out[i];
in2[i]=out[i+n];
}


char s=in2[l2-1];
in2[l2-2]=NULL;
in2[l2-1]=NULL;
return s;
}
void refresh1()
{
refresh();
Panel help;
help.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);;
help.show();
help.shape("Help");

}
void cfc(char a)
{
char z;
int q=pr_id_1%10;
z=65+q;
if(!(a==z))
{
cout<<"breeching security....";
getch();
exit(0);
}
}

void help1()
{
int bo_3=0;
fstream f1;
f1.open("help1//help.txt",ios::app|ios::nocreate);
if(f1.fail())
{
f1.close();
Panel move;

       move.init(220,120,525,455,OUT,THIN);
       move.show( );
       move.shape("HELP");

writ();

}
else
{
f1.close();
fstream f;
 f.open("help1//help.txt",ios::app|ios::in);
	if(f.fail())
		{
	       int  x2=200;
	       int  y2=200;
	       int dy=20;
	       int cnt=1;
		settextstyle(1,0,1);
	outtextxy(x2,y2+((6*dy)*cnt),"    open failed        ");
		}
	else
		{
	      char line[80];
	      int d=20;
	      int a=0;
	      int x=20;
	      int y=110;
	      int p=15;
	      int cnt=0;
		      while(1)
			{
	     lx:
	      a=cnt%d;
	      if(cnt<=0)
	      {
	      cnt=0;
	      }


	   if(a==0&&cnt!=0)
		{

	      Button F1,F2,F3;
	      F1.init(245,440,"Next",NORMAL,0,-2);
	      F1.show( );

	      F2.init(345,440,"Back",NORMAL,0,-2);
	      F2.show( );

	      F3.init(445,440,"Exit",NORMAL,0,-2);
	      F3.show( );
	      int s=selc3(F1,F2,F3,49,48,18);
	      if(s==3)
		{
	      refresh();
	      break;
	      }
	      else if(s==1)
	      {
	      cnt++;
	      refresh1();
	      continue;
	      }
	      else if(s==2)
	      {
	      refresh1();
	      cnt-=(2*d);
	      f.seekg(0,ios::beg);

	      for(int i=0;i<cnt;i++)
	      {
	      f.getline(line,80);
	      }
	      cnt++;
	      refresh1();
	      continue;
	      }
	      else
	      {
	      refresh1();
	      }

	      }
	      if(f.eof())
	      {
	      outtextxy(400,400,"end..");
	      bo_3=1;
	      {
	      Button F1,F2,F3;
	      F1.init(245,440,"Next",NORMAL,0,-2);
	      F1.show( );

	      F2.init(345,440,"Back",NORMAL,0,-2);
	      F2.show( );

	      F3.init(445,440,"Exit",NORMAL,0,-2);
	      F3.show( );
	      int s=selc3(F1,F2,F3,49,48,18);
	      if(s==3)
		{
	      refresh();
	      goto last;
	      }
	      else
	      goto l;
	      }






	      }
	      f.getline(line,80);
	      setcolor(16);
	      settextstyle(3,0,1);
	      outtextxy(x,y+(a*p),line);
	      cnt++;

	      }


	      }

	       l:

	      f.close();
 if(bo_3==1)
{
bo_3=0;
refresh1();
help1();

}




}
last:
}
