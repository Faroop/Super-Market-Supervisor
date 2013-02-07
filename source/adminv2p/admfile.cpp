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
void encrypt(char [],char []);
void passins();
int chkred(int rn);
void refresh();
void modif();
void cmpna();
void cmpad();
void taxation();
void passboxx();
int pr_id_1=12345;
int br_flag=0;
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
pr_id=pr_id_1;
}
int no();
void retname(char a[]);
float retprice();
void appm(product s1);
void display();
void getdata();
}pro[256],pdtbilled[20],s1;
void product::retname(char na[])
{
strcpy(na,name);

}
float product::retprice()
{
return price;

}



void draw();
union REGS mouse;
void getmouse(int &btn,int&x,int&y)
{
mouse.x.ax=3;
int86(0x33,&mouse,&mouse);
btn=mouse.x.bx;
x=mouse.x.cx;
y=mouse.x.dx;
}
void ccoc();
void runner();
void tdelete();
void tsearch();
void data(int=228,int=175);
void data2(int=228,int=175);


void tappend();
void data1();
void pass();


void add();void _delete();void modify();void about();void exitg();void search();

void pannelexamp();
void wrkng(int choice);
int selc(Button &b1,Button &b2,Button &b3,Button &b4,Button &b5,Button &b6,int a1,int a2,int a3,int a4,int a5,int a6);
int selc(Button &b1,Button &b2,int n,int o);
void shape1(char*txt,int x,int y);
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
 void passboxx(char ast[],int x=50,int y=50,int size=20,int col1=11,int col2=0,int col3=7)
       {
       get_current_settings( );
  char s[40]={NULL};
  char p[40]={NULL};



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
		   p[count_]=NULL;
		   count_--;

		}
	  else
	  {
	  char* d=NULL;
	  *d=(char)key;
	  strcat(s,d);


	 //if(count_!=0)
	   p[count_-1]='*';
	  cout<<count_;


	  }
	      if(count_<3)
	      {
	      setfillstyle(1,8);
	       bar(x_1,y_1,x_2,y_2);
	      }

	     setcolor(col1);
	     settextstyle(0,0,1);
	       moveto((x_1+5),(y_1+4));

	       setfillstyle(1,8);
	       bar(x_1,y_1,x_2,y_2);

		 outtext(p);

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
outtextxy(400,400,ast);
getch();
restore_previous_settings( );

       }
 int box3(float& a,int x1,int y1)
  {
  int tag=0;
  int size=20;
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
	     if(key_code==27)
	     {
		tag=1;
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
return tag;
  }
  int textbox3(char ast[],int x=50,int y=50,int size=20,int col1=11,int col2=0,int col3=7)
  {
  int tag=0;
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
	     if(key_code==27)
	     {
		tag=1;
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
return tag;
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
void boxx(int& a,int x1,int y1)
{
 int size=20;
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
		   key=NULL;
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


   sscreen( );
   getch();
   closegraph();

   return 0;
}
int selc(Button &b1,Button &b2,int n,int o)
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
		if(rightmousekeypressed( ) )
		{


		   br_flag=1;
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
		else if(key_code_1==27)
	     {
		br_flag=1;
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
		      }
		}
	  }
       while(!selected);

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

       Button Add,Delete,Modify,Search,About,Exit;
       Add.init(6,35,"Add         ",FLAT);
       Add.show( );

       Delete.init(111,35,"Delete      ",FLAT);
       Delete.show( );

       Modify.init(221,35,"Modify      ",FLAT);
       Modify.show( );

       Search.init(331,35,"Search      ",FLAT);
       Search.show( );


       About.init(441,35,"About       ",FLAT,0,0,7,1);
       About.show( );

       Exit.init(551,35,"Exit     ",FLAT);
       Exit.show( );

       Screen.init(5,53,632,467,IN,THICK,0);

       Screen.show( );

       setcolor(8);
	 rectangle(4,53,633,471);

       setcolor(15);
	 rectangle(5,54,634,472);
	 initmouse();

	while(1)
	{
	showmouse();
	 int ch=selc(Add,Delete,Modify,Search,About,Exit,30,32,50,31,48,18);

	 hidemouse();
	 wrkng(ch);

	}
    }
    void wrkng(int choice)
    {
    switch(choice)
    {
    case 1: add();   break;
    case 2: _delete();   break;
    case 3: modify();   break;
    case 4: search();   break;
    case 5: about();   break;
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
		      }
		}
	  }
       while(!selected);
       Panel scribble;
       scribble.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);
       scribble.show();
