 # include   "Gui.h"
 # include "Mouse.h"

 /*************************************************************************/
 /*************************************************************************/
 //------------------------  Global Variables  ---------------------------//
 /*************************************************************************/
 /*************************************************************************/

 int text_font=0;
 int text_direction=0;
 int text_size=0;
 int text_color=0;
 int fill_pattern=0;
 int fill_color=0;/************************************************************************
  ************************************************************************
  ************************  Class Panel  *********************************
  ************************************************************************
  ***********************************************************************/

 /************************************************************************/
 //---------------------------  Panel( )  -------------------------------//
 /************************************************************************/

 Panel::Panel( )
    {
       x1=0;
       y1=0;
       x2=0;
       y2=0;
       in_out=IN;
       thick_thin=THIN;
    }

      void Panel:: shape(char*txt)                 //233 119
 {

    int x=x1+13;
    int y=y1-1;


     setcolor(8);
	 rectangle(x1+4,y1+4,x2-5,y+41);
	 rectangle(x1+4,y+48,x2-5,y2-5);

       setcolor(15);
	 rectangle(x1+5,y+6,x2-4,y+42);
	 rectangle(x1+5,y+
	 49,x2-4,y2-4);

       setfillstyle(3,5);
	 bar(x1+8,y1+8,x2-8,y+38);
     settextstyle(8,0,4);                       //0-black(shadow)
	 setcolor(0);
	   outtextxy(x,y,txt);
	   outtextxy(x+1,y,txt);
	  settextstyle(8,0,4);
	 setcolor(14);                          //14-yello
	   outtextxy(x+2,y-1,txt);
	   outtextxy(x+3,y-1,txt);
	   outtextxy(x+4,y-1,txt);
	    settextstyle(2,0,11);

}
/*void Panel:: shape(char*txt,int col1,int col2)                 //233 119
 {
    int x=x1+13;
    int y=y1-1;


     setcolor(8);
	 rectangle(x1+4,y1+4,x2-5,y+41);
	 rectangle(x1+4,y+48,x2-5,y2-5);

       setcolor(15);
	 rectangle(x1+5,y+6,x2-4,y+42);
	 rectangle(x1+5,y+
	 49,x2-4,y2-4);

       setfillstyle(1,col1);
	 bar(x1+8,y1+8,x2-8,y+38);
     settextstyle(8,0,4);                       //0-black(shadow)
	 setcolor(0);
	   outtextxy(x,y,txt);
	   outtextxy(x+1,y,txt);

	 setcolor(col2);                          //14-yello
	   outtextxy(x+2,y-1,txt);
	   outtextxy(x+3,y-1,txt);
	   outtextxy(x+4,y-1,txt);
}
*/

 /************************************************************************/
 //-----------------  init(int,int,int,int,int,int,int)  ----------------//
 /************************************************************************/

 void Panel::init(int left,int top,int right,int bottom,int IN_OUT,
						    int THICK_THIN,int color)
    {

       x1=left;
       y1=top;
       x2=right;
       y2=bottom;

       panel_color=color;

       in_out=IN_OUT;
       thick_thin=THICK_THIN;

    }


 /************************************************************************/
 //-----------------  modify(int,int,int,int,int,int,int)  --------------//
 /************************************************************************/

 void Panel::modify(int left,int top,int right,int bottom,int IN_OUT,
						    int THICK_THIN,int color)
    {
       x1=left;
       y1=top;
       x2=right;
       y2=bottom;

       panel_color=color;

       in_out=IN_OUT;
       thick_thin=THICK_THIN;
    }

 /************************************************************************/
 //------------------------------  show( )  -----------------------------//
 /************************************************************************/

 void Panel::show( )
   {
       hidemouse( );
       get_current_settings( );

       if(panel_color==15)
	  panel_color=7;

       setfillstyle(1,panel_color);
	 bar(x1,y1,x2,y2);

       if(in_out==OUT)
	  setcolor(15);

       else
	  setcolor(8);

       line(x1,y1,x2-1,y1);
       line(x1,y1,x1,y2-1);

       if(thick_thin==THICK)
	  {
	     line(x1+1,y1+1,x2,y1+1);
	     line(x1+1,y1,x1+1,y2);
	  }

       if(in_out==OUT)
	  setcolor(8);

       else
	  setcolor(15);

       line(x1+1,y2,x2,y2);
       line(x2,y1+1,x2,y2);

       if(thick_thin==THICK)
	  {
	     line(x1+2,y2-1,x2,y2-1);
	     line(x2-1,y1+2,x2-1,y2);
	  }

       restore_previous_settings( );
       showmouse( );
    }
 union REGS InRegs;
  union REGS OutRegs;

 /*************************************************************************/
 /*************************************************************************/
 //------------------------  Function Definitions  -----------------------//
 /*************************************************************************/
 /*************************************************************************/

 /*************************************************************************/
 //---------------------------  initmouse( )  ----------------------------//
 /*************************************************************************/

 const int initmouse( )
    {
       InRegs.x.ax = 0x0000;
       int86(0x33, &InRegs, &OutRegs);

       if(OutRegs.x.ax == 0xFFFF)
	  return 1;

       else
	  return 0;
    }

 /*************************************************************************/
 //--------------------------  showmouse( )  -----------------------------//
 /*************************************************************************/

 void showmouse( )
    {
       InRegs.x.ax = 0x0001;
       int86(0x33, &InRegs, &OutRegs);
    }

 /*************************************************************************/
 //----------------------  getmousecoords(int*,int*)  --------------------//
 /*************************************************************************/

 void getmousecoords(int *x,int *y)
    {
       InRegs.x.ax = 0x03;
       int86(0x33, &InRegs, &OutRegs);

       *x=OutRegs.x.cx;
       *y=OutRegs.x.dx;
    }

 /*************************************************************************/
 //------------------------  mouse_key_pressed( )  -----------------------//
 /*************************************************************************/

 const int mouse_key_pressed( )
    {
       InRegs.x.ax=0x05;
       InRegs.x.bx=0x00;
       int86(0x33,&InRegs,&OutRegs);

       int flag=0;

       if(OutRegs.x.ax==0x01)
	  flag=1;

       InRegs.x.bx = 0x01;
       int86(0x33, &InRegs, &OutRegs);

       if(OutRegs.x.ax==0x02)
	  flag=2;

       InRegs.x.bx = 0x02;
       int86(0x33, &InRegs, &OutRegs);

       return flag;
    }

 /*************************************************************************/
 //-------------------------  leftmousekeypressed( ) ---------------------//
 /*************************************************************************/

 const int leftmousekeypressed( )
    {
       int flag=mouse_key_pressed( );

       return ((flag==1)?1:0);
    }

 /*************************************************************************/
 //------------------------  rightmousekeypressed( )  --------------------//
 /*************************************************************************/

 const int rightmousekeypressed( )
    {
       int flag=mouse_key_pressed( );

       return ((flag==2)?1:0);
    }

 /*************************************************************************/
 //----------------------------  hidemouse( )  ---------------------------//
 /*************************************************************************/

 void hidemouse( )
    {
       InRegs.x.ax = 0x02;
       int86(0x33, &InRegs, &OutRegs);
    }
