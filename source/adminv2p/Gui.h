
 //----------------------------  Header Files  ---------------------------//

 # include <iostream.h>
 # include <graphics.h>
 # include   <string.h>
 # include   <stdlib.h>
 # include    <stdio.h>
 # include    <conio.h>
 # include    <ctype.h>
 # include      <dos.h>

 //----------------------  Global Constant Variables  --------------------//

 # define IN               0
 # define OUT              1

 # define THICK            0
 # define THIN             1

 # define NORMAL           0
 # define FLAT             1

 # define KEY_BOARD        0
 # define LEFT_MOUSE_KEY   1
 # define RIGHT_MOUSE_KEY  2

 # define NUMBER           0
 # define CHARACTER        1
 # define ANYTHING         2

 //-------------------  General Functions Prototypes  --------------------//

 void init_graphic_mode(char*);
 void get_current_settings( );
 void restore_previous_settings( );
 void print3d(int,int,char*,int=15,int=0);
 void print_char_by_char(int,int,char*,int=15,int=10);
 const char* get_input(int,int,int,int=15,int=8,int=ANYTHING);

 //----------------------  Class Definitions  ----------------------------//
 //----------------------------  Button  ---------------------------------//

 class Button
    {
       private:
	     int x1;
	     int y1;
	     int x2;
	     int y2;
	     int mid_x;
	     int mid_y;
	     int button_color;
	     int red_char_position;
	     int NORMAL_FLAT;

	     char Label[55];

       public:
	     Button( );
	     ~Button( )  {  }

	     int hit( );

	     void show( );
	     void press( );
	     void select( );
	     void select_and_release(int=LEFT_MOUSE_KEY);
	     void press_and_release(int=LEFT_MOUSE_KEY);
	     void init(int,int,char *,int,int=0,int=0,int=7,int=0);
	     void modify(int,int,char *,int,int=0,int=0,int=7,int=0);
    };


 //-------------------------------  Panel  -------------------------------//


 class Panel
    {
       private:
	     int x1;
	     int x2;
	     int y1;
	     int y2;
	     int in_out;
	     int thick_thin;
	     int panel_color;

       public:
	     Panel( );
	     ~Panel( )  {  }
         void shape(char*txt);
	     void show( );
	     void init(int,int,int,int,int,int,int=7);
	     void modify(int,int,int,int,int,int,int=7);
    };


 //-------------------------------  Bevel  -------------------------------//


 class Bevel : public Panel
    {
	private :
		Panel Outer_bevel;
		Panel Inner_bevel;

	public :
		Bevel( )   {  }
		~Bevel( )  {  }

	        void show( );
	        void init(int,int,int,int,int,int=7);
	        void modify(int,int,int,int,int,int=7);
    };