return selected;
}

void add()
{
Panel add ;
Panel scribble;
add.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);
add.show();
add.shape("ADD");

get_current_settings( );
cmpna();
Panel move;
move.init(220,120,525,455,OUT,THIN);
       move.show( );
       move.shape("ADD");
cmpad();
move.init(220,120,525,455,OUT,THIN);
       move.show( );
       move.shape("ADD");

       scribble.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);
       scribble.show();
add.show();
add.shape("ADD");

passins();
move.init(220,120,525,455,OUT,THIN);
       move.show( );
       move.shape("ADD");
taxation();
move.init(220,120,525,455,OUT,THIN);
       move.show( );
       move.shape("ADD");

      runner();
int cnt=0;
cnt++;

       scribble.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);
       scribble.show();


}
void modify()
{
showmouse();
tappend();
refresh();
int cnt=0;
while((!kbhit())&&(!(leftmousekeypressed())))
cnt++;


Panel scribble;
       scribble.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);
       scribble.show();

}
void search()
{
Panel search;
search.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);;
search.show();
search.shape("SEARCH");


Panel move;

       move.init(220,120,525,455,OUT,THIN);
       move.show( );
       move.shape("SEARCH");




      settextstyle(1,0,1);

       tsearch();
int cnt=0;
while((!kbhit())&&(!(leftmousekeypressed())))
cnt++;
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
int cnt=0;
while((!kbhit())&&(!(leftmousekeypressed())))
cnt++;
Panel scribble;
       scribble.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);
       scribble.show();

}
void _delete()
{
Panel _delete;
_delete.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);;
_delete.show();
_delete.shape("Delete");
Panel move;

       move.init(220,120,525,455,OUT,THIN);
       move.show( );
       move.shape("Delete");
       settextstyle(1,0,1);





	 tdelete();
int cnt=0;
while((!kbhit())&&(!(leftmousekeypressed())))
cnt++;
Panel scribble;
       scribble.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);
       scribble.show();


}


void product::display()
{ char t1[40],t2[40],t3[40];
sprintf(t1,"%g",price);
sprintf(t2,"%d",prno);
//sprintf(t3,"%d",qty);
//outtextxy(240,202,"price");
outtextxy(240,242,name);
outtextxy(240,262,t1);
outtextxy(240,282,t2);
//outtextxy(240,302,t3);
char*x=NULL;
int t=0;
sprintf(x,"%d",t);



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
//settextstyle(1,0,1);
//outtextxy(240,322,"Qty");
//restore_previous_settings( );
//boxx(qty,260,342);
restore_previous_settings( );

}
void runner()
{


ccoc();


}
void tsearch()
{

int rn;
char found='n';
ifstream fi("pro//product",ios::app);
if(fi.fail())
{
outtextxy(240,202,"open failed");
goto last;
}
fi.seekg(0);
outtextxy(240,202,"prno");
boxx(rn,240,222);

while(!fi.eof())
{
fi.read((char*)&s1,sizeof(product));
if(s1.no()==rn)
{
outtextxy(240,182,"all your data");
s1.display();
found='y';
break;
}

}
if (found=='n')
{
outtextxy(240,242,"product not found");
}
last:

fi.close();

}