void get_current_settings( )
    {
       struct textsettingstype text_settings;
       struct fillsettingstype fill_settings;

       gettextsettings(&text_settings);
       getfillsettings(&fill_settings);

       text_font=text_settings.font;
       text_direction=text_settings.direction;
       text_size=text_settings.charsize;

       fill_pattern=fill_settings.pattern;
       fill_color=fill_settings.color;

       text_color=getcolor( );
    }

 /************************************************************************/
 //-------------------  restore_previous_settings( )  -------------------//
 /************************************************************************/

 void restore_previous_settings( )
    {
       setcolor(text_color);
       settextstyle(text_font,text_direction,text_size);

       setfillstyle(fill_pattern,fill_color);
    }
    /*************************************************************************/
 //----------------------------  Button( )  ------------------------------//
 /*************************************************************************/

 Button::Button( )
    {
       x1=0;
       y1=0;
       x2=0;
       y2=0;

       mid_x=0;
       mid_y=0;

       NORMAL_FLAT=NORMAL;
       red_char_position=0;

       button_color=7;

       strcpy(Label,NULL);
    }

 /************************************************************************/
 //--------------  init(int,int,char*,int,int,int,int,int)  -------------//
 /************************************************************************/

 void Button::init(int x,int y,char* Text,int button_type,int width,
					   int height,int color,int red_char)
    {
       x1=x;
       y1=y;

       NORMAL_FLAT=button_type;
       button_color=color;

       int i=0;

       while(Text[i]==' ')
	  i++;

       red_char_position=i;

       if(red_char!=0)
	  red_char_position=red_char;

       if(strlen(Text)<=50)
	  strcpy(Label,Text);

       else
	  strncpy(Label,Text,50);

       settextstyle(0,0,1);

       x2=textwidth(Label)+14+width+x1;
       y2=textheight(Label)+12+height+y1;

       mid_x=((x1+x2)/2)-(textwidth(Label)/2)+1;
       mid_y=((y1+y2)/2)-(textheight(Label)/2)+1;
    }

 /************************************************************************/
 //-------------  modify(int,int,char*,int,int,int,int,int)  ------------//
 /************************************************************************/

 void Button::modify(int x,int y,char* Text,int button_type,int width,
					   int height,int color,int red_char)
    {
       x1=x;
       y1=y;

       NORMAL_FLAT=button_type;
       button_color=color;

       int i=0;

       while(Text[i]==' ')
	  i++;

       red_char_position=i;

       if(red_char!=0)
	  red_char_position=red_char;

       if(strlen(Text)<=50)
	  strcpy(Label,Text);

       else
	  strncpy(Label,Text,50);

       settextstyle(0,0,1);

       x2=textwidth(Label)+14+width+x1;
       y2=textheight(Label)+12+height+y1;

       mid_x=((x1+x2)/2)-(textwidth(Label)/2)+1;
       mid_y=((y1+y2)/2)-(textheight(Label)/2)+1;
    }

 /*************************************************************************/
 //------------------------------  show( )  ------------------------------//
 /*************************************************************************/

 void Button::show( )
    {
       hidemouse( );
       get_current_settings( );

       setfillstyle(1,button_color);
	 bar(x1,y1,x2,y2);

       if(NORMAL_FLAT==FLAT)
	  {
	     setcolor(0);
	       rectangle(x1,y1,x2-1,y2-1);

	     setcolor(15);
	       rectangle(x1+1,y1+1,x2,y2);
	  }

       else if(NORMAL_FLAT==NORMAL)
	  {
	     setcolor(15);
	       line(x1,y1,x2,y1);
	       line(x1,y1,x1,y2);

	     setcolor(8);
	       line(x1+1,y2-1,x2,y2-1);
	       line(x2-1,y2,x2-1,y1+1);

	     setcolor(0);
	       line(x2,y2,x2,y1);
	       line(x1,y2,x2,y2);

	     setcolor(button_color);
	       line(x1+1,y1+1,x1+1,y2-2);
	       line(x1+1,y1+1,x2-2,y1+1);
	  }

       int label_size=strlen(Label);

       char Title[55]={NULL};

       if(red_char_position)
	  {
	     for(int count_1=0;count_1<red_char_position;count_1++)
		strcat(Title," ");

	     strrev(Title);
	  }

       char Red_char[5]={NULL};

       Red_char[0]=Label[red_char_position];

       if(red_char_position)
	 strcat(Title,Red_char);

       else
	  Title[0]=Label[0];

       int size=(label_size-1-red_char_position);

       for(int count_2=0;count_2<size;count_2++)
	  strcat(Title," ");

       settextstyle(0,0,1);
	 setcolor(button_color);
	   outtextxy(mid_x+1,mid_y+1,Label);

       if(button_color==0)
	  setcolor(15);

       else
	  setcolor(0);

       outtextxy(mid_x,mid_y,Label);

       if(button_color==4)
	  setcolor(15);

       else
	  setcolor(4);

       if(red_char_position!=-1)
	  outtextxy(mid_x,mid_y,Title);

       restore_previous_settings( );
       showmouse( );
    }

 /************************************************************************/
 //-----------------------------  press( )  -----------------------------//
 /************************************************************************/

 void Button::press( )
    {
       hidemouse( );
       get_current_settings( );

       if(NORMAL_FLAT==FLAT)
	  {
	     setcolor(button_color);
	       line(x2-1,y2-1,x2-1,y1);
	       line(x1,y2-1,x2-1,y2-1);

	     setcolor(0);
	       line(x1,y1,x2,y1);
	       line(x1,y1,x1,y2);

	     setcolor(8);
	       line(x1+1,y1+1,x1+1,y2-1);
	       line(x1+1,y1+1,x2-1,y1+1);
	  }

       else if(NORMAL_FLAT==NORMAL)
	  {
	     setcolor(button_color);
	       line(x1+1,y2-1,x2,y2-1);
	       line(x1+1,y1+2,x2,y1+2);
	       line(x1+2,y1+2,x1+2,y2);
	       line(x2-1,y1+2,x2-1,y2-1);

	     setcolor(15);
	       line(x2,y2,x2,y1);
	       line(x1,y2,x2,y2);

	     setcolor(0);
	       line(x1,y1,x2,y1);
	       line(x1,y1,x1,y2);

	     setcolor(8);
	       line(x1+1,y1+1,x1+1,y2-1);
	       line(x1+1,y1+1,x2-1,y1+1);
	  }

       int label_size=strlen(Label);

       char Title[55]={NULL};

       if(red_char_position)
	  {
	     for(int count_1=0;count_1<red_char_position;count_1++)
		strcat(Title," ");

	     strrev(Title);
	  }

       char Red_char[5]={NULL};

       Red_char[0]=Label[red_char_position];

       if(red_char_position)
	  strcat(Title,Red_char);

       else
	  Title[0]=Label[0];

       int size=(label_size-1-red_char_position);

       for(int count_2=0;count_2<size;count_2++)
	  strcat(Title," ");

       settextstyle(0,0,1);
	 setcolor(button_color);
	   outtextxy(mid_x,mid_y,Label);

       if(button_color==0)
	  setcolor(15);

       else
	  setcolor(0);

       outtextxy(mid_x+1,mid_y+1,Label);

       if(button_color==4)
	  setcolor(15);

       else
	  setcolor(4);

       if(red_char_position!=-1)
	  outtextxy(mid_x+1,mid_y+1,Title);

       restore_previous_settings( );
       showmouse( );
    }

 /************************************************************************/
 //-----------------------------  select( )  ----------------------------//
 /************************************************************************/

 void Button::select( )
    {
       hidemouse( );
       get_current_settings( );

       setcolor(15);
	 line(x1,y1,x2,y1);
	 line(x1,y1,x1,y2);

       setcolor(button_color);
	 line(x1+1,y1+1,x1+1,y2-2);
	 line(x1+1,y1+1,x2-2,y1+1);

       setcolor(8);
	 line(x1+1,y2-1,x2,y2-1);
	 line(x2-1,y2,x2-1,y1+1);

       setcolor(0);
	 line(x2,y2,x2,y1);
	 line(x1,y2,x2,y2);

       restore_previous_settings( );
       showmouse( );
    }

 /************************************************************************/
 //----------------------  press_and_release(int)  ----------------------//
 /************************************************************************/

 void Button::press_and_release(int flag)
    {
	 press( );

	 if(flag==KEY_BOARD)
	   delay(250);

	 else if(flag==LEFT_MOUSE_KEY)
	    while(hit( ) && leftmousekeypressed( ) && !kbhit( ));

	 else if(flag==RIGHT_MOUSE_KEY)
	    while(hit( ) && rightmousekeypressed( ) && !kbhit( ));

	 show( );
    }

 /************************************************************************/
 //---------------------  select_and_release(int)  ----------------------//
 /************************************************************************/

 void Button::select_and_release(int flag)
    {
	 select( );

	 if(flag==LEFT_MOUSE_KEY)
	    while(hit( ) && !leftmousekeypressed( ) && !kbhit( ));

	 else if(flag==RIGHT_MOUSE_KEY)
	    while(hit( ) && !rightmousekeypressed( ) && !kbhit( ));

	 show( );
    }

 /************************************************************************/
 //---------------------------  hit( )  ---------------------------------//
 /************************************************************************/

 int Button::hit( )
    {
	int x;
	int y;

	getmousecoords(&x,&y);

	return ((x>=x1 && x<=x2 && y>=y1 && y<=y2)?1:0);
    }