void tdelete()
{

ifstream fio("pro//product",ios::app);
ofstream file("pro//temp",ios::out);
fio.seekg(0);
int rno;
char found='f';
char confirm='n';
outtextxy(240,202,"enter prno to be deleted");
boxx(rno,240,222);
int vas=0;
while(!fio.eof())
{
fio.read((char*)&s1,sizeof(product));
if(s1.no()==rno)
{
found='t';
s1.display();
outtextxy(240,322,"   want to del this file(y/n)   ");
if(vas==0)
confirm=getch();
char aop[1]={NULL};
sprintf(aop,"%c",confirm);
outtextxy(240,342,aop);
vas++;


if(confirm=='n')
{ file.write((char*)&s1,sizeof(product));}

}
else
file.write((char*)&s1,sizeof(product));

}//eow

if(found=='f')
outtextxy(240,242,"record not found");
fio.close();
file.close();
remove("pro//product");
rename("pro//temp","pro//product");


fio.close();
file.close();

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
  void ccoc()
  {
     int rn,q;
     fstream f3;
	f3.open("pro//product",ios::app);
	f3.seekg(0);
	if(f3.fail())
	{

	outtextxy(40,40,"This is a deault file");
	}

	 int whcnt=0;
  do
  {

	 pro[whcnt].getdata();
	 rn=pro[whcnt].no();
	 if(rn==0)
	 {
	 goto last;
	 }
	q=chkred(rn);

	 if(q==1)
	 {
	 f3.seekg(ios::end);
	f3.write((char*)&pro[whcnt],sizeof(product));
	}

  Panel Check;

       Check.init(220,120,525,455,OUT,THIN);
       Check.show( );
       Check.shape("Choice Box");




       Button Next;
       Button Cancel;

       Next.init(265,260,"Next ",NORMAL,0,-2);
       Next.show( );

       Cancel.init(385,260,"Halt",NORMAL,0,-2);
       Cancel.show( );
       initmouse();
       showmouse();


     int i= selc(Next,Cancel,49,35);
     if(i!=1)
     { break;
     }

       Check.modify(220,120,525,455,OUT,THIN);
       Check.show();
       Check.shape("Add");
   whcnt++;
  } while(1);
  last:
  f3.close();
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
       outtextxy(a,b+160,"           ADMINISTRATOR     ");
       outtextxy(a,b+180,"");

       moveto(a,b+240);
       setcolor(4);
       outtext("By Sadanandh");
       outtextxy(a,b+260,"PROFITZ SOLUTIONS");
       showmouse();
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

void tappend()
  {

       Button Data,Pass;
       Data.init(221,57,"Data       ",FLAT);
       Data.show( );
       Pass.init(221,77,"Password   ",FLAT);
       Pass.show( );
       int i= selc(Data,Pass,32,25);
       if(i==1)
     {

     data1();
     }
      else if(i==2)
     {
      modif();
     }

  }
void data1()
  {
  hidemouse();
  Panel modify;
modify.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);;
modify.show();
modify.shape("MODIFY");
Panel move;

       move.init(220,120,525,455,OUT,THIN);
       move.show( );
       move.shape("MODIFY");
showmouse();
settextstyle(0,0,1);

ifstream fio("pro//product",ios::app);
ofstream file("pro//temp",ios::out);
fio.seekg(0);
product s1,s2;
int rno;
char found='f';
char confirm='y';
outtextxy(240,202,"enter prno to append");
boxx(rno,240,222);
while(!fio.eof())
{
fio.read((char*)&s1,sizeof(product));
if(s1.no()==rno)
{
found='t';


if(confirm=='y')
{ s1.display();
  s2.appm(s1);
 file.write((char*)&s2,sizeof(product));}
 confirm='n';
}
else
file.write((char*)&s1,sizeof(product));

}

if(found=='f')
outtextxy(240,242,"record not found");
fio.close();
file.close();
remove("pro//product");
rename("pro//temp","pro//product");


fio.close();
file.close();

  }


void product::appm(product s1)
  {
  int b=0,c=0;
  float a=0;
 int x1=240;
 int y1=382;
 char deflt[80];
 char yy[80];
 prno=s1.no();
 s1.retname(yy);
int col=getcolor();
 setcolor(4);
 outtextxy(x1,302,"TO RETAIN DATA PRESS esc");
 setcolor(col);
 outtextxy(x1,322,"New Name?");
 c=textbox3(deflt,x1,342);
 if(c==1)
 {
  strcpy(name,yy);

  }
  else
  {
  strcpy(name,deflt);
  }
 outtextxy(x1,362,"New Price?");
 b=box3(a,x1,y1);

 if(b==1)
 {
  price=s1.retprice();
  }
  else
  {
  price=a;
  }
  outtextxy(x1,402,"ok?");
 }



void passins()
{
int cnt=1;
int num;
char name1[80];
char pass1[80];
char txt1[40];
char txt2[40];
fstream op;
int x2=240;
int y2=180;
int dy=10;
Panel add ;
fstream n;
n.open("pro//passwrd.txt",ios::app|ios::nocreate);
if(!n.fail())
{
n.close();
goto lar;
}
n.close();

settextstyle(1,0,1);
outtextxy(x2,y2-40,"no of employee");
boxx(num,x2,y2-20);
while(cnt<(num+1))

       {      strcpy(txt1,"employee no");
	      sprintf(txt2,"%d",cnt);
	      strcat(txt1,txt2);
	      settextstyle(1,0,1);
	       outtextxy(x2,y2,txt1);
	       outtextxy(x2,y2+20,"name:");
		txt_box(name1,x2,y2+40);
		 outtextxy(x2,y2+60,"pass:");
			txt_box(pass1,x2,y2+80);

add.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);;
add.show();
add.shape("ADD");
		 op.open("pro//passwrd.txt",ios::app|ios::out);
	if(op.fail())
		{
		settextstyle(1,0,1);
	outtextxy(x2,y2+((6*dy)*cnt),"    open failed        ");
		}
	else
	      {
		  encrypt(name1,pass1);
		 op<<name1<<"\n";
		 op<<pass1<<"\n";

	      }
	      op.close();
	      cnt++;
	}

lar:
}
int chkred(int rn)
{
int x=0;
int rno;
char confirm='n';
//char found='n';
ifstream fi("pro//product",ios::app);
if(fi.fail())
{
outtextxy(240,202,"open failed");
goto last;
}
fi.seekg(0);

while(!fi.eof())
{
fi.read((char*)&s1,sizeof(product));
if(s1.no()==rn)
{
Panel add ;
add.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);;
add.show();
add.shape("ADD");
Panel move;
move.init(220,120,525,455,OUT,THIN);
       move.show( );
       move.shape("ADD");

settextstyle(1,0,1);
outtextxy(230,182,"data already exists please delete it");
s1.display();
getch();
break;
}

}
last:

if (confirm=='y')
{
 x=1;
}
x=1;
return x ;
}
void refresh( )
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

       Button Add,Delete,Modify,Search,About,Exit;
       Add.init(6,35,"Add         ",FLAT);
       Add.show( );

       Delete.init(111,35,"Delete      ",FLAT);
       Delete.show( );

       Modify.init(221,35,"Modify      ",FLAT);
       Modify.show( );

       Search.init(331,35,"Search      ",FLAT);
       Search.show( );


       About.init(441,35,"About       ",FLAT,0,0,7,1);
       About.show( );

       Exit.init(551,35,"Exit     ",FLAT);
       Exit.show( );

       Screen.init(5,53,632,467,IN,THICK,0);

       Screen.show( );

       setcolor(8);
	 rectangle(4,53,633,471);

       setcolor(15);
	 rectangle(5,54,634,472);
	 Panel scribble;
       scribble.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);
       scribble.show();

	 showmouse();


	}
      void modif()
       {

       char y='n';
       settextstyle(1,0,1);
       outtextxy(240,182,"delete all old password?(y/n)");
       y=getch();
       if(y=='y')
       {
       remove("pro//passwrd.txt");
       settextstyle(1,0,1);
       }

       }
       void cmpna()
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
if(!n.fail())
{
n.close();
goto lar;
}
n.close();

settextstyle(1,0,1);


       {
	      settextstyle(1,0,1);
	       outtextxy(x2,y2+20,"company name:");
		txt_box(name1,x2,y2+40);

add.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);;
add.show();
add.shape("ADD");
		 op.open("pro//compname.txt",ios::app|ios::out);
	if(op.fail())
		{
		settextstyle(1,0,1);
	outtextxy(x2,y2+((6*dy)*cnt),"    open failed        ");
		}
	else
	      {

		 op<<name1<<"\n";


	      }
	      op.close();
	      cnt++;
	}

lar:

       }
       void cmpad()
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
	if(!n.fail())
	{
	n.close();
	goto lar;
	}
	n.close();

	settextstyle(1,0,1);


       {
	      settextstyle(1,0,1);
	       outtextxy(x2,y2+20,"company address(4-lines)");
		txt_box(name1,x2,y2+40);
		txt_box(name2,x2,y2+60);
		txt_box(name3,x2,y2+80);
		txt_box(name4,x2,y2+100);
		outtextxy(x2,y2+120,"company ph-number(1-line)");
		txt_box(name5,x2,y2+140);

add.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);;
add.show();
add.shape("ADD");
		 op.open("pro//compadd.txt",ios::app|ios::out);
	if(op.fail())
		{
		settextstyle(1,0,1);
	outtextxy(x2,y2+((6*dy)*cnt),"    open failed        ");
		}
	else
	      {

		 op<<name1<<"\n";
		 op<<name2<<"\n";
		 op<<name3<<"\n";
		 op<<name4<<"\n";
		 op<<name5<<"\n";


	      }
	      op.close();
	      cnt++;
	}

lar:

       }
       void taxation()
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
	char more='n';

	Panel add ;
	fstream n;
	n.open("pro//tax.txt",ios::app|ios::nocreate);
	if(!n.fail())
	{
	n.close();
	goto lar;
	}
	n.close();

	settextstyle(1,0,1);


       {
	      settextstyle(1,0,1);
	      outtextxy(x2,y2+20,"taxname");
		txt_box(name1,x2,y2+40);
	       outtextxy(x2,y2+60,"tax1:%");
	      boxx(tax1,x2,y2+80);
	      outtextxy(x2+200,y2+60,"onether tax?(y/n)");
	      more=getch();
	      if(more=='y')
	      {
	      outtextxy(x2,y2+100,"taxname:");
		txt_box(name2,x2,y2+120);
	       outtextxy(x2,y2+140,"tax2:%");
	      boxx(tax2,x2,y2+160);
	      }
add.init(6,56,getmaxx()-5,getmaxy()-7,THIN,IN);;
add.show();
add.shape("ADD");
		 op.open("pro//tax.txt",ios::app|ios::out);
	if(op.fail())
		{
		settextstyle(1,0,1);
	outtextxy(x2,y2+((6*dy)*cnt),"    open failed        ");
		}
	else
	      {

		 op<<name1<<"\n";
		 op<<tax1;
		 if(more=='y')
		 {
		 op<<"\n"<<name2<<"\n";
		 op<<tax2<<"\n";
		 }

	      }
	      op.close();
	      cnt++;
	}

lar:

       }
void encrypt(char in1[],char in2[])
{
int l;
char out[80]={NULL};
char out1[80]={NULL};
char out2[80]={NULL};
l=strlen(in1);
strcat(in1,in2);
strcpy(out,in1);
int len=strlen(out);
for(int i=0,j=0;i<len;i+=2,j++)
{
out[i]+=1;
out1[j]=out[i];
}
for(i=1,j=0;i<len;i+=2,j++)
{
out[i]-=1;
out2[j]=out[i];
}
char a=l+65;
strcpy(in1,out1);
strcpy(in2,out2);
char txt[2]={NULL};
txt[0]=a;
strcat(in2,txt);
char z;
int q;
q=pr_id_1%10;
z=65+q;
char txt1[2]={NULL};
txt1[0]=z;
strcat(in2,txt1);

}
